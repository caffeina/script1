/////////////////////////////////////////////////////////////////////////////
// VariantUtilities.cpp
//

#include "StdAfx.h"
#include "VariantUtilities.h"

bool IsVariantNull( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_NULL )
    rc = true;
  else if( pva->vt == VT_I2 && pva->iVal == 1 ) // value of vbNull constant
    rc = true;

  return rc;
}

bool IsVariantBoolean( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_BOOL )
    rc = true;

  return rc;
}

bool IsVariantInteger( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_I2 || pva->vt == VT_I4 )
    rc = true;

  return rc;
}

bool IsVariantDouble( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_R4 || pva->vt == VT_R8 )
    rc = true;

  return rc;
}

bool IsVariantNumber( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_I2 || pva->vt == VT_I4 || pva->vt == VT_R4 || pva->vt == VT_R8 )
    rc = true;

  return rc;
}

bool IsVariantString( const VARIANT& va )
{
  bool rc = false;
  
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return rc;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  if( pva->vt == VT_BSTR )
    rc = true;

  return rc;
}

bool VariantToBoolean( const VARIANT& va, bool& b )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;
  
  switch( pva->vt )
  {
		case VT_BOOL:
			b = ( pva->boolVal ? true : false );
			break;
		case VT_I2:
			b = ( pva->iVal ? true : false );
			break;
		case VT_I4:
			b = ( pva->lVal ? true : false );
			break;
		case VT_R4:
			b = ( pva->fltVal ? true : false );
			break;
		case VT_R8:
			b = ( pva->dblVal ? true : false );
			break;
	  default:
			return false;
  }

  return true;
}

bool VariantToBoolean( const VARIANT& va, BOOL& b )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;
  
  switch( pva->vt )
  {
		case VT_BOOL:
			b = ( pva->boolVal ? TRUE : FALSE );
			break;
		case VT_I2:
			b = ( pva->iVal ? TRUE : FALSE );
			break;
		case VT_I4:
			b = ( pva->lVal ? TRUE : FALSE );
			break;
		case VT_R4:
			b = ( pva->fltVal ? TRUE : FALSE );
			break;
		case VT_R8:
			b = ( pva->dblVal ? TRUE : FALSE );
			break;
	  default:
			return false;
  }

  return true;
}

bool VariantToInteger( const VARIANT& va, int& n )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;
  
  switch( pva->vt )
  {
  case VT_BOOL:
    n = ( pva->boolVal ? (int)TRUE : (int)FALSE );
    break;
  case VT_I2:
    n = (int)pva->iVal;
    break;
  case VT_I4:
    n = (int)pva->lVal;
    break;
  case VT_R4:
    n = (int)pva->fltVal;
    break;
  case VT_R8:
    n = (int)pva->dblVal;
    break;
  default:
		return false;
  }

  return true;  
}

bool VariantToFloat( const VARIANT& va, float& f )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;
  
  switch( pva->vt )
  {
  case VT_BOOL:
    f = pva->boolVal ? (float)VARIANT_TRUE : (float)VARIANT_FALSE;
    break;
  case VT_I2:
    f = (float)pva->iVal;
    break;
  case VT_I4:
    f = (float)pva->lVal;
    break;
  case VT_R4:
    f = (float)pva->fltVal;
    break;
  case VT_R8:
    f = (float)pva->dblVal;
    break;
  default:
    return false;
  }

  return true;
}

bool VariantToDouble( const VARIANT& va, double& d )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;
  
  switch( pva->vt )
  {
  case VT_BOOL:
    d = pva->boolVal ? (double)VARIANT_TRUE : (double)VARIANT_FALSE;
    break;
  case VT_I2:
    d = (double)pva->iVal;
    break;
  case VT_I4:
    d = (double)pva->lVal;
    break;
  case VT_R4:
    d = (double)pva->fltVal;
    break;
  case VT_R8:
    d = (double)pva->dblVal;
    break;
  default:
    return false;
  }

  return true;
}

bool VariantToString( const VARIANT& va, CString& str )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  switch( pva->vt )
  {
  case VT_BOOL:
    str = pva->boolVal == VARIANT_TRUE ? L"True" : L"False";
    break;
  case VT_I2:
    str.Format( L"%d", pva->iVal );
    break;
  case VT_I4:
    str.Format( L"%d", pva->lVal );
    break;
  case VT_R4:
    str.Format( L"%f", pva->fltVal );
    break;
  case VT_R8:
    str.Format( L"%g", pva->dblVal );
    break;
  case VT_BSTR:
  	str = pva->bstrVal;
    break;
  default:
    return false;
  }

  return true;  
}

bool VariantToString( const VARIANT& va, ON_wString& str )
{
  if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
    return false;
  
  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

  switch( pva->vt )
  {
  case VT_BOOL:
    str = pva->boolVal == VARIANT_TRUE ? L"True" : L"False";
    break;
  case VT_I2:
    str.Format( L"%d", pva->iVal );
    break;
  case VT_I4:
    str.Format( L"%d", pva->lVal );
    break;
  case VT_R4:
    str.Format( L"%f", pva->fltVal );
    break;
  case VT_R8:
    str.Format( L"%g", pva->dblVal );
    break;
  case VT_BSTR:
  	str = pva->bstrVal;
    break;
  default:
    return false;
  }

  return true;  
}

