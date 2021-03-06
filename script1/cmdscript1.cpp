/////////////////////////////////////////////////////////////////////////////
// cmdscript1.cpp : command file
// 

#include "stdafx.h"
#include "script1PlugIn.h"
#include "DialogPrincipale.h"
#include "afxwin.h"
#include "script1App.h"
#include "atlstr.h"
#include "TestUserData.h"
#include <math.h>


#include "StdAfx.h"
#include "Resource.h"


/*********************************************************/
ON_LineCurve CurvaPV;
ON_3dPointArray m_P;
bool ExistPVLine = false;
ON_wString layer_PVLine = L"NONE";
//ON_NurbsCurve* nc = ON_NurbsCurve::New(); 
const CRhinoObject* duplicateNurbsPV;

/*********************************************************/

ON_wString LAYER_NAME_PV;
ON_UUID pvcurva;
ON_3dPoint AltezzaTacco;
ON_3dPoint	puntoAppoggio1;
ON_3dPoint	puntoAppoggio2;
ON_Plane planeAppoggio;
unsigned int OggettoMarcatura;


/********************UTLITY*************************/
/*
Description:
  Projects a curve onto a surface or polysurface
Parameters:
  brep  - [in] The brep to project the curve onto.
  curve - [in] The curve to project.
  dir   - [in] The direction of the projection.
  tol   - [in] The intersection tolerance.
  output_curves - [out] The output curves. 
                        NOTE, the caller is responsible 
                        for destroying these curves.
Returns:
  true if successful.
  false if unsuccessful.
*/
bool ProjectCurveToBrep(
        const ON_Brep& brep, 
        const ON_Curve& curve, 
        const ON_3dVector& dir, 
        double tolerance,
        ON_SimpleArray<ON_Curve*>& output_curves
        )
{
  ON_3dVector n = dir;
  if( !n.Unitize() ) 
    return false;
 
  ON_BoundingBox bbox = brep.BoundingBox();
  bbox.Union( curve.BoundingBox() );
 
  ON_Surface* pExtrusion = RhinoExtrudeCurveStraight( &curve, dir, bbox.Diagonal().Length() );
  if( 0 == pExtrusion )
    return false;
 
  ON_Brep* pBrep = ON_Brep::New();
  pBrep->Create( pExtrusion );
 
  BOOL rc = RhinoIntersectBreps( *pBrep, brep, tolerance, output_curves );
  delete pBrep; // Don't leak...
 
  return ( rc ) ? true : false;
}

/********************ENDUTLITY*************************/

/********************BEGIN_UTILITY_MARCATURA***********/
bool AddAnnotationText(
      CRhinoDoc& doc,       // reference to active document
      const ON_3dPoint& pt, // location of anotation text
      const wchar_t* text,  // the text
      double height,        // height of text item
      const wchar_t* font,  // font or face name
      int style,            // style 0=normal, 1=bold,
	  ON_Plane pl			// plane to use
      )                     //       2=italic, 3=bold and italic
{
  bool rc = false;
 
  ON_wString wText( text );
  if( wText.IsEmpty() )
    return rc;
 
  if( height <= 0 )
    height = 1.0;
 
  ON_wString wFont( font );
  if( wFont.IsEmpty() )
    wFont = L"Arial";
 
  if( style < 0 | style > 3 )
    style = 0;
 
  ON_Plane plane = pl;  //RhinoActiveCPlane();
  plane.SetOrigin( pt );
 
  ON_TextEntity2* text_entity = new ON_TextEntity2;
  CRhinoAnnotationText* text_object = new CRhinoAnnotationText;
  text_object->SetAnnotation( *text_entity );
  text_object->SetTextHeight( height );
  text_object->SetString( wText );
  text_object->SetPlane( plane );
  int idx = doc.m_font_table.FindOrCreateFont( wFont, style & 1, style & 2 );
  text_object->SetFontIndex( idx );
 
  if( doc.AddObject(text_object) )
  {
    rc = true;
    doc.Redraw();
  }
  else
  {
    delete text_object;
    text_object = 0;
  }
  return rc;
}

/**********************END_UTILITY_MARCATURA***********/

