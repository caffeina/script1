#pragma once
#include "Resource.h"
#include "afxwin.h"

// finestra di dialogo DialogPV

class DialogPV : public CRhinoDialog
{
	DECLARE_DYNAMIC(DialogPV)

public:
	DialogPV(CWnd* pParent = NULL);   // costruttore standard
	virtual ~DialogPV();

// Dati della finestra di dialogo
	enum { IDD = IDD_DIALOG2 };
	void KillDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Supporto DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString EstLineaDx;
public:
	afx_msg void OnEnChangeEdit2();
public:
	CString EstLineaSx;
public:
	afx_msg void OnEnChangeEdit3();
public:
	CString EstRettaPolilineaDx;
public:
	CString EstRettaPolilineaSx;
public:
	CString AngoloAlphaDx;
public:
	CString AngoloBetaSx;
public:
	CString FilletDx;
public:
	CString FilletSx;
};
