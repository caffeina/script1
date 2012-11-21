// DialogPV.cpp : file di implementazione
//

#include "stdafx.h"
#include "DialogPV.h"


// finestra di dialogo DialogPV

IMPLEMENT_DYNAMIC(DialogPV, CDialog)

DialogPV::DialogPV(CWnd* pParent /*=NULL*/)
	: CRhinoDialog(DialogPV::IDD, pParent)
	
{

}

DialogPV::~DialogPV()
{
}

void DialogPV::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(DialogPV, CDialog)
	
END_MESSAGE_MAP()


// gestori di messaggi DialogPV


void DialogPV::KillDialog()
{
  //OnCancel();
	RhinoApp().CommandCanceled();
}
void DialogPV::OnEnChangeEdit2()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPV::OnEnChangeEdit3()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}