static bool SelectObjectByUuid( CRhinoDoc& doc, ON_UUID  uuid, bool bRedraw )
{
  bool rc = false;
  const CRhinoObject* object = doc.LookupObject( uuid );
  if( object  )
  {
    object->Select( true ); // && object->IsSelectable()
    if( bRedraw )
	{
      doc.Redraw();
	}
    rc = true;
  }
  return rc;
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

static bool selectobjectbyuuid_s( CRhinoDoc& doc, const wchar_t* uuid_str, bool bredraw )
{
	bool rc = false;
	CRhinoLayerTable& layer_table = doc.m_layer_table;
	ON_Layer currentLayer;
	const CRhinoLayer& current_layer = layer_table.CurrentLayer();
	int layer_index = layer_table.CurrentLayerIndex();
	const CRhinoLayer& layer2 = layer_table[layer_index];
	ON_SimpleArray<CRhinoObject*> obj_list;
	int j, obj_count = doc.LookupObject( layer2, obj_list );
	for( j = 0; j < obj_count; j++ )
	{
		CRhinoObject* obj = obj_list[j];
		ON_wString prova55 =	obj->Attributes().m_name;
		if ( obj->Attributes().m_name!= uuid_str)
		{
			::RhinoApp().Print( L"nome oggetto non trovato");
		}
		else
		{
			::RhinoApp().Print( L"trovato");
			rc = true;
		}
		CRhinoObjRef ref(obj);
		if( obj  ) //&& object->isselectable()
		{
			obj->Select( true );
			if( bredraw )
			{
				doc.Redraw();
			}
		}
		if( obj_count )
			{
			if (obj_count >1)
			{
				::RhinoApp().Print( L"THERE ARE MORE OBJETC");
			}
		}
	};
	return rc;
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

static bool SetNametoObject( CRhinoDoc& doc,unsigned int first_sn, ON_wString  name, bool bRedraw )
{

	bool rc = false;
	const CRhinoObject* objN = doc.LookupObjectByRuntimeSerialNumber( first_sn );
	ON_3dmObjectAttributes obj_attribs = objN->Attributes();

	/*************************************/
	/*MODIFY THE ATTRIBUTES OF THE OBJECT*/
	/*************************************/
	obj_attribs.m_name = name;
	const CRhinoObjRef& objref = objN;
	doc.ModifyObjectAttributes( objref, obj_attribs );
	if( bRedraw )
	{
		doc.Redraw();
	}
	rc = true;
	return rc;
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

bool AddLayer(CRhinoDoc& doc, ON_Color color, ON_wString  LayerName)
{
	ON_Layer layer;
	layer.SetLayerName(LayerName);
	layer.SetColor(color);
	/**********************************/
	/*ADD THE LAYER TO THE LAYER TABLE*/
	/**********************************/
	if(doc.m_layer_table.AddLayer( layer ))
	{
		doc.Redraw();
		return true;
	}
	else
	{
		return false;
	}	
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

bool SplitBrep(CRhinoDoc& doc, const CRhinoObject* object1, const CRhinoObject* object2)
{
	ON_SimpleArray<ON_Brep*> pieces;
	ON_SimpleArray<ON_MassProperties> MassProp;
	const CRhinoObjRef& split_ref = object1;
	const ON_Brep* split = split_ref.Brep();

	const CRhinoObjRef& cutterTop_ref = object2;
	const ON_Brep* cutter = cutterTop_ref.Brep();

	ON_3dPoint maxPoint[2];
	double     maxArea[2];
	ON_BoundingBox bbox;

	if(!RhinoBrepSplit(*split, *cutter, doc.AbsoluteTolerance(), pieces))
	{
		RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
	}	
	else
	{
		const ON_Geometry* geo = object1->Geometry();
		geo->GetBoundingBox( bbox, bbox.IsValid() );	 
		ON_3dPoint base_point = bbox.Center();


		for(int i = 0; i < pieces.Count(); i++)
		{
			ON_MassProperties* mp = &MassProp.AppendNew();	
			const ON_Brep* brep = ON_Brep::Cast(pieces[i]);
			if(brep)
			{
				brep->VolumeMassProperties(*mp, true, true, false, false, base_point);
				maxPoint[i] = MassProp.At(i)->Centroid();
				MassProp.At(i)->m_mass_type = 2;
				maxArea[i]  = MassProp.At(i)->Area();
			}
		}

		/**************************************/
		/*FINDING THE MAX VALUE OF OBJECT AREA*/
		/**************************************/
		int k = 0;
		if(maxArea[1] > maxArea[0])
		{
			k = 0;
		}
		else
		{
			k = 1;
		}

		int count = pieces.Count();
		if( (count == 0) | (count == 1) )
		{
			if( count == 1 )
			{
				delete pieces[0];
			}
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(3)!\n" );
		}
		CRhinoObjectAttributes attrib = object1->Attributes();
		attrib.m_uuid = ON_nil_uuid;
		const CRhinoObjectVisualAnalysisMode* vam_list = object1->m_analysis_mode_list;
		CRhinoBrepObject* brep_object = new CRhinoBrepObject( attrib );
		if( brep_object )
		{
			brep_object->SetBrep( pieces[k] );
			if( doc.AddObject(brep_object) )
			{
				RhinoCopyAnalysisModes( vam_list, brep_object );
			}
			else
			{
				delete brep_object;
				return false;
			}
		}
		doc.DeleteObject(split_ref); 
		doc.Redraw();
	}/*CHIUSURA ELSE*/
	
	return true;
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

bool SplitBrepFace(CRhinoDoc& doc, const CRhinoObject* object1, int pos, const CRhinoObject* object2)
{
	const CRhinoObjRef& split_ref = object1;
	const ON_Brep* split = split_ref.Brep();
	if( !split )
	{
		RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
		return false;
	}

	const ON_Curve* cut2 = ON_Curve::Cast(object2->Geometry()); 
	if( !cut2 )
	{
		return false;
	}

	ON_SimpleArray<const ON_Curve*> EdgeCurves;
	EdgeCurves.Append(cut2);
	ON_SimpleArray<ON_MassProperties> MassProp;
	ON_BoundingBox bbox;
	ON_Brep* BrepResult = RhinoSplitBrepFace(*split, 0, EdgeCurves, doc.AbsoluteTolerance());
	int num = BrepResult->m_F.Count();
	ON_3dPoint maxPoint[2];
	double maxArea[2];
	if(BrepResult)
	{
		for(int i = 0; i < num; i++)
		{
			ON_Brep* face = BrepResult->DuplicateFace(i, false);
			if( face )
			{
				const ON_Geometry* geo = object2->Geometry();
				geo->GetBoundingBox( bbox, bbox.IsValid() );	 
				ON_3dPoint base_point = bbox.Center();
				ON_MassProperties* mp = &MassProp.AppendNew();
				face->VolumeMassProperties( *mp, true, true, false, false);
				maxPoint[i] = MassProp.At(i)->Centroid();
				MassProp.At(i)->m_mass_type = 2;
				maxArea[i]  = MassProp.At(i)->Area();
			}
		}
		if(maxArea[0] > maxArea[1])
		{
			double first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			ON_Brep* face = BrepResult->DuplicateFace(0, false);
			if(doc.AddBrepObject(*face))
			{
				doc.Redraw();
				//double next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				//if( first_sn == next_sn )
				//{
				//	return CRhinoCommand::nothing;
				//}
				//else
				//{
				//	SetNametoObject(doc,first_sn, L"SURFTOP",true);	
				//}
			}
		}
		else
		{
			ON_Brep* face = BrepResult->DuplicateFace(1, false);
			doc.AddBrepObject(*face);
			doc.Redraw();
		}
		doc.DeleteObject(split_ref);
		doc.Redraw();
	}/*CHIUSURA IF(BREPRESULT)*/

	return true;
}


/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

static void ZoomExtents( CRhinoView* view, const ON_3dPointArray& point_array )
{
  if( 0 == view )
    return;
 
  const ON_Viewport& current_vp = view->ActiveViewport().VP();
  ON_Viewport zoomed_vp;
 
  ON_Xform w2c;
  current_vp.GetXform( ON::world_cs, ON::camera_cs, w2c );
 
  ON_BoundingBox bbox = point_array.BoundingBox();
  if( bbox.IsValid() )
  {
    /*double border = 1.1;
 
    double dx = bbox.m_max.x - bbox.m_min.x;
    dx *= 0.5 * (border - 1.0);
    bbox.m_max.x += dx;
    bbox.m_min.x -= dx;
 
    double dy = bbox.m_max.y - bbox.m_min.y;
    dy *= 0.5 * (border - 1.0);
    bbox.m_max.y += dy;
    bbox.m_min.y -= dy;*/
 
    if( RhinoDollyExtents(current_vp, bbox, zoomed_vp) )
    {
      view->ActiveViewport().SetVP( zoomed_vp, false ); // secondo parametro era true
      view->Redraw();
    }
  }
}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
void DeleteObjs(CRhinoDoc& doc, int Layer_Index)
{
	ON_SimpleArray<CRhinoObject*> objects;
	const CRhinoLayer& layer = doc.m_layer_table[Layer_Index];
	int objects_count = doc.LookupObject( layer, objects );
	for(int i = 0; i < objects_count; i++)
	{
		const CRhinoObjRef& obj_ref = objects[i];
		doc.DeleteObject(obj_ref);
	}
	doc.Redraw();
}
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/




////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN script1 command
//

// Do NOT put the definition of class CCommandscript1 in a header
// file.  There is only ONE instance of a CCommandscript1 class
// and that instance is the static thescript1Command that appears
// immediately below the class definition.

class CCommandscript1 : public CRhinoCommand
{
public:
  // The one and only instance of CCommandscript1 is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandscript1::CCommandscript1()
  // is called exactly once when static thescript1Command is created.
	CCommandscript1() {}

  // CCommandscript1::~CCommandscript1()
  // is called exactly once when static thescript1Command is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandscript1() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {E9A6EA80-C645-4996-888E-D0070191CA83}
    static const GUID script1Command_UUID =
    { 0xE9A6EA80, 0xC645, 0x4996, { 0x88, 0x8E, 0xD0, 0x7, 0x1, 0x91, 0xCA, 0x83 } };
    return script1Command_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"script1"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() { return L"script1"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandscript1 object.  
// Do NOT create any other instance of a CCommandscript1 class.
static class CCommandscript1 thescript1Command;

CRhinoCommand::result CCommandscript1::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandscript1::RunCommand() is called when the user runs the "script1"
  // command or the "script1" command is run by a history operation.

  // TODO: Add command code here.

  // Rhino command that display a dialog box interface should also support
  // a command-line, or scriptable interface.

  Cscript1PlugIn& plugin = script1PlugIn();

  bool bVisible = plugin.IsDlgVisible();

  if( context.IsInteractive() )
  {
    if( false == bVisible )
		plugin.DisplayDlg(); // tolto come parametro context.m_doc
  }

  return CRhinoCommand::success;
}

//
// END script1 command
//IT WORKS FINE!
//IT WORKS FINE2!
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


/*******************/
/*BEGIN NEW COMMAND*/
/*******************/
class CGenPianoVis : public CRhinoTestCommand
{
public:
  // The one and only instance of CCommandscript1 is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandscript1::CCommandscript1()
  // is called exactly once when static thescript1Command is created.
	CGenPianoVis() {}

  // CCommandscript1::~CCommandscript1()
  // is called exactly once when static thescript1Command is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CGenPianoVis() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		
		static const GUID CGenPianoVisCommand_UUID = 
			{ 
				0xc80ef0d2, 0xbe2f, 0x48c0, { 0x84, 0x56, 0x55, 0xd5, 0x75, 0x92, 0x3f, 0x25 } 
			};
		return CGenPianoVisCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"GenPianoVis"; }
	const wchar_t* LocalCommandName() { return L"GenPianoVis"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

static class CGenPianoVis theGenPianoVisCommand;
CRhinoCommand::result CGenPianoVis::RunCommand( const CRhinoCommandContext& context )
{

  Cscript1PlugIn& plugin = script1PlugIn();

  if( !plugin.IsDlgVisible() )
  {
    return CRhinoCommand::nothing;
  }

  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
  const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
  /***************************************************************************************************/
  /*SE LAYER_NAME NON � "NONE", VUOL DIRE CHE NON � LA PRIMA VOLTA CHE VIENE ATTIVATA QUESTA FUNZIONE*/
  /***************************************************************************************************/
  if( layer_PVLine.Compare("NONE") )
  {

    /************************************/
	/*DELETING ALL OBJECTS INTO PV LAYER*/
    /************************************/
	DeleteObjs(context.m_doc, context.m_doc.m_layer_table.FindLayer(L"PV"));

	/******************************************************/
	/*DELETING ALL OBJECTS INTO LAYER FISSO IF IT IS EXIST*/
	/******************************************************/
	if(context.m_doc.m_layer_table.FindLayer(L"FISSO") > 0)
	{
		DeleteObjs(context.m_doc, context.m_doc.m_layer_table.FindLayer(L"FISSO"));
	}

	/*********************************************************/
	/*DELETING ALL OBJECTS INTO LAYER MATRICE  IF IT IS EXIST*/
	/*********************************************************/
	if(context.m_doc.m_layer_table.FindLayer(L"MATRICE") > 0)
	{
		DeleteObjs(context.m_doc, context.m_doc.m_layer_table.FindLayer(L"MATRICE"));
	}

	/**********************************************************/
	/*DELETING ALL OBJECTS INTO LAYER FONDELLO  IF IT IS EXIST*/
	/**********************************************************/
	if(context.m_doc.m_layer_table.FindLayer(L"FONDELLO") > 0)
	{
		DeleteObjs(context.m_doc, context.m_doc.m_layer_table.FindLayer(L"FONDELLO"));
	}

	/***************************/
	/*REDRAWING ORIGINAL PVLINE*/
	/***************************/
	

	const ON_Curve* nc = ON_Curve::Cast(duplicateNurbsPV->Geometry());
	if(nc)
	{
		CRhinoObjectAttributes atts;
		atts.m_layer_index = context.m_doc.m_layer_table.FindLayer(plugin.m_dialog->LayerPV);
		if(context.m_doc.AddCurveObject(*nc, &atts))
		{
			context.m_doc.Redraw();
		}
	}
	/*************************************************/


	int layer_index = layer_table.FindLayer(L"PV");
	if( layer_index < 0 )
	{
		RhinoApp().Print( L"LAYER \"%s\" DOES NOT EXIST.\n", plugin.m_dialog->LayerPV );	
		return CRhinoCommand::nothing;
	}
	else
	{
		layer_PVLine = plugin.m_dialog->LayerPV; //gs.String();
		ON_Layer currentLayer;
		int numLayers = layer_table.LayerCount();
		layer_table.SetCurrentLayerIndex(layer_index);
		for(int i = 0; i < numLayers; i++)
		{
			if(i != layer_index)
			{
				currentLayer = layer_table[i];
				currentLayer.SetVisible(false);
				layer_table.ModifyLayer(currentLayer, i);
			}
		}
		context.m_doc.Redraw();
	}/*CHIUSURA ELSE LAYER_INDEX < 0 */		

	
	/************************************************************/
	ON_SimpleArray<CRhinoObject*> objectsPV;
	int object_countPV;
	int layer_indexPV = context.m_doc.m_layer_table.FindLayer(plugin.m_dialog->LayerPV);

	if(layer_indexPV > 0)
	{
		objectsPV.Empty();
		object_countPV = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexPV], objectsPV );
	}
	/************************************************************/
	
	if(object_countPV > 1)
	{
		return CRhinoCommand::nothing;
	}
	const CRhinoObjRef& objref = objectsPV[0];
	
	const ON_Curve* pC = ON_Curve::Cast(objref.Geometry());
	if(!pC)
	{
		return CRhinoCommand::nothing;
	}
	ON_Curve* crv0 = pC->DuplicateCurve();
	if(!crv0)
	{
		return CRhinoCommand::nothing;
	}

	bool rc0 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 1, _wtof(plugin.m_dialog->EstLineaDx));
	bool rc1 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 0, _wtof(plugin.m_dialog->EstLineaSx));
	context.m_doc.ReplaceObject(objref, *crv0 );
	context.m_doc.Redraw();

	double alphaAngle = _wtof(plugin.m_dialog->AngoloAlphaDx);

	double antLen     = _wtof(plugin.m_dialog->EstRettaPolilineaDx);

	double antRad     = _wtof(plugin.m_dialog->FilletDx);

	double betaAngle  = _wtof(plugin.m_dialog->AngoloBetaSx);

	double posLen     = _wtof(plugin.m_dialog->EstRettaPolilineaSx);

	double posRad     = _wtof(plugin.m_dialog->FilletSx);

	ON_3dPoint pointStart;
	ON_3dPoint pointEnd;

/****************************************************/
	/*POSITIVE PV LINE' DIRECTION : POSITIVE X DIRECTION*/
	/****************************************************/
	ON_3dPoint Pt_s;
	ON_3dPoint Pt_e;
	double extensionDX = 0.0;
	double extensionSX = 0.0;
	if(crv0->PointAtStart().z < crv0->PointAtEnd().z)
	{
		Pt_s = crv0->PointAtStart();
		Pt_e = crv0->PointAtEnd();
	    extensionDX = _wtof(plugin.m_dialog->EstLineaDx);
	    extensionSX = _wtof(plugin.m_dialog->EstLineaSx);
	}
	else
	{
		Pt_e = crv0->PointAtStart();
		Pt_s = crv0->PointAtEnd();
	    extensionSX = _wtof(plugin.m_dialog->EstLineaDx);
	    extensionDX = _wtof(plugin.m_dialog->EstLineaSx);
	}
	/******************************/
	/*DOING THE FILLET CALCULATION*/ 
	/******************************/
	double t0 = 0.0; 
	double t1 = 0.0;
	

	ON_Plane plane;
	plane.plane_equation.y = 1.0;



	bool direction = false;

	if(crv0->PointAtStart().z < crv0->PointAtEnd().z)
	{
		pointStart = crv0->PointAtStart();
		pointEnd   = crv0->PointAtEnd();

		direction  = true;
	}
	else
	{
		pointEnd   = crv0->PointAtStart();
		pointStart = crv0->PointAtEnd();
		direction  = false;
	}
	
	puntoAppoggio1 = pointStart;
	puntoAppoggio2 = pointEnd;
	
	ON_3dPoint point0((pointStart.x - posLen*cos(betaAngle*acos(-1.0)/180.0)), 0.0, (pointStart.z + posLen*sin(betaAngle*acos(-1.0)/180.0)));
	ON_3dPoint point1((pointEnd.x + antLen*cos(alphaAngle*acos(-1.0)/180.0)), 0.0, (pointEnd.z - antLen*sin(alphaAngle*acos(-1.0)/180.0)));

	/**********************************/
	/*CREATE THE LINE CURVES TO FILLET*/ 
	/**********************************/
	ON_LineCurve curve0( pointStart, point0 ); //LINEA A SINISTRA IN FRONT VIEW
	ON_LineCurve curve1( point1, pointEnd );   //LINEA A DESTRA IN FRONT VIEW 


	/***************************************************/
	/*FILLET AT THE END/START POINTS OF THE LINE CURVES*/ 
	/***************************************************/
	double curve0_t = crv0->Domain().Max();
	double curve1_t = curve1.Domain().Min();
	ON_3dPoint PuntoAltezzaTacco = curve1.m_line.to;
	AltezzaTacco = PuntoAltezzaTacco;			


	if( RhinoGetFilletPoints(curve1,  *crv0, antRad, curve1_t, curve0_t, t1, t0, plane) )
	{
		/*******************************/
		/*TRIM BACK THE TWO LINE CURVES*/ 
		/*******************************/
		ON_Interval domain1( curve1.Domain().Min(), t1 );
		curve1.Trim( domain1 );

		if(direction)
		{
			ON_Interval domain0(crv0->Domain().Min(), t0);
			crv0->Trim(domain0);
		}
		else
		{
			ON_Interval domain0(t0, crv0->Domain().Max());
			crv0->Trim(domain0);
		}

		/**************************/
		/*COMPUTE THE FILLET CURVE*/ 
		/**************************/
		ON_3dVector radial0 = curve1.PointAt(t1) - plane.Origin();
		radial0.Unitize();

		ON_3dVector radial1 = crv0->PointAt(t0) - plane.Origin();
		radial1.Unitize();

		double angle = acos( radial0 * radial1 );
		ON_Plane fillet_plane( plane.Origin(), radial0, radial1 );
		planeAppoggio = fillet_plane;
		ON_Arc fillet( fillet_plane, plane.Origin(), antRad, angle );

		/******************/
		/*ADD THE GEOMETRY*/
		/******************/
		context.m_doc.AddCurveObject( curve1 );
		context.m_doc.ReplaceObject(objref, *crv0 );
		context.m_doc.AddCurveObject( fillet );
		context.m_doc.Redraw();
	}		

	t0 = 0.0, t1 = 0.0;

	/***********************************************/
	/*FILLET AT THE START POINTS OF THE LINE CURVES*/
	/***********************************************/
	curve0_t = crv0->Domain().Min();
	curve1_t = curve0.Domain().Min();

	if( RhinoGetFilletPoints(curve0, *crv0, posRad, curve1_t, curve0_t, t1, t0, plane) )
	{
		/*******************************/
		/*TRIM BACK THE TWO LINE CURVES*/ 
		/*******************************/
		ON_Interval domain0( t1, curve0.Domain().Max() );
		curve0.Trim( domain0 );

		if(direction)
		{
			ON_Interval domain1(t0, crv0->Domain().Max() );
			crv0->Trim( domain1 );
		}
		else
		{
			ON_Interval domain0(crv0->Domain().Min(), t0);
			crv0->Trim(domain0);
		}

		/**************************/
		/*COMPUTE THE FILLET CURVE*/ 
		/**************************/
		ON_3dVector radial0 = curve0.PointAt(t1) - plane.Origin();
		radial0.Unitize();

		ON_3dVector radial1 = crv0->PointAt(t0) - plane.Origin();
		radial1.Unitize();

		double angle = acos( radial0 * radial1 );
		ON_Plane fillet_plane( plane.Origin(), radial0, radial1 );
		ON_Arc fillet( fillet_plane, plane.Origin(), posRad, angle );

		/******************/
		/*ADD THE GEOMETRY*/ 
		/******************/
		context.m_doc.AddCurveObject( curve0 );
		context.m_doc.ReplaceObject(objref, *crv0 );
		context.m_doc.AddCurveObject( fillet );
		context.m_doc.Redraw();
	}

	/******************/
	/*CLEAN UP OR LEAK*/ 
	/******************/
	delete crv0;
	crv0 = 0;

	/*********************/
	/*JOIN LINES TOGETHER*/
	/*********************/
	ON_SimpleArray<const ON_Curve*> lines;
	ON_SimpleArray<CRhinoObject*> objectsLine;
	ON_SimpleArray<ON_Curve*> output;
	double tolerance = context.m_doc.AbsoluteTolerance();
	int LinesCount = context.m_doc.LookupObject( context.m_doc.m_layer_table.CurrentLayer(), objectsLine);

	if( LinesCount > 0 )
	{
		for(int i = 0; i < LinesCount; i++)
		{
			const CRhinoCurveObject* curve_obj = CRhinoCurveObject::Cast( objectsLine[i] );
			if( curve_obj )
			{
				lines.Append(curve_obj->Curve());
			}
		}
	}
	if( RhinoMergeCurves(lines, output, tolerance) )
	{
		for(int i = 0; i < output.Count(); i++ )
		{
			CRhinoCurveObject* crv = new CRhinoCurveObject;
			ON_3dmObjectAttributes obj_attribs = crv->Attributes();

			/*************************************/
			/*MODIFY THE ATTRIBUTES OF THE OBJECT*/ 
			/*************************************/
			obj_attribs.m_name = L"PVLine";
			const CRhinoObjRef& objref = crv;
			context.m_doc.ModifyObjectAttributes( objref, obj_attribs );

			crv->SetCurve( output[i] );
			if( context.m_doc.AddObject(crv) )
			{
				crv->Select();
			}
			else
			{
				delete crv;
			}
		}
	}/*CHIUSURA IF RHINOMERGECURVES(LINES, OUTPUT, TOLERANCE)*/

	/************************/
	/*DELETE CHILDREN CURVES*/
	/************************/
	for(int i = 0; i < LinesCount; i++ )
	{
		context.m_doc.DeleteObject(objectsLine[i]);
	}
	context.m_doc.Redraw();

	/*************************/
	/*END JOIN LINES TOGETHER*/
	/*************************/ 

	/*********************/
	/*ACTIVING ALL LAYERS*/
	/*********************/
	layer_PVLine = plugin.m_dialog->LayerPV; //gs.String();
	ON_Layer currentLayer;
	int numLayers = layer_table.LayerCount();
	layer_table.SetCurrentLayerIndex(layer_index);
	for(int i = 0; i < numLayers; i++)
	{
		if(i != layer_index)
		{
			currentLayer = layer_table[i];
			currentLayer.SetVisible(true);
			layer_table.ModifyLayer(currentLayer, i);
		}
	}
	context.m_doc.Redraw();

  }
  /*****************************************************/
  /*� LA PRIMA VOLTA CHE VIENE ATTIVATA QUESTA FUNZIONE*/
  /*****************************************************/
  if( !layer_PVLine.Compare("NONE") )
  {

	/*********************/
	/*VALIDATE THE STRING*/
	/*********************/
	ON_wString layer_name = plugin.m_dialog->LayerPV; //gs.String()
	layer_name.TrimLeftAndRight();
	if( layer_name.IsEmpty() )
	{
	  return CRhinoCommand::cancel;
	}

	/************************************/
	/*GET A REFERENCE TO THE LAYER TABLE*/
	/************************************/
	CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;

	/****************/
	/*FIND THE LAYER*/ 
	/****************/
	int layer_index = layer_table.FindLayer(layer_name);
	if( layer_index < 0 )
	{
		RhinoApp().Print( L"LAYER \"%s\" DOES NOT EXIST.\n", layer_name );	
		return CRhinoCommand::nothing;
	}
	else
	{
		layer_PVLine = layer_name; //gs.String();
		ON_Layer currentLayer;
		int numLayers = layer_table.LayerCount();
		layer_table.SetCurrentLayerIndex(layer_index);
		for(int i = 0; i < numLayers; i++)
		{
			if(i != layer_index)
			{
				currentLayer = layer_table[i];
				currentLayer.SetVisible(false);
				layer_table.ModifyLayer(currentLayer, i);
			}
		}
		context.m_doc.Redraw();
	}/*CHIUSURA ELSE LAYER_INDEX < 0 */	

	CRhinoGetObject gc;
	gc.SetCommandPrompt( L"SELECT LINE TO EXTEND" );
	gc.SetGeometryFilter( CRhinoGetObject::curve_object );
	gc.GetObjects( 1, 1 );
	if(!(gc.CommandResult() == CRhinoCommand::success))
	{
		return CRhinoCommand::nothing;
	}
	const CRhinoObjRef& objref = gc.Object(0);
	const ON_Curve* pC = ON_Curve::Cast( objref.Geometry() );
	ON_Curve* crv0 = pC->DuplicateCurve();
	duplicateNurbsPV = objref.Object()->Duplicate();

/****************************************************/
	/*POSITIVE PV LINE' DIRECTION : POSITIVE X DIRECTION*/
	/****************************************************/
	ON_3dPoint Pt_s;
	ON_3dPoint Pt_e;
	double extensionDX = 0.0;
	double extensionSX = 0.0;
	if(crv0->PointAtStart().z < crv0->PointAtEnd().z)
	{
		Pt_s = crv0->PointAtStart();
		Pt_e = crv0->PointAtEnd();
	    extensionDX = _wtof(plugin.m_dialog->EstLineaDx);
	    extensionSX = _wtof(plugin.m_dialog->EstLineaSx);
	}
	else
	{
		Pt_e = crv0->PointAtStart();
		Pt_s = crv0->PointAtEnd();
	    extensionSX = _wtof(plugin.m_dialog->EstLineaDx);
	    extensionDX = _wtof(plugin.m_dialog->EstLineaSx);
	}

	/***************************/
	/*RECORDING ORIGINAL PVLINE*/
	/***************************/
	CurvaPV.SetStartPoint(Pt_s);
	CurvaPV.SetEndPoint(Pt_e);

	bool rc0 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 1, extensionDX);
	bool rc1 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 0, extensionSX);
	context.m_doc.ReplaceObject(objref, *crv0 );
	context.m_doc.Redraw();


	double alphaAngle = _wtof(plugin.m_dialog->AngoloAlphaDx);//gn.Number();

	double antLen = _wtof(plugin.m_dialog->EstRettaPolilineaDx);// era gn.Number()

	double antRad =  _wtof(plugin.m_dialog->FilletDx);//gn.Number();

	double betaAngle = _wtof(plugin.m_dialog->AngoloBetaSx);//gn.Number();

	double posLen = _wtof(plugin.m_dialog->EstRettaPolilineaSx);//gn.Number()

	double posRad = _wtof(plugin.m_dialog->FilletSx);//gn.Number();

	ON_3dPoint pointStart;
	ON_3dPoint pointEnd;

	/***************************/
	/*DO THE FILLET CALCULATION*/ 
	/***************************/
	double t0 = 0.0, t1 = 0.0;
	puntoAppoggio1 = pointStart;
	puntoAppoggio2 = pointEnd;

	ON_Plane plane;
	plane.plane_equation.y = 1.0;


	bool direction = false;

	if(crv0->PointAtStart().z < crv0->PointAtEnd().z)
	{
		pointStart = crv0->PointAtStart();
		pointEnd   = crv0->PointAtEnd();

		direction  = true;
	}
	else
	{
		pointEnd   = crv0->PointAtStart();
		pointStart = crv0->PointAtEnd();
		direction  = false;
	}
	
	puntoAppoggio1 = pointStart;
	puntoAppoggio2 = pointEnd;

	ON_3dPoint point0((pointStart.x - posLen*cos(betaAngle*acos(-1.0)/180.0)), 0.0, (pointStart.z + posLen*sin(betaAngle*acos(-1.0)/180.0)));
	ON_3dPoint point1((pointEnd.x + antLen*cos(alphaAngle*acos(-1.0)/180.0)), 0.0, (pointEnd.z - antLen*sin(alphaAngle*acos(-1.0)/180.0)));

	/**********************************/
	/*CREATE THE LINE CURVES TO FILLET*/ 
	/**********************************/
	ON_LineCurve curve0( pointStart, point0 ); //LINEA A SINISTRA IN FRONT VIEW
	ON_LineCurve curve1( point1, pointEnd );   //LINEA A DESTRA IN FRONT VIEW 

	/***************************************************/
	/*FILLET AT THE END/START POINTS OF THE LINE CURVES*/ 
	/***************************************************/
	double curve0_t = crv0->Domain().Max();
	double curve1_t = curve1.Domain().Min();
	ON_3dPoint PuntoAltezzaTacco = curve1.m_line.to;
	AltezzaTacco = PuntoAltezzaTacco;	


	if( RhinoGetFilletPoints(curve1,  *crv0, antRad, curve1_t, curve0_t, t1, t0, plane) )
	{
		/*******************************/
		/*TRIM BACK THE TWO LINE CURVES*/ 
		/*******************************/
		ON_Interval domain1( curve1.Domain().Min(), t1 );
		curve1.Trim( domain1 );


		if(direction)
		{
			ON_Interval domain0(crv0->Domain().Min(), t0);
			crv0->Trim(domain0);
		}
		else
		{
			ON_Interval domain0(t0, crv0->Domain().Max());
			crv0->Trim(domain0);
		}

		/**************************/
		/*COMPUTE THE FILLET CURVE*/ 
		/**************************/
		ON_3dVector radial0 = curve1.PointAt(t1) - plane.Origin();
		radial0.Unitize();

		ON_3dVector radial1 = crv0->PointAt(t0) - plane.Origin();
		radial1.Unitize();

		double angle = acos( radial0 * radial1 );
		ON_Plane fillet_plane( plane.Origin(), radial0, radial1 );
		ON_Arc fillet( fillet_plane, plane.Origin(), antRad, angle );

		/******************/
		/*ADD THE GEOMETRY*/
		/******************/
		context.m_doc.AddCurveObject(curve1);
		context.m_doc.ReplaceObject(objref, *crv0);
		context.m_doc.AddCurveObject(fillet);
		context.m_doc.Redraw();
	}		

	t0 = 0.0, t1 = 0.0;

	/***********************************************/
	/*FILLET AT THE START POINTS OF THE LINE CURVES*/
	/***********************************************/
	curve0_t = crv0->Domain().Min();
	curve1_t = curve0.Domain().Min();

	if( RhinoGetFilletPoints(curve0, *crv0, posRad, curve1_t, curve0_t, t1, t0, plane) )
	{
		/*******************************/
		/*TRIM BACK THE TWO LINE CURVES*/ 
		/*******************************/
		ON_Interval domain0( t1, curve0.Domain().Max() );
		curve0.Trim( domain0 );


		if(direction)
		{
			ON_Interval domain1(t0, crv0->Domain().Max() );
			crv0->Trim( domain1 );
		}
		else
		{
			ON_Interval domain0(crv0->Domain().Min(), t0);
			crv0->Trim(domain0);
		}

		/**************************/
		/*COMPUTE THE FILLET CURVE*/ 
		/**************************/
		ON_3dVector radial0 = curve0.PointAt(t1) - plane.Origin();
		radial0.Unitize();

		ON_3dVector radial1 = crv0->PointAt(t0) - plane.Origin();
		radial1.Unitize();

		double angle = acos( radial0 * radial1 );
		ON_Plane fillet_plane( plane.Origin(), radial0, radial1 );
		ON_Arc fillet( fillet_plane, plane.Origin(), posRad, angle );

		/******************/
		/*ADD THE GEOMETRY*/ 
		/******************/
		context.m_doc.AddCurveObject( curve0 );
		context.m_doc.ReplaceObject(objref, *crv0 );
		context.m_doc.AddCurveObject( fillet );
		context.m_doc.Redraw();
	}

	/******************/
	/*CLEAN UP OR LEAK*/ 
	/******************/
	delete crv0;
	crv0 = 0;

	/*********************/
	/*JOIN LINES TOGETHER*/
	/*********************/
	ON_SimpleArray<const ON_Curve*> lines;
	ON_SimpleArray<CRhinoObject*> objectsLine;
	ON_SimpleArray<ON_Curve*> output;
	double tolerance = context.m_doc.AbsoluteTolerance();
	int LinesCount = context.m_doc.LookupObject( context.m_doc.m_layer_table.CurrentLayer(), objectsLine);

	if(LinesCount > 0)
	{
		for(int i = 0; i < LinesCount; i++)
		{
			const CRhinoCurveObject* curve_obj = CRhinoCurveObject::Cast( objectsLine[i] );
			if( curve_obj )
			{
				lines.Append(curve_obj->Curve());
			}
		}
	}
	if(RhinoMergeCurves(lines, output, tolerance))
	{
		for(int i = 0; i < output.Count(); i++ )
		{
			CRhinoCurveObject* crv = new CRhinoCurveObject;
			ON_3dmObjectAttributes obj_attribs = crv->Attributes();

			/*************************************/
			/*MODIFY THE ATTRIBUTES OF THE OBJECT*/ 
			/*************************************/
			obj_attribs.m_name = L"PVLine";
			const CRhinoObjRef& objref = crv;
			context.m_doc.ModifyObjectAttributes( objref, obj_attribs );

			crv->SetCurve( output[i] );
			if( context.m_doc.AddObject(crv) )
			{
				crv->Select();
			}
			else
			{
				delete crv;
			}
		}
	}/*CHIUSURA IF RHINOMERGECURVES(LINES, OUTPUT, TOLERANCE)*/
	/************************/
	/*DELETE CHILDREN CURVES*/
	/************************/
	for(int i = 0; i < LinesCount; i++ )
	{
		context.m_doc.DeleteObject(objectsLine[i]);
	}
	context.m_doc.Redraw();

	/*************************/
	/*END JOIN LINES TOGETHER*/
	/*************************/ 

	/*********************/
	/*ACTIVING ALL LAYERS*/
	/*********************/
	layer_PVLine = layer_name; //gs.String();
	ON_Layer currentLayer;
	int numLayers = layer_table.LayerCount();
	layer_table.SetCurrentLayerIndex(layer_index);
	for(int i = 0; i < numLayers; i++)
	{
		if(i != layer_index)
		{
			currentLayer = layer_table[i];
			currentLayer.SetVisible(true);
			layer_table.ModifyLayer(currentLayer, i);
		}
	}
	context.m_doc.Redraw();

 }/*CHIUSURA ELSE !LAYER_PVLINE.COMPARE("NONE")*/
 return CRhinoCommand::success;
}

/***********************/
/*BEGIN NEW COMMAND 2ND*/
/***********************/
class CGenCylinder : public CRhinoTestCommand
{
public:
  // The one and only instance of CCommandscript1 is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandscript1::CCommandscript1()
  // is called exactly once when static thescript1Command is created.
	CGenCylinder() {}

  // CCommandscript1::~CCommandscript1()
  // is called exactly once when static thescript1Command is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CGenCylinder() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		
	static const GUID CGenCylinderCommand_UUID = 
	{0x340e4824, 0x1cf2, 0x4f05, {0xbd, 0x74, 0xbb, 0xe7, 0x70, 0x12, 0xc1, 0x91}};
	return CGenCylinderCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"GenCylinder"; }
	const wchar_t* LocalCommandName() { return L"GenCylinder"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

static class CGenCylinder theCGenCylinderCommand;
CRhinoCommand::result CGenCylinder::RunCommand( const CRhinoCommandContext& context )
{

	Cscript1PlugIn& plugin = script1PlugIn();
	if( !plugin.IsDlgVisible() )
	{
		return CRhinoCommand::nothing;
	}

	/*****************************************/
	/*CHECKING IF THERE IS ALREADY A CYLINDER*/
	/*****************************************/
	const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
	ON_SimpleArray<CRhinoObject*> objects;
	int object_count = context.m_doc.LookupObject( layer, objects );
	const CRhinoBrepObject* brep_obj;
	const CRhinoCurveObject* curve_obj;
	const CRhinoSurfaceObject* surface_obj;
	const CRhinoLinearDimension* dimension;
	int surf_count=0;
	if( object_count > 0 )
	{
		int brep_obj_count = 0;
		int polycurve_count = 0;
		const CRhinoObject* object = 0;
		for(int i = 0; i < object_count; i++ )
		{
			object = objects[ i ];
			/************************************/
			/*TRY CASTING AS A RHINO BREP OBJECT*/ 
			/************************************/
			brep_obj = CRhinoBrepObject::Cast( object );
			if( brep_obj && !brep_obj->Attributes().m_name.Compare("CILINDRO"))
			{
				context.m_doc.DeleteObject(object);
				context.m_doc.Redraw();
			}
			dimension = CRhinoLinearDimension::Cast(object);
			if(dimension)
			{
				context.m_doc.DeleteObject(object);
				context.m_doc.Redraw();
			}
		}
		ON_3dPoint center_point( 0.0, 0.0, 0.0 );
		double radius = 63.5;
		int __count = plugin.m_dialog->m_comboAltTacco.GetCount();

		int nIndex = plugin.m_dialog->m_comboAltTacco.GetCurSel();
		CString strCBText;
		plugin.m_dialog->m_comboAltTacco.GetLBText( nIndex, strCBText);
		int height = _wtoi(strCBText);


		ON_3dPoint height_point( 0.0, 0.0, height);
		ON_3dVector zaxis = height_point - center_point;
		ON_Plane planeCir( center_point, zaxis );

        /********************************/
		/*ADD CIRCLE FOR CYLINDER'S BASE*/
		/********************************/
		ON_Circle circle( planeCir, radius );

		/**************/
		/*ADD CYLINDER*/
		/**************/
		ON_Cylinder cylinder( circle, zaxis.Length() );
		ON_Brep* brep = ON_BrepCylinder( cylinder, TRUE, TRUE );
		unsigned int first_SN;
		unsigned int next_SN;
		if( brep )
		{
			first_SN = CRhinoObject::NextRuntimeObjectSerialNumber();

			/********************/
			/*TRANSLATE CYLINDER*/
			/********************/
			int nIndex1 = plugin.m_dialog->AltezzaFondelloControllo.GetCurSel();
			CString strCBText1;
			plugin.m_dialog->AltezzaFondelloControllo.GetLBText( nIndex1, strCBText1);
			int altfondello = _wtoi(strCBText1);
			ON_wString obj_nameCyl = L"CILINDRO";
							
			
			brep->Translate(ON_3dVector( 0.0, 0.0, -altfondello));
			CRhinoBrepObject* cylinder_object = new CRhinoBrepObject();
			cylinder_object->SetBrep( brep );
			if( context.m_doc.AddObject(cylinder_object) )
			{
				context.m_doc.Redraw();
				next_SN = CRhinoObject::NextRuntimeObjectSerialNumber();
				if( first_SN == next_SN )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc,first_SN,obj_nameCyl,true);			  
				}
			}
			else
			{
				delete cylinder_object;
			}

			/*********************************************/
			/*             GESTIONE QUOTE:  DA SISTEMARE */
			/*********************************************/
			
			CRhinoSnapContext snap;
			bool dec1 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, (height - altfondello)));
			bool dec2 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, -altfondello));
			bool dec3 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, 0.0));
			bool dec4 = snap.SnapToPoint(ON_3dPoint(-63.5, 0.0, -altfondello));
			if(dec1 && dec2)
			{
				CRhinoLinearDimension* dim_obj = new CRhinoLinearDimension();
				ON_Plane plane( ON_zx_plane );
				plane.SetOrigin( ON_3dPoint(63.5, 0.0, 0.0) );
				dim_obj->SetPlane( plane );
				ON_3dPoint pt_1(63.5, 0.0, (height - altfondello));
				ON_3dPoint pt_2(63.5, 0.0, -altfondello);

				double u, v;
				plane.ClosestPointTo( pt_1, &u, &v );
				dim_obj->SetPoint( 0, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 1, ON_2dPoint(u, (v + height/2)) );


				plane.ClosestPointTo( pt_2, &u, &v );
				dim_obj->SetPoint( 2, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 3, ON_2dPoint(u, (v + height/2)) );

				dim_obj->UpdateText();
				 
				if( context.m_doc.AddObject(dim_obj) )
				{
					context.m_doc.Redraw();
				}		
				else
				{
					delete dim_obj;
				}
			}
			/*********************************************/
			/*               DA SISTEMARE                */
			/*********************************************/
			if(dec2 && dec3)
			{
				CRhinoLinearDimension* dim_obj = new CRhinoLinearDimension();
				ON_Plane plane( ON_zx_plane );
				plane.SetOrigin( ON_3dPoint(63.5, 0.0, 0.0) );
				dim_obj->SetPlane( plane );
				ON_3dPoint pt_1(63.5, 0.0, 0.0);
				ON_3dPoint pt_2(63.5, 0.0, -altfondello);

				double u, v;
				plane.ClosestPointTo( pt_1, &u, &v );
				dim_obj->SetPoint( 0, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 1, ON_2dPoint(u, (v + height/2)) );


				plane.ClosestPointTo( pt_2, &u, &v );
				dim_obj->SetPoint( 2, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 3, ON_2dPoint(u, (v + height/2)) );

				dim_obj->UpdateText();
				
				if( context.m_doc.AddObject(dim_obj) )
				{
					context.m_doc.Redraw();
				}		
				else
				{
					delete dim_obj;
				}
				
			}
			/*********************************************/
			/*  DA SISTEMARE: QUOTA FONDELLO ANCHE A SINISTRA         */
			/*********************************************/
			if(dec4 && dec3)
			{
				CRhinoLinearDimension* dim_obj = new CRhinoLinearDimension();
				
				//ON_Plane plane( ON_zx_plane );
				ON_3dVector x(0,0,1);
				ON_3dVector y(1,0,0);
				//ON_3dVector z(0,0,1);
				ON_3dPoint Origin;
				ON_Plane plane(Origin,x,y);
				plane.SetOrigin( ON_3dPoint(-63.5, 0.0, 0.0) );
				dim_obj->SetPlane( plane );
				ON_3dPoint pt_1(-63.5, 0.0, 0.0);
				ON_3dPoint pt_2(-63.5, 0.0, -altfondello);

				double u,v;
			
				plane.ClosestPointTo( pt_1, &u, &v );
				dim_obj->SetPoint( 0, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 1, ON_2dPoint(u, -(v + height/2)) );


				plane.ClosestPointTo( pt_2, &u, &v );
				dim_obj->SetPoint( 2, ON_2dPoint(u, v) );
				dim_obj->SetPoint( 3, ON_2dPoint(u, -(v + height/2)) );

				dim_obj->UpdateText();
				 
				if( context.m_doc.AddObject(dim_obj) )
				{
					context.m_doc.Redraw();
				}		
				else
				{
					delete dim_obj;
				}
			}
			
			/*********************************************/
			/*               DA SISTEMARE  By Nello      */
			/*********************************************/
			
			ON_3dPoint provapunto2 = AltezzaTacco;
			ON_3dPoint provapunto(59.5,0,provapunto2.z);
			provapunto.z-=0.7;
			ON_3dPoint pt_1(59.5, 0.0, (height - altfondello));
			CRhinoLinearDimension* dim_obj = new CRhinoLinearDimension();
			ON_Plane plane( ON_zx_plane );
			plane.SetOrigin(pt_1);
			dim_obj->SetPlane( plane );
			ON_3dPoint pt_2 = provapunto;

			double u, v;
			plane.ClosestPointTo( pt_1, &u, &v );
			dim_obj->SetPoint( 0, ON_2dPoint(u, v) );
			dim_obj->SetPoint( 1, ON_2dPoint(u, (v + height/2)) );


			plane.ClosestPointTo( pt_2, &u, &v );
			dim_obj->SetPoint( 2, ON_2dPoint(u, v) );
			dim_obj->SetPoint( 3, ON_2dPoint(u, (v + height/2)) );

			dim_obj->UpdateText();
				CRhinoObjRef ref(dim_obj);
				ON_3dmObjectAttributes obj_at_color = dim_obj->Attributes();
				if ( (height - altfondello)<provapunto.z+10)
				{
					obj_at_color.m_color.SetRGB(255,0,0);
					obj_at_color.SetColorSource(ON::color_from_object);
					
				}

			 
			if( context.m_doc.AddObject(dim_obj) )
			{
				context.m_doc.ModifyObjectAttributes(ref, obj_at_color);
				context.m_doc.Redraw();
			}		
			else
			{
				delete dim_obj;
			}
		
			/***************************/
			/*INIZIO FUNZIONE CONTROLLO*/
			/***************************/
	
			if((height - altfondello)>=provapunto.z+10)
			{
				::RhinoApp().Print( L"Funzione controllo altezza OK");
			}
			else
			{
								ON_wString wStr;
					wStr.Format( L"Funzione controllo altezza NOK: CONTROLLARE!! Il valore della testa e' minore del valore minimo di 10 mm. Occorre diminuire l'altezza del fondello o aumentare l'altezza dello stampo.", EnglishCommandName() );
					if( context.IsInteractive() )
						RhinoMessageBox( wStr, EnglishCommandName(), MB_OK );
					else
						RhinoApp().Print( wStr );
				//::RhinoApp().Print( L"Funzione controllo altezza NOK: CONTROLLARE!! Il valore della testa e' minore del valore minimo di 10 mm. Occorre diminuire l'altezza del fondello o aumentare l'altezza dello stampo.");
			}

			/****************************/
			/*INIZIO SPINE DI CENTRAGGIO*/ 
			/****************************/
			ON_3dPoint PT_SPINA_1_1(0,0,0); //(50.0,0,0)
			ON_3dPoint PT_SPINA_2_1(0,0,0); //(-50.0,0,0)
			if(!plugin.m_dialog->StatusRadio8_Fondello_di_alluminio )
			{
				PT_SPINA_1_1.x = 40;
				PT_SPINA_2_1.x = -40;
			}
			else
			{
				PT_SPINA_1_1.x = 50;
				PT_SPINA_2_1.x = -50;
			}
			ON_3dPoint PT_SPINA_1_2(50.0,0,130);
			ON_3dPoint PT_SPINA_2_2(-50.0,0,150);
			
			ON_Line Linea_Intersezione_1(PT_SPINA_1_1,PT_SPINA_1_2);
			ON_Line Linea_Intersezione_2(PT_SPINA_2_1,PT_SPINA_2_2);

			const ON_LineCurve* crvSpina1 = new ON_LineCurve(Linea_Intersezione_1);
			const ON_LineCurve* crvSpina2 = new ON_LineCurve(Linea_Intersezione_2);
			
			
			CRhinoGetObject go;
			go.SetCommandPrompt( L"Seleziona la linea originale del Piano Visionale" );
			go.SetGeometryFilter( ON::curve_object );
			go.GetObjects( 1, 1 );
			if( go.CommandResult() != CRhinoCommand::success )
				return go.CommandResult();
			 
			  // Validate input
			  const ON_Curve* curveA = go.Object(0).Curve();
			  const ON_Curve* curveB = crvSpina1;
			  const ON_Curve* curveC = crvSpina2;
				 
			  if( (0 == curveA) | (0 == curveB) )
				return CRhinoCommand::failure;
			 
			  // Calculate the intersection
			  double intersection_tolerance = 0.001;
			  double overlap_tolerance = 0.0;
			  ON_SimpleArray<ON_X_EVENT> events;
			  int count = curveA->IntersectCurve(
					curveB, 
					events, 
					intersection_tolerance, 
					overlap_tolerance
					);
			 
			  ON_3dPoint PuntoIntersezione;
			  // Process the results
			  if( count > 0 )
			  {
				  ::RhinoApp().Print( L"Intersezione punto per Piano Visionale Spina Centraggio trovato");
				  
				int i;
				for( i = 0; i < events.Count(); i++ )
				{
				  const ON_X_EVENT& e = events[i];
				  //context.m_doc.AddPointObject( e.m_A[0] );
					PuntoIntersezione = e.m_B[0];
					//context.m_doc.AddPointObject( e.m_B[0] );
				  /*if( e.m_A[0].DistanceTo(e.m_B[0]) > ON_EPSILON )
				  {
					
					context.m_doc.AddCurveObject( ON_Line(e.m_A[0], e.m_B[0]) );
					
				  }*/
				}
				

				context.m_doc.Redraw();
			  }
			 

				// second time
			   events =0;
			   count = 0;
			   count = curveA->IntersectCurve(
					curveC, 
					events, 
					intersection_tolerance, 
					overlap_tolerance
					);
			 
			  ON_3dPoint PuntoIntersezione2;
			  // Process the results
			  if( count > 0 )
			  {
				  ::RhinoApp().Print( L"Intersezione punto per Piano Visionale Spina Centraggio trovato \n");
				  
				int i;
				for( i = 0; i < events.Count(); i++ )
				{
				  const ON_X_EVENT& e = events[i];
				  //context.m_doc.AddPointObject( e.m_A[0] );
					PuntoIntersezione2 = e.m_B[0];
					//context.m_doc.AddPointObject( e.m_B[0] );
				  /*if( e.m_A[0].DistanceTo(e.m_B[0]) > ON_EPSILON )
				  {
					
					context.m_doc.AddCurveObject( ON_Line(e.m_A[0], e.m_B[0]) );
					
				  }*/
				}
				

				context.m_doc.Redraw();
			  }
			 
			 
			CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
			const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
			ON_SimpleArray<const ON_Curve*> lines;
			ON_SimpleArray<CRhinoObject*> objectsLine;	  
			
			ON_Circle SpinaCircle1( PuntoIntersezione, 4 );
			ON_Circle SpinaCircle2( PuntoIntersezione2, 4 );
			ON_Circle SpinaCircle3( PT_SPINA_1_1, 4 );
			ON_Circle SpinaCircle4( PT_SPINA_2_1, 4 );
			
			unsigned int first_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
			CRhinoCurveObject* curve_spina1 = context.m_doc.AddCurveObject( SpinaCircle1 );
			unsigned int next_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn1 == next_sn1 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINACIRCLE1";
				  SetNametoObject(context.m_doc,first_sn1,obj_name,true);			  
			  }
			unsigned int first_sn2 = CRhinoObject::NextRuntimeObjectSerialNumber();
			CRhinoCurveObject* curve_spina2 = context.m_doc.AddCurveObject( SpinaCircle2 );
			unsigned int next_sn2 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn2 == next_sn2 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINACIRCLE2";
				  SetNametoObject(context.m_doc,first_sn2,obj_name,true);			  
			  }
			unsigned int first_sn3 = CRhinoObject::NextRuntimeObjectSerialNumber();
			CRhinoCurveObject* curve_spina3 = context.m_doc.AddCurveObject( SpinaCircle3 );
			unsigned int next_sn3 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn3 == next_sn3 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINACIRCLE3";
				  SetNametoObject(context.m_doc,first_sn3,obj_name,true);			  
			  }
			unsigned int first_sn4 = CRhinoObject::NextRuntimeObjectSerialNumber();
			CRhinoCurveObject* curve_spina4 = context.m_doc.AddCurveObject( SpinaCircle4 );
			unsigned int next_sn4 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn4 == next_sn4 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINACIRCLE4";
				  SetNametoObject(context.m_doc,first_sn4,obj_name,true);			  
			  }
			context.m_doc.Redraw();
			ON_3dPoint offset(0,0,12.5);
			ON_LineCurve curvaSpina1;		
			
			
			curvaSpina1.SetStartPoint(PT_SPINA_1_1-offset);
			ON_3dPoint endpoint1(PT_SPINA_1_1+offset);
			curvaSpina1.SetEndPoint(endpoint1);

			ON_LineCurve curvaSpina2;
			curvaSpina2.SetStartPoint(PT_SPINA_2_1-offset);
			ON_3dPoint endpoint2(PT_SPINA_2_1+offset);
			curvaSpina2.SetEndPoint(endpoint2);

			ON_LineCurve curvaSpina3;
			curvaSpina3.SetStartPoint(PuntoIntersezione-offset);
			ON_3dPoint endpoint3(PuntoIntersezione+offset);
			curvaSpina3.SetEndPoint(endpoint3);
			
			ON_LineCurve curvaSpina4;
			curvaSpina4.SetStartPoint(PuntoIntersezione2-offset);
			ON_3dPoint endpoint4(PuntoIntersezione2+offset);
			curvaSpina4.SetEndPoint(endpoint4);

			//const CRhinoObjRef& objref = gc.Object(0);
		/*const ON_Curve* pC = ON_Curve::Cast( curvaSpina1 );
		ON_Curve* crv1 = pC->DuplicateCurve();
			bool rc1 = RhinoExtendCurve(crv1, CRhinoExtend::Line, 0,12.5 );*/
			unsigned int first_sn_spina1 = CRhinoObject::NextRuntimeObjectSerialNumber();
			context.m_doc.AddCurveObject(curvaSpina1);
			unsigned int next_sn_spina1 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn_spina1 == next_sn_spina1 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINALINEA1";
				  SetNametoObject(context.m_doc,first_sn_spina1,obj_name,true);			  
			  }
			  unsigned int first_sn_spina2 = CRhinoObject::NextRuntimeObjectSerialNumber();
			context.m_doc.AddCurveObject(curvaSpina2);
			unsigned int next_sn_spina2 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn_spina2 == next_sn_spina2 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINALINEA2";
				  SetNametoObject(context.m_doc,first_sn_spina2,obj_name,true);			  
			  }
			unsigned int first_sn_spina3 = CRhinoObject::NextRuntimeObjectSerialNumber();
			context.m_doc.AddCurveObject(curvaSpina3);
			unsigned int next_sn_spina3 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn_spina3 == next_sn_spina3 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINALINEA3";
				  SetNametoObject(context.m_doc,first_sn_spina3,obj_name,true);			  
			  }
		  unsigned int first_sn_spina4 = CRhinoObject::NextRuntimeObjectSerialNumber();
			context.m_doc.AddCurveObject(curvaSpina4);
			unsigned int next_sn_spina4 = CRhinoObject::NextRuntimeObjectSerialNumber();
			  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
			  if( first_sn_spina4 == next_sn_spina4 )
				return CRhinoCommand::nothing;
			  else
			  {
				  ON_wString obj_name = L"SPINALINEA4";
				  SetNametoObject(context.m_doc,first_sn_spina4,obj_name,true);			  
			  }
			context.m_doc.Redraw();
			/**************************/
			/*FINE SPINE DI CENTRAGGIO*/
			/**************************/


		  //return CRhinoCommand::success;

		/*********************************************************/
		}
	}
	/**********************************************************************/

			// BEGIN  SPINETTE CHE FERMANO LA SPINA (spinette)
				//
	  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	  int SPINALayer_Index = layer_table.FindLayer( L"Layer 01" );
	  const CRhinoLayer& SPINALayer = layer_table[SPINALayer_Index];
	  ON_SimpleArray<const ON_Curve*> lines;
	  ON_SimpleArray<CRhinoObject*> objectsLine;
	  int LinesCount = context.m_doc.LookupObject( SPINALayer, objectsLine);
	  ON_SimpleArray<const ON_Geometry*> geom( LinesCount );
	  
	  //CRhinoObject* spina = objectsLine[1];
	  for(int i = 0; i < LinesCount; i++ )
	  {
		  const ON_Geometry* geo =  objectsLine[i]->Geometry();
		  geom.Append( geo );
	  }
	  ON_BoundingBox bbox;
	  // begin inizio punto
	  for(int i = 0; i < LinesCount; i++ )
	  {
		geom[i]->GetBoundingBox( bbox, bbox.IsValid() );
	  }
	  ON_3dPoint base_point = bbox.Center();
	  ON_SimpleArray<ON_MassProperties> MassProp;
	  MassProp.Reserve( geom.Count() );
	  ON_3dPoint maxPoint;
	  ON_3dPoint a,b;
	  double maxHspinaZ = 0; 
	  double maxHspinaX = 0; 
	  double maxHspinaY = 0; 

	  for(int i = 0; i < geom.Count(); i++ )
	  {
		ON_MassProperties* mp = &MassProp.AppendNew();	
		const ON_Brep* brep = ON_Brep::Cast(geom[i]);
		if( brep )
		{
		  brep->VolumeMassProperties( *mp, true, true, false, false, base_point );
		  bool dio = brep->GetBoundingBox(a,b);
			ON_3dPoint c = b;
			if(c.z > maxHspinaZ) {maxHspinaZ = c.z;}
			if(c.x > maxHspinaX) {maxHspinaX = c.x;}
			if(c.y > maxHspinaY) {maxHspinaY = c.y;}
		}
	  }
	  
	  // il punto finale che varia sara' la x, quando la spina e' disassata.
	  // in base a un mio ragionamento questo valore e' cosi' determinato:
		double puntoSfinale = maxHspinaX - maxHspinaY; // da provare.
		/* qui andra' la parte di intersezione con la superficie nel fix... ripeto SUPERFICIE....*/
		// end fine punto

	  double valore_ugello =(_wtof(plugin.m_dialog->ValIniezioneDisassamento));
	  double temp5;
	  if (valore_ugello==12){temp5 = -2.6;}
	  else
	  {temp5 = 2.6;}

	  ON_3dPoint aa1(0,0,95);
	  ON_3dPoint aa2(temp5,2.6,95);
	  ON_3dPoint aa3(temp5,-2.6,95);
			
			LinesCount = context.m_doc.LookupObject( layer, objectsLine);
			ON_SimpleArray<const ON_Curve*> linesPV;
			ON_SimpleArray<CRhinoObject*> objectsLinePV;	  
			
			ON_Circle SpinaFermo1(aa1, 1.4); // di diametro 2.8
			ON_Circle SpinaFermo2(aa2, 1.4); // di diametro 2.8
			ON_Circle SpinaFermo3(aa3, 1.4); // di diametro 2.8
			if (AltezzaTacco.z < 45)
			{
				unsigned int first_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				CRhinoCurveObject* curve_SpinaFermo1 = context.m_doc.AddCurveObject( SpinaFermo1 );
				unsigned int next_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				if( first_sn1 == next_sn1 )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					ON_wString obj_name = L"SPINAFERMO1";
					SetNametoObject(context.m_doc,first_sn1,obj_name,true);			  
				}
			}
			else
			{
				unsigned int first_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				CRhinoCurveObject* curve_SpinaFermo2 = context.m_doc.AddCurveObject( SpinaFermo2 );
				unsigned int next_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				if( first_sn1 == next_sn1 )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					ON_wString obj_name = L"SPINAFERMO2";
					SetNametoObject(context.m_doc,first_sn1,obj_name,true);			  
				}

				unsigned int first_sn2 = CRhinoObject::NextRuntimeObjectSerialNumber();
				CRhinoCurveObject* curve_SpinaFermo3 = context.m_doc.AddCurveObject( SpinaFermo3 );
				unsigned int next_sn2 = CRhinoObject::NextRuntimeObjectSerialNumber();
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				if( first_sn2 == next_sn2 )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					ON_wString obj_name = L"SPINAFERMO3";
					SetNametoObject(context.m_doc,first_sn2,obj_name,true);			  
				}

			}
			context.m_doc.Redraw();
			// END  SPINETTE CHE FERMANO LA SPINA



			/****************************************************/
			// BEGIN PRESE DEI ROCCHETTI
			/* le prese dei rocchetti devono essere presenti soltanto quando non e' il rocchetto chiuso.*/
			/* i centri del cerchio sono a 80 e 100 dalla base del fondello*/
			/* se lo stampo e' 140 sara' presente solo quello piu' basso*/
			/* cerchi di diametro 10*/
			/* entrambi i cerchi devono capitare nella matrice, controllare questo*/
			int nIndex1 = plugin.m_dialog->AltezzaFondelloControllo.GetCurSel();
			CString strCBText1;
			plugin.m_dialog->AltezzaFondelloControllo.GetLBText( nIndex1, strCBText1);
			int altfondello = _wtoi(strCBText1); // da interfaccia parte da 10
			double valpresa = 80-altfondello;
			ON_3dPoint proc1 (0,-62.5,valpresa); // y=-62.5 da email cristiano 22 feb 2013
			ON_3dPoint proc2 (0,-62.5,valpresa+20);// y=-62.5 da email cristiano 22 feb 2013
			int nIndex = plugin.m_dialog->m_comboAltTacco.GetCurSel();
			CString strCBText;
			plugin.m_dialog->m_comboAltTacco.GetLBText( nIndex, strCBText);
			int altezzaTacco = _wtoi(strCBText); // puo essere 140, 160, 180
			
			ON_Circle PresaRocchetto1(ON_zx_plane, proc1, 5);
			ON_Circle PresaRocchetto2(ON_zx_plane, proc2, 5); 
			
			//CComboBox *combo= (CComboBox *)GetDlgItem(plugin.m_dialog->m_hWnd, IDC_COMBO2);
			//CString strCBText;
			//int nIndex = combo->GetCurSel();
			//combo->GetLBText( nIndex, strCBText);
			//CComboBox *combo2= (CComboBox *)GetDlgItem(IDC_CMBAltezzaTacco);

			// (strCBText)==("Rocchetto Normale") da mettere nell'if successivo. sara' gestito in futuro
			
			if (true)
			{
				unsigned int first_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				CRhinoCurveObject* curve_SpinaFermo1 = context.m_doc.AddCurveObject( PresaRocchetto1 );
				unsigned int next_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				if( first_sn1 == next_sn1 )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					ON_wString obj_name = L"PRESAROCCHETTO1";
					SetNametoObject(context.m_doc,first_sn1,obj_name,true);			  
				}
			}
			if (altezzaTacco>140)
			{
				unsigned int first_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				CRhinoCurveObject* curve_SpinaFermo1 = context.m_doc.AddCurveObject( PresaRocchetto2 );
				unsigned int next_sn1 = CRhinoObject::NextRuntimeObjectSerialNumber();
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				if( first_sn1 == next_sn1 )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					ON_wString obj_name = L"PRESAROCCHETTO2";
					SetNametoObject(context.m_doc,first_sn1,obj_name,true);			  
				}
			}



			// END PRESE DEI ROCCHETTI
			/****************************************************/
	
			//BEGIN ZOOM ALL
			//porca miseria non funziona bene!!
 /*
			CRhinoView* view = RhinoApp().ActiveView();
			
			if (!m_P.Count())
			{
				ON_3dPoint a1(-40,-40,-40);
				ON_3dPoint a2(40,40,40);
				m_P.Append(a1);
				m_P.Append(a2);
			}
				ZoomExtents(view,m_P);
			*/

			// END ZOOM ALL

			// begin aniello accendere tutti i layer
			ON_Layer currentLayer;
			int numLayers = layer_table.LayerCount();
			for(int i = 0; i < numLayers; i++)
			{	  
				currentLayer = layer_table[i];
				currentLayer.SetVisible(true);
				layer_table.ModifyLayer(currentLayer, i);
			}
			context.m_doc.Redraw();
			// end aniello accendere tutti i layer

			////BEGIN RINFORZO FONDELLO ALLUMINIO
			
		//UpdateData (TRUE);
			// plugin.m_dialog->StatusRadio8_Fondello_di_alluminio m_dialog.
		//GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		if(!plugin.m_dialog->StatusRadio8_Fondello_di_alluminio )
		{
					ON_3dPoint center_pointFF( 0.0, 0.0, 0.0 );
				double radiusFF = 45;
				int __countFF = plugin.m_dialog->m_comboAltTacco.GetCount();
				
				int nIndex1FF = plugin.m_dialog->AltezzaFondelloControllo.GetCurSel();
				CString strCBText1FF;
				plugin.m_dialog->AltezzaFondelloControllo.GetLBText( nIndex1FF, strCBText1FF);
				int altfondelloFF = _wtoi(strCBText1FF);
				//altfondelloFF = altfondelloFF - 35;
				if (altfondelloFF>20) return CRhinoCommand::success;


				int nIndexFF = plugin.m_dialog->m_comboAltTacco.GetCurSel();
				CString strCBTextFF;
				plugin.m_dialog->m_comboAltTacco.GetLBText( nIndexFF, strCBTextFF);
				//int heightFF = _wtoi(strCBTextFF);
				int heightFF = 35 - altfondelloFF ;

				ON_3dPoint height_pointFF( 0, 0.0, heightFF);
				ON_3dVector zaxisFF = height_pointFF - center_pointFF;
				ON_Plane planeCirFF( center_pointFF, zaxisFF );

				/********************************/
				/*ADD CIRCLE FOR CYLINDER'S BASE*/
				/********************************/
				ON_Circle circleFF( planeCirFF, radiusFF );

				/**************/
				/*ADD CYLINDER*/
				/**************/
				ON_Cylinder cylinderFF( circleFF, zaxisFF.Length() );
				ON_Brep* brepFF = ON_BrepCylinder( cylinderFF, TRUE, TRUE );
				unsigned int first_SN;
				unsigned int next_SN;
				if( brepFF )
				{
					first_SN = CRhinoObject::NextRuntimeObjectSerialNumber();

					/********************/
					/*TRANSLATE CYLINDER*/
					/********************/
					


					ON_wString obj_nameCylFF = L"rinforzofondello";
									
					
					brepFF->Translate(ON_3dVector( 0.0, 0.0, -35));
					CRhinoBrepObject* cylinder_objectFF = new CRhinoBrepObject();
					cylinder_objectFF->SetBrep( brepFF );
					if( context.m_doc.AddObject(cylinder_objectFF) )
					{
						context.m_doc.Redraw();
						next_SN = CRhinoObject::NextRuntimeObjectSerialNumber();
						if( first_SN == next_SN )
						{
							return CRhinoCommand::nothing;
						}
						else
						{
							SetNametoObject(context.m_doc,first_SN,obj_nameCylFF,true);			  
						}
					}
					else
					{
						delete cylinder_objectFF;
					}

				}
		}
			//// END RINFORZO FONDELLO ALLUMINIO


  return CRhinoCommand::success;

}