int VariantToArray( const VARIANT& va, ON_SimpleArray<bool>& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToBooleanArray( psa, arr );
  else
    return SafeArrayToBooleanArray( psa, arr );

  return 0;
}

int VariantToArray( const VARIANT& va, ON_SimpleArray<int>& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToIntegerArray( psa, arr );
  else
    return SafeArrayToIntegerArray( psa, arr );

  return 0;
}

int VariantToArray( const VARIANT& va, ON_SimpleArray<float>& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToFloatArray( psa, arr );
  else
    return SafeArrayToFloatArray( psa, arr );

  return 0;
}

int VariantToArray( const VARIANT& va, ON_SimpleArray<double>& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToDoubleArray( psa, arr );
  else
    return SafeArrayToDoubleArray( psa, arr );

  return 0;
}

int VariantToArray( const VARIANT& va, ON_ClassArray<ON_wString>& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToStringArray( psa, arr );
  else
    return SafeArrayToStringArray( psa, arr );

  return 0;
}

int VariantToArray( const VARIANT& va, CStringArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToStringArray( psa, arr );
  else
    return SafeArrayToStringArray( psa, arr );

  return 0;
}

bool VariantToPoint( const VARIANT& va, ON_2dPoint& pt )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 1 )
		return false;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPoint( psa, pt );
  else
    return SafeArrayToPoint( psa, pt );

  return false;
}

bool VariantToPoint( const VARIANT& va, ON_3dPoint& pt )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 1 )
		return false;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPoint( psa, pt );
  else
    return SafeArrayToPoint( psa, pt );

  return false;
}

bool VariantToPoint( const VARIANT& va, ON_3fPoint& pt )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 1 )
		return false;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPoint( psa, pt );
  else
    return SafeArrayToPoint( psa, pt );

  return false;
}

bool VariantToPoint( const VARIANT& va, ON_4fPoint& pt )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 1 )
		return false;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPoint( psa, pt );
  else
    return SafeArrayToPoint( psa, pt );

  return false;
}

bool VariantToPoint( const VARIANT& va, ON_4dPoint& pt )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 1 )
		return false;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPoint( psa, pt );
  else
    return SafeArrayToPoint( psa, pt );

  return false;
}

bool VariantToVector( const VARIANT& va, ON_3dVector& v )
{
  ON_3dPoint pt;
  bool rc = VariantToPoint( va, pt );
  if( rc )
    v = pt;
  return rc;
}

int VariantToPointArray( const VARIANT& va, ON_2dPointArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPointArray( psa, arr );
  else
    return SafeArrayToPointArray( psa, arr );

  return 0;
}

int VariantToPointArray( const VARIANT& va, ON_3dPointArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPointArray( psa, arr );
  else
    return SafeArrayToPointArray( psa, arr );

  return 0;
}

int VariantToPointArray( const VARIANT& va, ON_3fPointArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPointArray( psa, arr );
  else
    return SafeArrayToPointArray( psa, arr );

  return 0;
}

int VariantToPointArray( const VARIANT& va, ON_4dPointArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPointArray( psa, arr );
  else
    return SafeArrayToPointArray( psa, arr );

  return 0;
}

int VariantToPointArray( const VARIANT& va, ON_4fPointArray& arr )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return 0;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt & VT_ARRAY )
  {
    if( pva->vt & VT_BYREF )
		  psa = *pva->pparray;
	  else
		  psa = pva->parray;
  }

	if( psa == 0 )
		return 0;

	if( SafeArrayGetDim(psa) != 1 )
		return 0;

  if( psa->fFeatures & FADF_VARIANT )
    return VariantArrayToPointArray( psa, arr );
  else
    return SafeArrayToPointArray( psa, arr );

  return 0;
}

