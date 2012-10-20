/////////////////////////////////////////////////////////////////////////////
// script1PlugIn.cpp : defines the initialization routines for the plug-in.
//

#include "StdAfx.h"
#include "script1App.h"
#include "script1PlugIn.h"

// The plug-in object must be constructed before any plug-in classes
// derived from CRhinoCommand. The #pragma init_seg(lib) ensures that
// this happens.

#pragma warning( push )
#pragma warning( disable : 4073 )
#pragma init_seg( lib )
#pragma warning( pop )

// Rhino plug-in declaration
RHINO_PLUG_IN_DECLARE

// Rhino plug-in name
// Provide a short, friendly name for this plug-in.
RHINO_PLUG_IN_NAME( L"script1" );

// Rhino plug-in id
// Provide a unique uuid for this plug-in
RHINO_PLUG_IN_ID( L"E58CD7A6-B13B-45E5-AEF8-F18F1FB76174" );

// Rhino plug-in version
// Provide a version number string for this plug-in
RHINO_PLUG_IN_VERSION( __DATE__"  "__TIME__ )

// Rhino plug-in developer declarations
// TODO: fill in the following developer declarations with
// your company information. Note, all of these declarations
// must be present or your plug-in will not load.
//
// When completed, delete the following #error directive.
//#error Developer declarations block is incomplete!
RHINO_PLUG_IN_DEVELOPER_ORGANIZATION( L"OutOfFire" );
RHINO_PLUG_IN_DEVELOPER_ADDRESS( L"vuoto" );
RHINO_PLUG_IN_DEVELOPER_COUNTRY( L"italia" );
RHINO_PLUG_IN_DEVELOPER_PHONE( L"+3396766505" );
RHINO_PLUG_IN_DEVELOPER_FAX( L"vuoto" );
RHINO_PLUG_IN_DEVELOPER_EMAIL( L"aniello.iarnone@gmail.com" );
RHINO_PLUG_IN_DEVELOPER_WEBSITE( L"anielloiarnone.blogspot.com" );
RHINO_PLUG_IN_UPDATE_URL( L"anielloiarnone.blogspot.com" );

// The one and only Cscript1PlugIn object
static Cscript1PlugIn thePlugIn;

/////////////////////////////////////////////////////////////////////////////
// Cscript1PlugIn definition

Cscript1PlugIn& script1PlugIn()
{ 
  // Return a reference to the one and only Cscript1PlugIn object
  return thePlugIn; 
}



Cscript1PlugIn::Cscript1PlugIn()
{
  // Description:
  //   Cscript1PlugIn constructor. The constructor is called when the
  //   plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
  //   is loaded, Cscript1PlugIn::OnLoadPlugIn() is called. The 
  //   constructor should be simple and solid. Do anything that might fail in
  //   Cscript1PlugIn::OnLoadPlugIn().

  // TODO: Add construction code here
  m_plugin_version = RhinoPlugInVersion();
}

Cscript1PlugIn::~Cscript1PlugIn()
{
  // Description:
  //   Cscript1PlugIn destructor. The destructor is called to destroy
  //   "thePlugIn" when the plug-in is unloaded. Immediately before the
  //   DLL is unloaded, Cscript1PlugIn::OnUnloadPlugin() is called. Do
  //   not do too much here. Be sure to clean up any memory you have allocated
  //   with onmalloc(), onrealloc(), oncalloc(), or onstrdup().

  // TODO: Add destruction code here
}

/////////////////////////////////////////////////////////////////////////////
// Required overrides

const wchar_t* Cscript1PlugIn::PlugInName() const
{
  // Description:
  //   Plug-in name display string.  This name is displayed by Rhino when
  //   loading the plug-in, in the plug-in help menu, and in the Rhino 
  //   interface for managing plug-ins.

  // TODO: Return a short, friendly name for the plug-in.
  return RhinoPlugInName();
}

const wchar_t* Cscript1PlugIn::PlugInVersion() const
{
  // Description:
  //   Plug-in version display string. This name is displayed by Rhino 
  //   when loading the plug-in and in the Rhino interface for managing
  //   plug-ins.

  // TODO: Return the version number of the plug-in.
  return m_plugin_version;
}

