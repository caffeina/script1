/////////////////////////////////////////////////////////////////////////////
// cmdscript1.cpp : command file
// 

#include "stdafx.h"
#include "script1PlugIn.h"
#include "DialogPrincipale.h"
#include "afxwin.h"
#include "script1App.h"
#include "atlstr.h"


ON_UUID pvcurva;
ON_3dPoint AltezzaTacco;
static bool SelectObjectByUuid( CRhinoDoc& doc, ON_UUID uuid, bool bRedraw )
{
  bool rc = false;
  const CRhinoObject* object = doc.LookupObject( uuid );
  if( object && object->IsSelectable() )
  {
    object->Select( true );
    if( bRedraw )
      doc.Redraw();
    rc = true;
  }
  return rc;
}

static bool SelectObjectByUuid( CRhinoDoc& doc, const wchar_t* uuid_str, bool bRedraw )
{
  bool rc = false;
  if( uuid_str && uuid_str[0] )
    rc = SelectObjectByUuid( doc, ON_UuidFromString(uuid_str), bRedraw );
  return rc;
}










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
{ 0xc80ef0d2, 0xbe2f, 0x48c0, { 0x84, 0x56, 0x55, 0xd5, 0x75, 0x92, 0x3f, 0x25 } };
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


  /*GET THE LAYER NAME*/
  CRhinoGetString gs;
  gs.SetCommandPrompt( L"NAME OF LAYER WHICH CONTAINS VISIONAL PLANE : " );
  gs.GetString();
  if( gs.CommandResult() != CRhinoCommand::success )
  {
	  return gs.CommandResult();
  }
  /*VALIDATE THE STRING*/
  ON_wString layer_name = gs.String();
  layer_name.TrimLeftAndRight();
  if( layer_name.IsEmpty() )
  {
	  return CRhinoCommand::cancel;
  }
    
  /*GET A REFERENCE TO THE LAYER TABLE*/
  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
 
  /*FIND THE LAYER*/ 
  int layer_index = layer_table.FindLayer(layer_name );
  if( layer_index < 0 )
  {
    RhinoApp().Print( L"LAYER \"%s\" DOES NOT EXIST.\n", layer_name );
	
  }
  else
  {
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
	  const CRhinoLayer& layer = context.m_doc.m_layer_table[layer_index];
	  ON_SimpleArray<CRhinoObject*> obj_list;

	 
	  
      int object_count = context.m_doc.LookupObject( layer, obj_list );
      if( object_count > 0 )
      {
		 /********************************************************************/
		 //CRhinoObject* obj = obj_list[0];
		 //if( obj && obj->IsSelectable() )
		 //{
			// obj->Select(true);
			// obj->Highlight(true);
			// m_doc.Redraw();
		 //}
		 /********************************************************************/
		 //aniello gegin
		 // Disable redrawing
		 //CRhinoView::EnableDrawing( FALSE ); meglio tenerlo disabilitato altrimenti la schermata non si aggiorna.
 
         // Get the next runtime object serial number before scripting
		 unsigned int first_sn = CRhinoObject::NextRuntimeObjectSerialNumber();
	     //aniello end
	     /////////////////////
		  
		 CRhinoGetObject gc;
		 gc.SetCommandPrompt( L"SELECT LINE TO EXTEND" );
         gc.SetGeometryFilter( CRhinoGetObject::curve_object );
         gc.GetObjects( 1, 1 );
		 if(gc.CommandResult() == CRhinoCommand::success )
		 {
			const CRhinoObjRef& objref = gc.Object(0);
            const ON_Curve* pC = ON_Curve::Cast( objref.Geometry() );
			ON_Curve* crv0 = pC->DuplicateCurve();
			
			bool rc0 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 1, 5);
			bool rc1 = RhinoExtendCurve(crv0, CRhinoExtend::Line, 0, 15);
			context.m_doc.ReplaceObject(objref, *crv0 );
            context.m_doc.Redraw();

			///// begin prova memorizzazione id o name linea pv
		////ON_UUID uuid1 = gc->Attributes().m_uuid;
		////	ON_UUID uuid1 = objref.ObjectUuid();
		//	//ON_UuidToString( uuid1, cvrPrima );
		//	 const CRhinoObject* obj5 = objref.Object();
  //          ON_UUID uuid1 = obj5->Attributes().m_uuid;

		//	pvcurva =  uuid1;
		//	ON_3dmObjectAttributes obj_attribs = obj5->Attributes();
		//	CRhinoGetString gs;
  //gs.SetCommandPrompt( L"New object name" );
  //gs.SetDefaultString( obj_attribs.m_name );
  //gs.AcceptNothing( TRUE );
  //gs.GetString();
  //if( gs.CommandResult() != CRhinoCommand::success )
  //  return gs.CommandResult();
 
  //// Get the string entered by the user
  //ON_wString obj_name = gs.String();
  //obj_name.TrimLeftAndRight();
 
  //// Is name the same?
  //if( obj_name.Compare(obj_attribs.m_name) == 0 )
  //  return CRhinoCommand::nothing;

		//	//ON_wString obj_name = (L"stringanome");
		//	obj_attribs.m_name = obj_name;
		//	context.m_doc.ModifyObjectAttributes( objref, obj_attribs );

///// end prova memorizzazione id o name linea pv



			
			ON_3dPoint p0 = crv0->PointAtStart();
            ON_3dPoint p1 = crv0->PointAtEnd();
 
			CRhinoGetNumber gn;
			//double default_value = 30;
			gn.SetCommandPrompt( L"ENTER ANTERIOR ANGLE FOR EXTENSION in grad: " );
			gn.SetCommandPromptDefault(L"30");
			gn.SetDefaultNumber(30);
			//gn.AcceptNothing(true);
			gn.GetNumber();
			double alphaAngle = gn.Number();
			
			

			gn.SetCommandPrompt( L"ENTER ANTERIOR LENGTH FOR EXTENSION in mm: " );
			gn.SetCommandPromptDefault(L"80");
			gn.SetDefaultNumber(80);
			gn.GetNumber();
			double antLen = gn.Number();

			gn.SetCommandPrompt( L"ENTER ANTERIOR FILLET RADIUS in mm: " );
			gn.SetCommandPromptDefault(L"6");
			gn.SetDefaultNumber(6);
			gn.GetNumber();
			double antRad = gn.Number();

			gn.SetCommandPrompt( L"ENTER POSTERIOR ANGLE FOR EXTENSION default <ALPHA + 10°= 40°> : " );
			gn.SetCommandPromptDefault(L"40");
			gn.SetDefaultNumber(40);
			gn.GetNumber();
			double betaAngle = gn.Number();

			gn.SetCommandPrompt( L"ENTER POSTERIOR LENGTH FOR EXTENSION in mm: " );
			gn.SetCommandPromptDefault(L"80");
			gn.SetDefaultNumber(80);
			gn.GetNumber();
			double posLen = gn.Number();

			gn.SetCommandPrompt( L"ENTER POSTERIOR FILLET RADIUS in mm: " );
			gn.SetCommandPromptDefault(L"13");
			gn.SetDefaultNumber(13);
			gn.GetNumber();
			double posRad = gn.Number();

		
			ON_3dPoint pointStart;
            ON_3dPoint pointEnd;
		 
			//// Fillet radius
			//double radius = 1.0;
		 
			// Do the fillet calculation
			double t0 = 0.0, t1 = 0.0;
 
			ON_Plane plane;
			plane.plane_equation.y = 1.0;

			pointStart = crv0->PointAtStart();
			
			pointEnd   = crv0->PointAtEnd();

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
		 
				ON_Interval domain0( crv0->Domain().Min(), t0 );
				crv0->Trim( domain0 );

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
				context.m_doc.AddCurveObject( curve1 );
				context.m_doc.ReplaceObject(objref, *crv0 );
				context.m_doc.AddCurveObject( fillet );
				context.m_doc.Redraw();
			}
			

			t0 = 0.0, t1 = 0.0;
			/*FILLET AT THE START POINTS OF THE LINE CURVES*/
			curve0_t = crv0->Domain().Min();
			curve1_t = curve0.Domain().Min();

			if( RhinoGetFilletPoints(curve0, *crv0, posRad, curve1_t, curve0_t, t1, t0, plane) )
			{
				// Trim back the two line curves
				ON_Interval domain0( t1, curve0.Domain().Max() );
				curve0.Trim( domain0 );
		 
				ON_Interval domain1( t0, crv0->Domain().Max() );
				crv0->Trim( domain1 );
				

				/*COMPUTE THE FILLET CURVE*/ 
				ON_3dVector radial0 = curve0.PointAt(t1) - plane.Origin();
				radial0.Unitize();
		 
				ON_3dVector radial1 = crv0->PointAt(t0) - plane.Origin();
				radial1.Unitize();
		 
				double angle = acos( radial0 * radial1 );
				ON_Plane fillet_plane( plane.Origin(), radial0, radial1 );
				ON_Arc fillet( fillet_plane, plane.Origin(), posRad, angle );
		 
				/*ADD THE GEOMETRY*/ 
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

			
			// code temp
// aniello begin
// Get the next runtime object serial number after scripting
  unsigned int next_sn = CRhinoObject::NextRuntimeObjectSerialNumber();

 
  // Enable redrawing
  //CRhinoView::EnableDrawing( TRUE );
 
  // if the two are the same, then nothing happened
 /* if( first_sn == next_sn )
    //return CRhinoCommand::nothing;
	return;
*/ //commento questo per far compilare :-)
 
  // The the pointers of all of the objects that were added during scripting
  ON_SimpleArray<const CRhinoObject*> objects;
  for( unsigned int sn = first_sn; sn < next_sn; sn++ )
  {
    const CRhinoObject* obj = context.m_doc.LookupObjectByRuntimeSerialNumber( sn );
    if( obj && !obj->IsDeleted() )
      objects.Append( obj );
  }
 
  /*
  // Sort and cull the list, as there may be duplicates
  if( objects.Count() > 1 )
  {
    objects.HeapSort( CompareObjectPtr );
    const CRhinoObject* last_obj = objects[objects.Count()-1];
    for( int i = objects.Count()-2; i >= 0; i-- )
    {
      const CRhinoObject* prev_obj = objects[i];
     if( last_obj == prev_obj )
        objects.Remove(i);
      else
        last_obj = prev_obj;
    }
  }
	*/
  // Do something with the list...
  for( int i = 0; i < objects.Count(); i++ )
  {
    const CRhinoObject* obj = objects[i];
    if( obj->IsSelectable(true) )
      obj->Select( true );
  }
//aniello end
			//end code temp

  			/*********************/
			/*JOIN LINES TOGETHER*/
			/*********************/
			ON_SimpleArray<const ON_Curve*> lines;
			ON_SimpleArray<CRhinoObject*> objectsLine;
			ON_SimpleArray<ON_Curve*> output;
			double tolerance = context.m_doc.AbsoluteTolerance();
			int LinesCount = context.m_doc.LookupObject( layer, objectsLine);

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
		    }
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
	     }
	  }/*CHIUSURA IF( OBJECT_COUNT > 0 )*/
  }/*CHIUSURA ELSE*/

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
			if( brep_obj && object->IsSolid())
			{
				brep_obj_count++;
			}
			/*******************************/
			/*TRY CASTING AS A CURVE OBJECT*/ 
			/*******************************/
			curve_obj = CRhinoCurveObject::Cast( object );
			if( curve_obj )
			{
				polycurve_count++;
			}
		}
		if( brep_obj_count == 0)
		{
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

			/*ADD CIRCLE FOR CYLINDER'S BASE*/
			ON_Circle circle( planeCir, radius );

			/*ADD CYLINDER*/
			ON_Cylinder cylinder( circle, zaxis.Length() );
			ON_Brep* brep = ON_BrepCylinder( cylinder, TRUE, TRUE );
			if( brep )
			{
				/********************/
				/*TRANSLATE CYLINDER*/
				/********************/
				int nIndex1 = plugin.m_dialog->AltezzaFondelloControllo.GetCurSel();
				CString strCBText1;
				plugin.m_dialog->AltezzaFondelloControllo.GetLBText( nIndex1, strCBText1);
				int altfondello = _wtoi(strCBText1);
				
				
				brep->Translate(ON_3dVector( 0.0, 0.0, -altfondello));
				CRhinoBrepObject* cylinder_object = new CRhinoBrepObject();
				cylinder_object->SetBrep( brep );
				if( context.m_doc.AddObject(cylinder_object) )
				{
					context.m_doc.Redraw();
				}
				else
				{
					delete cylinder_object;
				}

				/*********************************************/
				/*               DA SISTEMARE                */
				/*********************************************/
				
				CRhinoSnapContext snap;
				bool dec1 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, (height - altfondello)));
				bool dec2 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, -altfondello));
				bool dec3 = snap.SnapToPoint(ON_3dPoint(63.5, 0.0, 0.0));
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
				/*               DA SISTEMARE  By Nello              */
				/*********************************************/
				
				ON_3dPoint provapunto2 = AltezzaTacco;
				ON_3dPoint provapunto(63.5,0,provapunto2.z);
				provapunto.z-=0.7;
				ON_3dPoint pt_1(63.5, 0.0, (height - altfondello));
				CRhinoLinearDimension* dim_obj = new CRhinoLinearDimension();
					ON_Plane plane( ON_zx_plane );
					plane.SetOrigin(pt_1);
					dim_obj->SetPlane( plane );
					//ON_3dPoint pt_1(63.5, 0.0, 0.0);
					ON_3dPoint pt_2 = provapunto;

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
				
					/*INIZIO FUNZIONE CONTROLLO*/
			
					if ( (height - altfondello)>=provapunto.z+10){
				::RhinoApp().Print( L"Funzione controllo altezza OK");
					}
					else{
						::RhinoApp().Print( L"Funzione controllo altezza NOK: CONTROLLARE!! Il valore della testa e' minore del valore minimo di 10 mm. Occorre diminuire l'altezza del fondello o aumentare l'altezza dello stampo.");
					}


				/*********************************************/
				/*           CREATE FONDELLO PLANE           */
				/*********************************************/

				ON_3dPoint point0((63.5 + 20.0),0.0, 0.0);
				ON_3dPoint point1(-(63.5 + 20.0),0.0, 0.0);
				ON_LineCurve curve0( point0, point1 );

				context.m_doc.AddCurveObject(curve0);
				context.m_doc.Redraw();


				/******************************************************/
				/*******************************************/
				/*ATTACH USER STRING TO OBJECT'S ATTRIBUTES*/ 
				/*******************************************/
				//ON_wString key = L"test";
				//ON_wString text = L"surf";
				//curve0.SetUserString(key, text);

				ON_SimpleArray<ON_Brep*> cutters;
				object_count = context.m_doc.LookupObject( layer, objects );
				for(int i = 0; i < object_count; i++ )
				{
					object = objects[ i ];
					/*******************************/
					/*TRY CASTING AS A CURVE OBJECT*/ 
					/*******************************/
					curve_obj = CRhinoCurveObject::Cast( object );
					if( curve_obj )
					{

						//CRhinoObjectAttributes attribs = curve_obj->Attributes();
						//attribs.SetUserString( key, text );
						//context.m_doc.ModifyObjectAttributes( curve_obj, attribs );


						const ON_Geometry* geo = curve_obj->Geometry();
						const ON_Curve* curve00 = ON_Curve::Cast(geo); 
						ON_3dPoint point = curve00->PointAt(0.0);
						ON_3dPoint point0(point.x, (point.y + 70.0), point.z);
						ON_3dPoint point1(point.x, (point.y - 70.0), point.z);
						ON_LineCurve* curve = new ON_LineCurve();
						curve->SetStartPoint(point0);
						curve->SetEndPoint(point1);
						ON_SumSurface sumSurf0;
						sumSurf0.Create(*curve, *curve00);

						if( context.m_doc.AddSurfaceObject(sumSurf0) )
						{
							ON_Brep* brep = ON_Brep::Cast(&sumSurf0); 
							cutters.Append(brep);
							context.m_doc.Redraw();
						}
					}
				}/*CLOSED FOR*/

				//int R = 0;
				//object_count = context.m_doc.LookupObject( layer, objects );
				//for(int i = 0; i < object_count; i++)
				//{
				//	object = objects[ i ];
				//	const CRhinoCurveObject* surface_obj = CRhinoCurveObject::Cast(object);
				//	if(surface_obj)
				//	{
				//		R++;
				//	}
				//}

			  /************************/
			  /*TRY SPLITTING THE BREP*/
			  /************************/
			  for(int j = 0; j < 2; j++)
			  {
				  /************************/
				  /*PICK THE BREP TO SPLIT*/ 
				  /************************/
				  CRhinoGetObject go;
				  go.SetCommandPrompt( L"SELECT SOLID TO SPLIT" );
				  go.SetGeometryFilter( CRhinoGetObject::polysrf_object  );//CRhinoGetObject::surface_object | CRhinoGetObject::polysrf_object 
				  go.GetObjects( 1, 1 );
				  if( go.CommandResult() != success )
				  {
					return go.CommandResult();
				  }
				  else
				  {
						RhinoMessageBox(L"CYLINDER IS SELECTED", PlugIn()->PlugInName(), MB_OK | MB_ICONEXCLAMATION );
				  }
				 
				  const CRhinoObjRef& split_ref = go.Object(0);
				 
				  const CRhinoObject* split_object = split_ref.Object();
				  if( !split_object )
				  {
					return failure;
				  }
				 
				  const ON_Brep* split = split_ref.Brep();
				  if( !split )
				  {
					return failure;
				  }

				  ON_SimpleArray<ON_Brep*> pieces;
				  double tol = context.m_doc.AbsoluteTolerance();
			 
				  /***********************/
				  /*PICK THE CUTTING BREP*/
				  /***********************/
				  go.SetCommandPrompt( L"SELECT CUTTING SURFACE OR POLYSUFACE" );
				  go.SetGeometryFilter( CRhinoGetObject::surface_object | CRhinoGetObject::polysrf_object  ); 
				  go.EnablePreSelect( FALSE );
				  go.EnableDeselectAllBeforePostSelect( FALSE );
				  go.GetObjects( 1, 2 );
				  if( go.CommandResult() != success )
				  {
					return go.CommandResult();
				  }

				  const ON_Brep* cutter = go.Object(0).Brep();
				  if( !cutter )
				  {
					return failure;
				  }
				 

				  if( !RhinoBrepSplit(*split, *cutter, tol, pieces) )
				  {
					RhinoApp().Print( L"UNABLE TO SPLIT BREP.\n" );
				  }
				 
				  int i, count = pieces.Count();
				  if( count == 0 | count == 1 )
				  {
					if( count == 1 )
					{
					  delete pieces[0];
					}
					return nothing;
				  }
				 
				  CRhinoObjectAttributes attrib = split_object->Attributes();
				  attrib.m_uuid = ON_nil_uuid; 
				 
				  const CRhinoObjectVisualAnalysisMode* vam_list = split_object->m_analysis_mode_list;
				 
				  for( i = 0; i < count; i++ )
				  {
					CRhinoBrepObject* brep_object = new CRhinoBrepObject( attrib );
					if( brep_object )
					{
					  brep_object->SetBrep( pieces[i] );
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
			  }


			/*********************************************************/
			}
		}/*CLOSED IF OVER CHECKING BREP COUNT OBJECT*/
		else
		{
			RhinoMessageBox(L"THERE IS ALREADY A CYLINDER OBJECT", PlugIn()->PlugInName(), MB_OK | MB_ICONEXCLAMATION );
		}
	}
	/**********************************************************************/



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
				  if( obj && obj->IsSelectable() )
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

		/*GET A REFERENCE TO THE LAYER TABLE*/
	  CRhinoLayerTable& layer_table = context.m_doc.m_layer_table;
	
	  //begin calcolo il punto di intersezione per disegnare l'ugello
	  double valore_ugello =(_wtof(plugin.m_dialog->ValIniezioneDisassamento));
	  ON_3dPoint inizio_linea (valore_ugello,0,0);
	  ON_3dPoint fine_linea (valore_ugello,0,130);
	  ON_Line line_ugello( inizio_linea, fine_linea );
	  const ON_LineCurve* crv3 = new ON_LineCurve(line_ugello);
	  //crv3->DuplicateCurve


	  // context.m_doc.AddCurveObject( line_ugello );