/***********************/
/*BEGIN Traslazione Ruotazione*/
/***********************/
class CTraslRuota : public CRhinoTestCommand
{
public:
  // The one and only instance of CCommandscript1 is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandscript1::CCommandscript1()
  // is called exactly once when static thescript1Command is created.
	CTraslRuota() {}

  // CCommandscript1::~CCommandscript1()
  // is called exactly once when static thescript1Command is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CTraslRuota() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
	
		// {9EDB030E-81A5-4e20-A7E6-0DAEB4D077D2}



	static const GUID CTraslRuotaCommand_UUID = 
	{ 0x9edb030e, 0x81a5, 0x4e20, { 0xa7, 0xe6, 0xd, 0xae, 0xb4, 0xd0, 0x77, 0xd2 } };
	return CTraslRuotaCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"TraslaRuota"; }
	const wchar_t* LocalCommandName() { return L"TraslaRuota"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

static class CTraslRuota theCTraslRuotaCommand;
CRhinoCommand::result CTraslRuota::RunCommand( const CRhinoCommandContext& context )
{
	Cscript1PlugIn& plugin = script1PlugIn();
	if( !plugin.IsDlgVisible() )
	{
		return CRhinoCommand::nothing;
	}

	/*GET A REFERENCE TO THE LAYER TABLE*/
	CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	ON_Layer currentLayer;
	int numLayers = layer_table.LayerCount();
	ON_wString name;

	for(int i = 0; i < numLayers; i++)
	{
		currentLayer = layer_table[i];
		const CRhinoLayer& layer = layer_table[i];

		currentLayer.SetVisible(true);

	  ON_Layer currentLayer;
		  int numLayers = layer_table.LayerCount();
		 
		  for(int i = 0; i < numLayers; i++)
	{
			  
				  currentLayer = layer_table[i];
				  const CRhinoLayer& layer = layer_table[i];

				  currentLayer.SetVisible(true);
				  
				  layer_table.ModifyLayer(currentLayer, i);
				  layer_table.SetCurrentLayerIndex(i);
				  
			  
		  
		  
		  
		  
		  const CRhinoLayer& current_layer = layer_table.CurrentLayer();

		  int layer_index = layer_table.CurrentLayerIndex();
		  const CRhinoLayer& layer2 = layer_table[layer_index];

		  ON_SimpleArray<CRhinoObject*> obj_list;
		  int j, obj_count = context.m_doc.LookupObject( layer2, obj_list );
		  for( j = 0; j < obj_count; j++ )
		  {	  
			  CRhinoObject* obj = obj_list[j];
			  ON_3dmObjectAttributes obj_attribs = obj->Attributes();
				name = obj->Attributes().m_name;
				  if( obj && obj->IsSelectable() && name.Compare("CILINDRO") )
					  obj->Select();
				  if( obj_count )
					context.m_doc.Redraw();
		  }
		  
	}  

		  context.m_doc.Redraw();

			//inizio rotazione
		  
		  double m_angle=(_wtof(plugin.m_dialog->ValoreRotazione));
		  ON_Plane plane = RhinoActiveCPlane();
		  
		CRhinoGetObject go1;
		  go1.GetObjects( 1, 0 );
		  int numero1 = go1.ObjectCount();
		for( int k = 0; k < go1.ObjectCount(); k++ )
		{
		 // Get an object reference
			const CRhinoObjRef& ref = go1.Object(k);
 
			// Get the real object
			const CRhinoObject* obj = ref.Object();
			if( !obj )
			continue;

			ON_Xform xform;
    xform.Rotation( m_angle * ON_PI / 180.0, plane.zaxis, plane.Origin() );
	context.m_doc.TransformObject( obj, xform, true, true, true );
	context.m_doc.Redraw();
		}

		//fine rotazione


			//inizio traslazione		 
		  CRhinoGetObject go;
		  int numero = go.ObjectCount();
		  go.GetObjects( 1, 0 );
		  
		for( int i = 0; i < go.ObjectCount(); i++ )
		{
		 // Get an object reference
			const CRhinoObjRef& ref = go.Object(i);
 
			// Get the real object
			const CRhinoObject* obj = ref.Object();
			if( !obj )
			continue;

			ON_Xform xform;
    xform.Rotation( m_angle * ON_PI / 180.0, plane.zaxis, plane.Origin() );
	//context.m_doc.TransformObject( obj, xform, true, true, true );
	context.m_doc.Redraw();
	xform.Translation((_wtof(plugin.m_dialog->ValoreTraslazione)),0,0);
	context.m_doc.TransformObject( obj, xform, true, true, true );
	context.m_doc.Redraw();
		}
			// fine traslazione

		
		 context.m_doc.Redraw();




return CRhinoCommand::success;


}
}




/***********************/
/*BEGIN Genera Ugello*/
/***********************/
class CGenUgello : public CRhinoTestCommand
{
public:
  // The one and only instance of CCommandscript1 is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandscript1::CCommandscript1()
  // is called exactly once when static thescript1Command is created.
	CGenUgello() {}

  // CCommandscript1::~CCommandscript1()
  // is called exactly once when static thescript1Command is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CGenUgello() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
	// {732BF1E5-41D8-41b0-83EF-30BCC117DF1C}

	
	static const GUID CGenUgelloCommand_UUID = 
	{ 0x732bf1e5, 0x41d8, 0x41b0, { 0x83, 0xef, 0x30, 0xbc, 0xc1, 0x17, 0xdf, 0x1c } };
	return CGenUgelloCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"GenUgello"; }
	const wchar_t* LocalCommandName() { return L"GenUgello"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

static class CGenUgello theCGenUgelloCommand;
CRhinoCommand::result CGenUgello::RunCommand( const CRhinoCommandContext& context )
{
		Cscript1PlugIn& plugin = script1PlugIn();
		if( !plugin.IsDlgVisible() )
		{
			return CRhinoCommand::nothing;
		}

	  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	  const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
	  ON_SimpleArray<const ON_Curve*> lines;
	  ON_SimpleArray<CRhinoObject*> objectsLine;
	  int LinesCount = context.m_doc.LookupObject( layer, objectsLine);
	  
	  for (int i = 0; i < LinesCount; i++ )
			{
				if(!objectsLine[i]->Attributes().m_name.Compare("ugello"))
						{
						context.m_doc.DeleteObject(objectsLine[i]);
						}
			}
	  context.m_doc.Redraw();
	  ON_SimpleArray<CRhUndoRecord* > UndoRec; 
	  context.m_doc.BeginUndoRecord(L"AC_CardBoard");
			

	  //begin calcolo il punto di intersezione per disegnare l'ugello
	  double valore_ugello =(_wtof(plugin.m_dialog->ValIniezioneDisassamento));
	  ON_3dPoint inizio_linea; // (valore_ugello,0,0);
	  ON_3dPoint fine_linea; // (valore_ugello,0,130);
	  if ((plugin.m_dialog->StatoTipologiaStampo)==(L"Rocchetto Normale"))
	  {
		  inizio_linea.Set(valore_ugello,0,0);
		  fine_linea.Set(valore_ugello,0,130);
	  }
	  if ((plugin.m_dialog->StatoTipologiaStampo)==(L"Rocchetto Trasversale"))
	  {
		  inizio_linea.Set(0,0,0);
		  fine_linea.Set(0,0,130);
	  }

	  ON_Line line_ugello( inizio_linea, fine_linea );
	  const ON_LineCurve* crv3 = new ON_LineCurve(line_ugello);
	  // context.m_doc.AddCurveObject( line_ugello );

	  //begin deseleziona tutto
	  ON_SimpleArray<CRhinoObject*> obj_list;
	  int j, obj_count = context.m_doc.LookupObject( layer, obj_list );
	  
	  for( j = 0; j < obj_count; j++ )
		  {
				  CRhinoObject* obj = obj_list[j];
				  if( obj && obj->IsSelectable() )
					  obj->UnselectAllSubObjects();
					//obj->Select(false);
				  if( obj_count )
					context.m_doc.Redraw();
		  }
		// end deseleziona tutto
	   
	   // inizio esempio

	  // Select two curves to intersect
  CRhinoGetObject go;
  go.SetCommandPrompt( L"Seleziona la linea originale del Piano Visionale" );
  go.SetGeometryFilter( ON::curve_object );
  go.GetObjects( 1, 1 );
  if( go.CommandResult() != CRhinoCommand::success )
    return go.CommandResult();
 
  // Validate input
  const ON_Curve* curveA = go.Object(0).Curve();
  const ON_Curve* curveB = crv3;//go.Object(1).Curve();
	 
  if( (0 == curveA) | (0 == curveB) )
    return CRhinoCommand::failure;
 
  // Calculate the intersection
  double intersection_tolerance = 0.001;
  double overlap_tolerance = 0.0;
  ON_SimpleArray<ON_X_EVENT> events;
  int count = curveA->IntersectCurve(
        curveB, 
        events, 
        intersection_tolerance, 
        overlap_tolerance
        );
 
  ON_3dPoint PuntoIntersezione;
  // Process the results
  if( count > 0 )
  {
	  ::RhinoApp().Print( L"Intersezione punto per ugello trovato");
	  
    int i;
    for( i = 0; i < events.Count(); i++ )
    {
      const ON_X_EVENT& e = events[i];
      //context.m_doc.AddPointObject( e.m_A[0] );
      if( e.m_A[0].DistanceTo(e.m_B[0]) > ON_EPSILON )
      {
        //context.m_doc.AddPointObject( e.m_B[0] );
        //context.m_doc.AddCurveObject( ON_Line(e.m_A[0], e.m_B[0]) );
		PuntoIntersezione = e.m_B[0];
      }
    }
    context.m_doc.Redraw();
  }

  // fine esempio

	  //begin calcolo il punto di intersezione per disegnare l'ugello
	  
	  
	   if ((plugin.m_dialog->StatoTipologiaStampo)==(L"Rocchetto Trasversale"))
	   {
			PuntoIntersezione.y+=valore_ugello;

	   }
	   ON_3dPoint top_pt = PuntoIntersezione;
	  
	  ON_3dPoint bottom_pt = PuntoIntersezione; // l'altro punto, e.m_A[0], non e' preciso.
	  double bottom_radius = 3.25;
	  ON_Circle bottom_circle( bottom_pt, bottom_radius );

	   
	   
		top_pt.z+=8.0;
	   double top_radius = 11;
	   ON_Circle top_circle( top_pt, top_radius );

  ON_RevSurface* revsrf = new ON_RevSurface;
  ON_LineCurve* pShapeCurve = new ON_LineCurve;
  revsrf->m_curve = pShapeCurve;
  pShapeCurve->m_dim = 3;
  pShapeCurve->m_line.from = bottom_circle.PointAt(0);
  pShapeCurve->m_line.to = top_circle.PointAt(0);
  pShapeCurve->m_t.Set(0, pShapeCurve->m_line.from.DistanceTo(pShapeCurve->m_line.to));
  revsrf->m_axis.from = bottom_circle.Center();
  revsrf->m_axis.to = top_circle.Center();
  revsrf->m_angle[0] = revsrf->m_t[0] = 0.0;
  revsrf->m_angle[1] = revsrf->m_t[1] = 2.0*ON_PI;
 
  ON_Brep* tcone_brep = ON_BrepRevSurface(revsrf, TRUE, TRUE );
  unsigned int first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
  if( tcone_brep )
  {
    CRhinoBrepObject* tcone_object = new CRhinoBrepObject();
    tcone_object->SetBrep( tcone_brep );
	

    if( context.m_doc.AddObject(tcone_object) )
      context.m_doc.Redraw();
    else
      delete tcone_object;
  }

  unsigned int next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
  /*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
  if( first_sn == next_sn )
    return CRhinoCommand::nothing;
  else
  {
	  ON_wString obj_name = L"ugello";
	  SetNametoObject(context.m_doc,first_sn,obj_name,true);			  
  }

    /*context.m_doc.EndUndoRecord(undo_record_sn);
  context.m_doc.GetUndoRecords

  context.m_doc.AddCustomUndoEvent*/
   context.m_doc.EndUndoRecord();
   context.m_doc.GetUndoRecords(UndoRec);
   /*context.m_doc.Undo(*UndoRec.At(0));
   context.m_doc.Redraw();*/

return CRhinoCommand::success;
}




////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN NewName command
//

class CCommandNewName : public CRhinoCommand
{
public:
	CCommandNewName() {}
	~CCommandNewName() {}
	UUID CommandUUID()
	{
		// {CF4D4BFF-AC77-4A40-AD75-3C3BFD5FD7DD}
		static const GUID NewNameCommand_UUID =
		{ 0xCF4D4BFF, 0xAC77, 0x4A40, { 0xAD, 0x75, 0x3C, 0x3B, 0xFD, 0x5F, 0xD7, 0xDD } };
		return NewNameCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"NewName"; }
	const wchar_t* LocalCommandName() { return L"NewName"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandNewName object
static class CCommandNewName theNewNameCommand;

CRhinoCommand::result CCommandNewName::RunCommand( const CRhinoCommandContext& context )
{
	/****************************/
	/*SELECT AN OBJECT TO MODIFY*/
	/****************************/
	CRhinoGetObject go;
	go.SetCommandPrompt( L"Select object to change name" );
	go.EnablePreSelect( TRUE );
	go.EnableSubObjectSelect( FALSE );
	go.GetObjects( 1, 1 );
	if( go.CommandResult() != CRhinoCommand::success )
	{
		return go.CommandResult();
	}

	/**************************/
	/*GET THE OBJECT REFERENCE*/
	/**************************/
	const CRhinoObjRef& objref = go.Object(0);

	/****************/
	/*GET THE OBJECT*/
	/****************/
	const CRhinoObject* obj = objref.Object();
	if(!obj)
	{
		return CRhinoCommand::failure;
	}

	/**********************************************/
	/*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS*/ 
	/*HOLDS AN OBJECT'S USER-DEFINED NAME.*/ 
	/**************************************/
	ON_3dmObjectAttributes obj_attribs = obj->Attributes();

	/****************************/
	/*PROMPT FOR NEW OBJECT NAME*/
	/****************************/
	CRhinoGetString gs;
	gs.SetCommandPrompt( L"New object name" );
	gs.SetDefaultString( obj_attribs.m_name );
	gs.AcceptNothing( TRUE );
	gs.GetString();
	if(gs.CommandResult() != CRhinoCommand::success)
	{
		return gs.CommandResult();
	}

	/************************************/
	/*GET THE STRING ENTERED BY THE USER*/
	/************************************/
	ON_wString obj_name = gs.String();
	obj_name.TrimLeftAndRight();

	/*******************/
	/*IS NAME THE SAME?*/
	/*******************/
	if(obj_name.Compare(obj_attribs.m_name) == 0)
	{
		return CRhinoCommand::nothing;
	}

	/*************************************/
	/*MODIFY THE ATTRIBUTES OF THE OBJECT*/
	/*************************************/
	obj_attribs.m_name = obj_name;
	context.m_doc.ModifyObjectAttributes(objref, obj_attribs);

	return CRhinoCommand::success;
}

//
// END NewName command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

//
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
////
//// BEGIN DialogPV command
////
//
//class CCommandDialogPV : public CRhinoCommand
//{
//public:
//	CCommandDialogPV() {}
//	~CCommandDialogPV() {}
//	UUID CommandUUID()
//	{
//		// {A05939D1-66A1-480D-BAFD-213DE82F8CB8}
//		static const GUID DialogPVCommand_UUID =
//		{ 0xA05939D1, 0x66A1, 0x480D, { 0xBA, 0xFD, 0x21, 0x3D, 0xE8, 0x2F, 0x8C, 0xB8 } };
//		return DialogPVCommand_UUID;
//	}
//	const wchar_t* EnglishCommandName() { return L"DialogPV"; }
//	const wchar_t* LocalCommandName() { return L"DialogPV"; }
//	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
//};
//
//// The one and only CCommandDialogPV object
//static class CCommandDialogPV theDialogPVCommand;
//
//CRhinoCommand::result CCommandDialogPV::RunCommand( const CRhinoCommandContext& context )
//{
//	Cscript1PlugIn& plugin = script1PlugIn();
//
//  bool bVisible = plugin.IsDlgVisible2();
//
//  if( context.IsInteractive() )
//  {
//    if( false == bVisible )
//		plugin.DisplayDlg2(); // tolto come parametro context.m_doc
//  }
//
//	return CRhinoCommand::success;
//}
//
////
//// END DialogPV command
////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN TrimCylinder command
//

class CCommandTrimCylinder : public CRhinoCommand
{
public:
	CCommandTrimCylinder() {}
	~CCommandTrimCylinder() {}
	UUID CommandUUID()
	{
		// {441A83E6-80CA-4A31-A4FE-F8079ADE953B}
		static const GUID TrimCylinderCommand_UUID =
		{ 0x441A83E6, 0x80CA, 0x4A31, { 0xA4, 0xFE, 0xF8, 0x07, 0x9A, 0xDE, 0x95, 0x3B } };
		return TrimCylinderCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"TrimCylinder"; }
	const wchar_t* LocalCommandName() { return L"TrimCylinder"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandTrimCylinder object
static class CCommandTrimCylinder theTrimCylinderCommand;

CRhinoCommand::result CCommandTrimCylinder::RunCommand( const CRhinoCommandContext& context )
{
		Cscript1PlugIn& plugin = script1PlugIn();
		if( !plugin.IsDlgVisible() )
		{
			return CRhinoCommand::nothing;
		}

		const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
		ON_SimpleArray<CRhinoObject*> objects;
		int object_count = context.m_doc.LookupObject( layer, objects );
		const CRhinoBrepObject* brep_obj;
		const CRhinoCurveObject* curve_obj;
		const CRhinoSurfaceObject* surface_obj;
		const CRhinoObject* object = 0;
		unsigned int first_sn;
		unsigned int next_sn;
		ON_wString obj_name;

		/************************************************/
		/*CHECKING IF IT IS POSSIBLE TO RESPLIT CYLINDER*/
		/************************************************/
		if((context.m_doc.m_layer_table.FindLayer(L"FISSO")    > 0)  || 
		   (context.m_doc.m_layer_table.FindLayer(L"MATRICE")  > 0)  ||
		   (context.m_doc.m_layer_table.FindLayer(L"FONDELLO") > 0))
		{
			ON_SimpleArray<CRhinoObject*> objects1;
			ON_SimpleArray<CRhinoObject*> objects2;
			ON_SimpleArray<CRhinoObject*> objects3;
			objects1.Empty();
			objects2.Empty();
			objects3.Empty();
			if((context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"FISSO")],    objects1) > 0) ||
			   (context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"MATRICE")],  objects2) > 0) ||
			   (context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"FONDELLO")], objects3) > 0))
			{
				RhinoMessageBox(L"IT IS NOT POSSIBLE TO SPLIT CYLINDER AGAIN. PLEASE, PREVIEW MUST BE DONE BEFORE.", L"Warning!", MB_OK );
				return CRhinoCommand::nothing;
			}
		}


		/*********************************************/
		/*           CREATE FONDELLO PLANE           */
		/*********************************************/

		ON_3dPoint point0((63.5 + 20.0),0.0, 0.0);
		ON_3dPoint point1(-(63.5 + 20.0),0.0, 0.0);
		ON_LineCurve curve0( point0, point1 );
		first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
		if(context.m_doc.AddCurveObject(curve0))
		{
			context.m_doc.Redraw();
			next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if( first_sn == next_sn )
			{
				return CRhinoCommand::nothing;
			}
			else
			{
				SetNametoObject(context.m_doc, first_sn, L"FONDLine", true);	
			}
		}

		/*************************************************/
		/*    CREATE SURFACES "SURFTOP" AND "SURFBOT"    */
		/*************************************************/
		
		object_count = context.m_doc.LookupObject( layer, objects );
		for(int i = 0; i < object_count; i++ )
		{
			object = objects[ i ];
			
			/*******************************/
			/*TRY CASTING AS A CURVE OBJECT*/ 
			/*******************************/
			curve_obj = CRhinoCurveObject::Cast( object );
			if((curve_obj && !objects[i]->Attributes().m_name.Compare(L"PVLine")) ||
			   (curve_obj && !objects[i]->Attributes().m_name.Compare(L"FONDLine")))
			{
				first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				const ON_Geometry* geo = curve_obj->Geometry();
				const ON_Curve* curve00 = ON_Curve::Cast(geo); 
				ON_3dPoint point  = curve00->PointAt(0.0);
				ON_3dPoint point_ = curve00->PointAt(1.0);
				if((point.z + point_.z)/2 > 0.0)
				{
					obj_name = L"SURFTOP";
				}
				else
				{
					obj_name = L"SURFBOT";
				}
				ON_3dPoint point0(point.x, (point.y + 70.0), point.z);
				ON_3dPoint point1(point.x, (point.y - 70.0), point.z);
				ON_LineCurve* curve = new ON_LineCurve();
				curve->SetStartPoint(point0);
				curve->SetEndPoint(point1);
				ON_SumSurface sumSurf0;
				sumSurf0.Create(*curve, *curve00);

				if( context.m_doc.AddSurfaceObject(sumSurf0) )
				{
					context.m_doc.Redraw();
					next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
					if( first_sn == next_sn )
					{
						return CRhinoCommand::nothing;
					}
					else
					{
						SetNametoObject(context.m_doc,first_sn,obj_name,true);	
					}
				}

			}
		}/*CLOSED FOR*/

	ON_wString name;
	objects.Empty();
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table.CurrentLayer(), objects );
	const CRhinoObjRef& split_ref = NULL;
	int cylindIndex = -1;
	int surfPVIndex = -1;
	int surfFOIndex = -1;
	int countCylnds = 0;
	int countCutter = 0;

	/***********************************************************/
	/*TRY TO FIND CUTTERS SURFACES BOTH "SURFTOP" AND "SURFBOT"*/
	/***********************************************************/
	bool myBreak = false;
	int countCut = 0;
	while(countCut < 2)
	{
		countCylnds = 0;
		countCutter = 0;
		objects.Empty();
		object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table.CurrentLayer(), objects );
		for(int i = 0; i < object_count; i++)
		{
		  object = objects[ i ];
		  /*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS*/ 
		  /*HOLDS AN OBJECT'S USER-DEFINED NAME.*/ 
		  ON_3dmObjectAttributes obj_attribs = object->Attributes();
		  name = object->Attributes().m_name;
		  brep_obj = CRhinoBrepObject::Cast( object );
		  surface_obj = CRhinoSurfaceObject::Cast( object );
		  if( surface_obj && !name.Compare("SURFTOP"))
		  {
			countCutter++;
		  }/*CHIUSURA IF SUPERFICIE*/

		  if(surface_obj && !name.Compare("SURFBOT"))
		  {
			countCutter++;
		  }/*CHIUSURA IF SUPERFICIE*/


		  if(brep_obj && !name.Compare("CILINDRO"))
		  {
			  countCylnds++;
		  }/*CHIUSURA IF CILINDRO*/
			
		}
		int *cylinders = new int[countCylnds];
		int *cutters   = new int[countCutter];
		countCylnds = 0;
		countCutter = 0;
		for(int i = 0; i < object_count; i++)
		{
		  object = objects[ i ];

		  /*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS*/ 
		  /*HOLDS AN OBJECT'S USER-DEFINED NAME.*/ 
		  ON_3dmObjectAttributes obj_attribs = object->Attributes();
		  name = object->Attributes().m_name;

		  surface_obj = CRhinoSurfaceObject::Cast( object );
		  brep_obj = CRhinoBrepObject::Cast( object );
		  if( surface_obj && !name.Compare("SURFTOP"))
		  {
			  cutters[countCutter] = i;
			  countCutter++;
		  }/*CHIUSURA IF SUPERFICIE*/

		  if( surface_obj && !name.Compare("SURFBOT"))
		  {
			  cutters[countCutter] = i;
			  countCutter++;
		  }/*CHIUSURA IF SUPERFICIE*/

		  if( brep_obj && !name.Compare("CILINDRO") )
		  {
			  cylinders[countCylnds] = i;
			  countCylnds++;
		  }/*CHIUSURA IF CILINDRO*/
		}/*CHIUSURA LOOP SUGLI OGGETTI*/

		for(int i = 0; i < countCylnds; i++)
		{
			for(int j = 0; j < countCutter; j++)
			{

				myBreak = false;
				const CRhinoObjRef& split_ref = objects[ cylinders[i] ];
				const ON_Brep* split = split_ref.Brep();
				if( !split )
				{
					RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
					return failure;
				}
				ON_SimpleArray<ON_Brep*> pieces;
				pieces.Empty();
				double tol = context.m_doc.AbsoluteTolerance();
				const CRhinoObjRef& cutterTop_ref = objects[ cutters[j] ];
				const ON_Brep* cutter = cutterTop_ref.Brep();
				if( !cutter )
				{
					RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(2)!\n" );
					return failure;
				}
				if( !RhinoBrepSplit(*split, *cutter, tol, pieces) )
				{
					RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
				}
				else
				{
					countCut++;
					myBreak = true;
				}
				int count = pieces.Count();
				if( (count == 0) | (count == 1) )
				{
					if( count == 1 )
					{
						delete pieces[0];
						continue;
					}
					RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(3)!\n" );
					continue;
				}
				CRhinoObjectAttributes attrib = objects[ cylinders[i] ]->Attributes();
				attrib.m_uuid = ON_nil_uuid;
				const CRhinoObjectVisualAnalysisMode* vam_list = objects[ cylinders[i] ]->m_analysis_mode_list;
				for( int k = 0; k < count; k++ )
				{
					CRhinoBrepObject* brep_object = new CRhinoBrepObject( attrib );
					if( brep_object )
					{
						brep_object->SetBrep( pieces[k] );
						if( context.m_doc.AddObject(brep_object) )
						{
							RhinoCopyAnalysisModes( vam_list, brep_object );
						}
						else
						{
							delete brep_object;
						}
					}
				}
				context.m_doc.DeleteObject( split_ref ); 
				context.m_doc.Redraw();

				if(myBreak == true)
				{
					break;
				}
			}/*CHIUSURA LOOP COUNTCUTTER*/
		}/*CHIUSURA LOOP COUNTCYLNDS*/
		delete cylinders;
		delete cutters; 
	}/*CHIUSURA WHILE*/

	/*****************************/
	/*CREATE THE THREE NEW LAYERS*/
	/*****************************/
	/****************************************/
	/*ADD THE LAYER FISSO TO THE LAYER TABLE*/
	/****************************************/
	if(!AddLayer(context.m_doc, ON_Color(255, 0, 0), L"FISSO"))
	{
		return CRhinoCommand::nothing;
	}

	/******************************************/
	/*ADD THE LAYER MATRICE TO THE LAYER TABLE*/
	/******************************************/
	if(!AddLayer(context.m_doc, ON_Color(0, 255, 0), L"MATRICE"))
	{
		return CRhinoCommand::nothing;
	}

	/*******************************************/
	/*ADD THE LAYER FONDELLO TO THE LAYER TABLE*/
	/*******************************************/
	if(!AddLayer(context.m_doc, ON_Color(0, 0, 255), L"FONDELLO"))
	{
		return CRhinoCommand::nothing;
	}

	/********************************************************************************************/

	/**************************************************/
	/*FINDING THE NUMBER(3) PARTS OF ORIGINAL CYLINDER*/
	/**************************************************/
	countCylnds = 0;
	objects.Empty();
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table.CurrentLayer(), objects );
	for(int i = 0; i < object_count; i++)
	{
		object = objects[ i ];

		/**********************************************************************************/
		/*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS HOLDS AN OBJECT'S USER-DEFINED NAME*/
		/**********************************************************************************/
		ON_3dmObjectAttributes obj_attribs = object->Attributes();
		name = object->Attributes().m_name;
		brep_obj = CRhinoBrepObject::Cast( object );

		if( brep_obj && !name.Compare("CILINDRO") )
		{
			countCylnds++;
		}/*CHIUSURA IF CILINDRO*/
	}/*CHIUSURA LOOP SUGLI OGGETTI*/

	/******************************************************************/
	/*FINDING THE OBJECT-INDEX OF THE THREE PARTS OF ORIGINAL CYLINDER*/
	/******************************************************************/

	int *cylinders = new int[countCylnds];
	countCylnds = 0;
	for(int i = 0; i < object_count; i++)
	{
		object = objects[ i ];

		/*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS*/ 
		/*HOLDS AN OBJECT'S USER-DEFINED NAME.*/ 
		ON_3dmObjectAttributes obj_attribs = object->Attributes();
		name = object->Attributes().m_name;
		brep_obj = CRhinoBrepObject::Cast( object );

		if( brep_obj && !name.Compare("CILINDRO") )
		{
			cylinders[countCylnds] = i;
			countCylnds++;
		}/*CHIUSURA IF CILINDRO*/
	}/*CHIUSURA LOOP SUGLI OGGETTI*/

	ON_SimpleArray<const ON_Geometry*> geom( countCylnds );
	for( int i = 0; i < countCylnds; i++ ) 
	{
		const ON_Geometry* geo = objects[cylinders[i]]->Geometry();
		if( 0 == geo )
		{
			return failure;
		}
		geom.Append( geo );
	}

	/********************************************************************/
	/*GET SEPARATED BOUNDING BOX OF THE THREE PARTS OF ORIGINAL CYLINDER*/
	/********************************************************************/
	ON_BoundingBox bbox;
	for(int i = 0; i < countCylnds; i++ )
	{
		geom[i]->GetBoundingBox( bbox, bbox.IsValid() );
	}

	ON_3dPoint base_point = bbox.Center();
	ON_SimpleArray<ON_MassProperties> MassProp;
	MassProp.Reserve(geom.Count());
	ON_3dPoint maxPoint[3];
	maxPoint[0].Zero();
	maxPoint[1].Zero();
	maxPoint[2].Zero();

	for(int i = 0; i < geom.Count(); i++ )
	{
		ON_MassProperties* mp = &MassProp.AppendNew();	
		const ON_Brep* brep = ON_Brep::Cast(geom[i]);
		if(brep)
		{
			brep->VolumeMassProperties(*mp, true, true, false, false, base_point);
			maxPoint[i] = MassProp.At(i)->Centroid();
		}
	}
	/****************************/
	/*BUBBLE SORT IMPLEMENTATION*/
	/****************************/
	int intTmp = 0;
	ON_3dPoint tmp;
	tmp.Zero();
	for(int alto = 2; alto > 0; --alto )
	{
		for (int i=0; i<alto; i++)
		{
			if (maxPoint[i].z < maxPoint[i+1].z) /* SOSTITUIRE ">" CON "<" PER AVERE UN ORDINAMENTO DECRESCENTE */
			{ 
				tmp = maxPoint[i]; 
				maxPoint[i] = maxPoint[i+1]; 
				maxPoint[i+1] = tmp;
				intTmp = cylinders[i]; 
				cylinders[i] = cylinders[i+1]; 
				cylinders[i+1] = intTmp;
			}
		}	
	}

	/****************/
	/*FIND THE LAYER*/
	/****************/
	int Cyl_layer_index[3] = {context.m_doc.m_layer_table.FindLayer(L"FISSO"), 
							  context.m_doc.m_layer_table.FindLayer(L"MATRICE"), 
							  context.m_doc.m_layer_table.FindLayer(L"FONDELLO")};


	/*********************************************************************/
	/*PUTTING THE THREE PARTS OF THE ORIGINAL CYLINDER INTO RELATED LAYER*/
	/*********************************************************************/
	for(int i = 0; i < 3; i++)
	{
		CRhinoObjectAttributes atts( objects[ cylinders[i] ]->Attributes() );
		atts.m_layer_index = Cyl_layer_index[i];
		CRhinoObjRef ref(objects[ cylinders[i] ]);
		context.m_doc.ModifyObjectAttributes(ref, atts);
		/**************************************/
		/*SET NAME OF the THREE CYLINDER PARTS*/
		/**************************************/
		if(i == 0)
		{
			ON_3dmObjectAttributes obj_attribs = objects[ cylinders[i] ]->Attributes();

			/*************************************/
			/*MODIFY THE ATTRIBUTES OF THE OBJECT*/ 
			/*************************************/
			obj_attribs.m_name = L"FISSO";
			const CRhinoObjRef& objref = objects[ cylinders[i] ];
			context.m_doc.ModifyObjectAttributes( objref, obj_attribs );
		}
		if(i == 1)
		{
			ON_3dmObjectAttributes obj_attribs = objects[ cylinders[i] ]->Attributes();

			/*************************************/
			/*MODIFY THE ATTRIBUTES OF THE OBJECT*/ 
			/*************************************/
			obj_attribs.m_name = L"MATRICE";
			const CRhinoObjRef& objref = objects[ cylinders[i] ];
			context.m_doc.ModifyObjectAttributes( objref, obj_attribs );
		}
		if(i == 2)
		{
			ON_3dmObjectAttributes obj_attribs = objects[ cylinders[i] ]->Attributes();

			/*************************************/
			/*MODIFY THE ATTRIBUTES OF THE OBJECT*/ 
			/*************************************/
			obj_attribs.m_name = L"FONDELLO";
			const CRhinoObjRef& objref = objects[ cylinders[i] ];
			context.m_doc.ModifyObjectAttributes( objref, obj_attribs );
		}
	}
	context.m_doc.Redraw();

	/************************************************************************************/
	/*SPLITTING THE SURFACE "SURFTOP" AND THE SURFACE "SURFBOT" USING THE PART "MATRICE"*/
	/************************************************************************************/
	countCylnds = 0;
	countCutter = 0;
	for(int i = 0; i < object_count; i++)
	{
		object = objects[ i ];
		surface_obj = CRhinoSurfaceObject::Cast( object );
		if(surface_obj && !object->Attributes().m_name.Compare("SURFTOP"))
		{
			if(!SplitBrep(context.m_doc, objects[i], objects[cylinders[1]]))
			{
				return CRhinoCommand::nothing;
			}
		}/*CHIUSURA IF SUPERFICIE*/

		if(surface_obj && !object->Attributes().m_name.Compare("SURFBOT"))
		{
			if(!SplitBrep(context.m_doc, objects[i], objects[cylinders[1] ]))
			{
				return CRhinoCommand::nothing;
			}
		}/*CHIUSURA IF SUPERFICIE*/		 
	}/*CHIUSURA LOOP SUGLI OGGETTI*/	

	ON_SimpleArray<CRhinoObject*> objectsCORONA;
	ON_SimpleArray<CRhinoObject*> objectsPIASTRINO;
	ON_SimpleArray<CRhinoObject*> objectsPV;
	ON_SimpleArray<CRhinoObject*> objectsMATRICE;
	int object_countCORONA;
	int object_countPIASTRINO;
	int object_countPV;
	int object_countMATRICE;
	int layer_indexMATRICE   = context.m_doc.m_layer_table.FindLayer(L"MATRICE");
	int layer_indexCORONA    = context.m_doc.m_layer_table.FindLayer(L"CORONA");
	int layer_indexPIASTRINO = context.m_doc.m_layer_table.FindLayer(L"PIASTRINO");
	int layer_indexFISSO     = context.m_doc.m_layer_table.FindLayer(L"FISSO");
	int layer_indexPV        = context.m_doc.m_layer_table.FindLayer(L"PV");
	int layer_indexFONDELLO  = context.m_doc.m_layer_table.FindLayer(L"FONDELLO");

	if(layer_indexCORONA > 0)
	{
		objectsCORONA.Empty();	  
		object_countCORONA = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexCORONA], objectsCORONA );
	}
	if(layer_indexPIASTRINO > 0)
	{
		objectsPIASTRINO.Empty();  
		object_countPIASTRINO = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexPIASTRINO], objectsPIASTRINO );
	}
	if(layer_indexMATRICE > 0)
	{
		objectsMATRICE.Empty();  
		object_countMATRICE = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE );
	}
	if(layer_indexPV > 0)
	{
		objectsPV.Empty();
		object_countPV = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexPV], objectsPV );
	}

	/*******************************************/
	/*FINDING "SURFTOP" AND "SURFBOT" SURFACES */
	/*******************************************/
	bool FindingSurfTop     = false;
	bool FindingSurfBot     = false;
	bool FindingCurveCorona = false;
	bool FindingCurvePias   = false;
	int  IndexSurfTop       = 0;
	int  IndexSurfBot       = 0;
	int  IndexCurveCorona   = 0;
	int  IndexCurvePias     = 0;

	/*******************************************/
	/*FINDING "SURFTOP" AND "SURFBOT" SURFACES */
	/*******************************************/
	for(int i = 0; i < object_countPV; i++)
	{
		object = objectsPV[ i ];
		surface_obj = CRhinoSurfaceObject::Cast(object);
		if(!object->Attributes().m_name.Compare("SURFTOP"))
		{
			IndexSurfTop   = i;
			FindingSurfTop = true;
		}
		if(!object->Attributes().m_name.Compare("SURFBOT"))
		{
			IndexSurfBot   = i;
			FindingSurfBot = true;
		}
	}
	/************************/
	/*FINDING CURVE "CORONA"*/
	/************************/
	for(int i = 0; i < object_countCORONA; i++)
	{
		object = objectsCORONA[ i ];
		curve_obj   = CRhinoCurveObject::Cast( object );
		if(curve_obj)
		{
			IndexCurveCorona   = i;
			FindingCurveCorona = true;
		}
	}

	/***************************/
	/*FINDING CURVE "PIASTRINO"*/
	/***************************/
	for(int i = 0; i < object_countPIASTRINO; i++)
	{
		object = objectsPIASTRINO[i];
		curve_obj   = CRhinoCurveObject::Cast(object);
		if(curve_obj)
		{
			IndexCurvePias   = i;
			FindingCurvePias = true;
		}
	}


	RhinoApp().Print( L"ANYTHING IS HAPPENED BEFORE TRIMMING \"SURFTOP\" SURFACE USING CORONA CURVE!\n");

	  /***********************************************/
	  /*TRIMMING "SURFTOP" SURFACE USING CORONA CURVE*/
	  /***********************************************/
	  if(FindingSurfTop && FindingCurveCorona)
	  {
		//if(!SplitBrepFace(context.m_doc, objectsPV[IndexSurfTop], 0, objectsCORONA[IndexCurveCorona]))
		//{
		//	return CRhinoCommand::nothing;
		//}
		const CRhinoObjRef& split_ref = objectsPV[IndexSurfTop];
		const ON_Brep* split = split_ref.Brep();
		if( !split )
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}

		const ON_Curve* cut2 = ON_Curve::Cast(objectsCORONA[IndexCurveCorona]->Geometry()); //goo.Object(0).Curve();
		if( !cut2 )
		{
			return failure;
		}

		ON_SimpleArray<const ON_Curve*> EdgeCurves;
		EdgeCurves.Append(cut2);

		ON_Brep* BrepResult = RhinoSplitBrepFace(*split, 0, EdgeCurves, context.m_doc.AbsoluteTolerance());
		int num = BrepResult->m_F.Count();
		if(BrepResult)
		{
			ON_3dPoint maxPoint[2];
			double     maxArea[2];
			for(int i = 0; i < num; i++)
			{
				ON_Brep* face = BrepResult->DuplicateFace(i, false);
				if( face )
				{
					ON_MassProperties* mp = &MassProp.AppendNew();
					face->VolumeMassProperties( *mp, true, true, false, false, base_point);
					maxPoint[i] = MassProp.At(i)->Centroid();
					MassProp.At(i)->m_mass_type = 2;
					maxArea[i]  = MassProp.At(i)->Area();
				}
			}
			if(maxArea[0] > maxArea[1])
			{
				first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				ON_Brep* face = BrepResult->DuplicateFace(0, false);
				if(context.m_doc.AddBrepObject(*face))
				{
					context.m_doc.Redraw();
					next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
					if( first_sn == next_sn )
					{
						return CRhinoCommand::nothing;
					}
					else
					{
						SetNametoObject(context.m_doc,first_sn, L"SURFTOP",true);	
					}
				}
			}
			else
			{
				ON_Brep* face = BrepResult->DuplicateFace(1, false);
				context.m_doc.AddBrepObject(*face);
				context.m_doc.Redraw();
			}
			context.m_doc.DeleteObject(split_ref);
			context.m_doc.Redraw();
		}/*CHIUSURA IF(BREPRESULT)*/
	  }/*CHIUSURA IF(FINDINGSURF && FINDINGCURV)*/
		
		RhinoApp().Print( L"ANYTHING IS HAPPENED BEFORE TRIMMING \"SURFBOT\" SURFACE USING PIASTRINO CURVE!\n");

	  /************************************************/
	  /*TRIMMING SURFBOT SURFACE USING PIASTRINO CURVE*/
	  /************************************************/
	  if(FindingSurfBot && FindingCurvePias)
	  {
		//if(!SplitBrepFace(context.m_doc, objectsPV[IndexSurfBot], 0, objectsPIASTRINO[IndexCurvePias]))
		//{
		//	return CRhinoCommand::nothing;
		//}

		const CRhinoObjRef& split_ref = objectsPV[ IndexSurfBot ];
		const ON_Brep* split = split_ref.Brep();
		if( !split )
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}

		const ON_Curve* cut2 = ON_Curve::Cast(objectsPIASTRINO[IndexCurvePias]->Geometry()); //goo.Object(0).Curve();
		if( !cut2 )
		{
			return failure;
		}

		ON_SimpleArray<const ON_Curve*> EdgeCurves;
		EdgeCurves.Append(cut2);

		ON_Brep* BrepResult = RhinoSplitBrepFace(*split, 0, EdgeCurves, context.m_doc.AbsoluteTolerance());
		int num = BrepResult->m_F.Count();
		if(BrepResult)
		{
			ON_3dPoint maxPoint[2];
			double     maxArea[2];
			for(int i = 0; i < num; i++)
			{
				ON_Brep* face = BrepResult->DuplicateFace(i, false);
				if( face )
				{
					ON_MassProperties* mp = &MassProp.AppendNew();
					face->VolumeMassProperties(*mp, true, true, false, false, base_point);
					maxPoint[i] = MassProp.At(i)->Centroid();
					MassProp.At(i)->m_mass_type = 2;
					maxArea[i]  = MassProp.At(i)->Area();
				}
			}
			if(maxArea[0] > maxArea[1])
			{
				first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				ON_Brep* face = BrepResult->DuplicateFace(0, false);
				if(context.m_doc.AddBrepObject(*face))
				{
					context.m_doc.Redraw();
					next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
					if( first_sn == next_sn )
					{
						return CRhinoCommand::nothing;
					}
					else
					{
						SetNametoObject(context.m_doc,first_sn, L"SURFBOT",true);	
					}
				}
			}
			else
			{
				ON_Brep* face = BrepResult->DuplicateFace(1, false);
				context.m_doc.AddBrepObject(*face);
				context.m_doc.Redraw();
			}
			context.m_doc.DeleteObject(split_ref);
			context.m_doc.Redraw();
		}/*CHIUSURA IF(BREPRESULT)*/
	}/*CHIUSURA IF(FINDINGSURF && FINDINGCURV)*/


	/********************************************/
	/*DUPLICATING VISIONAL PLANE OF THE FONDELLO*/
	/********************************************/
	CRhinoObject* duplicate = objectsPV[IndexSurfBot]->Duplicate();
	if(duplicate)
	{
		if(context.m_doc.AddObject(duplicate))
		{
			CRhinoObjectAttributes atts(objectsPV[IndexSurfBot]->Attributes());
			atts.m_layer_index = layer_indexFONDELLO;
			CRhinoObjRef ref(duplicate);
			if(context.m_doc.ModifyObjectAttributes(ref, atts))
			{
				context.m_doc.Redraw();
			}
		}
		else
		{
			delete duplicate;
		}
	}

	/******************************************************************************************/
	/*FINDING "SURFTOP" AND "SURFBOT" SURFACES IN LAYER PV AND TO COPY THEM INTO LAYER MATRICE*/
	/******************************************************************************************/
	layer_indexPV = context.m_doc.m_layer_table.FindLayer(L"PV");
	if(layer_indexPV > 0)
	{
		objectsPV.Empty();
		object_countPV = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexPV], objectsPV );
	}
	for(int i = 0; i < object_countPV; i++)
	{
		object = objectsPV[ i ];
		surface_obj = CRhinoSurfaceObject::Cast(object);
		if(!object->Attributes().m_name.Compare("SURFTOP"))
		{
			CRhinoObject* duplicate = object->Duplicate();
			if( duplicate )
			{
				if(context.m_doc.AddObject(duplicate))
				{
					CRhinoObjectAttributes atts(object->Attributes());
					atts.m_layer_index = layer_indexMATRICE;
					CRhinoObjRef ref(duplicate);
					if(context.m_doc.ModifyObjectAttributes(ref, atts))
					{
						context.m_doc.DeleteObject(object);
						context.m_doc.Redraw();
					}
				}
				else
				{
					delete duplicate;
				}
			}
		}
		if(!object->Attributes().m_name.Compare("SURFBOT"))
		{
			CRhinoObject* duplicate = object->Duplicate();
			if( duplicate )
			{
				if(context.m_doc.AddObject(duplicate))
				{
					CRhinoObjectAttributes atts(object->Attributes());
					atts.m_layer_index = layer_indexMATRICE;
					CRhinoObjRef ref(duplicate);
					if(context.m_doc.ModifyObjectAttributes(ref, atts))
					{
						context.m_doc.DeleteObject(object);
						context.m_doc.Redraw();
					}
				}
				else
				{
					delete duplicate;
				}
			}
		}
	}

	/*********************************************/
	/*DUPLICATING VISIONAL PLANE INTO LAYER FISSO*/
	/*********************************************/
	layer_indexMATRICE = context.m_doc.m_layer_table.FindLayer(L"MATRICE");
	if(layer_indexMATRICE > 0)
	{
		objectsMATRICE.Empty();
		object_countMATRICE = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	}

	for(int i = 0; i < object_countMATRICE; i++)
	{
		object = objectsMATRICE[ i ];
		surface_obj = CRhinoSurfaceObject::Cast(object);
		if(!object->Attributes().m_name.Compare("SURFTOP"))
		{
			CRhinoObject* duplicate = object->Duplicate();
			if( duplicate )
			{
				if(context.m_doc.AddObject(duplicate))
				{
					CRhinoObjectAttributes atts(object->Attributes());
					atts.m_layer_index = layer_indexFISSO;
					CRhinoObjRef ref(duplicate);
					if(context.m_doc.ModifyObjectAttributes(ref, atts))
					{
						context.m_doc.Redraw();
					}
				}
				else
				{
					delete duplicate;
				}
			}
		}
	}
	return CRhinoCommand::success;
}

