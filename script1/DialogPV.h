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

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Supporto DDX/DDV

	DECLARE_MESSAGE_MAP()
};