//begin deseleziona tutto
	 const CRhinoLayer& layer = context.m_doc.m_layer_table.CurrentLayer();
	
	  
	  
	 
	 
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
	   //const ON_Object* obj_ptr = context.m_doc.LookupDocumentObject(pvcurva, false);
//	   CRhinoObjRef& objref5 = CRhinoObject* LookupObject(pvcurva);
	  
		SelectObjectByUuid( context.m_doc, pvcurva, true );

	   //const CRhinoObject* object = context.m_doc.LookupObject( pvcurva );
	   //ON_TextLog* text_log;
	   //object->IsValid();
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
	 
  if( 0 == curveA | 0 == curveB )
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
      context.m_doc.AddPointObject( e.m_A[0] );
      if( e.m_A[0].DistanceTo(e.m_B[0]) > ON_EPSILON )
      {
        context.m_doc.AddPointObject( e.m_B[0] );
        context.m_doc.AddCurveObject( ON_Line(e.m_A[0], e.m_B[0]) );
		PuntoIntersezione = e.m_B[0];
      }
    }
    context.m_doc.Redraw();
  }
 


 
 /* ON_UUID uuid = obj->Attributes().m_uuid;
  ON_wString str;
  ON_UuidToString( uuid, str );
  ::RhinoApp().Print( L"The object's unique identifier is \"%s\".\n", str );*/




		// fine esempio
		
	
		
		//const CRhinoObjRef& objref1 = ref; //era object

	  /*const ON_LineCurve* GetLineCurve( const ON_Curve* pC5 ){
	  const ON_LineCurve* p = 0;
	  if( pC5 != 0 )
		p = ON_LineCurve::Cast( pC5 );
	  return p;
		//	}*/

	 // // const ON_LineCurve* pC5 = ON_LineCurve::Cast( ref.Geometry() );
	 ////  
		//	ON_Line line1 = crv7->m_line;
		////	//ON_Line line1 = pC5->

	 //  ON_3dVector v0 = line_ugello.to - line_ugello.from;
		//v0.Unitize();
 
	 //ON_3dVector v1 = line1.to - line1.from;
		//v1.Unitize();

		//if( v0.IsParallelTo(v1) != 0 )
  //{
  //  RhinoApp().Print( L"Selected lines are parallel.\n" );
  //  return nothing;
  //}
 

		// ON_Line ray0( line_ugello.from, line_ugello.from + v0 );
  //ON_Line ray1( line1.from, line1.from + v1 );

  //double s = 0, t = 0;
  //if( !ON_Intersect(ray0, ray1, &s, &t) )
  //{
  //  RhinoApp().Print( L"No intersection found.\n" );
  //  return nothing;
  //}
 
  //ON_3dPoint pt0 = line_ugello.from + s * v0;
  //ON_3dPoint pt1 = line1.from + t * v1;
  //context.m_doc.AddPointObject( pt0 );
  //
  //context.m_doc.Redraw();



	   //go5.g
		 //  const CRhinoObjRef& objref5 = go5.;
	   //CRhinoGetObject;
	   //CRhinoDoc::LookupDocumentObject(


	  //begin calcolo il punto di intersezione per disegnare l'ugello
	  
	  
	  
	  ON_3dPoint bottom_pt = PuntoIntersezione; // l'altro punto, e.m_A[0], non e' preciso.
	  double bottom_radius = 3.25;
	  ON_Circle bottom_circle( bottom_pt, bottom_radius );

	   ON_3dPoint top_pt = PuntoIntersezione;
	   
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
  if( tcone_brep )
  {
    CRhinoBrepObject* tcone_object = new CRhinoBrepObject();
    tcone_object->SetBrep( tcone_brep );
    if( context.m_doc.AddObject(tcone_object) )
      context.m_doc.Redraw();
    else
      delete tcone_object;
  }


