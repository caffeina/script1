// Il computer ha generato classi wrapper IDispatch create con l'Aggiunta guidata classe da libreria dei tipi

#import "C:\\Program Files\\Rhino 4.0 SDK\\inc\\RhinoScript.tlb" no_namespace \
rename("GetObject", "RsGetObject") \
  rename("MessageBox", "RsMessageBox") \
  rename("TextOut", "RsTextOut")
// CRhinoScript classe wrapper

class CRhinoScript : public COleDispatchDriver
{
public:
	CRhinoScript(){} // Chiama il costruttore predefinito COleDispatchDriver
	CRhinoScript(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRhinoScript(const CRhinoScript& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributi
public:

	// Operazioni
public:


	// IRhinoScript metodi
public:
	VARIANT Command(VARIANT& vaCmd, VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCmd, &vaMode);
		return result;
	}
	VARIANT Print(VARIANT& vaCmd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCmd);
		return result;
	}
	VARIANT AddLayer(VARIANT& vaName, VARIANT& vaColor, VARIANT& vaVisible, VARIANT& vaLocked, VARIANT& vaParent)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaColor, &vaVisible, &vaLocked, &vaParent);
		return result;
	}
	VARIANT DeleteLayer(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT CurrentLayer(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayer(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerEmpty(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerLocked(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerOn(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerReference(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT LayerColor(VARIANT& vaName, VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaColor);
		return result;
	}
	VARIANT LayerCount()
	{
		VARIANT result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT LayerMaterialIndex(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT LayerMode(VARIANT& vaName, VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaMode);
		return result;
	}
	VARIANT LayerNames(VARIANT& vaSort)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSort);
		return result;
	}
	VARIANT RenameLayer(VARIANT& vaOld, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOld, &vaNew);
		return result;
	}
	VARIANT LayerOrder(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerChangeable(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerSelectable(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerVisible(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT ExeFolder()
	{
		VARIANT result;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Help(VARIANT& vaTopic)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTopic);
		return result;
	}
	VARIANT InstallFolder()
	{
		VARIANT result;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Prompt(VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt);
		return result;
	}
	VARIANT RegistryKey()
	{
		VARIANT result;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT StatusBarDistance(VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDistance);
		return result;
	}
	VARIANT StatusBarPoint(VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint);
		return result;
	}
	VARIANT StatusBarMessage(VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText);
		return result;
	}
	VARIANT WindowHandle()
	{
		VARIANT result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AllObjects(VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT FirstObject(VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT GetObject(VARIANT& vaPrompt, VARIANT& vaType, VARIANT& vaPreSelect, VARIANT& vaSelect, VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaType, &vaPreSelect, &vaSelect, &vaObjects);
		return result;
	}
	VARIANT GetObjects(VARIANT& vaPrompt, VARIANT& vaType, VARIANT& vaGroup, VARIANT& vaPreSelect, VARIANT& vaSelect, VARIANT& vaObjects, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaType, &vaGroup, &vaPreSelect, &vaSelect, &vaObjects, &vaMin, &vaMax);
		return result;
	}
	VARIANT InvertSelectedObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT LastObject(VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT NextObject(VARIANT& vaObject, VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT ObjectsByColor(VARIANT& vaColor, VARIANT& vaSelect, VARIANT& vaIncludeLights)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaColor, &vaSelect, &vaIncludeLights);
		return result;
	}
	VARIANT ObjectsByGroup(VARIANT& vaGroup, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaGroup, &vaSelect);
		return result;
	}
	VARIANT ObjectsByLayer(VARIANT& vaLayer, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaSelect);
		return result;
	}
	VARIANT ObjectsByName(VARIANT& vaName, VARIANT& vaSelect, VARIANT& vaIncludeLights)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaSelect, &vaIncludeLights);
		return result;
	}
	VARIANT ObjectsByType(VARIANT& vaType, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaType, &vaSelect);
		return result;
	}
	VARIANT ObjectsByURL(VARIANT& vaURL, VARIANT& vaSelect, VARIANT& vaIncludeLights)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaURL, &vaSelect, &vaIncludeLights);
		return result;
	}
	VARIANT SelectedObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT UnselectAllObjects()
	{
		VARIANT result;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT UnselectedObjects(VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT IsObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectHidden(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectLocked(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectNormal(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectSelected(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectLayer(VARIANT& vaObject, VARIANT& vaLayer)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLayer);
		return result;
	}
	VARIANT CheckListBox(VARIANT& vaList, VARIANT& vaValues, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaList, &vaValues, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT ComboListBox(VARIANT& vaList, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaList, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT EditBox(VARIANT& vaString, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaString, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT IntegerBox(VARIANT& vaPrompt, VARIANT& vaInteger, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaInteger, &vaTitle);
		return result;
	}
	VARIANT ListBox(VARIANT& vaList, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaList, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT MultiListBox(VARIANT& vaList, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaList, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT PropertyListBox(VARIANT& vaList, VARIANT& vaValues, VARIANT& vaPrompt, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaList, &vaValues, &vaPrompt, &vaTitle);
		return result;
	}
	VARIANT RealBox(VARIANT& vaPrompt, VARIANT& vaReal, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaReal, &vaTitle);
		return result;
	}
	VARIANT StringBox(VARIANT& vaPrompt, VARIANT& vaString, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaString, &vaTitle);
		return result;
	}
	VARIANT GetPoint(VARIANT& vaPrompt, VARIANT& vaPoint, VARIANT& vaDistance, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPoint, &vaDistance, &vaPlane);
		return result;
	}
	VARIANT GetString(VARIANT& vaPrompt, VARIANT& vaDefault, VARIANT& vaStrings)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaDefault, &vaStrings);
		return result;
	}
	VARIANT GetReal(VARIANT& vaPrompt, VARIANT& vaDefault, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaDefault, &vaMin, &vaMax);
		return result;
	}
	VARIANT GetInteger(VARIANT& vaPrompt, VARIANT& vaDefault, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaDefault, &vaMin, &vaMax);
		return result;
	}
	VARIANT GetColor(VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaColor);
		return result;
	}
	VARIANT GetDistance(VARIANT& vaPoint, VARIANT& vaDefault, VARIANT& vaPrompt1, VARIANT& vaPrompt2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaDefault, &vaPrompt1, &vaPrompt2);
		return result;
	}
	VARIANT GetPoints(VARIANT& vaDraw, VARIANT& vaPlane, VARIANT& vaPrompt1, VARIANT& vaPrompt2, VARIANT& vaMax, VARIANT& vaBase)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDraw, &vaPlane, &vaPrompt1, &vaPrompt2, &vaMax, &vaBase);
		return result;
	}
	VARIANT AddPoint(VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint);
		return result;
	}
	VARIANT AddPointCloud(VARIANT& vaCloud)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCloud);
		return result;
	}
	VARIANT AddLine(VARIANT& vaPoint1, VARIANT& vaPoint2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint1, &vaPoint2);
		return result;
	}
	VARIANT AddSphere(VARIANT& vaCenter, VARIANT& vaRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCenter, &vaRadius);
		return result;
	}
	VARIANT AddBox(VARIANT& vaCorners)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCorners);
		return result;
	}
	VARIANT AddCylinder(VARIANT& vaCenter, VARIANT& vaHeight, VARIANT& vaRadius, VARIANT& vaCap)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCenter, &vaHeight, &vaRadius, &vaCap);
		return result;
	}
	VARIANT AddTorus(VARIANT& vaCenter, VARIANT& vaRadius1, VARIANT& vaRadius2, VARIANT& vaDirection)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCenter, &vaRadius1, &vaRadius2, &vaDirection);
		return result;
	}
	VARIANT AddCone(VARIANT& vaCenter, VARIANT& vaHeight, VARIANT& vaRadius, VARIANT& vaCap)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCenter, &vaHeight, &vaRadius, &vaCap);
		return result;
	}
	VARIANT AddText(VARIANT& vaText, VARIANT& vaPoint, VARIANT& vaHeight, VARIANT& vaFont, VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText, &vaPoint, &vaHeight, &vaFont, &vaStyle);
		return result;
	}
	VARIANT AddCurve(VARIANT& vaPoints, VARIANT& vaDegree)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaDegree);
		return result;
	}
	VARIANT DivideCurve(VARIANT& vaObject, VARIANT& vaCount, VARIANT& vaCreate, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaCount, &vaCreate, &vaPoints);
		return result;
	}
	VARIANT SurfaceContourPoints(VARIANT& vaObject, VARIANT& vaBase, VARIANT& vaEnd, VARIANT& vaInterval, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaBase, &vaEnd, &vaInterval, &vaAngle);
		return result;
	}
	VARIANT CurveRadius(VARIANT& vaObject, VARIANT& vaPoint, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint, &vaIndex);
		return result;
	}
	VARIANT FindFile(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT AddArc3Pt(VARIANT& vaPt1, VARIANT& vaPt2, VARIANT& vaPt3)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt1, &vaPt2, &vaPt3);
		return result;
	}
	VARIANT AddCircle(VARIANT& vaPlane, VARIANT& vaRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaRadius);
		return result;
	}
	VARIANT AddCircle3Pt(VARIANT& vaPt1, VARIANT& vaPt2, VARIANT& vaPt3)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt1, &vaPt2, &vaPt3);
		return result;
	}
	VARIANT AddPolyline(VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints);
		return result;
	}
	VARIANT ArcAngle(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT ArcCenterPoint(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT ArcMidPoint(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT ArcRadius(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CircleCenterPoint(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CircleCircumference(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CircleRadius(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveClosestPoint(VARIANT& vaObject, VARIANT& vaPoint, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint, &vaIndex);
		return result;
	}
	VARIANT CurveDegree(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveDomain(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveEndPoint(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaPoint);
		return result;
	}
	VARIANT CurveLength(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaDomain)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaDomain);
		return result;
	}
	VARIANT CurvePointCount(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveStartPoint(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaPoint);
		return result;
	}
	VARIANT EvaluateCurve(VARIANT& vaObject, VARIANT& vaParam, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam, &vaIndex);
		return result;
	}
	VARIANT IsArc(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCircle(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCurve(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCurveClosed(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCurveLinear(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCurvePeriodic(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsCurvePlanar(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsLine(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsNurbsCurve(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT IsPolyline(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT JoinCurves(VARIANT& vaObjects, VARIANT& vaDelete, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaDelete, &vaTolerance);
		return result;
	}
	VARIANT PolylineVertices(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT DocumentName()
	{
		VARIANT result;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Redraw()
	{
		VARIANT result;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Angle(VARIANT& vaFrom, VARIANT& vaTo, VARIANT& vaWorld)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFrom, &vaTo, &vaWorld);
		return result;
	}
	VARIANT Angle2(VARIANT& vaFirst, VARIANT& vaSecond)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFirst, &vaSecond);
		return result;
	}
	VARIANT BoundingBox(VARIANT& vaObjects, VARIANT& vaView, VARIANT& vaSystem)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaView, &vaSystem);
		return result;
	}
	VARIANT Distance(VARIANT& vaFrom, VARIANT& vaTo)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFrom, &vaTo);
		return result;
	}
	VARIANT IsMesh(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsPoint(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsPointCloud(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsText(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshContourPoints(VARIANT& vaObject, VARIANT& vaBase, VARIANT& vaEnd, VARIANT& vaInterval, VARIANT& vaConcident)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaBase, &vaEnd, &vaInterval, &vaConcident);
		return result;
	}
	VARIANT MeshFaceCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshFaces(VARIANT& vaObject, VARIANT& vaQuads)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaQuads);
		return result;
	}
	VARIANT MeshVertexCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshVertices(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT PointCloudCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT PointCloudPoints(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT PointCoordinates(VARIANT& vaObject, VARIANT& vaNewPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaNewPt);
		return result;
	}
	VARIANT XformCPlaneToWorld(VARIANT& vaPoint, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaPlane);
		return result;
	}
	VARIANT XformWorldToCPlane(VARIANT& vaPoint, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaPlane);
		return result;
	}
	VARIANT AddGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT AddObjectToGroup(VARIANT& vaObject, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaName);
		return result;
	}
	VARIANT AddObjectsToGroup(VARIANT& vaObjects, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaName);
		return result;
	}
	VARIANT DeleteGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT GroupCount()
	{
		VARIANT result;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT GroupNames()
	{
		VARIANT result;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT IsGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsGroupEmpty(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT RemoveObjectFromAllGroups(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT RemoveObjectFromGroup(VARIANT& vaObject, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaName);
		return result;
	}
	VARIANT RemoveObjectFromTopGroup(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT RemoveObjectsFromGroup(VARIANT& vaObjects, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaName);
		return result;
	}
	VARIANT RenameGroup(VARIANT& vaOld, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOld, &vaNew);
		return result;
	}
	VARIANT BrowseForFolder(VARIANT& vaPath, VARIANT& vaMessage, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPath, &vaMessage, &vaTitle);
		return result;
	}
	VARIANT GetPointOnCurve(VARIANT& vaObject, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPrompt);
		return result;
	}
	VARIANT GetPointOnSurface(VARIANT& vaObject, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPrompt);
		return result;
	}
	VARIANT MessageBeep(VARIANT& vaType)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaType);
		return result;
	}
	VARIANT MessageBox(VARIANT& vaText, VARIANT& vaType, VARIANT& vaCaption)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText, &vaType, &vaCaption);
		return result;
	}
	VARIANT OpenFileName(VARIANT& vaTitle, VARIANT& vaFilter, VARIANT& vaPath, VARIANT& vaFile, VARIANT& vaExt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTitle, &vaFilter, &vaPath, &vaFile, &vaExt);
		return result;
	}
	VARIANT SaveFileName(VARIANT& vaTitle, VARIANT& vaFilter, VARIANT& vaPath, VARIANT& vaFile, VARIANT& vaExt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTitle, &vaFilter, &vaPath, &vaFile, &vaExt);
		return result;
	}
	VARIANT AddDirectionalLight(VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStart, &vaEnd);
		return result;
	}
	VARIANT AddLinearLight(VARIANT& vaStart, VARIANT& vaEnd, VARIANT& vaWidth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStart, &vaEnd, &vaWidth);
		return result;
	}
	VARIANT AddPointLight(VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x9b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint);
		return result;
	}
	VARIANT AddRectangularLight(VARIANT& vaOrigin, VARIANT& vaX, VARIANT& vaY)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOrigin, &vaX, &vaY);
		return result;
	}
	VARIANT AddSpotLight(VARIANT& vaBase, VARIANT& vaRadius, VARIANT& vaApex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaBase, &vaRadius, &vaApex);
		return result;
	}
	VARIANT EnableLight(VARIANT& vaLight, VARIANT& vaBool)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaBool);
		return result;
	}
	VARIANT IsDirectionalLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsLightEnabled(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsLightReference(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsLinearLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsPointLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsRectangularLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT IsSpotLight(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT LightColor(VARIANT& vaLight, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaValue);
		return result;
	}
	VARIANT LightCount()
	{
		VARIANT result;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT LightName(VARIANT& vaLight, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaValue);
		return result;
	}
	VARIANT LightObjects()
	{
		VARIANT result;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SpotLightHardness(VARIANT& vaLight, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaValue);
		return result;
	}
	VARIANT SpotLightShadowIntensity(VARIANT& vaLight, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaValue);
		return result;
	}
	VARIANT AddMaterialToLayer(VARIANT& vaLayer)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer);
		return result;
	}
	VARIANT AddMaterialToObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsMaterialDefault(VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex);
		return result;
	}
	VARIANT IsMaterialReference(VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex);
		return result;
	}
	VARIANT MaterialBump(VARIANT& vaIndex, VARIANT& vaBump)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaBump);
		return result;
	}
	VARIANT MaterialColor(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialName(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialReflectiveColor(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialShine(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialTexture(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialTransparency(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT CopyObject(VARIANT& vaObject, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStart, &vaEnd);
		return result;
	}
	VARIANT DeleteObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT DeleteObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT HideObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectInGroup(VARIANT& vaObject, VARIANT& vaGroup)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xbc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaGroup);
		return result;
	}
	VARIANT IsObjectSolid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT LockObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectColor(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xbf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT ObjectColorSource(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT ObjectGroups(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectMaterialIndex(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectMaterialSource(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT ObjectName(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT ObjectTopGroup(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectType(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectURL(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SelectObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ShowObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT UnlockObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddEdgeSrf(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT AddSrfPt(VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints);
		return result;
	}
	VARIANT EvaluateSurface(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT IsBrep(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsPolySurface(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsPolySurfaceClosed(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsPolySurfacePlanar(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsSurface(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsSurfaceClosed(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT IsSurfacePeriodic(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT IsSurfacePlanar(VARIANT& vaObject, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaTol);
		return result;
	}
	VARIANT IsSurfaceSingular(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SurfaceClosestPoint(VARIANT& vaObject, VARIANT& vaPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPt);
		return result;
	}
	VARIANT SurfaceDegree(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SurfaceDomain(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SurfacePointCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddToolBar(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT AddToolBarButton(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT AddToolBarCollection(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT CloseToolBarCollection(VARIANT& vaAlias, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaPrompt);
		return result;
	}
	VARIANT DeleteToolBar(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT HideToolBar(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT IsToolBar(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT IsToolBarCollection(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT IsToolBarVisible(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT OpenToolBarCollection(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT SaveToolBarCollection(VARIANT& vaAlias)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias);
		return result;
	}
	VARIANT SaveToolBarCollectionAs(VARIANT& vaAlias, VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaFile);
		return result;
	}
	VARIANT ShowToolBar(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xe7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT ToolBarCollectionCount()
	{
		VARIANT result;
		InvokeHelper(0xe8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ToolBarCollectionPath(VARIANT& vaAlias)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias);
		return result;
	}
	VARIANT ToolBarCollectionNames(VARIANT& vaPath)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xea, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPath);
		return result;
	}
	VARIANT ToolBarCount(VARIANT& vaAlias)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias);
		return result;
	}
	VARIANT ToolBarNames(VARIANT& vaAlias)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xec, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias);
		return result;
	}
	VARIANT DeleteDocumentData(VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xed, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaApp, &vaKey);
		return result;
	}
	VARIANT DeleteObjectData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xee, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey);
		return result;
	}
	VARIANT DocumentDataCount()
	{
		VARIANT result;
		InvokeHelper(0xef, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT GetDocumentData(VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaApp, &vaKey);
		return result;
	}
	VARIANT GetObjectData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey);
		return result;
	}
	VARIANT ObjectDataCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xf2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SetDocumentData(VARIANT& vaApp, VARIANT& vaKey, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaApp, &vaKey, &vaValue);
		return result;
	}
	VARIANT SetObjectData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey, &vaValue);
		return result;
	}
	VARIANT ClipboardText(VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xf5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText);
		return result;
	}
	VARIANT GetSettings(VARIANT& vaFile, VARIANT& vaSection, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile, &vaSection, &vaKey);
		return result;
	}
	VARIANT SaveSettings(VARIANT& vaFile, VARIANT& vaSection, VARIANT& vaKey, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile, &vaSection, &vaKey, &vaValue);
		return result;
	}
	VARIANT Sleep(VARIANT& vaTime)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xf8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTime);
		return result;
	}
	VARIANT Sort(VARIANT& vaStrings, VARIANT& vaMode, VARIANT& vaNoCase)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xf9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStrings, &vaMode, &vaNoCase);
		return result;
	}
	VARIANT Strtok(VARIANT& vaString, VARIANT& vaSeps)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaString, &vaSeps);
		return result;
	}
	VARIANT CurrentView(VARIANT& vaView, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaNames);
		return result;
	}
	VARIANT IsView(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT IsViewCurrent(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT IsViewMaximized(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT IsViewPerspective(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xff, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT IsViewTitleVisible(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT MaximizeRestoreView(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT NamedCPlanes()
	{
		VARIANT result;
		InvokeHelper(0x102, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT NamedViews()
	{
		VARIANT result;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT RenameView(VARIANT& vaOld, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x104, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOld, &vaNew);
		return result;
	}
	VARIANT ShowViewTitle(VARIANT& vaView, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x105, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaValue);
		return result;
	}
	VARIANT ViewCameraLens(VARIANT& vaView, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x106, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaValue);
		return result;
	}
	VARIANT ViewCameraTarget(VARIANT& vaView, VARIANT& vaCamera, VARIANT& vaTarget)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x107, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaCamera, &vaTarget);
		return result;
	}
	VARIANT ViewCPlane(VARIANT& vaView, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x108, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaValue);
		return result;
	}
	VARIANT ViewNames(VARIANT& vaNames, VARIANT& vaTypes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x109, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNames, &vaTypes);
		return result;
	}
	VARIANT ViewProjection(VARIANT& vaView, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x10a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaValue);
		return result;
	}
	VARIANT ViewSize(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x10b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT AddInterpCurve(VARIANT& vaPoints, VARIANT& vaDegree, VARIANT& vaKnot, VARIANT& vaCV1, VARIANT& vaCVn1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x10c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaDegree, &vaKnot, &vaCV1, &vaCVn1);
		return result;
	}
	VARIANT IsSurfaceTrimmed(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x10d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MoveObject(VARIANT& vaObject, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x10e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStart, &vaEnd);
		return result;
	}
	VARIANT IsObjectReference(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x10f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT TransformObject(VARIANT& vaObject, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaXform);
		return result;
	}
	VARIANT IsDocumentModified()
	{
		VARIANT result;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Notes(VARIANT& vaNotes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x112, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNotes);
		return result;
	}
	VARIANT DocumentURL(VARIANT& vaURL)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x113, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaURL);
		return result;
	}
	VARIANT HtmlBox(VARIANT& vaFile, VARIANT& vaArgs, VARIANT& vaOptions, VARIANT& vaModal)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x114, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile, &vaArgs, &vaOptions, &vaModal);
		return result;
	}
	VARIANT GetAngle(VARIANT& vaPoint, VARIANT& vaRef, VARIANT& vaDefault, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x115, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaRef, &vaDefault, &vaPrompt);
		return result;
	}
	VARIANT IsDocumentData()
	{
		VARIANT result;
		InvokeHelper(0x116, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT IsObjectData(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x117, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddNamedCPlane(VARIANT& vaName, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x118, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaView);
		return result;
	}
	VARIANT AddNamedView(VARIANT& vaName, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x119, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaView);
		return result;
	}
	VARIANT RestoreNamedCPlane(VARIANT& vaName, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x11a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaView);
		return result;
	}
	VARIANT RestoreNamedView(VARIANT& vaName, VARIANT& vaView, VARIANT& vaRestoreBitmap)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x11b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaView, &vaRestoreBitmap);
		return result;
	}
	VARIANT DeleteNamedCPlane(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT DeleteNamedView(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT NamedCPlane(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsProcedure(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT Version()
	{
		VARIANT result;
		InvokeHelper(0x120, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SynchronizeCPlanes(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x121, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT ViewDisplayMode(VARIANT& vaView, VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x122, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaMode);
		return result;
	}
	VARIANT PurgeLayer(VARIANT& vaLayer)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x123, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer);
		return result;
	}
	VARIANT LastCommandResult()
	{
		VARIANT result;
		InvokeHelper(0x124, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AddSrfPtGrid(VARIANT& vaCount, VARIANT& vaPoint, VARIANT& vaDegree, VARIANT& vaClosed)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x125, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCount, &vaPoint, &vaDegree, &vaClosed);
		return result;
	}
	VARIANT AddSrfControlPtGrid(VARIANT& vaCount, VARIANT& vaPoints, VARIANT& vaDegree)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x126, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCount, &vaPoints, &vaDegree);
		return result;
	}
	VARIANT CopyObjects(VARIANT& vaObjects, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x127, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStart, &vaEnd);
		return result;
	}
	VARIANT MoveObjects(VARIANT& vaObjects, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x128, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStart, &vaEnd);
		return result;
	}
	VARIANT Pt2Str(VARIANT& vaPoint, VARIANT& vaPrecision, VARIANT& vaSpace)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x129, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaPrecision, &vaSpace);
		return result;
	}
	VARIANT SelectObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x12a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT UnselectObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x12b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT UnselectObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x12c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT DocumentPath()
	{
		VARIANT result;
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT TransformObjects(VARIANT& vaObjects, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaXform);
		return result;
	}
	VARIANT HideObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT LockObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT ShowObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x131, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT UnlockObjects(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT IsObjectSelectable(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x133, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CurvePoints(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x134, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT AddNurbsCurve(VARIANT& vaPoints, VARIANT& vaKnots, VARIANT& vaDegree, VARIANT& vaWeights)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x135, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaKnots, &vaDegree, &vaWeights);
		return result;
	}
	VARIANT CurveKnotCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x136, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CurveKnots(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x137, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT StatusBarNumber(VARIANT& vaNumber)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x138, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNumber);
		return result;
	}
	VARIANT IsLayerCurrent(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x139, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT CurveWeights(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT PlugIns(VARIANT& vaTypes, VARIANT& vaLoaded)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTypes, &vaLoaded);
		return result;
	}
	VARIANT DefaultRenderer(VARIANT& vaRenderer)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x13c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRenderer);
		return result;
	}
	VARIANT EnableRedraw(VARIANT& vaRedraw)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRedraw);
		return result;
	}
	VARIANT IsPointOnCurve(VARIANT& vaObject, VARIANT& vaPoint, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x13e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint, &vaIndex);
		return result;
	}
	VARIANT IsPointOnSurface(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x13f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT AddTextDot(VARIANT& vaText, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText, &vaPoint);
		return result;
	}
	VARIANT AddLeader(VARIANT& vaPoints, VARIANT& vaView, VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x141, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaView, &vaText);
		return result;
	}
	VARIANT MatchMaterial(VARIANT& vaSrc, VARIANT& vaDest)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrc, &vaDest);
		return result;
	}
	VARIANT DocumentModified(VARIANT& vaModified)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x143, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaModified);
		return result;
	}
	VARIANT UnitAbsoluteTolerance(VARIANT& vaTol, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTol, &vaModel);
		return result;
	}
	VARIANT UnitAngleTolerance(VARIANT& vaTol, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x145, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTol, &vaModel);
		return result;
	}
	VARIANT UnitCustomUnitSystem(VARIANT& vaValue, VARIANT& vaScale, VARIANT& vaName, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x146, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaValue, &vaScale, &vaName, &vaModel);
		return result;
	}
	VARIANT UnitDistanceDisplayMode(VARIANT& vaMode, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x147, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode, &vaModel);
		return result;
	}
	VARIANT UnitDistanceDisplayPrecision(VARIANT& vaPrecision, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x148, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrecision, &vaModel);
		return result;
	}
	VARIANT UnitRelativeTolerance(VARIANT& vaTol, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x149, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTol, &vaModel);
		return result;
	}
	VARIANT UnitSystem(VARIANT& vaSystem, VARIANT& vaScale, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x14a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSystem, &vaScale, &vaModel);
		return result;
	}
	VARIANT RenderColor(VARIANT& vaItem, VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x14b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaItem, &vaColor);
		return result;
	}
	VARIANT RenderResolution(VARIANT& vaSizes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x14c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSizes);
		return result;
	}
	VARIANT RenderAntialias(VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x14d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaValue);
		return result;
	}
	VARIANT RenderSettings(VARIANT& vaSetting)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x14e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSetting);
		return result;
	}
	VARIANT AppearanceColor(VARIANT& vaItem, VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x14f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaItem, &vaColor);
		return result;
	}
	VARIANT IsTextDot(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x150, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsLeader(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x151, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsAngularDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x152, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsLinearDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x153, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsRadialDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x154, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT GetRectangle(VARIANT& vaMode, VARIANT& vaPoint, VARIANT& vaPrompt1, VARIANT& vaPrompt2, VARIANT& vaPrompt3, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x155, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode, &vaPoint, &vaPrompt1, &vaPrompt2, &vaPrompt3, &vaPlane);
		return result;
	}
	VARIANT GetBox(VARIANT& vaMode, VARIANT& vaPoint, VARIANT& vaPrompt1, VARIANT& vaPrompt2, VARIANT& vaPrompt3)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x156, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode, &vaPoint, &vaPrompt1, &vaPrompt2, &vaPrompt3);
		return result;
	}
	VARIANT OsnapMode(VARIANT& vaModes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x157, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaModes);
		return result;
	}
	VARIANT Snap(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x158, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT Ortho(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x159, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT Planar(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT Osnap(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT ProjectOsnaps(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT OsnapDialog(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT MeshQuadCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshTriangleCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x15f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshQuadsToTriangles(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x160, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshArea(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x161, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshVolume(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x162, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsMeshClosed(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x163, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT PrinterNames()
	{
		VARIANT result;
		InvokeHelper(0x164, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SpoolToPrinter(VARIANT& vaFile, VARIANT& vaPrinter)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x165, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile, &vaPrinter);
		return result;
	}
	VARIANT CurrentPrinter(VARIANT& vaPrinter)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x166, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrinter);
		return result;
	}
	VARIANT SdkVersion()
	{
		VARIANT result;
		InvokeHelper(0x167, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT BuildDate()
	{
		VARIANT result;
		InvokeHelper(0x168, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SurfaceIsocurveDensity(VARIANT& vaObject, VARIANT& vaDensity)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x169, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDensity);
		return result;
	}
	VARIANT SurfaceNormal(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT CurveTangent(VARIANT& vaObject, VARIANT& vaParam, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam, &vaIndex);
		return result;
	}
	VARIANT NormalObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT LockedObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT HiddenObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT ReferenceObjects(VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x16f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT IsPolyCurve(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x170, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT PolyCurveCount(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x171, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT PrintEx(VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x172, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText);
		return result;
	}
	VARIANT AddPlanarSrf(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x173, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT SurfacePoints(VARIANT& vaObject, VARIANT& vaReturnAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x174, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaReturnAll);
		return result;
	}
	VARIANT LastLoadedScriptFile()
	{
		VARIANT result;
		InvokeHelper(0x175, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT DivideCurveLength(VARIANT& vaObject, VARIANT& vaLength, VARIANT& vaCreate, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x176, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLength, &vaCreate, &vaPoints);
		return result;
	}
	VARIANT ZoomExtents(VARIANT& vaView, VARIANT& vaAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x177, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaAll);
		return result;
	}
	VARIANT ZoomSelected(VARIANT& vaView, VARIANT& vaAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x178, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaAll);
		return result;
	}
	VARIANT ConvertCurveToPolyline(VARIANT& vaObject, VARIANT& vaLineAngleTolerance, VARIANT& vaLineTolerance, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x179, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLineAngleTolerance, &vaLineTolerance, &vaDelete);
		return result;
	}
	VARIANT SurfaceCurvature(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x17a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT CurveCurvature(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x17b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT IsCurveRational(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x17c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveDim(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x17d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT SurfaceArea(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x17e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceVolume(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x17f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceAreaCentroid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x180, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceVolumeCentroid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x181, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceAreaMoments(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x182, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceVolumeMoments(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x183, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CreatePreviewImage(VARIANT& vaFileName, VARIANT& vaView, VARIANT& vaSize, VARIANT& vaFlags, VARIANT& vaWireframe)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x184, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFileName, &vaView, &vaSize, &vaFlags, &vaWireframe);
		return result;
	}
	VARIANT ExtractPreviewImage(VARIANT& vaFileName, VARIANT& vaModelName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x185, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFileName, &vaModelName);
		return result;
	}
	VARIANT OrientObject(VARIANT& vaObject, VARIANT& vaFrom, VARIANT& vaTo, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x186, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaFrom, &vaTo, &vaFlags);
		return result;
	}
	VARIANT OrientObjects(VARIANT& vaObjects, VARIANT& vaFrom, VARIANT& vaTo, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x187, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaFrom, &vaTo, &vaFlags);
		return result;
	}
	VARIANT RotateObject(VARIANT& vaObject, VARIANT& vaPoint, VARIANT& vaAngle, VARIANT& vaAxis, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x188, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint, &vaAngle, &vaAxis, &vaCopy);
		return result;
	}
	VARIANT RotateObjects(VARIANT& vaObjects, VARIANT& vaPoint, VARIANT& vaAngle, VARIANT& vaAxis, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x189, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaPoint, &vaAngle, &vaAxis, &vaCopy);
		return result;
	}
	VARIANT ViewCamera(VARIANT& vaView, VARIANT& vaCamera)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x18a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaCamera);
		return result;
	}
	VARIANT ViewTarget(VARIANT& vaView, VARIANT& vaTarget)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x18b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaTarget);
		return result;
	}
	VARIANT BlockNames(VARIANT& vaSort)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x18c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSort);
		return result;
	}
	VARIANT BlockCount()
	{
		VARIANT result;
		InvokeHelper(0x18d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT IsBlock(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x18e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT RenameBlock(VARIANT& vaOld, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x18f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOld, &vaNew);
		return result;
	}
	VARIANT BlockDescription(VARIANT& vaName, VARIANT& vaDesc)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x190, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaDesc);
		return result;
	}
	VARIANT GetPointOnMesh(VARIANT& vaObject, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x191, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPrompt);
		return result;
	}
	VARIANT BlockURL(VARIANT& vaName, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x192, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaNew);
		return result;
	}
	VARIANT BlockURLTag(VARIANT& vaName, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x193, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaNew);
		return result;
	}
	VARIANT BlockInstanceCount(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x194, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsBlockEmbedded(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x195, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsBlockInUse(VARIANT& vaName, VARIANT& vaWhere)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x196, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaWhere);
		return result;
	}
	VARIANT IsBlockReference(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x197, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT BlockPath(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x198, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT Str2Pt(VARIANT& vaStr)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x199, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStr);
		return result;
	}
	VARIANT Str2PtArray(VARIANT& vaStr)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x19a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStr);
		return result;
	}
	VARIANT BlockContainerCount(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x19b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT BlockContainers(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x19c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT BlockInstanceInsertPoint(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x19d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT BlockInstances(VARIANT& vaName, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x19e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaSelect);
		return result;
	}
	VARIANT BlockInstanceXform(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x19f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT BlockObjectCount(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT BlockObjects(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT DeleteBlock(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT ExplodeBlockInstance(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsBlockInstance(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT TextDotText(VARIANT& vaObject, VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1a5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaText);
		return result;
	}
	VARIANT TextDotPoint(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1a6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT CurveCurveIntersection(VARIANT& vaCrvA, VARIANT& vaCrvB, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1a7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrvA, &vaCrvB, &vaTol);
		return result;
	}
	VARIANT CurveSurfaceIntersection(VARIANT& vaCrv, VARIANT& vaSrf, VARIANT& vaTol, VARIANT& vaAngleTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1a8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaSrf, &vaTol, &vaAngleTol);
		return result;
	}
	VARIANT MeshTextureCoordinates(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshVertexNormals(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1aa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceEditPoints(VARIANT& vaObject, VARIANT& vaReturnParameters, VARIANT& vaReturnAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ab, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaReturnParameters, &vaReturnAll);
		return result;
	}
	VARIANT AutosaveFile(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1ac, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT AutosaveInterval(VARIANT& vaMinutes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1ad, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMinutes);
		return result;
	}
	VARIANT EnableAutosave(VARIANT& vaEnable)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1ae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaEnable);
		return result;
	}
	VARIANT SurfaceKnotCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1af, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceKnots(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceWeights(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsSurfaceRational(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddNurbsSurface(VARIANT& vaPointCount, VARIANT& vaPoints, VARIANT& vaKnotsU, VARIANT& vaKnotsV, VARIANT& vaDegree, VARIANT& vaWeights)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPointCount, &vaPoints, &vaKnotsU, &vaKnotsV, &vaDegree, &vaWeights);
		return result;
	}
	VARIANT ExtendCurveLength(VARIANT& vaObject, VARIANT& vaType, VARIANT& vaSide, VARIANT& vaLength)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaType, &vaSide, &vaLength);
		return result;
	}
	VARIANT ExtendCurvePoint(VARIANT& vaObject, VARIANT& vaSize, VARIANT& vaPoint, VARIANT& vaType)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSize, &vaPoint, &vaType);
		return result;
	}
	VARIANT ExtendCurve(VARIANT& vaObject, VARIANT& vaType, VARIANT& vaSide, VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaType, &vaSide, &vaObjects);
		return result;
	}
	VARIANT WorkingFolder(VARIANT& vaFolder)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFolder);
		return result;
	}
	VARIANT CloseCurve(VARIANT& vaObject, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaTolerance);
		return result;
	}
	VARIANT IsCurveClosable(VARIANT& vaObject, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1b9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaTolerance);
		return result;
	}
	VARIANT CurveEditPoints(VARIANT& vaObject, VARIANT& vaReturnParameters, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ba, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaReturnParameters, &vaIndex);
		return result;
	}
	VARIANT IsPointInSurface(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1bb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT MakeCurvePeriodic(VARIANT& vaObject, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDelete);
		return result;
	}
	VARIANT MakeSurfacePeriodic(VARIANT& vaObject, VARIANT& vaDir, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1bd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDir, &vaDelete);
		return result;
	}
	VARIANT ExplodeCurves(VARIANT& vaObject, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1be, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDelete);
		return result;
	}
	VARIANT ExplodePolysurfaces(VARIANT& vaObjects, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1bf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaDelete);
		return result;
	}
	VARIANT EdgeAnalysisMode(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT EdgeAnalysisColor(VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaColor);
		return result;
	}
	VARIANT LocaleID()
	{
		VARIANT result;
		InvokeHelper(0x1c2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT DimStyleCount()
	{
		VARIANT result;
		InvokeHelper(0x1c3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT DimStyleNames(VARIANT& vaSort)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSort);
		return result;
	}
	VARIANT CurrentDimStyle(VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle);
		return result;
	}
	VARIANT IsDimStyle(VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle);
		return result;
	}
	VARIANT AddDimStyle(VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle);
		return result;
	}
	VARIANT DeleteDimStyle(VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle);
		return result;
	}
	VARIANT IsDimStyleReference(VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1c9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle);
		return result;
	}
	VARIANT RenameDimStyle(VARIANT& vaOld, VARIANT& vaNew)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ca, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOld, &vaNew);
		return result;
	}
	VARIANT DimStyleNumberFormat(VARIANT& vaStyle, VARIANT& vaFormat)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1cb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaFormat);
		return result;
	}
	VARIANT DimScale(VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1cc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaScale);
		return result;
	}
	VARIANT DimStyleTextAlignment(VARIANT& vaStyle, VARIANT& vaAlignment)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1cd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaAlignment);
		return result;
	}
	VARIANT DimStyleFont(VARIANT& vaStyle, VARIANT& vaFont)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ce, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaFont);
		return result;
	}
	VARIANT DimStyleLinearPrecision(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1cf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimStyleAnglePrecision(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimStyleTextHeight(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimStyleExtension(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimStyleOffset(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimStyleArrowSize(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT DimensionText(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1d5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectDescription(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1d6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT TextObjectPoint(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT TextObjectText(VARIANT& vaObject, VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaText);
		return result;
	}
	VARIANT TextObjectHeight(VARIANT& vaObject, VARIANT& vaSize)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1d9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSize);
		return result;
	}
	VARIANT TextObjectFont(VARIANT& vaObject, VARIANT& vaFont)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1da, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaFont);
		return result;
	}
	VARIANT TextObjectStyle(VARIANT& vaObject, VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1db, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStyle);
		return result;
	}
	VARIANT TextObjectPlane(VARIANT& vaObject, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1dc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPlane);
		return result;
	}
	VARIANT MeshAreaCentroid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1dd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshVolumeCentroid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1de, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ZoomBoundingBox(VARIANT& vaCorners, VARIANT& vaView, VARIANT& vaAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1df, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCorners, &vaView, &vaAll);
		return result;
	}
	VARIANT PlanarClosedCurveContainment(VARIANT& vaCrv1, VARIANT& vaCrv2, VARIANT& vaPlane, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv1, &vaCrv2, &vaPlane, &vaTol);
		return result;
	}
	VARIANT PlanarCurveCollision(VARIANT& vaCrv1, VARIANT& vaCrv2, VARIANT& vaPlane, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv1, &vaCrv2, &vaPlane, &vaTol);
		return result;
	}
	VARIANT PointInPlanarClosedCurve(VARIANT& vaPt, VARIANT& vaCrv, VARIANT& vaPlane, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt, &vaCrv, &vaPlane, &vaTol);
		return result;
	}
	VARIANT IsCurveInPlane(VARIANT& vaObject, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPlane);
		return result;
	}
	VARIANT SurfaceSurfaceIntersection(VARIANT& vaSrfA, VARIANT& vaSrfB, VARIANT& vaTol, VARIANT& vaCreate)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrfA, &vaSrfB, &vaTol, &vaCreate);
		return result;
	}
	VARIANT LastCreatedObjects(VARIANT& vaSelect, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect, &vaFlags);
		return result;
	}
	VARIANT PrevSelectedObjects(VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1e6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSelect);
		return result;
	}
	VARIANT JoinSurfaces(VARIANT& vaObjects, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaDelete);
		return result;
	}
	VARIANT ExtractIsoCurve(VARIANT& vaObject, VARIANT& vaParam, VARIANT& vaDir)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam, &vaDir);
		return result;
	}
	VARIANT CurveEvaluate(VARIANT& vaCrv, VARIANT& vaParam, VARIANT& vaDevCount)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1e9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaParam, &vaDevCount);
		return result;
	}
	VARIANT LightLocation(VARIANT& vaLight, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ea, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaPoint);
		return result;
	}
	VARIANT LightDirection(VARIANT& vaLight, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1eb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaPoint);
		return result;
	}
	VARIANT UnitSystemName(VARIANT& vaCapitalize, VARIANT& vaSingular, VARIANT& vaAbbreviate, VARIANT& vaModel)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ec, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCapitalize, &vaSingular, &vaAbbreviate, &vaModel);
		return result;
	}
	VARIANT PullCurve(VARIANT& vaObject, VARIANT& vaCurve, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ed, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaCurve, &vaDelete);
		return result;
	}
	VARIANT AddMesh(VARIANT& vaVertices, VARIANT& vaFaces, VARIANT& vaNormals, VARIANT& vaTextures, VARIANT& vaColors)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ee, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVertices, &vaFaces, &vaNormals, &vaTextures, &vaColors);
		return result;
	}
	VARIANT MeshFaceVertices(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1ef, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SendKeystrokes(VARIANT& vaStr, VARIANT& vaReturn)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1f0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStr, &vaReturn);
		return result;
	}
	VARIANT ObjectGripsOn(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectGripsSelected(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT EnableObjectGrips(VARIANT& vaObject, VARIANT& vaEnable)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1f3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaEnable);
		return result;
	}
	VARIANT ObjectGripCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SelectObjectGrips(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT UnselectObjectGrips(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AllProcedures(VARIANT& vaAll)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAll);
		return result;
	}
	VARIANT SplitCurve(VARIANT& vaCrv, VARIANT& vaParam, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1f8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaParam, &vaDelete);
		return result;
	}
	VARIANT TrimCurve(VARIANT& vaCrv, VARIANT& vaInterval, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1f9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaInterval, &vaDelete);
		return result;
	}
	VARIANT BooleanUnion(VARIANT& vaObjects, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1fa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaDelete);
		return result;
	}
	VARIANT BooleanIntersection(VARIANT& vaInBreps0, VARIANT& vaInBreps1, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1fb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaInBreps0, &vaInBreps1, &vaDelete);
		return result;
	}
	VARIANT BooleanDifference(VARIANT& vaInBreps0, VARIANT& vaInBreps1, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1fc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaInBreps0, &vaInBreps1, &vaDelete);
		return result;
	}
	VARIANT SearchPathCount()
	{
		VARIANT result;
		InvokeHelper(0x1fd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SearchPathList()
	{
		VARIANT result;
		InvokeHelper(0x1fe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AddSearchPath(VARIANT& vaFolder, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1ff, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFolder, &vaIndex);
		return result;
	}
	VARIANT DeleteSearchPath(VARIANT& vaFolder)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x200, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFolder);
		return result;
	}
	VARIANT AddInterpCrvOnSrf(VARIANT& vaObject, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x201, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoints);
		return result;
	}
	VARIANT BrepClosestPoint(VARIANT& vaBrep, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x202, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaBrep, &vaPoint);
		return result;
	}
	VARIANT InsertCurveKnot(VARIANT& vaObject, VARIANT& vaParam, VARIANT& vaSym)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x203, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam, &vaSym);
		return result;
	}
	VARIANT InsertSurfaceKnot(VARIANT& vaSrf, VARIANT& vaParam, VARIANT& vaDir, VARIANT& vaSym)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x204, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrf, &vaParam, &vaDir, &vaSym);
		return result;
	}
	VARIANT ViewCameraUp(VARIANT& vaView, VARIANT& vaUp)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x205, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaUp);
		return result;
	}
	VARIANT TiltView(VARIANT& vaView, VARIANT& vaDir, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x206, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaDir, &vaAngle);
		return result;
	}
	VARIANT RotateCamera(VARIANT& vaView, VARIANT& vaDir, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x207, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaDir, &vaAngle);
		return result;
	}
	VARIANT AddInterpCurveEx(VARIANT& vaPoints, VARIANT& vaDegree, VARIANT& vaKnotSpacing, VARIANT& vaSharp, VARIANT& vaStartTangent, VARIANT& vaEndTangent)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x208, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaDegree, &vaKnotSpacing, &vaSharp, &vaStartTangent, &vaEndTangent);
		return result;
	}
	VARIANT CurveNormal(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x209, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsObjectValid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x20a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsEllipse(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x20b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT EllipseCenterPoint(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x20c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT EllipseQuadPoints(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x20d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddPoints(VARIANT& vaCloud)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x20e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCloud);
		return result;
	}
	VARIANT CurveSeam(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x20f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT TemplateFolder(VARIANT& vaFolder)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x210, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFolder);
		return result;
	}
	VARIANT TemplateFile(VARIANT& vaFile)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x211, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFile);
		return result;
	}
	VARIANT IsCommand(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x212, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsWallpaper(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x213, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT Wallpaper(VARIANT& vaView, VARIANT& vaFileName, VARIANT& vaHidden, VARIANT& vaGrayscale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x214, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaFileName, &vaHidden, &vaGrayscale);
		return result;
	}
	VARIANT WallpaperHidden(VARIANT& vaView, VARIANT& vaHidden)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x215, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaHidden);
		return result;
	}
	VARIANT WallpaperGrayScale(VARIANT& vaView, VARIANT& vaGrayscale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x216, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaGrayscale);
		return result;
	}
	VARIANT AddRevSrf(VARIANT& vaObject, VARIANT& vaAxis, VARIANT& vaSA, VARIANT& vaEA)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x217, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaAxis, &vaSA, &vaEA);
		return result;
	}
	VARIANT AddRailRevSrf(VARIANT& vaProfile, VARIANT& vaRail, VARIANT& vaAxis)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x218, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaProfile, &vaRail, &vaAxis);
		return result;
	}
	VARIANT Exit()
	{
		VARIANT result;
		InvokeHelper(0x219, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ExtrudeCurve(VARIANT& vaCurve, VARIANT& vaPath)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaPath);
		return result;
	}
	VARIANT ExtrudeCurveStraight(VARIANT& vaCurve, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaStart, &vaEnd);
		return result;
	}
	VARIANT ExtrudeCurvePoint(VARIANT& vaCurve, VARIANT& vaApex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaApex);
		return result;
	}
	VARIANT ExtrudeSurface(VARIANT& vaSurface, VARIANT& vaCurve, VARIANT& vaCap)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSurface, &vaCurve, &vaCap);
		return result;
	}
	VARIANT ReverseCurve(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x21e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CurveDirectionsMatch(VARIANT& vaCrv1, VARIANT& vaCrv2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x21f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv1, &vaCrv2);
		return result;
	}
	VARIANT IntersectBreps(VARIANT& vaBrep0, VARIANT& vaBrep1, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x220, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaBrep0, &vaBrep1, &vaTol);
		return result;
	}
	VARIANT CurveBrepIntersect(VARIANT& vaCurve, VARIANT& vaBrep, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x221, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaBrep, &vaTol);
		return result;
	}
	VARIANT MeshPolyline(VARIANT& vaCrv)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x222, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv);
		return result;
	}
	VARIANT JoinArrays(VARIANT& vaFirst, VARIANT& vaSecond)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x223, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFirst, &vaSecond);
		return result;
	}
	VARIANT CullDuplicatePoints(VARIANT& vaPoints, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x224, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaTolerance);
		return result;
	}
	VARIANT CullDuplicateStrings(VARIANT& vaStrings, VARIANT& vaCaseSensitive)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x225, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStrings, &vaCaseSensitive);
		return result;
	}
	VARIANT CullDuplicateNumbers(VARIANT& vaNumbers, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x226, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNumbers, &vaTolerance);
		return result;
	}
	VARIANT SortPoints(VARIANT& vaPoints, VARIANT& vaAscending, VARIANT& vaOrder)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x227, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaAscending, &vaOrder);
		return result;
	}
	VARIANT SortNumbers(VARIANT& vaNumbers, VARIANT& vaAscending)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x228, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNumbers, &vaAscending);
		return result;
	}
	VARIANT ScreenSize()
	{
		VARIANT result;
		InvokeHelper(0x229, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SelectObjectGrip(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT UnselectObjectGrip(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT ObjectGripLocation(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaPt);
		return result;
	}
	VARIANT ObjectGripLocations(VARIANT& vaObject, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoints);
		return result;
	}
	VARIANT NextObjectGrip(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaDir, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaDir, &vaSelect);
		return result;
	}
	VARIANT PrevObjectGrip(VARIANT& vaObject, VARIANT& vaIndex, VARIANT& vaDir, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x22f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex, &vaDir, &vaSelect);
		return result;
	}
	VARIANT SelectedObjectGrips(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x230, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT GetObjectGrip(VARIANT& vaPrompt, VARIANT& vaPreSelect, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x231, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPreSelect, &vaSelect);
		return result;
	}
	VARIANT GetObjectGrips(VARIANT& vaPrompt, VARIANT& vaPreSelect, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x232, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPreSelect, &vaSelect);
		return result;
	}
	VARIANT DimensionUserText(VARIANT& vaObject, VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x233, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaText);
		return result;
	}
	VARIANT IsDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x234, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsDiameterDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x235, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsAlignedDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x236, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT AddLoftSrf(VARIANT& vaObjects, VARIANT& vaStartPt, VARIANT& vaEndPt, VARIANT& vaType, VARIANT& vaSimplify, VARIANT& vaVal, VARIANT& vaClosed)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x237, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStartPt, &vaEndPt, &vaType, &vaSimplify, &vaVal, &vaClosed);
		return result;
	}
	VARIANT DimensionValue(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x238, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshFaceNormals(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x239, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshFaceCenters(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x23a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT BlockInstanceName(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x23b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CurveFilletPoints(VARIANT& vaCrv0, VARIANT& vaCrv1, VARIANT& vaRadius, VARIANT& vaPt0, VARIANT& vaPt1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x23c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv0, &vaCrv1, &vaRadius, &vaPt0, &vaPt1);
		return result;
	}
	VARIANT SimplifyCurve(VARIANT& vaObject, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x23d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaFlags);
		return result;
	}
	VARIANT AddFilletCurve(VARIANT& vaCrv0, VARIANT& vaCrv1, VARIANT& vaRadius, VARIANT& vaPt0, VARIANT& vaPt1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x23e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv0, &vaCrv1, &vaRadius, &vaPt0, &vaPt1);
		return result;
	}
	VARIANT GetCurveObject(VARIANT& vaPrompt, VARIANT& vaPreSelect, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x23f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPreSelect, &vaSelect);
		return result;
	}
	VARIANT GetSurfaceObject(VARIANT& vaPrompt, VARIANT& vaPreSelect, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x240, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPreSelect, &vaSelect);
		return result;
	}
	VARIANT CurveMidPoint(VARIANT& vaObject, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x241, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaIndex);
		return result;
	}
	VARIANT CurveArrows(VARIANT& vaObject, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x242, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaFlags);
		return result;
	}
	VARIANT CurveDiscontinuity(VARIANT& vaObject, VARIANT& vaType)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x243, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaType);
		return result;
	}
	VARIANT MeshNakedEdgePoints(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x244, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT XformScreenToWorld(VARIANT& vaPoint, VARIANT& vaView, VARIANT& vaScreenToClient)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x245, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaView, &vaScreenToClient);
		return result;
	}
	VARIANT XformWorldToScreen(VARIANT& vaPoint, VARIANT& vaView, VARIANT& vaClientToScreen)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x246, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaView, &vaClientToScreen);
		return result;
	}
	VARIANT SurfaceEvaluate(VARIANT& vaObject, VARIANT& vaParam, VARIANT& vaDerCount)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x247, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam, &vaDerCount);
		return result;
	}
	VARIANT SpotLightRadius(VARIANT& vaLight, VARIANT& vaRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x248, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight, &vaRadius);
		return result;
	}
	VARIANT ScaleObject(VARIANT& vaObject, VARIANT& vaOrigin, VARIANT& vaScale, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x249, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaOrigin, &vaScale, &vaCopy);
		return result;
	}
	VARIANT ScaleObjects(VARIANT& vaObjects, VARIANT& vaOrigin, VARIANT& vaScale, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaOrigin, &vaScale, &vaCopy);
		return result;
	}
	VARIANT ShearObject(VARIANT& vaObject, VARIANT& vaOrigin, VARIANT& vaRefPt, VARIANT& vaDegrees, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaOrigin, &vaRefPt, &vaDegrees, &vaCopy);
		return result;
	}
	VARIANT ShearObjects(VARIANT& vaObjects, VARIANT& vaOrigin, VARIANT& vaRefPt, VARIANT& vaDegrees, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaOrigin, &vaRefPt, &vaDegrees, &vaCopy);
		return result;
	}
	VARIANT MirrorObject(VARIANT& vaObject, VARIANT& vaStart, VARIANT& vaEnd, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStart, &vaEnd, &vaCopy);
		return result;
	}
	VARIANT MirrorObjects(VARIANT& vaObjects, VARIANT& vaStart, VARIANT& vaEnd, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x24e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStart, &vaEnd, &vaCopy);
		return result;
	}
	VARIANT CommandHistory()
	{
		VARIANT result;
		InvokeHelper(0x24f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ClearCommandHistory()
	{
		VARIANT result;
		InvokeHelper(0x250, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT PointsAreCoplanar(VARIANT& vaPoints, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x251, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaTolerance);
		return result;
	}
	VARIANT LastCommandName()
	{
		VARIANT result;
		InvokeHelper(0x252, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT PopupMenu(VARIANT& vaItems, VARIANT& vaModes, VARIANT& vaPoint, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x253, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaItems, &vaModes, &vaPoint, &vaView);
		return result;
	}
	VARIANT InCommand(VARIANT& vaScript)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x254, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaScript);
		return result;
	}
	VARIANT SimplifyArray(VARIANT& vaArray)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x255, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaArray);
		return result;
	}
	VARIANT CompareGeometry(VARIANT& vaObj1, VARIANT& vaObj2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x256, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObj1, &vaObj2);
		return result;
	}
	VARIANT FairCurve(VARIANT& vaObject, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x257, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaTolerance);
		return result;
	}
	VARIANT LayerVisible(VARIANT& vaLayer, VARIANT& vaVisible)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x258, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaVisible);
		return result;
	}
	VARIANT LayerLocked(VARIANT& vaLayer, VARIANT& vaLocked)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x259, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaLocked);
		return result;
	}
	VARIANT LayerLinetype(VARIANT& vaLayer, VARIANT& vaLinetype)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x25a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaLinetype);
		return result;
	}
	VARIANT LayerPrintColor(VARIANT& vaLayer, VARIANT& vaPrintColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x25b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaPrintColor);
		return result;
	}
	VARIANT LayerPrintWidth(VARIANT& vaLayer, VARIANT& vaPrintWidth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x25c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayer, &vaPrintWidth);
		return result;
	}
	VARIANT LinetypeCount()
	{
		VARIANT result;
		InvokeHelper(0x25d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT LinetypeNames(VARIANT& vaSort)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x25e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSort);
		return result;
	}
	VARIANT IsLinetype(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x25f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLinetypeReference(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x260, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT CurvePlane(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x261, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsVectorTiny(VARIANT& vaVec)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x262, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec);
		return result;
	}
	VARIANT IsVectorZero(VARIANT& vaVec)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x263, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec);
		return result;
	}
	VARIANT VectorAdd(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x264, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorCompare(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x265, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorCreate(VARIANT& vaPt0, VARIANT& vaPt1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x266, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt0, &vaPt1);
		return result;
	}
	VARIANT VectorCrossProduct(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x267, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorDotProduct(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x268, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorLength(VARIANT& vaVec)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x269, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec);
		return result;
	}
	VARIANT VectorReverse(VARIANT& vaVec)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x26a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec);
		return result;
	}
	VARIANT VectorScale(VARIANT& vaVec, VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x26b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec, &vaScale);
		return result;
	}
	VARIANT VectorSubtract(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x26c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorUnitize(VARIANT& vaVec)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x26d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec);
		return result;
	}
	VARIANT GetBoolean(VARIANT& vaPrompt, VARIANT& vaItems, VARIANT& vaDefaults)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x26e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaItems, &vaDefaults);
		return result;
	}
	VARIANT SurfaceFrame(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x26f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT VectorMultiply(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x270, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT VectorDivide(VARIANT& vaVec, VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x271, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec, &vaScale);
		return result;
	}
	VARIANT PlaneFromNormal(VARIANT& vaOrigin, VARIANT& vaNormal)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x272, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOrigin, &vaNormal);
		return result;
	}
	VARIANT PlaneFromFrame(VARIANT& vaOrigin, VARIANT& vaX, VARIANT& vaY)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x273, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOrigin, &vaX, &vaY);
		return result;
	}
	VARIANT DistanceToPlane(VARIANT& vaPlane, VARIANT& vaPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x274, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaPt);
		return result;
	}
	VARIANT PlaneClosestPoint(VARIANT& vaPlane, VARIANT& vaPt, VARIANT& vaReturnPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x275, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaPt, &vaReturnPt);
		return result;
	}
	VARIANT RotatePlane(VARIANT& vaPlane, VARIANT& vaDegrees, VARIANT& vaX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x276, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaDegrees, &vaX);
		return result;
	}
	VARIANT MovePlane(VARIANT& vaPlane, VARIANT& vaOrigin)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x277, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaOrigin);
		return result;
	}
	VARIANT SurfaceCurvatureAnalysis(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x278, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT InsertBlock(VARIANT& vaName, VARIANT& vaPt, VARIANT& vaScale, VARIANT& vaAngle, VARIANT& vaRotate)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x279, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaPt, &vaScale, &vaAngle, &vaRotate);
		return result;
	}
	VARIANT OffsetCurve(VARIANT& vaObject, VARIANT& vaOrigin, VARIANT& vaDistance, VARIANT& vaNormal, VARIANT& vaCorner)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x27a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaOrigin, &vaDistance, &vaNormal, &vaCorner);
		return result;
	}
	VARIANT OffsetSurface(VARIANT& vaObject, VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x27b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDistance);
		return result;
	}
	VARIANT GetPlugInObject(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x27c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT SplitBrep(VARIANT& vaObject, VARIANT& vaCutter, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x27d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaCutter, &vaDelete);
		return result;
	}
	VARIANT IsPlaneSurface(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x27e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ObjectNames(VARIANT& vaObjects, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x27f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaNames);
		return result;
	}
	VARIANT SortStrings(VARIANT& vaStrings, VARIANT& vaMode, VARIANT& vaNoCase)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x280, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStrings, &vaMode, &vaNoCase);
		return result;
	}
	VARIANT AddInterpCrvOnSrfUV(VARIANT& vaObject, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x281, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoints);
		return result;
	}
	VARIANT PlaneEquation(VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x282, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane);
		return result;
	}
	VARIANT CurveArea(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x283, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SortPointList(VARIANT& vaPoints, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x284, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaTolerance);
		return result;
	}
	VARIANT GetPointCoordinates(VARIANT& vaPrompt, VARIANT& vaPreSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x285, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPreSelect);
		return result;
	}
	VARIANT ObjectLinetype(VARIANT& vaObject, VARIANT& vaLinetype)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x286, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLinetype);
		return result;
	}
	VARIANT ObjectLinetypeSource(VARIANT& vaObject, VARIANT& vaSource)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x287, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSource);
		return result;
	}
	VARIANT AddPlaneSurface(VARIANT& vaPlane, VARIANT& vaDX, VARIANT& vaDY)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x288, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaDX, &vaDY);
		return result;
	}
	VARIANT PlaneFromPoints(VARIANT& vaOrigin, VARIANT& vaX, VARIANT& vaY)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x289, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaOrigin, &vaX, &vaY);
		return result;
	}
	VARIANT RotateView(VARIANT& vaView, VARIANT& vaDir, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x28a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaDir, &vaAngle);
		return result;
	}
	VARIANT AddArc(VARIANT& vaPlane, VARIANT& vaRadius, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x28b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaRadius, &vaAngle);
		return result;
	}
	VARIANT WorldXYPlane()
	{
		VARIANT result;
		InvokeHelper(0x28c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT WorldYZPlane()
	{
		VARIANT result;
		InvokeHelper(0x28d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT WorldZXPlane()
	{
		VARIANT result;
		InvokeHelper(0x28e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT RemapObject(VARIANT& vaObject, VARIANT& vaSrcPlane, VARIANT& vaDstPlane, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x28f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSrcPlane, &vaDstPlane, &vaCopy);
		return result;
	}
	VARIANT RemapObjects(VARIANT& vaObjects, VARIANT& vaSrcPlane, VARIANT& vaDstPlane, VARIANT& vaCopy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x290, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaSrcPlane, &vaDstPlane, &vaCopy);
		return result;
	}
	VARIANT DuplicateEdgeCurves(VARIANT& vaObject, VARIANT& vaSelect)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x291, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSelect);
		return result;
	}
	VARIANT CurveArcLengthPoint(VARIANT& vaObject, VARIANT& vaLength, VARIANT& vaStart)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x292, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLength, &vaStart);
		return result;
	}
	VARIANT IsOrdinateDimension(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x293, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsVectorParallelTo(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x294, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT IsVectorPerpendicularTo(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x295, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT Polar(VARIANT& vaPoint, VARIANT& vaAngle, VARIANT& vaDistance, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x296, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaAngle, &vaDistance, &vaPlane);
		return result;
	}
	VARIANT PI()
	{
		VARIANT result;
		InvokeHelper(0x297, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ToDegrees(VARIANT& vaRadians)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x298, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRadians);
		return result;
	}
	VARIANT ToRadians(VARIANT& vaDegrees)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x299, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDegrees);
		return result;
	}
	VARIANT PointAdd(VARIANT& vaPt0, VARIANT& vaPt1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt0, &vaPt1);
		return result;
	}
	VARIANT PointCompare(VARIANT& vaPt0, VARIANT& vaPt1, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt0, &vaPt1, &vaTol);
		return result;
	}
	VARIANT PointDivide(VARIANT& vaPt, VARIANT& vaDivide)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt, &vaDivide);
		return result;
	}
	VARIANT PointScale(VARIANT& vaPt, VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt, &vaScale);
		return result;
	}
	VARIANT PointSubtract(VARIANT& vaPt0, VARIANT& vaPt1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt0, &vaPt1);
		return result;
	}
	VARIANT PointTransform(VARIANT& vaPt, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x29f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPt, &vaXform);
		return result;
	}
	VARIANT GetLayer(VARIANT& vaPrompt, VARIANT& vaLayer, VARIANT& vaNewButton, VARIANT& vaCurrentButton)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaLayer, &vaNewButton, &vaCurrentButton);
		return result;
	}
	VARIANT GetLinetype(VARIANT& vaLinetype)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2a1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLinetype);
		return result;
	}
	VARIANT GetPrintWidth(VARIANT& vaPrintWidth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2a2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrintWidth);
		return result;
	}
	VARIANT CurveFrame(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT CurvePerpFrame(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT CurveAreaCentroid(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2a5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT VectorRotate(VARIANT& vaVec, VARIANT& vaAngle, VARIANT& vaAxis)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec, &vaAngle, &vaAxis);
		return result;
	}
	VARIANT AddEllipse(VARIANT& vaPlane, VARIANT& vaDX, VARIANT& vaDY)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaDX, &vaDY);
		return result;
	}
	VARIANT AddEllipse3Pt(VARIANT& vaCenter, VARIANT& vaSecond, VARIANT& vaThird)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCenter, &vaSecond, &vaThird);
		return result;
	}
	VARIANT AddSubCrv(VARIANT& vaObject, VARIANT& vaParam0, VARIANT& vaParam1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2a9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam0, &vaParam1);
		return result;
	}
	VARIANT GetAttributeData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2aa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey);
		return result;
	}
	VARIANT SetAttributeData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ab, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey, &vaValue);
		return result;
	}
	VARIANT DeleteAttributeData(VARIANT& vaObject, VARIANT& vaApp, VARIANT& vaKey)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ac, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaApp, &vaKey);
		return result;
	}
	VARIANT AttributeDataCount(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2ad, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsAttributeData(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2ae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CurveDeviation(VARIANT& vaCrvA, VARIANT& vaCrvB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2af, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrvA, &vaCrvB);
		return result;
	}
	VARIANT ParentLayer(VARIANT& vaName, VARIANT& vaParent)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2b0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaParent);
		return result;
	}
	VARIANT IsLayerExpanded(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT ExpandLayer(VARIANT& vaName, VARIANT& vaExpand)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2b2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaExpand);
		return result;
	}
	VARIANT LayerChildren(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsLayerChildOf(VARIANT& vaName, VARIANT& vaParent)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2b4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaParent);
		return result;
	}
	VARIANT IsLayerParentOf(VARIANT& vaName, VARIANT& vaParent)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2b5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaParent);
		return result;
	}
	VARIANT LayerChildCount(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT MeshHasVertexNormals(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshHasFaceNormals(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshHasTextureCoordinates(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2b9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshHasVertexColors(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2ba, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshVertexColors(VARIANT& vaObject, VARIANT& vaColors)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2bb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaColors);
		return result;
	}
	VARIANT ShrinkTrimmedSurface(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2bc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT CapPlanarHoles(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2bd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ShortPath(VARIANT& vaObject, VARIANT& vaStart, VARIANT& vaEnd)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2be, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStart, &vaEnd);
		return result;
	}
	VARIANT DimensionStyle(VARIANT& vaObject, VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2bf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaStyle);
		return result;
	}
	VARIANT DimStyleLeaderArrowSize(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2c0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT ObjectDump(VARIANT& vaObject, VARIANT& vaType)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2c1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaType);
		return result;
	}
	VARIANT AliasCount()
	{
		VARIANT result;
		InvokeHelper(0x2c2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AliasNames()
	{
		VARIANT result;
		InvokeHelper(0x2c3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AliasMacro(VARIANT& vaName, VARIANT& vaMacro)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2c4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaMacro);
		return result;
	}
	VARIANT AddAlias(VARIANT& vaName, VARIANT& vaMacro)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2c5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName, &vaMacro);
		return result;
	}
	VARIANT DeleteAlias(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2c6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT IsAlias(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2c7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT StartupScriptCount()
	{
		VARIANT result;
		InvokeHelper(0x2c8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT StartupScriptList()
	{
		VARIANT result;
		InvokeHelper(0x2c9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT AddStartupScript(VARIANT& vaScript, VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ca, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaScript, &vaIndex);
		return result;
	}
	VARIANT DeleteStartupScript(VARIANT& vaScript)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2cb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaScript);
		return result;
	}
	VARIANT PullPoints(VARIANT& vaObject, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2cc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoints);
		return result;
	}
	VARIANT SurfacePrincipalCurvature(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2cd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT FlipSurface(VARIANT& vaObject, VARIANT& vaReverse)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ce, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaReverse);
		return result;
	}
	VARIANT PullCurveToMesh(VARIANT& vaMesh, VARIANT& vaCurve)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2cf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh, &vaCurve);
		return result;
	}
	VARIANT MeshOffset(VARIANT& vaMesh, VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh, &vaDistance);
		return result;
	}
	VARIANT DisjointMeshCount(VARIANT& vaMesh)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2d1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh);
		return result;
	}
	VARIANT SplitDisjointMesh(VARIANT& vaMesh, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh, &vaDelete);
		return result;
	}
	VARIANT UnifyMeshNormals(VARIANT& vaMesh)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2d3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh);
		return result;
	}
	VARIANT IsToolbarDocked(VARIANT& vaAlias, VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAlias, &vaName);
		return result;
	}
	VARIANT PlaneFitFromPoints(VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2d5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints);
		return result;
	}
	VARIANT LineFitFromPoints(VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2d6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints);
		return result;
	}
	VARIANT IsVisibleInView(VARIANT& vaObject, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaView);
		return result;
	}
	VARIANT SetUserText(VARIANT& vaObject, VARIANT& vaKey, VARIANT& vaText, VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaKey, &vaText, &vaMode);
		return result;
	}
	VARIANT GetUserText(VARIANT& vaObject, VARIANT& vaKey, VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2d9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaKey, &vaMode);
		return result;
	}
	VARIANT IsUserText(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2da, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT MeshBooleanUnion(VARIANT& vaMeshes, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2db, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMeshes, &vaDelete);
		return result;
	}
	VARIANT MeshBooleanDifference(VARIANT& vaMeshes0, VARIANT& vaMeshes1, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2dc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMeshes0, &vaMeshes1, &vaDelete);
		return result;
	}
	VARIANT MeshBooleanIntersection(VARIANT& vaMeshes0, VARIANT& vaMeshes1, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2dd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMeshes0, &vaMeshes1, &vaDelete);
		return result;
	}
	VARIANT MeshBooleanSplit(VARIANT& vaMeshes0, VARIANT& vaMeshes1, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2de, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMeshes0, &vaMeshes1, &vaDelete);
		return result;
	}
	VARIANT EnableHistoryRecording(VARIANT& vaEnable)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2df, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaEnable);
		return result;
	}
	VARIANT LineLineIntersection(VARIANT& vaLine0, VARIANT& vaLine1, VARIANT& vaPlanar)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine0, &vaLine1, &vaPlanar);
		return result;
	}
	VARIANT ReadFileVersion()
	{
		VARIANT result;
		InvokeHelper(0x2e1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ShowGrid(VARIANT& vaView, VARIANT& vaShow)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaShow);
		return result;
	}
	VARIANT ShowGridAxes(VARIANT& vaView, VARIANT& vaShow)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaShow);
		return result;
	}
	VARIANT ShowWorldAxes(VARIANT& vaView, VARIANT& vaShow)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaShow);
		return result;
	}
	VARIANT DimStyleTextGap(VARIANT& vaStyle, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaStyle, &vaValue);
		return result;
	}
	VARIANT PointArrayClosestPoint(VARIANT& vaPoints, VARIANT& vaPt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaPt);
		return result;
	}
	VARIANT LinePlaneIntersection(VARIANT& vaLine, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaPlane);
		return result;
	}
	VARIANT PlanePlaneIntersection(VARIANT& vaPlaneA, VARIANT& vaPlaneB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlaneA, &vaPlaneB);
		return result;
	}
	VARIANT IntersectPlanes(VARIANT& vaPlaneA, VARIANT& vaPlaneB, VARIANT& vaPlaneC)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2e9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlaneA, &vaPlaneB, &vaPlaneC);
		return result;
	}
	VARIANT PointArrayBoundingBox(VARIANT& vaPoints, VARIANT& vaView, VARIANT& vaSystem)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ea, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaView, &vaSystem);
		return result;
	}
	VARIANT AddSrfContourCrvs(VARIANT& vaObject, VARIANT& va0, VARIANT& va1, VARIANT& va2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2eb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &va0, &va1, &va2);
		return result;
	}
	VARIANT CurveContourPoints(VARIANT& vaObject, VARIANT& vaBase, VARIANT& vaEnd, VARIANT& vaInterval)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ec, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaBase, &vaEnd, &vaInterval);
		return result;
	}
	VARIANT MeshMeshIntersection(VARIANT& vaMesh0, VARIANT& vaMesh1, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ed, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh0, &vaMesh1, &vaTolerance);
		return result;
	}
	VARIANT MeshClosestPoint(VARIANT& vaMesh, VARIANT& vaPoint, VARIANT& vaTolerance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ee, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh, &vaPoint, &vaTolerance);
		return result;
	}
	VARIANT EvaluatePlane(VARIANT& vaPlane, VARIANT& vaParameter)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2ef, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaParameter);
		return result;
	}
	VARIANT AppearanceDisplay(VARIANT& vaItem, VARIANT& vaDisplay)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2f0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaItem, &vaDisplay);
		return result;
	}
	VARIANT MaterialTransparencyMap(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2f1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT MaterialEnvironmentMap(VARIANT& vaIndex, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2f2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex, &vaValue);
		return result;
	}
	VARIANT TextOut(VARIANT& vaText, VARIANT& vaTitle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2f3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaText, &vaTitle);
		return result;
	}
	VARIANT ASin(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT ACos(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT ATan2(VARIANT& vy, VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2f6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vy, &vx);
		return result;
	}
	VARIANT SinH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT CosH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT TanH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2f9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT ASinH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2fa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT ACosH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2fb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT ATanH(VARIANT& vx)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2fc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx);
		return result;
	}
	VARIANT Hypot(VARIANT& vx, VARIANT& vy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2fd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vx, &vy);
		return result;
	}
	VARIANT Ceil(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2fe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Floor(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2ff, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Max(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x300, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Min(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x301, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Sum(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x302, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Mean(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x303, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Median(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x304, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT Deviation(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x305, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT E()
	{
		VARIANT result;
		InvokeHelper(0x306, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT GetSurfaceIsoParamPoint(VARIANT& vaBrep, VARIANT& vaPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x307, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaBrep, &vaPrompt);
		return result;
	}
	VARIANT RectangularLightPlane(VARIANT& vaLight)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x308, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLight);
		return result;
	}
	VARIANT Log10(VARIANT& var)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x309, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &var);
		return result;
	}
	VARIANT ViewCameraPlane(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x30a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT IsBackgroundBitmap(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x30b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT BackgroundBitmap(VARIANT& vaView, VARIANT& vaFileName, VARIANT& vaPoint, VARIANT& vaWidth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x30c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaFileName, &vaPoint, &vaWidth);
		return result;
	}
	VARIANT MatchObjectAttributes(VARIANT& vaTarget, VARIANT& vaSource)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x30d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTarget, &vaSource);
		return result;
	}
	VARIANT XformZero()
	{
		VARIANT result;
		InvokeHelper(0x30e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT XformIdentity()
	{
		VARIANT result;
		InvokeHelper(0x30f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT XformDiagonal(VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x310, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaValue);
		return result;
	}
	VARIANT IsXformZero(VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x311, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform);
		return result;
	}
	VARIANT IsXformIdentity(VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x312, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform);
		return result;
	}
	VARIANT IsXformSimilarity(VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x313, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform);
		return result;
	}
	VARIANT XformMultiply(VARIANT& vaXform0, VARIANT& vaXform1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x314, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform0, &vaXform1);
		return result;
	}
	VARIANT XformCompare(VARIANT& vaXform0, VARIANT& vaXform1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x315, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform0, &vaXform1);
		return result;
	}
	VARIANT XformScale(VARIANT& va0, VARIANT& va1, VARIANT& va2, VARIANT& va3)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x316, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &va0, &va1, &va2, &va3);
		return result;
	}
	VARIANT XformShear(VARIANT& va0, VARIANT& va1, VARIANT& va2, VARIANT& va3)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x317, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &va0, &va1, &va2, &va3);
		return result;
	}
	VARIANT XformTranslation(VARIANT& vaVector)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x318, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVector);
		return result;
	}
	VARIANT XformPlanarProjection(VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x319, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane);
		return result;
	}
	VARIANT XformRotation(VARIANT& va0, VARIANT& va1, VARIANT& va2, VARIANT& va3, VARIANT& va4, VARIANT& va5)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &va0, &va1, &va2, &va3, &va4, &va5);
		return result;
	}
	VARIANT XformMirror(VARIANT& vaPoint, VARIANT& vaNormal)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint, &vaNormal);
		return result;
	}
	VARIANT XformChangeBasis(VARIANT& va0, VARIANT& va1, VARIANT& va2, VARIANT& va3, VARIANT& va4, VARIANT& va5)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &va0, &va1, &va2, &va3, &va4, &va5);
		return result;
	}
	VARIANT GetPointOnPlane(VARIANT& vaPrompt, VARIANT& vaPlane, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaPlane, &vaPoint);
		return result;
	}
	VARIANT GetPointOnLine(VARIANT& vaPrompt, VARIANT& vaStart, VARIANT& vaEnd, VARIANT& vaTracking)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaStart, &vaEnd, &vaTracking);
		return result;
	}
	VARIANT IsObjectInBox(VARIANT& vaObject, VARIANT& vaBox, VARIANT& vaFlag)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x31f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaBox, &vaFlag);
		return result;
	}
	VARIANT VectorTransform(VARIANT& vaVector, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x320, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVector, &vaXform);
		return result;
	}
	VARIANT PlaneTransform(VARIANT& vaPlane, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x321, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaXform);
		return result;
	}
	VARIANT PointArrayTransform(VARIANT& vaPoints, VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x322, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaXform);
		return result;
	}
	VARIANT AddSrfSectionCrvs(VARIANT& vaObject, VARIANT& vaPlane)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x323, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPlane);
		return result;
	}
	VARIANT SurfaceSeam(VARIANT& vaObject, VARIANT& vaDir, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x324, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDir, &vaParam);
		return result;
	}
	VARIANT ObjectPrintColor(VARIANT& vaObject, VARIANT& vaColor)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x325, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaColor);
		return result;
	}
	VARIANT ObjectPrintColorSource(VARIANT& vaObject, VARIANT& vaSource)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x326, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSource);
		return result;
	}
	VARIANT ObjectPrintWidth(VARIANT& vaObject, VARIANT& vavaWidth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x327, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vavaWidth);
		return result;
	}
	VARIANT ObjectPrintWidthSource(VARIANT& vaObject, VARIANT& vaSource)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x328, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaSource);
		return result;
	}
	VARIANT CurveBooleanUnion(VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x329, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects);
		return result;
	}
	VARIANT CurveBooleanIntersection(VARIANT& vaCurveA, VARIANT& vaCurveB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurveA, &vaCurveB);
		return result;
	}
	VARIANT CurveBooleanDifference(VARIANT& vaCurveA, VARIANT& vaCurveB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurveA, &vaCurveB);
		return result;
	}
	VARIANT CopyMaterial(VARIANT& vaSrcIndex, VARIANT& vaDstIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrcIndex, &vaDstIndex);
		return result;
	}
	VARIANT FitCurve(VARIANT& vaCrv, VARIANT& vaDegree, VARIANT& vaTol, VARIANT& vaAngTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaDegree, &vaTol, &vaAngTol);
		return result;
	}
	VARIANT RebuildCurve(VARIANT& vaCrv, VARIANT& vaDegree, VARIANT& vaPointCount)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCrv, &vaDegree, &vaPointCount);
		return result;
	}
	VARIANT FitSurface(VARIANT& vaSrf, VARIANT& vaDegree, VARIANT& vaTol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x32f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrf, &vaDegree, &vaTol);
		return result;
	}
	VARIANT RebuildSurface(VARIANT& vaSrf, VARIANT& vaDegree, VARIANT& vaPointCount)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x330, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSrf, &vaDegree, &vaPointCount);
		return result;
	}
	VARIANT XformInverse(VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x331, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform);
		return result;
	}
	VARIANT XformDeterminant(VARIANT& vaXform)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x332, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaXform);
		return result;
	}
	VARIANT GetObjectEx(VARIANT& vaPrompt, VARIANT& vaType, VARIANT& vaPreSelect, VARIANT& vaSelect, VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x333, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaType, &vaPreSelect, &vaSelect, &vaObjects);
		return result;
	}
	VARIANT GetObjectsEx(VARIANT& vaPrompt, VARIANT& vaType, VARIANT& vaGroup, VARIANT& vaPreSelect, VARIANT& vaSelect, VARIANT& vaObjects, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x334, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPrompt, &vaType, &vaGroup, &vaPreSelect, &vaSelect, &vaObjects, &vaMin, &vaMax);
		return result;
	}
	VARIANT OpenFileNames(VARIANT& vaTitle, VARIANT& vaFilter, VARIANT& vaPath, VARIANT& vaFile, VARIANT& vaExt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x335, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTitle, &vaFilter, &vaPath, &vaFile, &vaExt);
		return result;
	}
	VARIANT AddCutPlane(VARIANT& vaObjects, VARIANT& vaStart, VARIANT& vaEnd, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x336, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStart, &vaEnd, &vaView);
		return result;
	}
	VARIANT ViewNearCorners(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x337, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT ViewRadius(VARIANT& vaView, VARIANT& vaRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x338, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaRadius);
		return result;
	}
	VARIANT VisibleObjects(VARIANT& vaView, VARIANT& vaSelect, VARIANT& vaIncludeLights, VARIANT& vaIncludeGrips)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x339, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaSelect, &vaIncludeLights, &vaIncludeGrips);
		return result;
	}
	VARIANT AddHatchPatterns(VARIANT& vaFileName, VARIANT& vaReplace)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x33a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFileName, &vaReplace);
		return result;
	}
	VARIANT CurrentHatchPattern(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x33b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT HatchPatternCount()
	{
		VARIANT result;
		InvokeHelper(0x33c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT HatchPatternDescription(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x33d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT HatchPatternNames()
	{
		VARIANT result;
		InvokeHelper(0x33e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT HatchPatternFillType(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x33f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT IsHatchPattern(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x340, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT IsHatchPatternCurrent(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x341, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT IsHatchPatternReference(VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x342, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHatch);
		return result;
	}
	VARIANT AddHatch(VARIANT& vaCurve, VARIANT& vaHatch, VARIANT& vaScale, VARIANT& vaRotation)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x343, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaHatch, &vaScale, &vaRotation);
		return result;
	}
	VARIANT AddHatches(VARIANT& vaCurve, VARIANT& vaHatch, VARIANT& vaScale, VARIANT& vaRotation)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x344, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaHatch, &vaScale, &vaRotation);
		return result;
	}
	VARIANT HatchPattern(VARIANT& vaObject, VARIANT& vaHatch)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x345, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaHatch);
		return result;
	}
	VARIANT HatchScale(VARIANT& vaObject, VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x346, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaScale);
		return result;
	}
	VARIANT HatchRotation(VARIANT& vaObject, VARIANT& vaRotation)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x347, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaRotation);
		return result;
	}
	VARIANT IsHatch(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x348, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ExplodeHatch(VARIANT& vaObject, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x349, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDelete);
		return result;
	}
	VARIANT CurveMeshIntersection(VARIANT& vaCurve, VARIANT& vaMesh, VARIANT& vaReturnFaces)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x34a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaMesh, &vaReturnFaces);
		return result;
	}
	VARIANT RenderMeshQuality(VARIANT& vaQuality)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x34b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaQuality);
		return result;
	}
	VARIANT RenderMeshDensity(VARIANT& vaDensity)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x34c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDensity);
		return result;
	}
	VARIANT RenderMeshMaxAngle(VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x34d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaAngle);
		return result;
	}
	VARIANT RenderMeshMaxAspectRatio(VARIANT& vaRatio)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x34e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRatio);
		return result;
	}
	VARIANT RenderMeshMinEdgeLength(VARIANT& vaLength)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x34f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLength);
		return result;
	}
	VARIANT RenderMeshMaxEdgeLength(VARIANT& vaLength)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x350, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLength);
		return result;
	}
	VARIANT RenderMeshMaxDistEdgeToSrf(VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x351, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDistance);
		return result;
	}
	VARIANT RenderMeshMinInitialGridQuads(VARIANT& vaQuads)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x352, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaQuads);
		return result;
	}
	VARIANT RenderMeshSettings(VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x353, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFlags);
		return result;
	}
	VARIANT DuplicateSurfaceBorder(VARIANT& vaSurface)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x354, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSurface);
		return result;
	}
	VARIANT DuplicateMeshBorder(VARIANT& vaMesh)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x355, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh);
		return result;
	}
	VARIANT IsBrepManifold(VARIANT& vaBrep)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x356, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaBrep);
		return result;
	}
	VARIANT IsMeshManifold(VARIANT& vaMesh)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x357, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMesh);
		return result;
	}
	VARIANT EnableObjectMesh(VARIANT& vaObject, VARIANT& vaEnable)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x358, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaEnable);
		return result;
	}
	VARIANT ObjectMeshQuality(VARIANT& vaObject, VARIANT& vaQuality)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x359, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaQuality);
		return result;
	}
	VARIANT ObjectMeshDensity(VARIANT& vaObject, VARIANT& vaDensity)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDensity);
		return result;
	}
	VARIANT ObjectMeshMaxAngle(VARIANT& vaObject, VARIANT& vaAngle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaAngle);
		return result;
	}
	VARIANT ObjectMeshMaxAspectRatio(VARIANT& vaObject, VARIANT& vaRatio)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaRatio);
		return result;
	}
	VARIANT ObjectMeshMinEdgeLength(VARIANT& vaObject, VARIANT& vaLength)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLength);
		return result;
	}
	VARIANT ObjectMeshMaxEdgeLength(VARIANT& vaObject, VARIANT& vaLength)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLength);
		return result;
	}
	VARIANT ObjectMeshMaxDistEdgeToSrf(VARIANT& vaObject, VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x35f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDistance);
		return result;
	}
	VARIANT ObjectMeshMinInitialGridQuads(VARIANT& vaObject, VARIANT& vaQuads)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x360, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaQuads);
		return result;
	}
	VARIANT ObjectMeshSettings(VARIANT& vaObject, VARIANT& vaFlags)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x361, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaFlags);
		return result;
	}
	VARIANT AddObjectMesh(VARIANT& vaObject, VARIANT& vaQuality, VARIANT& vaEnable)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x362, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaQuality, &vaEnable);
		return result;
	}
	VARIANT ObjectHasMesh(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x363, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT UnitScale(VARIANT& vaTo, VARIANT& vaFrom)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x364, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaTo, &vaFrom);
		return result;
	}
	VARIANT FlashObject(VARIANT& vaObjects, VARIANT& vaStyle)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x365, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaStyle);
		return result;
	}
	VARIANT CurveClosestObject(VARIANT& vaCurve, VARIANT& vaObjects)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x366, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaObjects);
		return result;
	}
	VARIANT HideGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x367, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT ShowGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x368, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT LockGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x369, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT UnlockGroup(VARIANT& vaName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x36a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaName);
		return result;
	}
	VARIANT MakeArray(VARIANT& vaRGB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x36b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRGB);
		return result;
	}
	VARIANT ColorRGBToHLS(VARIANT& vaHLS)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x36c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaHLS);
		return result;
	}
	VARIANT ColorHLSToRGB(VARIANT& vaUpperBound, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x36d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaUpperBound, &vaValue);
		return result;
	}
	VARIANT ColorAdjustLuma(VARIANT& vaRGB, VARIANT& vaLuma, VARIANT& vaScale)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x36e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRGB, &vaLuma, &vaScale);
		return result;
	}
	VARIANT IsParameterOnSurface(VARIANT& vaObject, VARIANT& vaParam)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x36f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaParam);
		return result;
	}
	VARIANT ColorRedValue(VARIANT& vaRGB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x370, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRGB);
		return result;
	}
	VARIANT ColorGreenValue(VARIANT& vaRGB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x371, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRGB);
		return result;
	}
	VARIANT ColorBlueValue(VARIANT& vaRGB)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x372, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRGB);
		return result;
	}
	VARIANT IsSphere(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x373, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsCylinder(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x374, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsCone(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x375, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsTorus(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x376, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceSphere(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x377, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceCylinder(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x378, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceCone(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x379, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT SurfaceTorus(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x37a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ProjectCurveToSurface(VARIANT& vaCurves, VARIANT& vaSurfaces, VARIANT& vaDirection)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurves, &vaSurfaces, &vaDirection);
		return result;
	}
	VARIANT ProjectPointToSurface(VARIANT& vaPoints, VARIANT& vaSurfaces, VARIANT& vaDirection)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaSurfaces, &vaDirection);
		return result;
	}
	VARIANT AddSweep1(VARIANT& vaRail, VARIANT& vaCurves, VARIANT& vaStartPoint, VARIANT& vaEndPoint, VARIANT& vaClosed, VARIANT& vaStyle, VARIANT& vaStyleArg, VARIANT& vaSimplify, VARIANT& vaSimplifyArg)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRail, &vaCurves, &vaStartPoint, &vaEndPoint, &vaClosed, &vaStyle, &vaStyleArg, &vaSimplify, &vaSimplifyArg);
		return result;
	}
	VARIANT AddSweep2(VARIANT& vaRail, VARIANT& vaCurves, VARIANT& vaStartPoint, VARIANT& vaEndPoint, VARIANT& vaClosed, VARIANT& vaSimpleSweep, VARIANT& vaSameHeight, VARIANT& vaSimplify, VARIANT& vaSimplifyArg)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaRail, &vaCurves, &vaStartPoint, &vaEndPoint, &vaClosed, &vaSimpleSweep, &vaSameHeight, &vaSimplify, &vaSimplifyArg);
		return result;
	}
	VARIANT LeaderText(VARIANT& vaObject, VARIANT& vaText)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x37f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaText);
		return result;
	}
	VARIANT DisplayOleAlerts(VARIANT& vaDisplay)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x380, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaDisplay);
		return result;
	}
	VARIANT LineTransform(VARIANT& vaLine, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x381, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaPoint);
		return result;
	}
	VARIANT LinePlane(VARIANT& vaLine)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x382, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine);
		return result;
	}
	VARIANT LineClosestPoint(VARIANT& vaLine, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x383, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaPoint);
		return result;
	}
	VARIANT LineMinDistanceTo(VARIANT& vaLine, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x384, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaPoints);
		return result;
	}
	VARIANT LineMaxDistanceTo(VARIANT& vaLine, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x385, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaPoints);
		return result;
	}
	VARIANT LineIsFartherThan(VARIANT& vaLine, VARIANT& vaDist, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x386, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaDist, &vaPoints);
		return result;
	}
	VARIANT ExplodeMeshes(VARIANT& vaMeshes, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x387, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMeshes, &vaDelete);
		return result;
	}
	VARIANT AddClippingPlane(VARIANT& vaPlane, VARIANT& vaDX, VARIANT& vaDY, VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x388, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaDX, &vaDY, &vaView);
		return result;
	}
	VARIANT IsClippingPlane(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x389, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT OffsetCurveOnSurface(VARIANT& vaCurve, VARIANT& vaSurface, VARIANT& vaDistance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x38a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaSurface, &vaDistance);
		return result;
	}
	VARIANT ViewTitle(VARIANT& vaView)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x38b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView);
		return result;
	}
	VARIANT ViewDisplayModes(VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x38c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaNames);
		return result;
	}
	VARIANT ViewDisplayModeName(VARIANT& vaMode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x38d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaMode);
		return result;
	}
	VARIANT ViewDisplayModeEx(VARIANT& vaView, VARIANT& vaMode, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x38e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaView, &vaMode, &vaNames);
		return result;
	}
	VARIANT ProjectCurveToMesh(VARIANT& vaCurves, VARIANT& vaMeshes, VARIANT& vaDirection)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x38f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurves, &vaMeshes, &vaDirection);
		return result;
	}
	VARIANT ProjectPointToMesh(VARIANT& vaPoints, VARIANT& vaMeshes, VARIANT& vaDirection)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x390, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaMeshes, &vaDirection);
		return result;
	}
	VARIANT DivideCurveEquidistant(VARIANT& vaCurve, VARIANT& vaLength, VARIANT& vaCreate, VARIANT& vaPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x391, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaLength, &vaCreate, &vaPoints);
		return result;
	}
	VARIANT ExtrudeCurveTapered(VARIANT& vaCurve, VARIANT& vaDistance, VARIANT& vaDirection, VARIANT& vaBase, VARIANT& vaAngle, VARIANT& vaCornerType)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x392, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaDistance, &vaDirection, &vaBase, &vaAngle, &vaCornerType);
		return result;
	}
	VARIANT AddPlanarMesh(VARIANT& vaCurve, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x393, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaDelete);
		return result;
	}
	VARIANT RemoveCurveKnot(VARIANT& vaCurve, VARIANT& vaKnot)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x394, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaCurve, &vaKnot);
		return result;
	}
	VARIANT RemoveSurfaceKnot(VARIANT& vaSurface, VARIANT& vaKnot, VARIANT& vaDir)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x395, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSurface, &vaKnot, &vaDir);
		return result;
	}
	VARIANT BoxMorphObject(VARIANT& vaObject, VARIANT& vaPoints, VARIANT& vaCopy, VARIANT& vaCorners)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x396, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoints, &vaCopy, &vaCorners);
		return result;
	}
	VARIANT IsLayoutObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x397, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsLayout(VARIANT& vaLayout)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x398, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayout);
		return result;
	}
	VARIANT IsDetail(VARIANT& vaLayout, VARIANT& vaDetail)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x399, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayout, &vaDetail);
		return result;
	}
	VARIANT DetailNames(VARIANT& vaLayout, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayout, &vaNames);
		return result;
	}
	VARIANT CurrentDetail(VARIANT& vaLayout, VARIANT& vaDetail, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLayout, &vaDetail, &vaNames);
		return result;
	}
	VARIANT ObjectLayout(VARIANT& vaObject, VARIANT& vaLayout, VARIANT& vaNames)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaLayout, &vaNames);
		return result;
	}
	VARIANT MakeCurveNonPeriodic(VARIANT& vaObject, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDelete);
		return result;
	}
	VARIANT MakeSurfaceNonPeriodic(VARIANT& vaObject, VARIANT& vaDir, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDir, &vaDelete);
		return result;
	}
	VARIANT ReverseSurface(VARIANT& vaObject, VARIANT& vaDir)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x39f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDir);
		return result;
	}
	VARIANT DimStyleLengthFactor(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT DimStylePrefix(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT DimStyleSuffix(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT ShootRay(VARIANT& vaObjects, VARIANT& vaPoint, VARIANT& vaDir, VARIANT& vaCount)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObjects, &vaPoint, &vaDir, &vaCount);
		return result;
	}
	VARIANT ClosedCurveOrientation(VARIANT& vaObject, VARIANT& vaDir)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDir);
		return result;
	}
	VARIANT CurveParameter(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT CurveNormalizedParameter(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SurfaceParameter(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT SurfaceNormalizedParameter(VARIANT& vaObject, VARIANT& vaValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaValue);
		return result;
	}
	VARIANT MeshVertexFaces(VARIANT& vaObject, VARIANT& vaVertex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3a9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaVertex);
		return result;
	}
	VARIANT GetMeshVertices(VARIANT& vaObject, VARIANT& vaPrompt, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3aa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPrompt, &vaMin, &vaMax);
		return result;
	}
	VARIANT GetMeshFaces(VARIANT& vaObject, VARIANT& vaPrompt, VARIANT& vaMin, VARIANT& vaMax)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3ab, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPrompt, &vaMin, &vaMax);
		return result;
	}
	VARIANT SolveQuadratic(VARIANT& vaA, VARIANT& vaB, VARIANT& vaC)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3ac, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaA, &vaB, &vaC);
		return result;
	}
	VARIANT PlaneSphereIntersection(VARIANT& vaPlane, VARIANT& vaSpherePlane, VARIANT& vaSphereRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3ad, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPlane, &vaSpherePlane, &vaSphereRadius);
		return result;
	}
	VARIANT LineSphereIntersection(VARIANT& vaLine, VARIANT& vaSpherePlane, VARIANT& vaSphereRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3ae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaSpherePlane, &vaSphereRadius);
		return result;
	}
	VARIANT LineCylinderIntersection(VARIANT& vaLine, VARIANT& vaCylinderPlane, VARIANT& vaCylinderHeight, VARIANT& vaCylinderRadius)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3af, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaLine, &vaCylinderPlane, &vaCylinderHeight, &vaCylinderRadius);
		return result;
	}
	VARIANT IntersectSpheres(VARIANT& vaSpherePlane0, VARIANT& vaSphereRadius0, VARIANT& vaSpherePlane1, VARIANT& vaSphereRadius1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3b0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaSpherePlane0, &vaSphereRadius0, &vaSpherePlane1, &vaSphereRadius1);
		return result;
	}
	VARIANT IsPointOnMesh(VARIANT& vaObject, VARIANT& vaPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3b1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint);
		return result;
	}
	VARIANT ResetMaterial(VARIANT& vaIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3b2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaIndex);
		return result;
	}
	VARIANT SdkServiceRelease()
	{
		VARIANT result;
		InvokeHelper(0x3b3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ExeVersion()
	{
		VARIANT result;
		InvokeHelper(0x3b4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT ExeServiceRelease()
	{
		VARIANT result;
		InvokeHelper(0x3b5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SerialNumber()
	{
		VARIANT result;
		InvokeHelper(0x3b6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT NodeType()
	{
		VARIANT result;
		InvokeHelper(0x3b7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT InstallType()
	{
		VARIANT result;
		InvokeHelper(0x3b8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT CreateSolid(VARIANT& vaObject, VARIANT& vaDelete)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3b9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaDelete);
		return result;
	}
	VARIANT EllipseFocalDistance(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3ba, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT EllipseFoci(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3bb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT IsBox(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3bc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT BoxPoints(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3bd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}
	VARIANT ExtendSurface(VARIANT& vaObject, VARIANT& vaPoint, VARIANT& vaLength, VARIANT& vaSmooth)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3be, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject, &vaPoint, &vaLength, &vaSmooth);
		return result;
	}
	VARIANT ReadDelimitedFile(VARIANT& vaFileName, VARIANT& vaDelimiters, VARIANT& vaSkipEmptyRows, VARIANT& vaTrimSpaces)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3bf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFileName, &vaDelimiters, &vaSkipEmptyRows, &vaTrimSpaces);
		return result;
	}
	VARIANT ReadTextFile(VARIANT& vaFileName, VARIANT& vaSkipEmptyRows, VARIANT& vaTrimSpaces)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaFileName, &vaSkipEmptyRows, &vaTrimSpaces);
		return result;
	}
	VARIANT ExePlatform()
	{
		VARIANT result;
		InvokeHelper(0x3c1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT SortPointsByDistance(VARIANT& vaPoints, VARIANT& vaPt, VARIANT& vaReturnPoints)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoints, &vaPt, &vaReturnPoints);
		return result;
	}
	VARIANT AddArcPtTanPt(VARIANT& vaPoint0, VARIANT& vaTangent, VARIANT& vaPoint1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint0, &vaTangent, &vaPoint1);
		return result;
	}
	VARIANT AddCirclePtTanPt(VARIANT& vaPoint0, VARIANT& vaTangent, VARIANT& vaPoint1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaPoint0, &vaTangent, &vaPoint1);
		return result;
	}
	VARIANT VectorAngle(VARIANT& vaVec0, VARIANT& vaVec1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3c5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaVec0, &vaVec1);
		return result;
	}
	VARIANT IsBlockObject(VARIANT& vaObject)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3c6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vaObject);
		return result;
	}

	// IRhinoScript proprietà
public:

};