GUID Cscript1PlugIn::PlugInID() const
{
  // Description:
  //   Plug-in unique identifier. The identifier is used by Rhino to
  //   manage the plug-ins.

  // TODO: Return a unique identifier for the plug-in.
  // {E58CD7A6-B13B-45E5-AEF8-F18F1FB76174}
  return ON_UuidFromString( RhinoPlugInId() );
}

BOOL Cscript1PlugIn::OnLoadPlugIn()
{
  // Description:
  //   Called after the plug-in is loaded and the constructor has been
  //   run. This is a good place to perform any significant initialization,
  //   license checking, and so on.  This function must return TRUE for
  //   the plug-in to continue to load.

  // TODO: Add plug-in initialization code here.
  return CRhinoUtilityPlugIn::OnLoadPlugIn();
}


void Cscript1PlugIn::OnSaveAllSettings()
{
  DestroyDlg();
}


void Cscript1PlugIn::OnUnloadPlugIn()
{
  // Description:
  //   Called when the plug-in is about to be unloaded.  After
  //   this function is called, the destructor will be called.

  // TODO: Add plug-in cleanup code here.
  CRhinoUtilityPlugIn::OnUnloadPlugIn();
}

/////////////////////////////////////////////////////////////////////////////
// Online help overrides

BOOL Cscript1PlugIn::AddToPlugInHelpMenu() const
{
  // Description:
  //   Return true to have your plug-in name added to the Rhino help menu.
  //   OnDisplayPlugInHelp will be called when to activate your plug-in help.

  return TRUE;
}

BOOL Cscript1PlugIn::OnDisplayPlugInHelp( HWND hWnd ) const
{
  // Description:
  //   Called when the user requests help about your plug-in.
  //   It should display a standard Windows Help file (.hlp or .chm).

  // TODO: Add support for online help here.
  return CRhinoUtilityPlugIn::OnDisplayPlugInHelp( hWnd );
}

// aggiunta metodi per finestre modeless

bool Cscript1PlugIn::IsDlgCreated()
{
  bool rc = false;
  if( m_dialog && ::IsWindow(m_dialog->m_hWnd) )
    rc = true;
  return rc;
}

bool Cscript1PlugIn::IsDlgVisible()
{
  bool rc = false;
  if( IsDlgCreated() && m_dialog->IsWindowVisible() )
    rc = true;
  return rc;

}

bool Cscript1PlugIn::SetDlgVisible()
{
  bool rc = false;
  if( IsDlgCreated() && !IsDlgVisible() )
  {
    m_dialog->ShowWindow( SW_SHOWNORMAL );
    m_dialog->SetFocus();
    rc = true;
  }
  return rc;
}

bool Cscript1PlugIn::SetDlgHidden()
{
  bool rc = false;
  if( IsDlgCreated() && IsDlgVisible() )
  {
    m_dialog->ShowWindow( SW_HIDE );
    ::SetFocus( RhinoApp().MainWnd() );
    rc = true;
  }
  return rc;
}

bool Cscript1PlugIn::DisplayDlg()// tolto parametro CRhinoDoc& m_doc
{
	AFX_MANAGE_STATE( AfxGetStaticModuleState() );

  if( IsDlgCreated() )
  {
    if( !IsDlgVisible() )
      SetDlgVisible();
    m_dialog->SetFocus();
    return true;
  }

	m_dialog = new DialogPrincipale( CWnd::FromHandle(RhinoApp().MainWnd()) ); // tolto m_doc come parametro
	if( m_dialog->Create(IDD_DIALOG1, CWnd::FromHandle(RhinoApp().MainWnd())) )
	{
		m_dialog->ShowWindow( SW_SHOW );
		m_dialog->UpdateWindow();
		m_dialog->SetFocus();
		return true;
	}

	return false;
}


void Cscript1PlugIn::DestroyDlg()
{
  if( IsDlgCreated() )
  {
    m_dialog->KillDialog();
    m_dialog = 0;
  }
}


void Cscript1PlugIn::ZeroDlg()
{
  m_dialog = 0;
}