//////

  // CRhinoGetObject go;
  //go.SetCommandPrompt( L"Select edge of surface to extend" );
  //go.SetGeometryFilter(CRhinoGetObject::edge_object);
  //go.SetGeometryAttributeFilter( CRhinoGetObject::edge_curve );
  //go.GetObjects( 1, 1 );
  //if( go.CommandResult() != CRhinoCommand::success )
  //  return go.CommandResult();
 
  //const CRhinoObjRef& objref = go.Object(0);
  //const ON_Surface* srf = objref.Surface();
  //if( !srf )
  //{
  //  RhinoApp().Print( L"Unable to extend polysurfaces.\n" );
  //  return CRhinoCommand::nothing;    
  //}
 
  //const ON_Brep* brep = objref.Brep();
  //const ON_BrepFace* face = objref.Face();
  //if( !brep | !face | face->m_face_index < 0 )
  //  return CRhinoCommand::failure;
 
  //if( !brep->IsSurface() )
  //{
  //  RhinoApp().Print( L"Unable to extend trimmed surfaces.\n" );
  //  return CRhinoCommand::nothing;    
  //}
 
  //const ON_BrepTrim* trim = objref.Trim();
  //if( !trim )
  //  return CRhinoCommand::failure;
 
  //ON_Surface::ISO edge_index( trim->m_iso );
  //int dir = edge_index % 2;
  //if( srf->IsClosed(1-dir) )
  //{
  //  RhinoApp().Print(L"Unable to extend surface at seam.\n" );
  //  return CRhinoCommand::nothing;  
  //}
  //if( edge_index < ON_Surface::W_iso | edge_index > ON_Surface::N_iso )
  //{
  //  RhinoApp().Print( L"Selected edge must be an underlying surface edge.\n" );
  //  return CRhinoCommand::nothing;  
  //}
 
  //ON_Surface* myface = srf->DuplicateSurface();
  //if( !myface )
  //  return CRhinoCommand::failure;
 
  //bool rc = RhinoExtendSurface( myface, edge_index, 5.0, true);  
  //if( rc )
  //{
  //  ON_Brep* mybrep = new ON_Brep();
  //  mybrep->Create( myface );
  //  CRhinoBrepObject* obj = new CRhinoBrepObject();
  //  obj->SetBrep( mybrep );
  //  context.m_doc.ReplaceObject( CRhinoObjRef(objref.Object()), obj );
  //  context.m_doc.Redraw();
  //}