bool VariantToXform( const VARIANT& va, ON_Xform& xform )
{
	if( va.vt == VT_ERROR && va.scode == DISP_E_PARAMNOTFOUND )
		return false;

  const VARIANT* pva = &va;
  while( pva->vt == (VT_BYREF|VT_VARIANT) )
    pva = pva->pvarVal;

	SAFEARRAY* psa = 0;
	if( pva->vt == (VT_ARRAY|VT_VARIANT) )
		psa = pva->parray;
	else if( pva->vt == (VT_ARRAY|VT_VARIANT|VT_BYREF) )
		psa = *pva->pparray;

	if( psa == 0 )
		return false;

	if( SafeArrayGetDim(psa) != 2 )
		return false;

	long col_count, col_lower, col_upper;
	SafeArrayGetLBound( psa, 1, &col_lower );
	SafeArrayGetUBound( psa, 1, &col_upper );

	long row_count, row_lower, row_upper;
	SafeArrayGetLBound( psa, 2, &row_lower );
	SafeArrayGetUBound( psa, 2, &row_upper );

	long col_size = col_upper - col_lower;
	long row_size = row_upper - row_lower;
	if( col_size != 3 && row_size != 3 )
		return false;

  double matrix[4][4];
  long index[2];
  for( col_count = col_lower; col_count <= col_upper; col_count++ )
  {
    for( row_count = row_lower; row_count <= row_upper; row_count++ )
    {
			VARIANT element;
			VariantInit( &element );

      index[0] = row_count;
      index[1] = col_count;

			SafeArrayGetElement( psa, index, &element );
			
			double d = 0.0;
			if( VariantToDouble(element, d) )
        matrix[row_count][col_count] = d;

			VariantClear( &element );
		}
	}

  ON_Xform temp( matrix );
  xform = temp;

  return xform.IsValid() ? true : false;
}

bool VariantToPlane( const VARIANT& va, ON_Plane& plane )
{
  bool rc = false;
  ON_3dPointArray arr;
  if( VariantToPointArray(va, arr) && arr.Count() > 2 )
  {
    plane.CreateFromFrame( arr[0], arr[1], arr[2] );
    rc = ( plane.IsValid() ? true : false );
  }
  return rc;
}

void PointToSafeArray( const ON_2dPoint& pt, COleSafeArray& sa )
{
	COleVariant var[2];
	var[0] = pt.x;
	var[1] = pt.y;
	sa.CreateOneDim( VT_VARIANT, 2, var );
}

void PointToSafeArray( const ON_2fPoint& pt, COleSafeArray& sa )
{
	COleVariant var[2];
	var[0] = pt.x;
	var[1] = pt.y;
	sa.CreateOneDim( VT_VARIANT, 2, var );
}

void PointToSafeArray( const ON_3dPoint& pt, COleSafeArray& sa )
{
	COleVariant var[3];
	var[0] = pt.x;
	var[1] = pt.y;
	var[2] = pt.z;
	sa.CreateOneDim( VT_VARIANT, 3, var );
}

void PointToSafeArray( const ON_3fPoint& pt, COleSafeArray& sa )
{
	COleVariant var[3];
	var[0] = pt.x;
	var[1] = pt.y;
	var[2] = pt.z;
	sa.CreateOneDim( VT_VARIANT, 3, var );
}

void PointToSafeArray( const ON_4dPoint& pt, COleSafeArray& sa )
{
	COleVariant var[4];
	var[0] = pt.x;
	var[1] = pt.y;
	var[2] = pt.z;
  var[3] = pt.w;
	sa.CreateOneDim( VT_VARIANT, 4, var );
}

void PointToSafeArray( const ON_4fPoint& pt, COleSafeArray& sa )
{
	COleVariant var[4];
	var[0] = pt.x;
	var[1] = pt.y;
	var[2] = pt.z;
  var[3] = pt.w;
	sa.CreateOneDim( VT_VARIANT, 4, var );
}

void VectorToSafeArray( const ON_3dVector& v, COleSafeArray& sa )
{
	COleVariant var[3];
	var[0] = v.x;
	var[1] = v.y;
	var[2] = v.z;
	sa.CreateOneDim( VT_VARIANT, 3, var );
}

void VectorToSafeArray( const ON_3fVector& v, COleSafeArray& sa )
{
	COleVariant var[3];
	var[0] = v.x;
	var[1] = v.y;
	var[2] = v.z;
	sa.CreateOneDim( VT_VARIANT, 3, var );
}

