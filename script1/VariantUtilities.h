/////////////////////////////////////////////////////////////////////////////
// VariantUtilities.h
//

// Variant validators
bool IsVariantNull( const VARIANT& va );
bool IsVariantBoolean( const VARIANT& va );
bool IsVariantInteger( const VARIANT& va );
bool IsVariantDouble( const VARIANT& va );
bool IsVariantNumber( const VARIANT& va );
bool IsVariantString( const VARIANT& va );

// Variant to data type conversions
bool VariantToBoolean( const VARIANT& va, bool& b );
bool VariantToBoolean( const VARIANT& va, BOOL& b );
bool VariantToInteger( const VARIANT& va, int& n );
bool VariantToFloat( const VARIANT& va, float& f );
bool VariantToDouble( const VARIANT& va, double& d );
bool VariantToString( const VARIANT& va, ON_wString& s );
bool VariantToString( const VARIANT& va, CString& s );

// Variant to array conversions
int VariantToArray( const VARIANT& va, ON_SimpleArray<bool>& arr );
int VariantToArray( const VARIANT& va, ON_SimpleArray<int>& arr );
int VariantToArray( const VARIANT& va, ON_SimpleArray<float>& arr );
int VariantToArray( const VARIANT& va, ON_SimpleArray<double>& arr );
int VariantToArray( const VARIANT& va, ON_ClassArray<ON_wString>& arr );
int VariantToArray( const VARIANT& va, CStringArray& arr );

// Variant to point conversions
bool VariantToPoint( const VARIANT& va, ON_2dPoint& pt );
bool VariantToPoint( const VARIANT& va, ON_3dPoint& pt );
bool VariantToPoint( const VARIANT& va, ON_3fPoint& pt );
bool VariantToPoint( const VARIANT& va, ON_4dPoint& pt );
bool VariantToPoint( const VARIANT& va, ON_4fPoint& pt );
bool VariantToVector( const VARIANT& va, ON_3dVector& v );

// Variant to point array conversion
int VariantToPointArray( const VARIANT& va, ON_2dPointArray& arr );
int VariantToPointArray( const VARIANT& va, ON_3dPointArray& arr );
int VariantToPointArray( const VARIANT& va, ON_3fPointArray& arr );
int VariantToPointArray( const VARIANT& va, ON_4dPointArray& arr );
int VariantToPointArray( const VARIANT& va, ON_4fPointArray& arr );

// Miscellaneous variant conversions
bool VariantToXform( const VARIANT& va, ON_Xform& xf );
bool VariantToPlane( const VARIANT& va, ON_Plane& plane );

// General array to safearray conversion
bool BooleanArrayToSafeArray( const ON_SimpleArray<bool>& arr, COleSafeArray& sa );
bool BooleanArrayToSafeArray( const ON_SimpleArray<BOOL>& arr, COleSafeArray& sa );
bool IntegerArrayToSafeArray( const ON_SimpleArray<int>& arr, COleSafeArray& sa );
bool DoubleArrayToSafeArray( const ON_SimpleArray<double>& arr, COleSafeArray& sa );
bool StringArrayToSafeArray( const ON_ClassArray<ON_wString>& arr, COleSafeArray& sa, bool bAllowEmptyStrings = true );
bool StringArrayToSafeArray( const CStringArray& arr, COleSafeArray& sa, bool bAllowEmptyStrings = true );

// Point and vector to safearray conversion
void PointToSafeArray( const ON_2dPoint& pt, COleSafeArray& sa );
void PointToSafeArray( const ON_2fPoint& pt, COleSafeArray& sa );
void PointToSafeArray( const ON_3dPoint& pt, COleSafeArray& sa );
void PointToSafeArray( const ON_3fPoint& pt, COleSafeArray& sa );
void PointToSafeArray( const ON_4dPoint& pt, COleSafeArray& sa );
void PointToSafeArray( const ON_4fPoint& pt, COleSafeArray& sa );
void VectorToSafeArray( const ON_3dVector& v, COleSafeArray& sa );
void VectorToSafeArray( const ON_3fVector& v, COleSafeArray& sa );