//
// END TrimCylinder command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN AssegnaOggettiLayer command
//

class CCommandAssegnaOggettiLayer : public CRhinoCommand
{
public:
	CCommandAssegnaOggettiLayer() {}
	~CCommandAssegnaOggettiLayer() {}
	UUID CommandUUID()
	{
		// {EB41C791-9974-41B1-905B-5EC3E32F3203}
		static const GUID AssegnaOggettiLayerCommand_UUID =
		{ 0xEB41C791, 0x9974, 0x41B1, { 0x90, 0x5B, 0x5E, 0xC3, 0xE3, 0x2F, 0x32, 0x03 } };
		return AssegnaOggettiLayerCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"AssegnaOggettiLayer"; }
	const wchar_t* LocalCommandName() { return L"AssegnaOggettiLayer"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandAssegnaOggettiLayer object
static class CCommandAssegnaOggettiLayer theAssegnaOggettiLayerCommand;

CRhinoCommand::result CCommandAssegnaOggettiLayer::RunCommand( const CRhinoCommandContext& context )
{
	Cscript1PlugIn& plugin = script1PlugIn();
		if( !plugin.IsDlgVisible() )
		{
			return CRhinoCommand::nothing;
		}

	  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	  
	  ON_SimpleArray<CRhinoObject*> objectsLine;
	   /****************/
	  /*FIND THE LAYER*/
	  /****************/
	  int Cyl_layer_index[4] = {context.m_doc.m_layer_table.FindLayer(L"FISSO"), 
								context.m_doc.m_layer_table.FindLayer(L"MATRICE"), 
								context.m_doc.m_layer_table.FindLayer(L"FONDELLO"),
								context.m_doc.m_layer_table.FindLayer(L"pv")	
								};
	  ////

	  /*if((context.m_doc.m_layer_table.FindLayer(L"FISSO")    > 0)  || 
		   (context.m_doc.m_layer_table.FindLayer(L"MATRICE")  > 0)  ||
		   (context.m_doc.m_layer_table.FindLayer(L"FONDELLO") > 0))
		{
			ON_SimpleArray<CRhinoObject*> objects1;
			ON_SimpleArray<CRhinoObject*> objects2;
			ON_SimpleArray<CRhinoObject*> objects3;
			objects1.Empty();
			objects2.Empty();
			objects3.Empty();
			if((context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"FISSO")],    objects1) > 0) ||
			   (context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"MATRICE")],  objects2) > 0) ||
			   (context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"FONDELLO")], objects3) > 0))
			
		}*/

	  ON_SimpleArray<CRhinoObject*> objects1;
	  objects1.Empty();
	  int LinesCount = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],objects1);
	   /*********************************************************************/
	  /*PUTTING THE THREE PARTS OF THE ORIGINAL CYLINDER INTO RELATED LAYER*/
	  /*********************************************************************/
	 
		
		///////////////////////////////////////////////////////////////////
	  
	  
	  for (int i = 0; i < LinesCount; i++ )
			{
				if(
					(!objects1[i]->Attributes().m_name.Compare("SPINACIRCLE3")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINACIRCLE4"))
					)
						{
							CRhinoObjectAttributes atts( objects1[i]->Attributes() );
							atts.m_layer_index = Cyl_layer_index[2];// al fondello
							CRhinoObjRef ref(objects1[i]);
							context.m_doc.ModifyObjectAttributes(ref, atts);
						}
				if(
					(!objects1[i]->Attributes().m_name.Compare("SPINACIRCLE1")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINACIRCLE2")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINAFERMO1")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINAFERMO2")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINAFERMO3"))
					)
						{
							CRhinoObjectAttributes atts( objects1[i]->Attributes() );
							atts.m_layer_index = Cyl_layer_index[0];// al fisso
							CRhinoObjRef ref(objects1[i]);
							context.m_doc.ModifyObjectAttributes(ref, atts);
						}
				if(
					(!objects1[i]->Attributes().m_name.Compare("SPINALINEA1")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINALINEA2")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINALINEA3")) ||
					(!objects1[i]->Attributes().m_name.Compare("SPINALINEA4"))
					)
						{
							CRhinoObjectAttributes atts( objects1[i]->Attributes() );
							atts.m_layer_index = Cyl_layer_index[1];// alla matrice. ti amo romina
							CRhinoObjRef ref(objects1[i]);
							context.m_doc.ModifyObjectAttributes(ref, atts);
						}
			}
	  context.m_doc.Redraw();




	return CRhinoCommand::success;
}