bool BooleanArrayToSafeArray( const ON_SimpleArray<bool>& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
		  v.vt = VT_BOOL;
      v.boolVal = ( arr[i] ? VARIANT_TRUE : VARIANT_FALSE );
		  sa.PutElement( index, &v );
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool BooleanArrayToSafeArray( const ON_SimpleArray<BOOL>& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
		  v.vt = VT_BOOL;
      v.boolVal = ( arr[i] ? VARIANT_TRUE : VARIANT_FALSE );
		  sa.PutElement( index, &v );
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool IntegerArrayToSafeArray( const ON_SimpleArray<int>& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
		  v.vt = VT_I4;
		  v.lVal = arr[i];
		  sa.PutElement( index, &v );
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool DoubleArrayToSafeArray( const ON_SimpleArray<double>& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
		  v.vt = VT_R8;
		  v.dblVal = arr[i];
		  sa.PutElement( index, &v );
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool StringArrayToSafeArray( const ON_ClassArray<ON_wString>& arr, COleSafeArray& sa, bool bAllowEmptyStrings )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
      ON_wString w = arr[i];
		  CString s( w );
      if( s.IsEmpty() && bAllowEmptyStrings == false )
      {
        v.vt = VT_NULL;
  		  sa.PutElement( index, &v );
      }
      else
      {
		    v.vt = VT_BSTR;
		    v.bstrVal = s.AllocSysString();
		    sa.PutElement( index, &v );
		    SysFreeString( v.bstrVal );
      }
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool StringArrayToSafeArray( const CStringArray& arr, COleSafeArray& sa, bool bAllowEmptyStrings )
{
  bool rc = false;
  int i, count = (int)arr.GetCount();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
		  VARIANT v;
		  VariantInit( &v );
		  CString s = arr.GetAt(i);
      if( s.IsEmpty() && bAllowEmptyStrings == false )
      {
        v.vt = VT_NULL;
  		  sa.PutElement( index, &v );
      }
      else
      {
		    v.vt = VT_BSTR;
		    v.bstrVal = s.AllocSysString();
		    sa.PutElement( index, &v );
		    SysFreeString( v.bstrVal );
      }
		  VariantClear( &v );
	  }
    rc = true;
  }
  return rc;
}

bool PointArrayToSafeArray( const ON_2dPointArray& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      PointToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

bool PointArrayToSafeArray( const ON_2fPointArray& arr,  COleSafeArray& sa  )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      PointToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

bool PointArrayToSafeArray( const ON_3dPointArray& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      PointToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

bool PointArrayToSafeArray( const ON_4fPointArray& arr,  COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      PointToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

bool VectorArrayToSafeArray( const ON_3dVectorArray& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      VectorToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

bool VectorArrayToSafeArray( const ON_3fVectorArray& arr, COleSafeArray& sa )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      VectorToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

void XformToSafeArray( const ON_Xform& xform,  COleSafeArray& sa )
{
  DWORD numElements[] = {4, 4};
  sa.Create( VT_VARIANT, 2, numElements );
  int i, j;
  long index[2];
  for( i = 0; i < 4; i++ )
  {
    for( j = 0; j < 4; j++ )
    {
		  index[0] = (long)i;
      index[1] = (long)j;
		  VARIANT v;
		  VariantInit( &v );
		  v.vt = VT_R8;
      v.dblVal = xform.m_xform[i][j];
		  sa.PutElement( index, &v );
		  VariantClear( &v );
    }
  }
}

bool PlaneToSafeArray( const ON_Plane& plane, COleSafeArray& sa )
{
  ON_3dPointArray arr;
  arr.Append( plane.origin );
  arr.Append( plane.xaxis );
  arr.Append( plane.yaxis );
  arr.Append( plane.zaxis );
  return PointArrayToSafeArray( arr, sa );
}

void MeshFaceToSafeArray( const ON_MeshFace& face,  COleSafeArray& sa  )
{
	COleVariant var[4];
	var[0] = (long)face.vi[0];
	var[1] = (long)face.vi[1];
	var[2] = (long)face.vi[2];
  var[3] = (long)face.vi[3];
	sa.CreateOneDim( VT_VARIANT, 4, var );
}

bool MeshFaceArrayToSafeArray( const ON_SimpleArray<ON_MeshFace>& arr, COleSafeArray& sa  )
{
  bool rc = false;
  int i, count = arr.Count();
  if( count > 0 )
  {
    DWORD numElements[1];
  	numElements[0] = (DWORD)count;
	  sa.Create( VT_VARIANT, 1, numElements );
	  long index[1];
    for( i = 0; i < count; i++ )
	  {
		  index[0] = (long)i;
      COleSafeArray osa;
      MeshFaceToSafeArray( arr[i], osa );
      COleVariant va;
      va.Attach( osa.Detach() );
      sa.PutElement( index, va );
	  }
    rc = true;
  }
  return rc;
}

int VariantArrayToBooleanArray( SAFEARRAY* psa, ON_SimpleArray<bool>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        bool b = false;
        if( VariantToBoolean(pvData[i], b) )
	        arr.Append( b );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToIntegerArray( SAFEARRAY* psa, ON_SimpleArray<int>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        int n = 0;
        if( VariantToInteger(pvData[i], n) )
	        arr.Append( n );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToFloatArray( SAFEARRAY* psa, ON_SimpleArray<float>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        float f = 0.0;
        if( VariantToFloat(pvData[i], f) )
	        arr.Append( f );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToDoubleArray( SAFEARRAY* psa, ON_SimpleArray<double>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        double d = 0.0;
        if( VariantToDouble(pvData[i], d) )
	        arr.Append( d );
      }
      SafeArrayUnaccessData( psa );
    }
  }
  return arr.Count();
}

int VariantArrayToStringArray( SAFEARRAY* psa, ON_ClassArray<ON_wString>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_wString str;
        if( VariantToString(pvData[i], str) )
	        arr.Append( str );
      }
      SafeArrayUnaccessData( psa );
    }
  }
  return arr.Count();
}

int VariantArrayToStringArray( SAFEARRAY* psa, CStringArray& arr )
{
  ASSERT( psa );
  arr.RemoveAll();
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    VARIANT* pvData = 0;
    HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        CString str;
        if( VariantToString(pvData[i], str) )
	        arr.Add( str );
      }
      SafeArrayUnaccessData( psa );
    }
  }
  return (int)arr.GetCount();
}

