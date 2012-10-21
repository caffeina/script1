/////////////////////////////////////////////////////////////////////////////
// TestUserData.cpp

#include "StdAfx.h"
#include "TestUserData.h"
#include "script1PlugIn.h"

// Opennurbs classes that are saved in .3dm files require
// an ON_OBJECT_IMPLEMENT() call in their implmentation.
// Use Microsoft's guidgen to create the id.
ON_OBJECT_IMPLEMENT( CTestUserData, ON_UserData, "A001FCCA-C3EF-4bb2-95F6-B8C2D47EA077" );

ON_UUID CTestUserData::Id()
{
  return CTestUserData::m_CTestUserData_class_id.Uuid();
}

CTestUserData::CTestUserData()
{
  m_userdata_uuid = CTestUserData::Id();
  m_application_uuid = script1PlugIn().PlugInID();
  m_userdata_copycount = 1; // enable copying

  // initialize your data members here
  m_my_point.Set(0.0,0.0,0.0);
}

CTestUserData::~CTestUserData()
{
}

CTestUserData::CTestUserData(const CTestUserData& src) : ON_UserData(src)
{
  m_userdata_uuid = CTestUserData::Id();
  m_application_uuid = script1PlugIn().PlugInID();

  // All other ON_UserData fields are correctly initialized by 
  // the ON_UserData(src) call. In fact, if src is 
  // a CTestUserData class, then ALL ON_UserData fields are 
  // correctly initialized by ON_UserData(src).  
  // The next 4 lines are here to handle the rare case 
  // when a class derived from CTestUserData is passed as src.

  // copy your data members here.
  m_my_string = src.m_my_string;
  m_my_point = src.m_my_point;
}

CTestUserData& CTestUserData::operator=(const CTestUserData& src)
{
  // NEVER set m_userdata_uuid or m_application_uuid
  // in an operator=.  These values are set when the
  // class is constructed and should not be changed.
  if ( this != &src )
  {
    // Use the base class to copy all appropriate 
    // ON_UserData fields.
    ON_UserData::operator=(src);

    // Explictly copy ONLY members you added to
    // the CTestUserData class.
    m_my_string = src.m_my_string;
    m_my_point = src.m_my_point;
  }
  return *this;
}

BOOL CTestUserData::GetDescription( ON_wString& description )
{
  description = L"Test user data";
  return true;
}

BOOL CTestUserData::Archive() const 
{
  // If false is returned, nothing will be saved in
  // 3dm archives.
  return true;
}

BOOL CTestUserData::Write(
       ON_BinaryArchive& binary_archive
     ) const
{
  int minor_version = 0;
  bool rc = binary_archive.BeginWrite3dmChunk(
                TCODE_ANONYMOUS_CHUNK,
                1,
                minor_version
                );
  if (!rc)
    return false;

  // Write class members like this
  for (;;)
  {
    // version 1.0 fields
    rc = binary_archive.WriteString(m_my_string);
    if (!rc) break;

    rc = binary_archive.WritePoint(m_my_point);
    if (!rc) break;

    // If you add data members to CTestUserData after you 
    // have released a product, simply increment minor_version
    // by one, and write the new information.  This way you
    // can enhance your user data over several versions of
    // your product without breaking file IO.  It is CRITICAL
    // that once you write something to a customer's .3dm
    // file, you continue to write it the same way for all
    // future versions.
    
    // version 1.1 fields added DD MMM YYYY
    // rc = binary_archive.WriteSomethingNew( ... );
    // if (!rc) break;
    // rc = binary_archive.WriteSomethingElseNew( ... );
    // if (!rc) break;
    
    // version 1.2 fields added DD MMM YYYY
    // rc = binary_archive.WriteAnotherSomethingNew( ... );
    // if (!rc) break;
    // rc = binary_archive.WriteAnotherSomethingElseNew( ... );
    // if (!rc) break;

    break;
  }

  // If BeginWrite3dmChunk() returns true,
  // then EndWrite3dmChunk() must be called, 
  // even if a write operation failed.
  if ( !binary_archive.EndWrite3dmChunk() )
    rc = false;

  return rc;
}

BOOL CTestUserData::Read(
       ON_BinaryArchive& binary_archive
     )
{
  int major_version = 0;
  int minor_version = 0;
  bool rc = binary_archive.BeginRead3dmChunk(
                TCODE_ANONYMOUS_CHUNK,
                &major_version,
                &minor_version
                );
  if (!rc)
    return false;

  // Read class members like this
  for (;;)
  {
    rc = ( 1 == major_version );
    if (!rc) break;

    // version 1.0 fields
    rc = binary_archive.ReadString(m_my_string);
    if (!rc) break;

    rc = binary_archive.ReadPoint(m_my_point);
    if (!rc) break;

    // The code in the comment below demonstrates how to
    // correctly read information added in later releases
    // of your product.
    //if ( minor_version >= 1 )
    //{
    //  // version 1.1 fields added DD MMM YYYY
    //  rc = binary_archive.ReadSomethingNew( ... );
    //  if (!rc) break;
    //  rc = binary_archive.ReadSomethingElseNew( ... );
    //  if (!rc) break;
    //  
    //  if ( minor_version >= 2 )
    //  {
    //    // version 1.2 fields added DD MMM YYYY
    //    rc = binary_archive.ReadAnotherSomethingNew( ... );
    //    if (!rc) break;
    //    rc = binary_archive.ReadAnotherSomethingElseNew( ... );
    //    if (!rc) break;
    //  }
    //}

    break;
  }

  // If BeginRead3dmChunk() returns true,
  // then EndRead3dmChunk() must be called, 
  // even if a read operation failed.
  if ( !binary_archive.EndRead3dmChunk() )
    rc = false;

  return rc;
}