//
// END AssegnaOggettiLayer command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
//
// BEGIN catturaPV command
//

class CCommandcatturaPV : public CRhinoCommand
{
public:
	CCommandcatturaPV() {}
	~CCommandcatturaPV() {}
	UUID CommandUUID()
	{
		// {3F6ABBAC-DBCB-4E73-B40F-99A6144C4E81}
		static const GUID catturaPVCommand_UUID =
		{ 0x3F6ABBAC, 0xDBCB, 0x4E73, { 0xB4, 0x0F, 0x99, 0xA6, 0x14, 0x4C, 0x4E, 0x81 } };
		return catturaPVCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"catturaPV"; }
	const wchar_t* LocalCommandName() { return L"catturaPV"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandcatturaPV object
static class CCommandcatturaPV thecatturaPVCommand;

CRhinoCommand::result CCommandcatturaPV::RunCommand( const CRhinoCommandContext& context )
{
	/*ON_wString wStr;
	wStr.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
	if( context.IsInteractive() )
		RhinoMessageBox( wStr, EnglishCommandName(), MB_OK );
	else
		RhinoApp().Print( wStr );
	*/
	/*static ON_LineCurve CurvaPV;
	static bool ExistPVLine = false;*/
	static ON_wString layer_PVLine = L"NONE";

  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
  const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
  if( layer_PVLine.Compare("NONE") )/*SE LAYER_NAME NON � "NONE", NON � LA PRIMA VOLTA CHE VIENE ATTIVATA QUESTA FUNZIONE*/
  {
	/****************/
	/*FIND THE LAYER*/ 
	/****************/
	const CRhinoCurveObject* curve_obj;
	int current_layer_index = layer.LayerIndex();
	int PVLayer_Index = layer_table.FindLayer( layer_PVLine ); //INDICE DEL LAYER CONTENENTE IL PIANO VISIONALE.
	ON_SimpleArray<CRhinoObject*> objects;
	
	ON_Layer currentLayer;
	int numLayers = layer_table.LayerCount();
	layer_table.SetCurrentLayerIndex(PVLayer_Index);
	for(int i = 0; i < numLayers; i++)
	{
	  if(i != PVLayer_Index)
	  {
		  currentLayer = layer_table[i];
		  currentLayer.SetVisible(false);
		  layer_table.ModifyLayer(currentLayer, i);
	  }
	}
	context.m_doc.Redraw();
  }
	return CRhinoCommand::success;
}

//
// END catturaPV command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN TrimMatrix command
//

class CCommandTrimMatrix : public CRhinoCommand
{
public:
	CCommandTrimMatrix() {}
	~CCommandTrimMatrix() {}
	UUID CommandUUID()
	{
		// {6A358671-5D3F-4029-B44A-652E8A354B7D}
		static const GUID TrimMatrixCommand_UUID =
		{ 0x6A358671, 0x5D3F, 0x4029, { 0xB4, 0x4A, 0x65, 0x2E, 0x8A, 0x35, 0x4B, 0x7D } };
		return TrimMatrixCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"TrimMatrix"; }
	const wchar_t* LocalCommandName() { return L"TrimMatrix"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandTrimMatrix object
static class CCommandTrimMatrix theTrimMatrixCommand;

CRhinoCommand::result CCommandTrimMatrix::RunCommand( const CRhinoCommandContext& context )
{
	Cscript1PlugIn& plugin = script1PlugIn();
	if( !plugin.IsDlgVisible() )
	{
		return CRhinoCommand::nothing;
	}

	int first_sn = 0;
	int next_sn  = 0;

	int layer_indexTACCO = context.m_doc.m_layer_table.FindLayer(L"TACCO");
	int layer_indexSIL = context.m_doc.m_layer_table.FindLayer(L"SIL");
	/*****************************************/
	/*JOINING ALL SURFACES INTO LAYER "FISSO"*/
	/*****************************************/

	ON_SimpleArray<ON_Brep*> OutBreps;
	ON_SimpleArray<CRhinoObject*> objects;
	CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	int layer_indexFISSO = layer_table.FindLayer(L"FISSO");
	const CRhinoLayer& layer = context.m_doc.m_layer_table[layer_indexFISSO];
	int object_count = context.m_doc.LookupObject( layer, objects );
	ON_SimpleArray<const ON_Brep*> InBreps( object_count );
	for(int i = 0; i < object_count; i++ )
	{
		const ON_Brep* brep = ON_Brep::Cast(objects[i]->Geometry());
		if( brep )
		{
			InBreps.Append( brep );
		}
	}
	ON_SimpleArray<ON_Brep*> OutBreps2;
	bool something_happened = false;
	double tolerance = context.m_doc.AbsoluteTolerance();
	bool rc = false;

	rc = RhinoBooleanUnion( InBreps, tolerance, &something_happened, OutBreps2);
	if( !rc | !something_happened )
	{
		for(int i = 0; i < OutBreps.Count(); i++ )
		{
		  delete OutBreps[i];
		  OutBreps[i] = 0;
		}
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < OutBreps2.Count(); i++ )
	{
	ON_Brep* brep   = OutBreps2[i];
	if( brep )
	{
      CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
	  pAttributes.m_layer_index = layer_indexFISSO;
	  context.m_doc.AddBrepObject( *brep, &pAttributes);
	  brep = 0;
	  delete OutBreps2[i];
	  OutBreps2[i] = 0;
	}
	}
	for(int i = 0; i < InBreps.Count(); i++ )
	{
		context.m_doc.DeleteObject(objects[i]);
	}
	context.m_doc.Redraw();

	/*******************************************/
	/*JOINING ALL SURFACES INTO LAYER "MATRICE"*/
	/*******************************************/

	OutBreps.Empty();
	objects.Empty();
	int layer_indexMATRICE = context.m_doc.m_layer_table.FindLayer(L"MATRICE");
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexMATRICE], objects );
	InBreps.Empty();
	for(int i = 0; i < object_count; i++ )
	{
		const ON_Brep* brep = ON_Brep::Cast(objects[i]->Geometry());
		if( brep )
		{
			InBreps.Append( brep );
		}
		if(!objects[i]->Attributes().m_name.Compare("SURFTOP"))
		{
			ON_3dPoint pt = ON_3dPoint(0.0, 0.0, 250.0);
			double u = 0.0;
			double v = 0.0;
			ON_3dVector du, dv, dir;
			/***********************/
			/*GET THE SELECTED FACE*/
			/***********************/
			const CRhinoObjRef& ref = objects[i];
			const ON_Brep* brep = ref.Brep();
			if(brep)
			{
				ON_Brep* DupBrep = brep->Duplicate(); 
				if(DupBrep)
				{
					DupBrep->Flip();
					CRhinoObjectAttributes pAttributes(objects[i]->Attributes());
					pAttributes.m_layer_index = layer_indexMATRICE;
					context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
					context.m_doc.DeleteObject(ref);
					context.m_doc.Redraw();
				}
			}
		}
	}
	InBreps.Empty();
	objects.Empty();
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexMATRICE], objects );
	for(int i = 0; i < object_count; i++ )
	{
		const ON_Brep* brep = ON_Brep::Cast(objects[i]->Geometry());
		if( brep )
		{
			InBreps.Append( brep );
		}
	}