/////////







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
	// Select an object to modify
  CRhinoGetObject go;
  go.SetCommandPrompt( L"Select object to change name" );
  go.EnablePreSelect( TRUE );
  go.EnableSubObjectSelect( FALSE );
  go.GetObjects( 1, 1 );
  if( go.CommandResult() != CRhinoCommand::success )
    return go.CommandResult();
 
  // Get the object reference
  const CRhinoObjRef& objref = go.Object(0);
 
  // Get the object
  const CRhinoObject* obj = objref.Object();
  if( !obj )
    return CRhinoCommand::failure;
 
  // Make copy of object attributes. This objects
  // holds an object's user-defined name.
  ON_3dmObjectAttributes obj_attribs = obj->Attributes();
 
  // Prompt for new object name
  CRhinoGetString gs;
  gs.SetCommandPrompt( L"New object name" );
  gs.SetDefaultString( obj_attribs.m_name );
  gs.AcceptNothing( TRUE );
  gs.GetString();
  if( gs.CommandResult() != CRhinoCommand::success )
    return gs.CommandResult();
 
  // Get the string entered by the user
  ON_wString obj_name = gs.String();
  obj_name.TrimLeftAndRight();
 
  // Is name the same?
  if( obj_name.Compare(obj_attribs.m_name) == 0 )
    return CRhinoCommand::nothing;
 
  // Modify the attributes of the object
  obj_attribs.m_name = obj_name;
  context.m_doc.ModifyObjectAttributes( objref, obj_attribs );
 
  return CRhinoCommand::success;

}

//
// END NewName command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