bool VariantArrayToPoint( SAFEARRAY* psa, ON_2dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    if( upper - lower == 1 )
    {
      VARIANT* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        double p[] = { 0.0, 0.0 };
    	  for( i = lower; i <= upper; i++ )
		      VariantToDouble( pvData[i], p[i] );
        SafeArrayUnaccessData( psa );
        pt.x = p[0];
	      pt.y = p[1];
        rc = true;
      }
    }
  }
  return rc;
}

bool VariantArrayToPoint( SAFEARRAY* psa, ON_3dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    if( upper - lower == 1 || upper - lower == 2 )
    {
      VARIANT* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        double p[] = { 0.0, 0.0, 0.0 };
    	  for( i = lower; i <= upper; i++ )
		      VariantToDouble( pvData[i], p[i] );
        SafeArrayUnaccessData( psa );
        pt.x = p[0];
	      pt.y = p[1];
        pt.z = p[2];
        rc = true;
      }
    }
  }
  return rc;
}

bool VariantArrayToPoint( SAFEARRAY* psa, ON_3fPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    if( upper - lower == 1 || upper - lower == 2 )
    {
      VARIANT* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        float p[] = { 0.0, 0.0, 0.0 };
    	  for( i = lower; i <= upper; i++ )
		      VariantToFloat( pvData[i], p[i] );
        SafeArrayUnaccessData( psa );
        pt.x = p[0];
	      pt.y = p[1];
        pt.z = p[2];
        rc = true;
      }
    }
  }
  return rc;
}

bool VariantArrayToPoint( SAFEARRAY* psa, ON_4dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    if( upper - lower == 2 || upper - lower == 3 )
    {
      VARIANT* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        double p[] = { 0.0, 0.0, 0.0, 0.0 };
    	  for( i = lower; i <= upper; i++ )
		      VariantToDouble( pvData[i], p[i] );
        SafeArrayUnaccessData( psa );
        pt.x = p[0];
	      pt.y = p[1];
        pt.z = p[2];
        pt.w = p[3];
        rc = true;
      }
    }
  }
  return rc;
}

bool VariantArrayToPoint( SAFEARRAY* psa, ON_4fPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    if( upper - lower == 2 || upper - lower == 3 )
    {
      VARIANT* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        float p[] = { 0.0, 0.0, 0.0, 0.0 };
    	  for( i = lower; i <= upper; i++ )
		      VariantToFloat( pvData[i], p[i] );
        SafeArrayUnaccessData( psa );
        pt.x = p[0];
	      pt.y = p[1];
        pt.z = p[2];
        pt.w = p[3];
        rc = true;
      }
    }
  }
  return rc;
}

