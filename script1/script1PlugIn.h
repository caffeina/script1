/////////////////////////////////////////////////////////////////////////////
// script1PlugIn.h : main header file for the script1 plug-in
//

#pragma once

#include "DialogPrincipale.h"

/////////////////////////////////////////////////////////////////////////////
// Cscript1PlugIn
// See script1PlugIn.cpp for the implementation of this class
//

class Cscript1PlugIn : public CRhinoUtilityPlugIn
{
public:
  Cscript1PlugIn();
  ~Cscript1PlugIn();

  // Required overrides
  const wchar_t* PlugInName() const;
  const wchar_t* PlugInVersion() const;
  GUID PlugInID() const;
  BOOL OnLoadPlugIn();
  void OnUnloadPlugIn();

  void OnSaveAllSettings();

  // Online help overrides
  BOOL AddToPlugInHelpMenu() const;
  BOOL OnDisplayPlugInHelp( HWND hWnd ) const;

	// Modeless dialog helpers
  bool IsDlgCreated();
  bool IsDlgVisible();
  bool SetDlgVisible();
  bool SetDlgHidden();
  bool DisplayDlg(); // tolto CRhinoDoc& m_doc
  void DestroyDlg();
  void ZeroDlg();
  void SetDlgPointValue( int item, const ON_3dPoint& pt );

  /*DEFINIZIONE PROPRIETÀ*/
  void setVarAltezzaTacco(CString);
  int  getVarAltezzaTacco(void);

public:
  ON_wString m_plugin_version;
  DialogPrincipale* m_dialog;

  // TODO: Add additional class information here
};

Cscript1PlugIn& script1PlugIn();