// Point and vector array to safearray conversion
bool PointArrayToSafeArray( const ON_2dPointArray& arr, COleSafeArray& sa );
bool PointArrayToSafeArray( const ON_2fPointArray& arr, COleSafeArray& sa );
bool PointArrayToSafeArray( const ON_3dPointArray& arr, COleSafeArray& sa );
bool PointArrayToSafeArray( const ON_4fPointArray& arr, COleSafeArray& sa );
bool VectorArrayToSafeArray( const ON_3dVectorArray& arr, COleSafeArray& sa );
bool VectorArrayToSafeArray( const ON_3fVectorArray& arr, COleSafeArray& sa );

// Miscellaneous safearray conversions
void XformToSafeArray( const ON_Xform& xf, COleSafeArray& sa );
bool PlaneToSafeArray( const ON_Plane& plane, COleSafeArray& sa );
void MeshFaceToSafeArray( const ON_MeshFace& mf, COleSafeArray& sa );
bool MeshFaceArrayToSafeArray( const ON_SimpleArray<ON_MeshFace>& arr, COleSafeArray& sa );

// Low level members to convert safearrays of variants to arrays
int VariantArrayToBooleanArray( SAFEARRAY* psa, ON_SimpleArray<bool>& arr );
int VariantArrayToIntegerArray( SAFEARRAY* psa, ON_SimpleArray<int>& arr );
int VariantArrayToFloatArray( SAFEARRAY* psa, ON_SimpleArray<float>& arr );
int VariantArrayToDoubleArray( SAFEARRAY* psa, ON_SimpleArray<double>& arr );
int VariantArrayToStringArray( SAFEARRAY* psa, ON_ClassArray<ON_wString>& arr );
int VariantArrayToStringArray( SAFEARRAY* psa, CStringArray& arr );

// Low level members to convert safearrays of variants to points
bool VariantArrayToPoint( SAFEARRAY* psa, ON_2dPoint& pt );
bool VariantArrayToPoint( SAFEARRAY* psa, ON_3dPoint& pt );
bool VariantArrayToPoint( SAFEARRAY* psa, ON_3fPoint& pt );
bool VariantArrayToPoint( SAFEARRAY* psa, ON_4dPoint& pt );
bool VariantArrayToPoint( SAFEARRAY* psa, ON_4fPoint& pt );

// Low level members to convert safearrays of variants to point arrays
int VariantArrayToPointArray( SAFEARRAY* psa, ON_2dPointArray& arr );
int VariantArrayToPointArray( SAFEARRAY* psa, ON_3dPointArray& arr );
int VariantArrayToPointArray( SAFEARRAY* psa, ON_3fPointArray& arr );
int VariantArrayToPointArray( SAFEARRAY* psa, ON_4dPointArray& arr );
int VariantArrayToPointArray( SAFEARRAY* psa, ON_4fPointArray& arr );

// Low level members to convert safearrays of data to arrays
int SafeArrayToBooleanArray( SAFEARRAY* psa, ON_SimpleArray<bool>& arr );
int SafeArrayToIntegerArray( SAFEARRAY* psa, ON_SimpleArray<int>& arr );
int SafeArrayToFloatArray( SAFEARRAY* psa, ON_SimpleArray<float>& arr );
int SafeArrayToDoubleArray( SAFEARRAY* psa, ON_SimpleArray<double>& arr );
int SafeArrayToStringArray( SAFEARRAY* psa, ON_ClassArray<ON_wString>& arr );
int SafeArrayToStringArray( SAFEARRAY* psa, CStringArray& arr );

// Low level members to convert safearrays of numbers to points
bool SafeArrayToPoint( SAFEARRAY* psa, ON_2dPoint& pt );
bool SafeArrayToPoint( SAFEARRAY* psa, ON_3dPoint& pt );
bool SafeArrayToPoint( SAFEARRAY* psa, ON_3fPoint& pt );
bool SafeArrayToPoint( SAFEARRAY* psa, ON_4dPoint& pt );
bool SafeArrayToPoint( SAFEARRAY* psa, ON_4fPoint& pt );

// Low level members to convert safearrays of numbers to point arrays
int SafeArrayToPointArray( SAFEARRAY* psa, ON_2dPointArray& arr );
int SafeArrayToPointArray( SAFEARRAY* psa, ON_3dPointArray& arr );
int SafeArrayToPointArray( SAFEARRAY* psa, ON_3fPointArray& arr );
int SafeArrayToPointArray( SAFEARRAY* psa, ON_4dPointArray& arr );
int SafeArrayToPointArray( SAFEARRAY* psa, ON_4fPointArray& arr );