int VariantArrayToPointArray( SAFEARRAY* psa, ON_2dPointArray& arr )
{
  ASSERT( psa );
  arr.Empty();

	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( FAILED(hl) || FAILED(hu) )
    return 0;

  VARIANT va;
  VariantInit( &va );
  HRESULT hr = SafeArrayGetElement( psa, &lower, &va );
  if( FAILED(hr) )
    return 0;

  bool bIsNumber = IsVariantNumber( va );
  VariantClear( &va );
  if( bIsNumber )
  {
    int stride = 2;
    ON_SimpleArray<double> vals;
    int count = VariantToArray(va, vals);
    if( count && count % stride == 0 )
    {
      int i, point_count = count / stride;
      arr.SetCapacity( point_count );
      arr.SetCount( point_count );
      ON_2dPoint pt( 0.0, 0.0 );
      const double* ptr = vals.Array();
      for( i = 0; i < point_count; i++ )
      {
        pt.x = ptr[0];
        pt.y = ptr[1];
        arr[i] = pt;
        ptr += stride;
      }
      return arr.Count();
    }
    else
		  return 0;
  }
  else
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_2dPoint pt;
        if( VariantToPoint(pvData[i], pt) )
	        arr.Append( pt );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToPointArray( SAFEARRAY* psa, ON_3dPointArray& arr )
{
  ASSERT( psa );
  arr.Empty();

	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( FAILED(hl) || FAILED(hu) )
    return 0;

  VARIANT va;
  VariantInit( &va );
  HRESULT hr = SafeArrayGetElement( psa, &lower, &va );
  if( FAILED(hr) )
    return 0;

  bool bIsNumber = IsVariantNumber( va );
  VariantClear( &va );
  if( bIsNumber )
  {
    int stride = 3;
    ON_SimpleArray<double> vals;
    int count = VariantToArray(va, vals);
    if( count && count % stride == 0 )
    {
      int i, point_count = count / stride;
      arr.SetCapacity( point_count );
      arr.SetCount( point_count );
      ON_3dPoint pt( 0.0, 0.0, 0.0 );
      const double* ptr = vals.Array();
      for( i = 0; i < point_count; i++ )
      {
        pt.x = ptr[0];
        pt.y = ptr[1];
        pt.z = ptr[2];
        arr[i] = pt;
        ptr += stride;
      }
      return arr.Count();
    }
    else
		  return 0;
  }
  else
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_3dPoint pt;
        if( VariantToPoint(pvData[i], pt) )
	        arr.Append( pt );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToPointArray( SAFEARRAY* psa, ON_3fPointArray& arr )
{
  ASSERT( psa );
  arr.Empty();

	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( FAILED(hl) || FAILED(hu) )
    return 0;

  VARIANT va;
  VariantInit( &va );
  HRESULT hr = SafeArrayGetElement( psa, &lower, &va );
  if( FAILED(hr) )
    return 0;

  bool bIsNumber = IsVariantNumber( va );
  VariantClear( &va );
  if( bIsNumber )
  {
    int stride = 3;
    ON_SimpleArray<float> vals;
    int count = VariantToArray(va, vals);
    if( count && count % stride == 0 )
    {
      int i, point_count = count / stride;
      arr.SetCapacity( point_count );
      arr.SetCount( point_count );
      ON_3fPoint pt( 0.0, 0.0, 0.0 );
      const float* ptr = vals.Array();
      for( i = 0; i < point_count; i++ )
      {
        pt.x = ptr[0];
        pt.y = ptr[1];
        pt.z = ptr[2];
        arr[i] = pt;
        ptr += stride;
      }
      return arr.Count();
    }
    else
		  return 0;
  }
  else
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_3fPoint pt;
        if( VariantToPoint(pvData[i], pt) )
	        arr.Append( pt );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToPointArray( SAFEARRAY* psa, ON_4dPointArray& arr )
{
  ASSERT( psa );
  arr.Empty();

	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( FAILED(hl) || FAILED(hu) )
    return 0;

  VARIANT va;
  VariantInit( &va );
  HRESULT hr = SafeArrayGetElement( psa, &lower, &va );
  if( FAILED(hr) )
    return 0;

  bool bIsNumber = IsVariantNumber( va );
  VariantClear( &va );
  if( bIsNumber )
  {
    int stride = 4;
    ON_SimpleArray<double> vals;
    int count = VariantToArray(va, vals);
    if( count && count % stride == 0 )
    {
      int i, point_count = count / stride;
      arr.SetCapacity( point_count );
      arr.SetCount( point_count );
      ON_4dPoint pt( 0.0, 0.0, 0.0, 0.0 );
      const double* ptr = vals.Array();
      for( i = 0; i < point_count; i++ )
      {
        pt.x = ptr[0];
        pt.y = ptr[1];
        pt.z = ptr[2];
        pt.w = ptr[3];
        arr[i] = pt;
        ptr += stride;
      }
      return arr.Count();
    }
    else
		  return 0;
  }
  else
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_4dPoint pt;
        if( VariantToPoint(pvData[i], pt) )
	        arr.Append( pt );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int VariantArrayToPointArray( SAFEARRAY* psa, ON_4fPointArray& arr )
{
  ASSERT( psa );
  arr.Empty();

	long i, lower, upper;
	HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
	HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( FAILED(hl) || FAILED(hu) )
    return 0;

  VARIANT va;
  VariantInit( &va );
  HRESULT hr = SafeArrayGetElement( psa, &lower, &va );
  if( FAILED(hr) )
    return 0;

  bool bIsNumber = IsVariantNumber( va );
  VariantClear( &va );
  if( bIsNumber )
  {
    int stride = 4;
    ON_SimpleArray<float> vals;
    int count = VariantToArray(va, vals);
    if( count && count % stride == 0 )
    {
      int i, point_count = count / stride;
      arr.SetCapacity( point_count );
      arr.SetCount( point_count );
      ON_4fPoint pt( 0.0, 0.0, 0.0, 0.0 );
      const float* ptr = vals.Array();
      for( i = 0; i < point_count; i++ )
      {
        pt.x = ptr[0];
        pt.y = ptr[1];
        pt.z = ptr[2];
        pt.w = ptr[3];
        arr[i] = pt;
        ptr += stride;
      }
      return arr.Count();
    }
    else
		  return 0;
  }
  else
  {
    arr.SetCapacity( upper - lower + 1 );
    VARIANT* pvData = 0;
    hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
    if( SUCCEEDED(hr) && pvData )
    {
	    for( i = lower; i <= upper; i++ )
	    {
        ON_4fPoint pt;
        if( VariantToPoint(pvData[i], pt) )
	        arr.Append( pt );
      }
      SafeArrayUnaccessData( psa );
    }
  }

  return arr.Count();
}

int SafeArrayToBooleanArray( SAFEARRAY* psa, ON_SimpleArray<bool>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
  HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
  HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARTYPE vt = 0;
    HRESULT hr = SafeArrayGetVartype( psa, &vt );
    if( SUCCEEDED(hr) )
    {
      if( vt == VT_BOOL )
      {
        VARIANT_BOOL* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( pvData[i] == VARIANT_TRUE ? true : false );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I4 )
      {
        long* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( pvData[i] ? true : false );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I2 )
      {
        short* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( pvData[i] ? true : false );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R8 )
      {
        double* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( pvData[i] ? true : false );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R4 )
      {
        float* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( pvData[i] ? true : false );
          SafeArrayUnaccessData( psa );
        }
      }
    }
  }
  return arr.Count();
}

int SafeArrayToIntegerArray( SAFEARRAY* psa, ON_SimpleArray<int>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
  HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
  HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARTYPE vt = 0;
    HRESULT hr = SafeArrayGetVartype( psa, &vt );
    if( SUCCEEDED(hr) )
    {
      if( vt == VT_I4 )
      {
        long* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (int)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I2 )
      {
        short* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (int)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R8 )
      {
        double* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (int)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R4 )
      {
        float* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (int)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
    }
  }
  return arr.Count();
}

int SafeArrayToFloatArray( SAFEARRAY* psa, ON_SimpleArray<float>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
  HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
  HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARTYPE vt = 0;
    HRESULT hr = SafeArrayGetVartype( psa, &vt );
    if( SUCCEEDED(hr) )
    {
      if( vt == VT_R8 )
      {
        double* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (float)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R4 )
      {
        float* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (float)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I4 )
      {
        long* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (float)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I2 )
      {
        short* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (float)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
    }
  }
  return arr.Count();
}

int SafeArrayToDoubleArray( SAFEARRAY* psa, ON_SimpleArray<double>& arr )
{
  ASSERT( psa );
  arr.Empty();
  long i, lower, upper;
  HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
  HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
  if( SUCCEEDED(hl) && SUCCEEDED(hu) )
  {
    arr.SetCapacity( upper - lower + 1 );
    VARTYPE vt = 0;
    HRESULT hr = SafeArrayGetVartype( psa, &vt );
    if( SUCCEEDED(hr) )
    {
      if( vt == VT_R8 )
      {
        double* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (double)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_R4 )
      {
        float* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (double)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I4 )
      {
        long* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (double)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
      else if( vt == VT_I2 )
      {
        short* pvData = 0;
        hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
        if( SUCCEEDED(hr) && pvData )
        {
          for( i = lower; i <= upper; i++ )
            arr.Append( (double)pvData[i] );
          SafeArrayUnaccessData( psa );
        }
      }
    }
  }
  return arr.Count();
}

int SafeArrayToStringArray( SAFEARRAY* psa, ON_ClassArray<ON_wString>& arr )
{
  ASSERT( psa );
  arr.Empty();
  if( psa->fFeatures & FADF_BSTR )
  {
    long i, lower, upper;
    HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
    HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
    if( SUCCEEDED(hl) && SUCCEEDED(hu) )
    {
      arr.SetCapacity( upper - lower + 1 );
      BSTR* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        for( i = lower; i <= upper; i++ )
        {
          ON_wString str( pvData[i] );
          if( !str.IsEmpty() )
            arr.Append( str );
        }
        SafeArrayUnaccessData( psa );
      }
    }
  }
  return arr.Count();
}

int SafeArrayToStringArray( SAFEARRAY* psa, CStringArray& arr )
{
  ASSERT( psa );
  arr.RemoveAll();
  if( psa->fFeatures & FADF_BSTR )
  {
    long i, lower, upper;
    HRESULT hl = SafeArrayGetLBound( psa, 1, &lower );
    HRESULT hu = SafeArrayGetUBound( psa, 1, &upper );
    if( SUCCEEDED(hl) && SUCCEEDED(hu) )
    {
      BSTR* pvData = 0;
      HRESULT hr = SafeArrayAccessData( psa, (void HUGEP**)&pvData );
      if( SUCCEEDED(hr) && pvData )
      {
        for( i = lower; i <= upper; i++ )
        {
          CString str( pvData[i] );
          if( !str.IsEmpty() )
            arr.Add( str );
        }
        SafeArrayUnaccessData( psa );
      }
    }
  }
  return (int)arr.GetCount();
}

bool SafeArrayToPoint( SAFEARRAY* psa, ON_2dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  ON_SimpleArray<double> arr;
  int count = SafeArrayToDoubleArray( psa, arr );
  if( count > 1 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    rc = true;
  }
  return rc;
}

bool SafeArrayToPoint( SAFEARRAY* psa, ON_3dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  ON_SimpleArray<double> arr;
  int count = SafeArrayToDoubleArray( psa, arr );
  if( count == 2 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = 0.0;
    rc = true;
  }
  else if( count > 2 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    rc = true;
  }
  return rc;
}

bool SafeArrayToPoint( SAFEARRAY* psa, ON_3fPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  ON_SimpleArray<float> arr;
  int count = SafeArrayToFloatArray( psa, arr );
  if( count == 2 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = 0.0;
    rc = true;
  }
  else if( count > 2 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    rc = true;
  }
  return rc;
}

bool SafeArrayToPoint( SAFEARRAY* psa, ON_4dPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  ON_SimpleArray<double> arr;
  int count = SafeArrayToDoubleArray( psa, arr );
  if( count == 3 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    pt.w = 0.0;
    rc = true;
  }
  else if( count > 3 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    pt.w = arr[3];
    rc = true;
  }
  return rc;
}

bool SafeArrayToPoint( SAFEARRAY* psa, ON_4fPoint& pt )
{
  ASSERT( psa );
  bool rc = false;
  ON_SimpleArray<float> arr;
  int count = SafeArrayToFloatArray( psa, arr );
  if( count == 3 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    pt.w = 0.0;
    rc = true;
  }
  else if( count > 3 )
  {
    pt.x = arr[0];
    pt.y = arr[1];
    pt.z = arr[2];
    pt.w = arr[3];
    rc = true;
  }
  return rc;
}

int SafeArrayToPointArray( SAFEARRAY* psa, ON_2dPointArray& arr )
{
  ASSERT( psa );
  int rc = 0;
  ON_SimpleArray<double> vals;
  int count = SafeArrayToDoubleArray( psa, vals );
  int stride = 2;
  if( count && count % stride == 0 )
  {
    int i, point_count = count / stride;
    arr.SetCapacity( point_count );
    arr.SetCount( point_count );
    ON_2dPoint pt( 0.0, 0.0 );
    const double* ptr = vals.Array();
    for( i = 0; i < point_count; i++ )
    {
      pt.x = ptr[0];
      pt.y = ptr[1];
      arr[i] = pt;
      ptr += stride;
    }
    rc = arr.Count();
  }
  return rc;
}

int SafeArrayToPointArray( SAFEARRAY* psa, ON_3dPointArray& arr )
{
  ASSERT( psa );
  int rc = 0;
  ON_SimpleArray<double> vals;
  int count = SafeArrayToDoubleArray( psa, vals );
  int stride = 3;
  if( count && count % stride == 0 )
  {
    int i, point_count = count / stride;
    arr.SetCapacity( point_count );
    arr.SetCount( point_count );
    ON_3dPoint pt( 0.0, 0.0, 0.0 );
    const double* ptr = vals.Array();
    for( i = 0; i < point_count; i++ )
    {
      pt.x = ptr[0];
      pt.y = ptr[1];
      pt.z = ptr[2];
      arr[i] = pt;
      ptr += stride;
    }
    rc = arr.Count();
  }
  return rc;
}

int SafeArrayToPointArray( SAFEARRAY* psa, ON_3fPointArray& arr )
{
  ASSERT( psa );
  int rc = 0;
  ON_SimpleArray<float> vals;
  int count = SafeArrayToFloatArray( psa, vals );
  int stride = 3;
  if( count && count % stride == 0 )
  {
    int i, point_count = count / stride;
    arr.SetCapacity( point_count );
    arr.SetCount( point_count );
    ON_3fPoint pt( 0.0, 0.0, 0.0 );
    const float* ptr = vals.Array();
    for( i = 0; i < point_count; i++ )
    {
      pt.x = ptr[0];
      pt.y = ptr[1];
      pt.z = ptr[2];
      arr[i] = pt;
      ptr += stride;
    }
    rc = arr.Count();
  }
  return rc;
}

int SafeArrayToPointArray( SAFEARRAY* psa, ON_4dPointArray& arr )
{
  ASSERT( psa );
  int rc = 0;
  ON_SimpleArray<double> vals;
  int count = SafeArrayToDoubleArray( psa, vals );
  int stride = 4;
  if( count && count % stride == 0 )
  {
    int i, point_count = count / stride;
    arr.SetCapacity( point_count );
    arr.SetCount( point_count );
    ON_4dPoint pt( 0.0, 0.0, 0.0, 0.0 );
    const double* ptr = vals.Array();
    for( i = 0; i < point_count; i++ )
    {
      pt.x = ptr[0];
      pt.y = ptr[1];
      pt.z = ptr[2];
      pt.w = ptr[3];
      arr[i] = pt;
      ptr += stride;
    }
    rc = arr.Count();
  }
  return rc;
}

int SafeArrayToPointArray( SAFEARRAY* psa, ON_4fPointArray& arr )
{
  ASSERT( psa );
  int rc = 0;
  ON_SimpleArray<float> vals;
  int count = SafeArrayToFloatArray( psa, vals );
  int stride = 3;
  if( count && count % stride == 0 )
  {
    int i, point_count = count / stride;
    arr.SetCapacity( point_count );
    arr.SetCount( point_count );
    ON_4fPoint pt( 0.0, 0.0, 0.0, 0.0 );
    const float* ptr = vals.Array();
    for( i = 0; i < point_count; i++ )
    {
      pt.x = ptr[0];
      pt.y = ptr[1];
      pt.z = ptr[2];
      pt.w = ptr[3];
      arr[i] = pt;
      ptr += stride;
    }
    rc = arr.Count();
  }
  return rc;
}


