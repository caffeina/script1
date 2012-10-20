// Il computer ha generato classi wrapper IDispatch create con l'Aggiunta guidata classe da libreria dei tipi

#import "C:\\Program Files\\Rhino 4.0 SDK\\inc\\Rhino4.tlb" no_namespace
// CRhino4Interface classe wrapper

class CRhino4Interface : public COleDispatchDriver
{
public:
	CRhino4Interface(){} // Chiama il costruttore predefinito COleDispatchDriver
	CRhino4Interface(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRhino4Interface(const CRhino4Interface& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributi
public:

	// Operazioni
public:


	// IRhino4Interface metodi
public:
	VARIANT GetScriptObject()
	{
		VARIANT result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN GetPlugInObject(LPCTSTR plugin_uuid, LPCTSTR interface_uuid)
	{
		LPUNKNOWN result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, parms, plugin_uuid, interface_uuid);
		return result;
	}

	// IRhino4Interface proprietà
public:
	long GetVisible()
	{
		long result;
		GetProperty(0x1, VT_I4, (void*)&result);
		return result;
	}
	void SetVisible(long propVal)
	{
		SetProperty(0x1, VT_I4, propVal);
	}

};