	OutBreps2.Empty();
	something_happened = false;
	tolerance = context.m_doc.AbsoluteTolerance();

	rc = RhinoBooleanUnion( InBreps, tolerance, &something_happened, OutBreps2);
	if( !rc | !something_happened )
	{
		for(int i = 0; i < OutBreps.Count(); i++ )
		{
		  delete OutBreps[i];
		  OutBreps[i] = 0;
		}
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < OutBreps2.Count(); i++ )
	{
	ON_Brep* brep   = OutBreps2[i];
	if( brep )
	{
      CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
	  pAttributes.m_layer_index = layer_indexMATRICE;
	  if(context.m_doc.AddBrepObject(*brep, &pAttributes))
	  {
		  context.m_doc.Redraw();
		  brep = 0;
		  delete OutBreps2[i];
		  OutBreps2[i] = 0;
	  }
	}
	}
	for(int i = 0; i < InBreps.Count(); i++ )
	{
		context.m_doc.DeleteObject(objects[i]);
	}
	context.m_doc.Redraw();

	/********************************************/
	/*JOINING ALL SURFACES INTO LAYER "FONDELLO"*/
	/********************************************/

	OutBreps.Empty();
	objects.Empty();
	int layer_indexFONDELLO = context.m_doc.m_layer_table.FindLayer(L"FONDELLO");
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexFONDELLO], objects );
	InBreps.Empty();
	for(int i = 0; i < object_count; i++ )
	{
		const ON_Brep* brep = ON_Brep::Cast(objects[i]->Geometry());
		if( brep )
		{
			InBreps.Append( brep );
		}
		if(!objects[i]->Attributes().m_name.Compare("SURFBOT"))
		{
			/***********************/
			/*GET THE SELECTED FACE*/
			/***********************/
			const CRhinoObjRef& ref = objects[i];
			const ON_Brep* brep = ref.Brep();
			if(brep)
			{
				ON_Brep* DupBrep = brep->Duplicate(); 
				if(DupBrep)
				{
					DupBrep->Flip();
					CRhinoObjectAttributes pAttributes(objects[i]->Attributes());
					pAttributes.m_layer_index = layer_indexFONDELLO;
					context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
					context.m_doc.DeleteObject(ref);
					context.m_doc.Redraw();
				}
			}
		}
	}
	InBreps.Empty();
	objects.Empty();
	object_count = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexFONDELLO], objects );
	for(int i = 0; i < object_count; i++ )
	{
		const ON_Brep* brep = ON_Brep::Cast(objects[i]->Geometry());
		if( brep )
		{
			InBreps.Append( brep );
		}
	}

	OutBreps2.Empty();
	something_happened = false;
	tolerance = context.m_doc.AbsoluteTolerance();
	rc = RhinoBooleanUnion(InBreps, tolerance, &something_happened, OutBreps2);
	if( !rc | !something_happened )
	{
		for(int i = 0; i < OutBreps2.Count(); i++ )
		{
		  delete OutBreps2[i];
		  OutBreps2[i] = 0;
		}
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < OutBreps2.Count(); i++ )
	{
		ON_Brep* brep   = OutBreps2[i];
		if( brep )
		{
			CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
			pAttributes.m_layer_index = layer_indexFONDELLO;
			context.m_doc.AddBrepObject( *brep, &pAttributes);
			brep = 0;
			delete OutBreps2[i];
			OutBreps2[i] = 0;
		}
	}
	for(int i = 0; i < InBreps.Count(); i++ )
	{
		context.m_doc.DeleteObject(objects[i]);
	}
	context.m_doc.Redraw();

	/**************************/
	/*RENAME SOME LAYER OBJECT*/
	/**************************/
	layer_indexMATRICE = context.m_doc.m_layer_table.FindLayer(L"MATRICE");
	objects.Empty();
	object_count = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objects);
	if(!(object_count > 1))
	{
		const CRhinoObjRef& ref = objects[0];
		const ON_Brep* brep = ref.Brep();
		if(brep)
		{
			ON_Brep* DupBrep = brep->Duplicate(); 
			if(DupBrep)
			{
				DupBrep->Flip();
				CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
				pAttributes.m_layer_index = layer_indexMATRICE;
				pAttributes.m_name = L"MATRICE";
				context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
				context.m_doc.DeleteObject(ref);
				context.m_doc.Redraw();
			}
		}
	}

	layer_indexFISSO = context.m_doc.m_layer_table.FindLayer(L"FISSO");
	objects.Empty();
	object_count = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexFISSO], objects);
	if(!(object_count > 1))
	{
		const CRhinoObjRef& ref = objects[0];
		const ON_Brep* brep = ref.Brep();
		if(brep)
		{
			ON_Brep* DupBrep = brep->Duplicate(); 
			if(DupBrep)
			{
				DupBrep->Flip();
				CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
				pAttributes.m_layer_index = layer_indexFISSO;
				pAttributes.m_name = L"FISSO";
				context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
				context.m_doc.DeleteObject(ref);
				context.m_doc.Redraw();
			}
		}
	}

	layer_indexFONDELLO = context.m_doc.m_layer_table.FindLayer(L"FONDELLO");
	objects.Empty();
	object_count = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexFONDELLO], objects);
	if(!(object_count > 1))
	{
		const CRhinoObjRef& ref = objects[0];
		const ON_Brep* brep = ref.Brep();
		if(brep)
		{
			ON_Brep* DupBrep = brep->Duplicate(); 
			if(DupBrep)
			{
				DupBrep->Flip();
				CRhinoObjectAttributes pAttributes(objects[0]->Attributes());
				pAttributes.m_layer_index = layer_indexFONDELLO;
				pAttributes.m_name = L"FONDELLO";
				context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
				context.m_doc.DeleteObject(ref);
				context.m_doc.Redraw();
			}
		}
	}
	/********************************************************************************************/
	/********************************************************************************************/
	/********************************************************************************************/

	/**********************************************/
	/*CREATING PLANE TO DIVIDE MATRIX IN TWO PARTS*/
	/**********************************************/
	objects.Empty();
	int layer_indexPV = context.m_doc.m_layer_table.FindLayer(L"PV");
	object_count = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexPV], objects);
	for(int i = 0; i < objects.Count(); i++)
	{
		/**********************************************/
		/*MAKE COPY OF OBJECT ATTRIBUTES. THIS OBJECTS*/ 
		/*HOLDS AN OBJECT'S USER-DEFINED NAME.*/ 
		/**********************************************/
		CRhinoCurveObject* curve_obj = CRhinoCurveObject::Cast(objects[i]);

		if(curve_obj && !objects[i]->Attributes().m_name.Compare(L"FONDLine"))
		{
			const ON_Geometry* geo = curve_obj->Geometry();
			const ON_Curve* pCurve = ON_Curve::Cast(geo); 

			int nIndex = plugin.m_dialog->m_comboAltTacco.GetCurSel();
			CString strCBText;
			plugin.m_dialog->m_comboAltTacco.GetLBText( nIndex, strCBText);
			layer_indexMATRICE = context.m_doc.m_layer_table.FindLayer(L"MATRICE");

			
			/*************************************************************************************************/
			//ON_SumSurface Split_Plane;
			//Split_Plane.Create(*pCurve, ON_3dVector(0.0, 0.0, _wtoi(strCBText)));

			context.m_doc.m_layer_table.SetCurrentLayerIndex(layer_indexMATRICE);
			ON_Surface* Split_Plane = RhinoExtrudeCurveStraight(pCurve, ON_3dVector(0.0, 0.0, _wtoi(strCBText)), 1.0);
			/*************************************************************************************************/

			first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if(context.m_doc.AddSurfaceObject(*Split_Plane))
			//if(context.m_doc.AddSurfaceObject(Split_Plane))
			{
				context.m_doc.Redraw();
				next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				if( first_sn == next_sn )
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc, first_sn, L"TRIMMATRIX", true);	
				}
			}
		}
	}

	/******************************/
	/*DIVIDING MATRIX IN TWO PARTS*/
	/******************************/
	int IndexMATRIX = 0;
	int IndexTRIMMATRIXPLANE = 0;
	int IndexPVLINE = 0;
	int IndexTACCO = 0;
	int IndexSIL = 0;
	bool FindingPVLINE = false;
	bool FindingMATRIX = false;
	bool FindingTRIMMATRIXPLANE = false;
	ON_SimpleArray<CRhinoObject*> objectsMATRICE;
	ON_SimpleArray<CRhinoObject*> objectsPV;
	ON_SimpleArray<CRhinoObject*> objectsTACCO;
	ON_SimpleArray<CRhinoObject*> objectsSIL;
	ON_SimpleArray<ON_MassProperties> MassProp;
	int object_countMATRICE = 0;
	int object_countPV = 0;
	int object_countTACCO = 0;
	int object_countSIL = 0;

	objectsMATRICE.Empty();
	objectsPV.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	object_countPV = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexPV], objectsPV);
	if(object_count == 0)
	{
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			IndexTRIMMATRIXPLANE = i;
			FindingTRIMMATRIXPLANE = true;
		}		
	}
	for(int i = 0; i < object_countPV; i++ )
	{
		if(!objectsPV[i]->Attributes().m_name.Compare("PVLine"))
		{
			IndexPVLINE = i;
			FindingPVLINE = true;
		}		
	}

	if(FindingPVLINE && FindingTRIMMATRIXPLANE)
	{
		const CRhinoObjRef& split_ref = objectsMATRICE[IndexTRIMMATRIXPLANE];
		const ON_Brep* split = split_ref.Brep();
		if( !split )
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}

		const ON_Curve* cut2 = ON_Curve::Cast(objectsPV[IndexPVLINE]->Geometry());
		if(!cut2)
		{
			return failure;
		}

		ON_SimpleArray<const ON_Curve*> EdgeCurves;
		EdgeCurves.Append(cut2);
		ON_Brep* BrepResult = RhinoSplitBrepFace(*split, 0, EdgeCurves, context.m_doc.AbsoluteTolerance());
		int num = BrepResult->m_F.Count();
		if(BrepResult)
		{
			//ON_3dPoint maxPoint[2];
			//double     maxArea[2];
			ON_SimpleArray<ON_MassProperties> areas(num);
			for(int i = 0; i < num; i++)
			{
				ON_Brep* face = BrepResult->DuplicateFace(i, false);
				if( face )
				{
					first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
					if(context.m_doc.AddBrepObject(*face))
					{
						context.m_doc.Redraw();
						next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
						if( first_sn == next_sn )
						{
							return CRhinoCommand::nothing;
						}
						else
						{
							SetNametoObject(context.m_doc,first_sn, L"TRIMMATRIX",true);	
						}
					}
				}
			}
			context.m_doc.DeleteObject(split_ref);
			context.m_doc.Redraw();
		}/*CHIUSURA IF(BREPRESULT)*/
	}/*CHIUSURA IF(FINDINGPVLINE && FINDINGTRIMMATRIXPLANE)*/

	/*****************************************************/
	/*DELETING PART OF TRIMATRIX PLANE WITH SMALLEST AREA*/
	/*****************************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	if(object_countMATRICE == 0)
	{
		return CRhinoCommand::nothing;
	}
	ON_SimpleArray<CRhinoObject*> TrimMatrix;
	for(int i = 0; i < object_countMATRICE; i++)
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			TrimMatrix.Append(objectsMATRICE[i]);
		}		
	}
	ON_SimpleArray<double> areas( TrimMatrix.Count() );
	for(int i = 0; i < TrimMatrix.Count(); i++ )
	{
		ON_MassProperties mp;
		const ON_Brep* face = ON_Brep::Cast(TrimMatrix[i]->Geometry());
		if(face)
		{
			if( face->AreaMassProperties(mp, true, false, false, false, 1e-6, 1e-6) )
			{
				areas.Append( mp.Area());
				//RhinoApp().Print( L"Area %i = %f square units\n", (i+1), mp.Area() );
			}
		}
	}
	if(areas[0] > areas[1])
	{
		context.m_doc.DeleteObject(TrimMatrix[1]);
		context.m_doc.Redraw();
	}
	else
	{
		context.m_doc.DeleteObject(TrimMatrix[0]);
		context.m_doc.Redraw();
	}

	/*******************************************/
	/*TRIMMING THE TRIMATRIX PLANE USING MATRIX*/
	/*******************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			IndexTRIMMATRIXPLANE = i;
			FindingTRIMMATRIXPLANE = true;
		}		
	}
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("MATRICE"))
		{
			IndexMATRIX = i;
			FindingMATRIX = true;
		}		
	}
	if(FindingMATRIX && FindingTRIMMATRIXPLANE)
	{
		const CRhinoObjRef& split_ref = objectsMATRICE[IndexTRIMMATRIXPLANE];
		const ON_Brep* split = split_ref.Brep();
		if(!split)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		const CRhinoObjRef& cutter_ref = objectsMATRICE[IndexMATRIX];
		const ON_Brep* cutter = cutter_ref.Brep();
		if(!cutter)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		ON_SimpleArray<ON_Brep*> pieces;
		pieces.Empty();
		if( !RhinoBrepSplit(*split, *cutter, context.m_doc.AbsoluteTolerance(), pieces) )
		{
			RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
		}
		int count = pieces.Count();
		if( (count == 0) | (count == 1) )
		{
			if( count == 1 )
			{
				delete pieces[0];
			}
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(3)!\n" );
		}
		CRhinoObjectAttributes attrib = objectsMATRICE[IndexTRIMMATRIXPLANE]->Attributes();
		attrib.m_uuid = ON_nil_uuid;
		const CRhinoObjectVisualAnalysisMode* vam_list = objectsMATRICE[IndexTRIMMATRIXPLANE]->m_analysis_mode_list;
		for( int k = 0; k < count; k++ )
		{
			CRhinoBrepObject* brep_object = new CRhinoBrepObject(attrib);
			if(brep_object)
			{
				brep_object->SetBrep( pieces[k]);
				if(context.m_doc.AddObject(brep_object))
				{
					RhinoCopyAnalysisModes(vam_list, brep_object);
				}
				else
				{
					delete brep_object;
				}
			}
		}
		context.m_doc.DeleteObject(split_ref); 
		context.m_doc.Redraw();		
	}/*CHIUSURA IF(FINDINGMATRIX && FINDINGTRIMMATRIXPLANE)*/

	/*********************************************/
	/*FINDING TRIM-MATRIX PLANE WITH BIGGEST AREA*/
	/*********************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);

	TrimMatrix.Empty();
	for(int i = 0; i < object_countMATRICE; i++)
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			TrimMatrix.Append(objectsMATRICE[i]);
		}		
	}

	areas.Empty();
	for(int i = 0; i < TrimMatrix.Count(); i++ )
	{
		ON_MassProperties mp;
		const ON_Brep* face = ON_Brep::Cast(TrimMatrix[i]->Geometry());
		if(face)
		{
			if( face->AreaMassProperties(mp, true, false, false, false, 1e-6, 1e-6) )
			{
				areas.Append(mp.Area());
			}
		}
	}
	int IndexBiggestArea = 0;
	double BiggestArea = areas[0];
	for(int i = 1; i < areas.Count(); i++)
	{
		if(areas[i] > BiggestArea)
		{
			BiggestArea = areas[i];
			IndexBiggestArea = i;
		}
		else
		{
			context.m_doc.DeleteObject(TrimMatrix[i]);
			context.m_doc.Redraw();
		}
	}	

	/***********************************************/
	/*TRIMMING MATRIX OBJECT USING TRIMMATRIX PLANE*/
	/***********************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			IndexTRIMMATRIXPLANE = i;
			FindingTRIMMATRIXPLANE = true;
		}		
	}
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("MATRICE"))
		{
			IndexMATRIX = i;
			FindingMATRIX = true;
		}		
	}
	if(FindingMATRIX && FindingTRIMMATRIXPLANE)
	{
		const CRhinoObjRef& split_ref = objectsMATRICE[IndexMATRIX];
		const ON_Brep* split = split_ref.Brep();
		if(!split)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		const CRhinoObjRef& cutter_ref = objectsMATRICE[IndexTRIMMATRIXPLANE];
		const ON_Brep* cutter = cutter_ref.Brep();
		if(!cutter)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		ON_SimpleArray<ON_Brep*> pieces;
		pieces.Empty();
		if( !RhinoBrepSplit(*split, *cutter, context.m_doc.AbsoluteTolerance(), pieces) )
		{
			RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
		}
		int count = pieces.Count();
		if( (count == 0) | (count == 1) )
		{
			if( count == 1 )
			{
				delete pieces[0];
			}
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(3)!\n" );
		}
		CRhinoObjectAttributes attrib = objectsMATRICE[IndexMATRIX]->Attributes();
		attrib.m_uuid = ON_nil_uuid;
		const CRhinoObjectVisualAnalysisMode* vam_list = objectsMATRICE[IndexMATRIX]->m_analysis_mode_list;
		for( int k = 0; k < count; k++ )
		{
			CRhinoBrepObject* brep_object = new CRhinoBrepObject(attrib);
			if(brep_object)
			{
				brep_object->SetBrep( pieces[k]);
				if(context.m_doc.AddObject(brep_object))
				{
					RhinoCopyAnalysisModes(vam_list, brep_object);
				}
				else
				{
					delete brep_object;
				}
			}
		}
		context.m_doc.DeleteObject(split_ref); 
		context.m_doc.Redraw();		
	}/*CHIUSURA IF(FINDINGMATRIX && FINDINGTRIMMATRIXPLANE)*/

	/*************************************************/
	/*TRIMMING TACCO SURFACE USING TRIMMATRIX SURFACE*/
	/*************************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	objectsTACCO.Empty();
	object_countTACCO = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexTACCO], objectsTACCO);
	if(object_countTACCO > 1)
	{
		return CRhinoCommand::nothing;
	}
	FindingTRIMMATRIXPLANE = false;
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			IndexTRIMMATRIXPLANE = i;
			FindingTRIMMATRIXPLANE = true;
		}		
	}

	if(FindingTRIMMATRIXPLANE)
	{
		const CRhinoObjRef& split_ref = objectsTACCO[0];
		const ON_Brep* split = split_ref.Brep();
		if(!split)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		const CRhinoObjRef& cutter_ref = objectsMATRICE[IndexTRIMMATRIXPLANE];
		const ON_Brep* cutter = cutter_ref.Brep();
		if(!cutter)
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}
		ON_SimpleArray<ON_Brep*> pieces;
		pieces.Empty();
		if( !RhinoBrepSplit(*split, *cutter, context.m_doc.AbsoluteTolerance(), pieces) )
		{
			RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
		}
		int count = pieces.Count();
		if( (count == 0) | (count == 1) )
		{
			if( count == 1 )
			{
				delete pieces[0];
			}
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(3)!\n" );
		}
		CRhinoObjectAttributes attrib = objectsTACCO[0]->Attributes();
		attrib.m_uuid = ON_nil_uuid;
		const CRhinoObjectVisualAnalysisMode* vam_list = objectsTACCO[0]->m_analysis_mode_list;
		for( int k = 0; k < count; k++ )
		{
			CRhinoBrepObject* brep_object = new CRhinoBrepObject(attrib);
			if(brep_object)
			{
				brep_object->SetBrep( pieces[k]);
				if(context.m_doc.AddObject(brep_object))
				{
					RhinoCopyAnalysisModes(vam_list, brep_object);
				}
				else
				{
					delete brep_object;
				}
			}
		}
		context.m_doc.DeleteObject(split_ref); 
		context.m_doc.Redraw();		
	}/*CHIUSURA IF(FINDINGMATRIX && FINDINGTRIMMATRIXPLANE)*/

	/*****************************************************/
	/*TRIMMING THE TRIMATRIX PLANE USING SILHOUETTE LINES*/
	/*****************************************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	objectsSIL.Empty();
	object_countSIL = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexSIL], objectsSIL);
	if(object_countSIL > 2)
	{
		return CRhinoCommand::nothing;
	}

	FindingTRIMMATRIXPLANE = false;
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			IndexTRIMMATRIXPLANE = i;
			FindingTRIMMATRIXPLANE = true;
		}		
	}
	if(FindingTRIMMATRIXPLANE)
	{
		const CRhinoObjRef& split_ref = objectsMATRICE[IndexTRIMMATRIXPLANE];
		const ON_Brep* split = split_ref.Brep();
		if( !split )
		{
			RhinoApp().Print( L"IT HAS HAPPENED SOMETHING(1)!\n" );
			return failure;
		}

		const ON_Curve* cut1 = ON_Curve::Cast(objectsSIL[0]->Geometry());
		if(!cut1)
		{
			return failure;
		}

		ON_SimpleArray<const ON_Curve*> EdgeCurves;
		EdgeCurves.Append(cut1);

		const ON_Curve* cut2 = ON_Curve::Cast(objectsSIL[1]->Geometry());
		if(!cut2)
		{
			return failure;
		}
		EdgeCurves.Append(cut2);

		ON_Brep* BrepResult = RhinoSplitBrepFace(*split, 0, EdgeCurves, context.m_doc.AbsoluteTolerance());
		int num = BrepResult->m_F.Count();
		if(BrepResult)
		{
			ON_SimpleArray<ON_MassProperties> areas(num);
			for(int i = 0; i < num; i++)
			{
				ON_Brep* face = BrepResult->DuplicateFace(i, false);
				if( face )
				{
					first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
					if(context.m_doc.AddBrepObject(*face))
					{
						context.m_doc.Redraw();
						next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
						if( first_sn == next_sn )
						{
							return CRhinoCommand::nothing;
						}
						else
						{
							SetNametoObject(context.m_doc,first_sn, L"TRIMMATRIX",true);	
						}
					}
				}
			}
			context.m_doc.DeleteObject(split_ref);
			context.m_doc.Redraw();
		}/*CHIUSURA IF(BREPRESULT)*/
	}/*CHIUSURA IF(FINDINGPVLINE && FINDINGTRIMMATRIXPLANE)*/

	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);

	TrimMatrix.Empty();
	for(int i = 0; i < object_countMATRICE; i++)
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			TrimMatrix.Append(objectsMATRICE[i]);
		}		
	}
	areas.Empty();
	for(int i = 0; i < TrimMatrix.Count(); i++ )
	{
		ON_MassProperties mp;
		const ON_Brep* face = ON_Brep::Cast(TrimMatrix[i]->Geometry());
		if(face)
		{
			if( face->AreaMassProperties(mp, true, false, false, false, 1e-6, 1e-6) )
			{
				areas.Append(mp.Area());
			}
		}
	}
	int IndexSmallestArea = 0;
	double SmallestArea = areas[0];
	for(int i = 1; i < areas.Count(); i++)
	{
		if(areas[i] > SmallestArea)
		{
			context.m_doc.DeleteObject(TrimMatrix[IndexSmallestArea]);
			context.m_doc.Redraw();
		}
		else
		{
			SmallestArea = areas[i];
			IndexSmallestArea = i;
		}	
	}	
	/*****************************/
	/*FLIPPING THE MATRICE OBJECT*/
	/*****************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("MATRICE"))
		{
			const CRhinoObjRef& ref = objectsMATRICE[i];
			const ON_Brep* brep = ref.Brep();
			if(brep)
			{
				ON_Brep* DupBrep = brep->Duplicate(); 
				if(DupBrep)
				{
					DupBrep->Flip();
					CRhinoObjectAttributes pAttributes(objectsMATRICE[i]->Attributes());
					pAttributes.m_layer_index = layer_indexMATRICE;
					pAttributes.m_name = L"MATRICE";
					context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
					context.m_doc.DeleteObject(ref);
					context.m_doc.Redraw();
				}
			}			
		}
	}/*CHIUSURA FOR*/

	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	ON_SimpleArray<int> TrimMatrixIndeces;
	ON_SimpleArray<int> MatrixObjsIndeces;
	InBreps.Empty();
	objects.Empty();
	OutBreps.Empty();
	something_happened = false;
	tolerance = context.m_doc.AbsoluteTolerance();
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("MATRICE"))
		{
			MatrixObjsIndeces.Append(i);
		}

		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			TrimMatrixIndeces.Append(i);
			const ON_Brep* brep = ON_Brep::Cast(objectsMATRICE[i]->Geometry());
			if(brep)
			{
				InBreps.Append( brep );
			}
		}
	}/*CHIUSURA FOR*/
	const ON_Brep* brep = ON_Brep::Cast(objectsMATRICE[MatrixObjsIndeces[1]]->Geometry());
	if(brep)
	{
		InBreps.Append(brep);
	}

	rc = RhinoBooleanUnion(InBreps, tolerance, &something_happened, OutBreps);
	if(!rc | !something_happened)
	{
		for(int i = 0; i < OutBreps.Count(); i++ )
		{
		  delete OutBreps[i];
		  OutBreps[i] = 0;
		}
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < OutBreps.Count(); i++ )
	{
		ON_Brep* brep   = OutBreps[i];
		if( brep )
		{
			CRhinoObjectAttributes pAttributes(objectsMATRICE[MatrixObjsIndeces[1]]->Attributes());
			pAttributes.m_layer_index = layer_indexMATRICE;
			pAttributes.m_name = L"LEFT_MATRICE";
			context.m_doc.AddBrepObject(*brep, &pAttributes);
			brep = 0;
			delete OutBreps[i];
			OutBreps[i] = 0;
		}
	}
	context.m_doc.DeleteObject(objectsMATRICE[MatrixObjsIndeces[1]]);	
	context.m_doc.Redraw();

	/********************************/
	/*FLIPPING THE TRIMMATRIX PLANES*/
	/********************************/
	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			const CRhinoObjRef& ref = objectsMATRICE[i];
			const ON_Brep* brep = ref.Brep();
			if(brep)
			{
				ON_Brep* DupBrep = brep->Duplicate(); 
				if(DupBrep)
				{
					DupBrep->Flip();
					CRhinoObjectAttributes pAttributes(objectsMATRICE[i]->Attributes());
					pAttributes.m_layer_index = layer_indexMATRICE;
					pAttributes.m_name = L"TRIMMATRIX";
					context.m_doc.AddBrepObject(*DupBrep, &pAttributes);
					context.m_doc.DeleteObject(ref);
					context.m_doc.Redraw();
				}
			}			
		}
	}/*CHIUSURA FOR*/

	objectsMATRICE.Empty();
	object_countMATRICE = context.m_doc.LookupObject(context.m_doc.m_layer_table[layer_indexMATRICE], objectsMATRICE);
	TrimMatrixIndeces.Empty();
	MatrixObjsIndeces.Empty();
	InBreps.Empty();
	objects.Empty();
	OutBreps.Empty();
	something_happened = false;
	tolerance = context.m_doc.AbsoluteTolerance();
	for(int i = 0; i < object_countMATRICE; i++ )
	{
		if(!objectsMATRICE[i]->Attributes().m_name.Compare("MATRICE"))
		{
			MatrixObjsIndeces.Append(i);
		}

		if(!objectsMATRICE[i]->Attributes().m_name.Compare("TRIMMATRIX"))
		{
			TrimMatrixIndeces.Append(i);
			const ON_Brep* brep = ON_Brep::Cast(objectsMATRICE[i]->Geometry());
			if(brep)
			{
				InBreps.Append( brep );
			}
		}
	}/*CHIUSURA FOR*/
	brep = ON_Brep::Cast(objectsMATRICE[MatrixObjsIndeces[0]]->Geometry());
	if(brep)
	{
		InBreps.Append(brep);
	}

	rc = RhinoBooleanUnion(InBreps, tolerance, &something_happened, OutBreps);
	if(!rc | !something_happened)
	{
		for(int i = 0; i < OutBreps.Count(); i++ )
		{
		  delete OutBreps[i];
		  OutBreps[i] = 0;
		}
		return CRhinoCommand::nothing;
	}
	for(int i = 0; i < OutBreps.Count(); i++ )
	{
		ON_Brep* brep   = OutBreps[i];
		if( brep )
		{
			CRhinoObjectAttributes pAttributes(objectsMATRICE[MatrixObjsIndeces[1]]->Attributes());
			pAttributes.m_layer_index = layer_indexMATRICE;
			pAttributes.m_name = L"RIGHT_MATRICE";
			context.m_doc.AddBrepObject(*brep, &pAttributes);
			brep = 0;
			delete OutBreps[i];
			OutBreps[i] = 0;
		}
	}
	for(int i = 0; i < MatrixObjsIndeces.Count(); i++)
	{
		context.m_doc.DeleteObject(objectsMATRICE[MatrixObjsIndeces[i]]);
	}
	for(int i = 0; i < TrimMatrixIndeces.Count(); i++)
	{
		context.m_doc.DeleteObject(objectsMATRICE[TrimMatrixIndeces[i]]);
	}
	context.m_doc.Redraw();
	return CRhinoCommand::success;
}

