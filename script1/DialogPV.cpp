// DialogPV.cpp : file di implementazione
//

#include "stdafx.h"
#include "DialogPV.h"


// finestra di dialogo DialogPV

IMPLEMENT_DYNAMIC(DialogPV, CDialog)

DialogPV::DialogPV(CWnd* pParent /*=NULL*/)
	: CRhinoDialog(DialogPV::IDD, pParent)
	, EstLineaDx(_T("5"))
	, EstLineaSx(_T("15"))
	, EstRettaPolilineaDx(_T("80"))
	, EstRettaPolilineaSx(_T("80"))
	, AngoloAlphaDx(_T("30"))
	, AngoloBetaSx(_T("40"))
	, FilletDx(_T("6"))
	, FilletSx(_T("13"))
{

}

DialogPV::~DialogPV()
{
}

void DialogPV::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, EstLineaDx);
	DDX_Text(pDX, IDC_EDIT3, EstLineaSx);
	DDX_Text(pDX, IDC_EDIT6, EstRettaPolilineaDx);
	DDX_Text(pDX, IDC_EDIT7, EstRettaPolilineaSx);
	DDX_Text(pDX, IDC_EDIT8, AngoloAlphaDx);
	DDX_Text(pDX, IDC_EDIT9, AngoloBetaSx);
	DDX_Text(pDX, IDC_EDIT10, FilletDx);
	DDX_Text(pDX, IDC_EDIT11, FilletSx);
}


BEGIN_MESSAGE_MAP(DialogPV, CDialog)
	ON_EN_CHANGE(IDC_EDIT2, &DialogPV::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &DialogPV::OnEnChangeEdit3)
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