//
// END TrimMatrix command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN GenSpineCentraggio command
//

class CCommandGenSpineCentraggio : public CRhinoCommand
{
public:
	CCommandGenSpineCentraggio() {}
	~CCommandGenSpineCentraggio() {}
	UUID CommandUUID()
	{
		// {F6367DFC-93D4-45E5-9CCC-764D02BE0F16}
		static const GUID GenSpineCentraggioCommand_UUID =
		{ 0xF6367DFC, 0x93D4, 0x45E5, { 0x9C, 0xCC, 0x76, 0x4D, 0x02, 0xBE, 0x0F, 0x16 } };
		return GenSpineCentraggioCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"GenSpineCentraggio"; }
	const wchar_t* LocalCommandName() { return L"GenSpineCentraggio"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandGenSpineCentraggio object
static class CCommandGenSpineCentraggio theGenSpineCentraggioCommand;

CRhinoCommand::result CCommandGenSpineCentraggio::RunCommand( const CRhinoCommandContext& context )
{
	Cscript1PlugIn& plugin = script1PlugIn();
	if( !plugin.IsDlgVisible() )
	{
		return CRhinoCommand::nothing;
	}

	int first_sn;
	int next_sn;
	const CRhinoCurveObject* curve_obj;
	bool FindingSpineLinea1 = false;
	bool FindingSpineLinea2 = false;
	bool FindingSpineLinea3 = false;
	bool FindingSpineLinea4 = false;
	int IndexSpineLinea[4];
	int IndexSilLineSX = 0;
	int IndexSilLineDX = 0;
	ON_SimpleArray<CRhinoObject*> objectsPV;
	ON_SimpleArray<CRhinoObject*> objectsSIL;
	int object_countPV;
	int object_countSIL;

	int layer_indexPV  = context.m_doc.m_layer_table.FindLayer(L"PV");
	int layer_indexSIL = context.m_doc.m_layer_table.FindLayer(L"SIL");
	if(layer_indexPV > 0)
	{
	  objectsPV.Empty();
	  object_countPV = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexPV], objectsPV );
	}
	if(layer_indexSIL > 0)
	{
	  objectsSIL.Empty();
	  object_countSIL = context.m_doc.LookupObject( context.m_doc.m_layer_table[layer_indexSIL], objectsSIL );
	}
	/****************************/
	/*FINDING "SPINALINEA" LINES*/
	/****************************/
	if(object_countSIL == 2)
	{
		CRhinoCurveObject* ObjSilCurve = CRhinoCurveObject::Cast(objectsSIL[0]);
		ON_3dPoint middlePt = ON_3dPoint((ObjSilCurve->Curve()->PointAtStart().x + ObjSilCurve->Curve()->PointAtEnd().x)/2.0, 
									(ObjSilCurve->Curve()->PointAtStart().y + ObjSilCurve->Curve()->PointAtEnd().y)/2.0,
									(ObjSilCurve->Curve()->PointAtStart().z + ObjSilCurve->Curve()->PointAtEnd().z)/2.0);

		if(middlePt.x < 0.0)
		{
			IndexSilLineSX = 0;
			IndexSilLineDX = 1;
		}
		else
		{
			IndexSilLineSX = 1;
			IndexSilLineDX = 0;
		}
	}
	else
	{
		CRhinoCommand::nothing;		
	}

	/****************************/
	/*FINDING "SPINALINEA" LINES*/
	/****************************/
	for(int i = 0; i < object_countPV; i++)
	{
	  if(!objectsPV[i]->Attributes().m_name.Compare("SPINALINEA1"))
	  {
		IndexSpineLinea[0] = i;
		FindingSpineLinea1 = true;
	  }
	  if(!objectsPV[i]->Attributes().m_name.Compare("SPINALINEA2"))
	  {
		IndexSpineLinea[1] = i;
		FindingSpineLinea2 = true;
	  }
	  if(!objectsPV[i]->Attributes().m_name.Compare("SPINALINEA3"))
	  {
		IndexSpineLinea[2] = i;
		FindingSpineLinea3 = true;
	  }
	  if(!objectsPV[i]->Attributes().m_name.Compare("SPINALINEA4"))
	  {
		IndexSpineLinea[3] = i;
		FindingSpineLinea4 = true;
	  }
	}

	if(FindingSpineLinea2 && FindingSpineLinea4)
	{
		CRhinoCurveObject* ObjCurve1 = CRhinoCurveObject::Cast(objectsPV[IndexSpineLinea[1]]);/*SPINALINEA2*/
		CRhinoCurveObject* ObjCurve2 = CRhinoCurveObject::Cast(objectsPV[IndexSpineLinea[3]]);/*SPINALINEA4*/
		if(ObjCurve1 && ObjCurve2)
		{
			ON_3dPoint MiddleTopPtSX;
			ON_3dPoint MiddleBotPtSX;
			/**************************/
			/*SPINALINEA2 MIDDLE POINT*/
			/**************************/
			ON_3dPoint pt2 = ON_3dPoint((ObjCurve1->Curve()->PointAtStart().x + ObjCurve1->Curve()->PointAtEnd().x)/2.0, 
				                        (ObjCurve1->Curve()->PointAtStart().y + ObjCurve1->Curve()->PointAtEnd().y)/2.0,
										(ObjCurve1->Curve()->PointAtStart().z + ObjCurve1->Curve()->PointAtEnd().z)/2.0);
			/**************************/
			/*SPINALINEA4 MIDDLE POINT*/
			/**************************/
			ON_3dPoint pt4 = ON_3dPoint((ObjCurve2->Curve()->PointAtStart().x + ObjCurve2->Curve()->PointAtEnd().x)/2.0, 
				                        (ObjCurve2->Curve()->PointAtStart().y + ObjCurve2->Curve()->PointAtEnd().y)/2.0, 
										(ObjCurve2->Curve()->PointAtStart().z + ObjCurve2->Curve()->PointAtEnd().z)/2.0);

			CRhinoCurveObject* ObjSilCurve = CRhinoCurveObject::Cast(objectsSIL[IndexSilLineSX]);
			ON_3dPoint TopPt = ObjSilCurve->Curve()->PointAtEnd();
			ON_3dPoint BotPt = ObjSilCurve->Curve()->PointAtStart();
			if(TopPt.z > BotPt.z)
			{
				MiddleTopPtSX = ON_3dPoint((TopPt.x + pt4.x)/2.0,
					                       (TopPt.y + pt4.y)/2.0,
										   (TopPt.z + pt4.z)/2.0);

				MiddleBotPtSX = ON_3dPoint((BotPt.x + pt2.x)/2.0,
					                       (BotPt.y + pt2.y)/2.0,
										   (BotPt.z + pt2.z)/2.0);

			}
			else
			{
				MiddleTopPtSX = ON_3dPoint((TopPt.x + pt2.x)/2.0,
				                           (TopPt.y + pt2.y)/2.0,
				    					   (TopPt.z + pt2.z)/2.0);

				MiddleBotPtSX = ON_3dPoint((BotPt.x + pt4.x)/2.0,
				                           (BotPt.y + pt4.y)/2.0,
										   (BotPt.z + pt4.z)/2.0);
			}
			/*********************/
			/*FINDING START POINT*/
			/*********************/
			ON_3dPoint StartPt = (MiddleTopPtSX.z > MiddleBotPtSX.z ? MiddleTopPtSX : MiddleBotPtSX);
			ON_3dPoint EndPt   = (MiddleTopPtSX.z < MiddleBotPtSX.z ? MiddleTopPtSX : MiddleBotPtSX);
			double length = sqrt((MiddleTopPtSX.x - MiddleBotPtSX.x)*(MiddleTopPtSX.x - MiddleBotPtSX.x) + 
								 (MiddleTopPtSX.y - MiddleBotPtSX.y)*(MiddleTopPtSX.y - MiddleBotPtSX.y) + 
				                 (MiddleTopPtSX.z - MiddleBotPtSX.z)*(MiddleTopPtSX.z - MiddleBotPtSX.z));

			/*****************************/
			/*COMPUTING DIRECTION COSINES*/
			/*****************************/
			double CosX = (EndPt.z - StartPt.z)/length;
			double SinX = (EndPt.x - StartPt.x)/length;

			ON_Plane plane = ON_Plane(ON_3dPoint(StartPt.x, 0.0, StartPt.z), ON_3dVector(0.0, 1.0, 0.0));
			ON_Circle Circle1(plane, ON_3dPoint((StartPt.x + SinX*length/4.0), 0.0, (StartPt.z + CosX*length/4.0)), 3.0); // fix aniello da email: deve essere diamentro 6 mm
			ON_Circle Circle2(plane, ON_3dPoint((StartPt.x + 3.0*SinX*length/4.0), 0.0, (StartPt.z + 3.0*CosX*length/4.0)), 4.0); // fix aniello da email: deve essere diamentro 8 mm

			first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if(context.m_doc.AddCurveObject(Circle1))
			{
				next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				/************************************************/
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				/************************************************/
				if(first_sn == next_sn)
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc, first_sn, L"SPINACENTRAGGIO1", true);			  
				}
				context.m_doc.Redraw();
			}

			first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if(context.m_doc.AddCurveObject(Circle2))
			{
				next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				/************************************************/
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				/************************************************/
				if(first_sn == next_sn)
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc, first_sn, L"SPINACENTRAGGIO2", true);			  
				}
				context.m_doc.Redraw();
			}		
		}/*CHIUSURA IF OBJCURVE1 && OBJCURVE2*/		
	}/*CHIUSURA IF FINDINGSPINELINEA2 && FINDINGSPINELINEA4*/
	if(FindingSpineLinea1 && FindingSpineLinea3)
	{
		CRhinoCurveObject* ObjCurve1 = CRhinoCurveObject::Cast(objectsPV[IndexSpineLinea[0]]);/*SPINALINEA1*/
		CRhinoCurveObject* ObjCurve2 = CRhinoCurveObject::Cast(objectsPV[IndexSpineLinea[2]]);/*SPINALINEA3*/
		if(ObjCurve1 && ObjCurve2)
		{
			ON_3dPoint MiddleTopPtSX;
			ON_3dPoint MiddleBotPtSX;
			/**************************/
			/*SPINALINEA1 MIDDLE POINT*/
			/**************************/
			ON_3dPoint pt1 = ON_3dPoint((ObjCurve1->Curve()->PointAtStart().x + ObjCurve1->Curve()->PointAtEnd().x)/2.0, 
				                        (ObjCurve1->Curve()->PointAtStart().y + ObjCurve1->Curve()->PointAtEnd().y)/2.0,
										(ObjCurve1->Curve()->PointAtStart().z + ObjCurve1->Curve()->PointAtEnd().z)/2.0);
			/**************************/
			/*SPINALINEA3 MIDDLE POINT*/
			/**************************/
			ON_3dPoint pt3 = ON_3dPoint((ObjCurve2->Curve()->PointAtStart().x + ObjCurve2->Curve()->PointAtEnd().x)/2.0, 
				                        (ObjCurve2->Curve()->PointAtStart().y + ObjCurve2->Curve()->PointAtEnd().y)/2.0, 
										(ObjCurve2->Curve()->PointAtStart().z + ObjCurve2->Curve()->PointAtEnd().z)/2.0);

			CRhinoCurveObject* ObjSilCurve = CRhinoCurveObject::Cast(objectsSIL[IndexSilLineDX]);
			ON_3dPoint TopPt = ObjSilCurve->Curve()->PointAtEnd();
			ON_3dPoint BotPt = ObjSilCurve->Curve()->PointAtStart();
			if(TopPt.z > BotPt.z)
			{
				MiddleTopPtSX = ON_3dPoint((TopPt.x + pt3.x)/2.0,
				                           (TopPt.y + pt3.y)/2.0,
										   (TopPt.z + pt3.z)/2.0);

				MiddleBotPtSX = ON_3dPoint((BotPt.x + pt1.x)/2.0,
					                       (BotPt.y + pt1.y)/2.0,
										   (BotPt.z + pt1.z)/2.0);

			}
			else
			{
				MiddleTopPtSX = ON_3dPoint((TopPt.x + pt1.x)/2.0,
				                           (TopPt.y + pt1.y)/2.0,
										   (TopPt.z + pt1.z)/2.0);

				MiddleBotPtSX = ON_3dPoint((BotPt.x + pt3.x)/2.0,
				                           (BotPt.y + pt3.y)/2.0,
									       (BotPt.z + pt3.z)/2.0);
			}
			/*********************/
			/*FINDING START POINT*/
			/*********************/
			ON_3dPoint StartPt = (MiddleTopPtSX.z > MiddleBotPtSX.z ? MiddleTopPtSX : MiddleBotPtSX);
			ON_3dPoint EndPt   = (MiddleTopPtSX.z < MiddleBotPtSX.z ? MiddleTopPtSX : MiddleBotPtSX);
			double length = sqrt((MiddleTopPtSX.x - MiddleBotPtSX.x)*(MiddleTopPtSX.x - MiddleBotPtSX.x) + 
								 (MiddleTopPtSX.y - MiddleBotPtSX.y)*(MiddleTopPtSX.y - MiddleBotPtSX.y) + 
				                 (MiddleTopPtSX.z - MiddleBotPtSX.z)*(MiddleTopPtSX.z - MiddleBotPtSX.z));

			/*****************************/
			/*COMPUTING DIRECTION COSINES*/
			/*****************************/
			double CosX = (EndPt.z - StartPt.z)/length;
			double SinX = (EndPt.x - StartPt.x)/length;

			ON_Plane plane = ON_Plane(ON_3dPoint(StartPt.x, 0.0, StartPt.z), ON_3dVector(0.0, 1.0, 0.0));
			ON_Circle Circle1(plane, ON_3dPoint((StartPt.x + SinX*length/4.0), 0.0, (StartPt.z + CosX*length/4.0)), 4.0); // fix aniello da email: deve essere diamentro 8 mm
			ON_Circle Circle2(plane, ON_3dPoint((StartPt.x + 3.0*SinX*length/4.0), 0.0, (StartPt.z + 3.0*CosX*length/4.0)), 3.0); // fix aniello da email: deve essere diamentro 6 mm
			first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if(context.m_doc.AddCurveObject(Circle1))
			{
				next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				/************************************************/
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				/************************************************/
				if(first_sn == next_sn)
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc, first_sn, L"SPINACENTRAGGIO3", true);			  
				}
				context.m_doc.Redraw();
			}
			first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			if(context.m_doc.AddCurveObject(Circle2))
			{
				next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
				/************************************************/
				/*IF THE TWO ARE THE SAME, THEN NOTHING HAPPENED*/
				/************************************************/
				if(first_sn == next_sn)
				{
					return CRhinoCommand::nothing;
				}
				else
				{
					SetNametoObject(context.m_doc, first_sn, L"SPINACENTRAGGIO4", true);			  
				}
				context.m_doc.Redraw();
			}	
		}/*CHIUSURA IF OBJCURVE1 && OBJCURVE2*/		
	}/*CHIUSURA IF FINDINGSPINELINEA1 && FINDINGSPINELINEA3*/	
	return CRhinoCommand::success;
}

//
// END GenSpineCentraggio command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN BeginMarcatura command
//

class CCommandBeginMarcatura : public CRhinoCommand
{
public:
	CCommandBeginMarcatura() {}
	~CCommandBeginMarcatura() {}
	UUID CommandUUID()
	{
		// {46DE0C31-7A2A-4D3B-BF5A-221414DB8D22}
		static const GUID BeginMarcaturaCommand_UUID =
		{ 0x46DE0C31, 0x7A2A, 0x4D3B, { 0xBF, 0x5A, 0x22, 0x14, 0x14, 0xDB, 0x8D, 0x22 } };
		return BeginMarcaturaCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"BeginMarcatura"; }
	const wchar_t* LocalCommandName() { return L"BeginMarcatura"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandBeginMarcatura object
static class CCommandBeginMarcatura theBeginMarcaturaCommand;

CRhinoCommand::result CCommandBeginMarcatura::RunCommand( const CRhinoCommandContext& context )
{
	
	
	/*ON_wString wStr;
	wStr.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
	if( context.IsInteractive() )
		RhinoMessageBox( wStr, EnglishCommandName(), MB_OK );
	else
		RhinoApp().Print( wStr );*/

	unsigned int first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
	OggettoMarcatura = first_sn;
	return CRhinoCommand::success;
}

//
// END BeginMarcatura command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN EndMarcatura command
//

class CCommandEndMarcatura : public CRhinoCommand
{
public:
	CCommandEndMarcatura() {}
	~CCommandEndMarcatura() {}
	UUID CommandUUID()
	{
		// {61129EEB-3878-4EB3-A25F-875A3F469697}
		static const GUID EndMarcaturaCommand_UUID =
		{ 0x61129EEB, 0x3878, 0x4EB3, { 0xA2, 0x5F, 0x87, 0x5A, 0x3F, 0x46, 0x96, 0x97 } };
		return EndMarcaturaCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"EndMarcatura"; }
	const wchar_t* LocalCommandName() { return L"EndMarcatura"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandEndMarcatura object
static class CCommandEndMarcatura theEndMarcaturaCommand;

CRhinoCommand::result CCommandEndMarcatura::RunCommand( const CRhinoCommandContext& context )
{
	


	/*************** BEGIN MARCATURA *****************************/
			ON_3dPoint kk(puntoAppoggio1);
			ON_3dPoint kk1(puntoAppoggio2);
			ON_3dVector kk2 = kk1 - kk;
			ON_3dPoint kk3 (kk);
			
			ON_Xform xform, xform2;
			xform.Translation(14,14,4);
			kk3.Transform(xform);

			int countMarcatura=0;
			ON_Plane pl (kk1,kk);
			if (countMarcatura==0) xform2.PlanarProjection(pl);
			countMarcatura++;
			
			unsigned int first_sn = OggettoMarcatura + 1; // non lo so perche' ma il primo oggetto non va bene.
			unsigned int next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			const CRhinoObject* objN = context.m_doc.LookupObjectByRuntimeSerialNumber( first_sn );
			const CRhinoObjRef& objref = objN;
						if( first_sn == next_sn )
				return CRhinoCommand::nothing;
						else {
								for(first_sn; first_sn != next_sn; first_sn++)
										  {
											  ON_wString obj_name = L"MARCATURA";
											  SetNametoObject(context.m_doc,first_sn,obj_name,true);			  
										  }
							}
			
	  
	  ON_SimpleArray<CRhinoObject*> objectsMarcatura;
	   /****************/
	  /*FIND THE LAYER*/
	  /****************/
	  int layer_marcatura_index = context.m_doc.m_layer_table.FindLayer(L"pv");

	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura;
	  
	  oggettiMarcatura.Empty();
	 
	  int LinesCount = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura);
	  
	  
	 
		
		///////////////////////////////////////////////////////////////////
	  
	  
	  for (int i = 0; i < LinesCount; i++ )
			{
				if  (
					(!oggettiMarcatura[i]->Attributes().m_name.Compare("MARCATURA"))
					)
						{
							context.m_doc.TransformObject( oggettiMarcatura[i], xform2, true, true, true );
							context.m_doc.Redraw();
							
							
						}
			}
	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura2; // per la seconda traslazione
	  oggettiMarcatura2.Empty();
	  int LinesCount2 = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura2);
	  
	  for (int j = 0; j < LinesCount2; j++ )
			{
				if  (
					(!oggettiMarcatura2[j]->Attributes().m_name.Compare("MARCATURA"))
					)
						{
							
							context.m_doc.TransformObject( oggettiMarcatura2[j], xform, true, true, true );
							context.m_doc.Redraw();
							ON_wString obj_name = L"MARCATURASETTED";
							//oggettiMarcatura2[j]->Attributes().m_name.Destroy();
							/*CRhinoObjectAttributes pAttributes = oggettiMarcatura2[j]->Attributes();
							pAttributes.m_name = L"marcaturaoff";
							const CRhinoObjRef& objref = oggettiMarcatura2[j];
							context.m_doc.ModifyObjectAttributes( objref, pAttributes );
							context.m_doc.Redraw();*/
						}
			}

	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura3; // per la seconda traslazione
	  oggettiMarcatura3.Empty();
	  int LinesCount3 = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura3);
	  for (int i = 0; i < LinesCount3; i++ )
			{
				if(
					(!oggettiMarcatura3[i]->Attributes().m_name.Compare("MARCATURA")) 
					)
						{
							CRhinoObjectAttributes atts( oggettiMarcatura3[i]->Attributes() );
							atts.m_name = L"vuoto";  // al fondello
							CRhinoObjRef ref(oggettiMarcatura3[i]);
							context.m_doc.ModifyObjectAttributes(ref, atts);
						}
	  }
	  context.m_doc.Redraw();
	//  ON_3dmObjectAttributes obj_attribs = objN->Attributes();

	///*************************************/
	///*MODIFY THE ATTRIBUTES OF THE OBJECT*/
	///*************************************/
	//obj_attribs.m_name = name;
	//const CRhinoObjRef& objref = objN;
	//doc.ModifyObjectAttributes( objref, obj_attribs );
	//if( bRedraw )
	//{
	//	doc.Redraw();
	//}
			/*first_sn = OggettoMarcatura + 1;
			for(first_sn; first_sn != next_sn; first_sn++)
										  {
											  ON_wString obj_name = L"MARCATURASET";
											  SetNametoObject(context.m_doc,first_sn,obj_name,true);			  
										  }*/

			/*ON_wString lullu2(L"12345");
			xform.Translation(14,4,4);
			ON_3dPoint kk4 (kk);
			kk4.Transform(xform);
			if (AddAnnotationText(context.m_doc,kk4,lullu2,altezza,carattere,1,pl))
			{
				context.m_doc.Redraw();
			}
			ON_wString lullu3(L"ClientCod");
			xform.Translation(14,-8,4);
			ON_3dPoint kk5 (kk);
			kk5.Transform(xform);
			if (AddAnnotationText(context.m_doc,kk5,lullu3,altezza,carattere,1,pl))
			{
				context.m_doc.Redraw();
			}*/

			/*************** END MARCATURA *****************************/
	return CRhinoCommand::success;
}

//
// END EndMarcatura command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN EndMarcaturaTaglia command
//

class CCommandEndMarcaturaTaglia : public CRhinoCommand
{
public:
	CCommandEndMarcaturaTaglia() {}
	~CCommandEndMarcaturaTaglia() {}
	UUID CommandUUID()
	{
		// {471D1A5A-EC7E-4C3B-B726-A07BF13AE8E9}
		static const GUID EndMarcaturaTagliaCommand_UUID =
		{ 0x471D1A5A, 0xEC7E, 0x4C3B, { 0xB7, 0x26, 0xA0, 0x7B, 0xF1, 0x3A, 0xE8, 0xE9 } };
		return EndMarcaturaTagliaCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"EndMarcaturaTaglia"; }
	const wchar_t* LocalCommandName() { return L"EndMarcaturaTaglia"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandEndMarcaturaTaglia object
static class CCommandEndMarcaturaTaglia theEndMarcaturaTagliaCommand;

CRhinoCommand::result CCommandEndMarcaturaTaglia::RunCommand( const CRhinoCommandContext& context )
{

	/*************** BEGIN MARCATURA *****************************/
			ON_3dPoint kk(puntoAppoggio1);
			ON_3dPoint kk1(puntoAppoggio2);
			ON_3dVector kk2 = kk1 - kk;
			ON_3dPoint kk3 (kk);
			
			ON_Xform xform, xform2;
			xform.Translation(14,14,4);
			
			kk3.Transform(xform);
			ON_3dVector centro1(0,0,0);
			int countMarcatura=0;
			ON_Plane pl (kk1,kk);
			
			ON_3dVector normale (pl.Normal());
			normale.Unitize();
			//normale.Reverse();
			//normale.Rotate(1,0,normale);
			ON_3dVector normale2(1,0,0);
			pl.Rotate(200,normale);
			ON_3dVector asse1 (pl.Xaxis());
			ON_3dVector asse2 (pl.Yaxis());
			asse1.Reverse();
			asse2.Reverse();
			asse1.Rotate(3.14,normale);
			asse2.Rotate(3.14,normale);
			pl.xaxis=asse1;
			pl.yaxis=asse2;
			pl.Flip();
			ON_3dVector ZeroVector;
			//pl.xaxis=ZeroVector;
			if (countMarcatura==0) xform2.PlanarProjection(pl);
			countMarcatura++;
			
			
			
			unsigned int first_sn = OggettoMarcatura + 1; // non lo so perche' ma il primo oggetto non va bene.
			unsigned int next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
			const CRhinoObject* objN = context.m_doc.LookupObjectByRuntimeSerialNumber( first_sn );
			const CRhinoObjRef& objref = objN;
						if( first_sn == next_sn )
				return CRhinoCommand::nothing;
						else {
								for(first_sn; first_sn != next_sn; first_sn++)
										  {
											  ON_wString obj_name = L"MARCATURA";
											  SetNametoObject(context.m_doc,first_sn,obj_name,true);			  
										  }
							}
			
	  
	  ON_SimpleArray<CRhinoObject*> objectsMarcatura;
	   /****************/
	  /*FIND THE LAYER*/
	  /****************/
	  int layer_marcatura_index = context.m_doc.m_layer_table.FindLayer(L"pv");

	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura;
	  
	  oggettiMarcatura.Empty();
	 
	  int LinesCount = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura);
	  
	  
	 
		
		///////////////////////////////////////////////////////////////////
	  
	  
	  for (int i = 0; i < LinesCount; i++ )
			{
				if  (
					(!oggettiMarcatura[i]->Attributes().m_name.Compare("MARCATURA"))
					)
						{
							context.m_doc.TransformObject( oggettiMarcatura[i], xform2, true, true, true );
							context.m_doc.Redraw();
							
							
						}
			}
	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura2; // per la seconda traslazione
	  oggettiMarcatura2.Empty();
	  int LinesCount2 = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura2);
	  
	  for (int j = 0; j < LinesCount2; j++ )
			{
				if  (
					(!oggettiMarcatura2[j]->Attributes().m_name.Compare("MARCATURA"))
					)
						{
							
							context.m_doc.TransformObject( oggettiMarcatura2[j], xform, true, true, true );
							context.m_doc.Redraw();
							ON_wString obj_name = L"MARCATURASETTED";
							//oggettiMarcatura2[j]->Attributes().m_name.Destroy();
							/*CRhinoObjectAttributes pAttributes = oggettiMarcatura2[j]->Attributes();
							pAttributes.m_name = L"marcaturaoff";
							const CRhinoObjRef& objref = oggettiMarcatura2[j];
							context.m_doc.ModifyObjectAttributes( objref, pAttributes );
							context.m_doc.Redraw();*/
						}
			}

	  ON_SimpleArray<CRhinoObject*> oggettiMarcatura3; // per la seconda traslazione
	  oggettiMarcatura3.Empty();
	  int LinesCount3 = context.m_doc.LookupObject( context.m_doc.m_layer_table[context.m_doc.m_layer_table.FindLayer(L"pv")],oggettiMarcatura3);
	  for (int i = 0; i < LinesCount3; i++ )
			{
				if(
					(!oggettiMarcatura3[i]->Attributes().m_name.Compare("MARCATURA")) 
					)
						{
							CRhinoObjectAttributes atts( oggettiMarcatura3[i]->Attributes() );
							atts.m_name = L"vuoto";  // al fondello
							CRhinoObjRef ref(oggettiMarcatura3[i]);
							context.m_doc.ModifyObjectAttributes(ref, atts);
						}
	  }
	  context.m_doc.Redraw();
	//  ON_3dmObjectAttributes obj_attribs = objN->Attributes();

	///*************************************/
	///*MODIFY THE ATTRIBUTES OF THE OBJECT*/
	///*************************************/
	//obj_attribs.m_name = name;
	//const CRhinoObjRef& objref = objN;
	//doc.ModifyObjectAttributes( objref, obj_attribs );
	//if( bRedraw )
	//{
	//	doc.Redraw();
	//}
			/*first_sn = OggettoMarcatura + 1;
			for(first_sn; first_sn != next_sn; first_sn++)
										  {
											  ON_wString obj_name = L"MARCATURASET";
											  SetNametoObject(context.m_doc,first_sn,obj_name,true);			  
										  }*/

			/*ON_wString lullu2(L"12345");
			xform.Translation(14,4,4);
			ON_3dPoint kk4 (kk);
			kk4.Transform(xform);
			if (AddAnnotationText(context.m_doc,kk4,lullu2,altezza,carattere,1,pl))
			{
				context.m_doc.Redraw();
			}
			ON_wString lullu3(L"ClientCod");
			xform.Translation(14,-8,4);
			ON_3dPoint kk5 (kk);
			kk5.Transform(xform);
			if (AddAnnotationText(context.m_doc,kk5,lullu3,altezza,carattere,1,pl))
			{
				context.m_doc.Redraw();
			}*/
	return CRhinoCommand::success;
}

//
// END EndMarcaturaTaglia command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
