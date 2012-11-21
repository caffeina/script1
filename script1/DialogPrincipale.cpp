// DialogPrincipale.cpp : file di implementazione
//

#include "stdafx.h"
#include "DialogPrincipale.h"
#include "Resource.h"
//#include "DialogPV.h"


// finestra di dialogo DialogPrincipale

IMPLEMENT_DYNAMIC(DialogPrincipale, CDialog)

DialogPrincipale::DialogPrincipale(CWnd* pParent)
	: CRhinoDialog(DialogPrincipale::IDD, pParent)  
	, VAR_Valore_Disassamento(0) 
	, VAR_Altezza_Tacco(_T("140"))
	, StatusRadio1_Centrale(0)
	, StatusRadio3_Iniezione_Centrale(0)
	, StatusRadio7_Fondello_di_ferro(0)
	, ValIniezioneDisassamento(_T("+12"))
	, ValoreAltezzaFondello(_T("20"))
	, ValoreTraslazione(_T(""))
	, ValoreRotazione(_T(""))
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

DialogPrincipale::~DialogPrincipale()
{
}

void DialogPrincipale::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT2, VAR_Valore_Disassamento);
	DDV_MinMaxInt(pDX, VAR_Valore_Disassamento, -12, +12);
	DDX_CBString(pDX, IDC_CMBAltezzaTacco, VAR_Altezza_Tacco);
	DDX_CBString(pDX, IDC_CMBAltezzaFondello, ValoreAltezzaFondello);
	DDX_Control(pDX, IDC_CMBAltezzaTacco, m_comboAltTacco);
	DDX_Radio(pDX, IDC_RADIO1, StatusRadio1_Centrale);
	DDX_Radio(pDX, IDC_RADIO2, StatusRadio2_Dissasata);
	DDX_Radio(pDX, IDC_RADIO3, StatusRadio3_Iniezione_Centrale);
	DDX_Radio(pDX, IDC_RADIO4, StatusRadio4_Iniezione_Disassata);
	DDX_Radio(pDX, IDC_RADIO7, StatusRadio7_Fondello_di_ferro);
	DDX_Radio(pDX, IDC_RADIO8, StatusRadio8_Fondello_di_alluminio);
	DDX_CBString(pDX, IDC_COMBO1, ValIniezioneDisassamento);
	DDX_Control(pDX, IDC_CHECK1, StatusCheckTaccoSpina);
	DDX_Text(pDX, IDC_EDIT4, ValoreTraslazione);
	DDX_Text(pDX, IDC_EDIT5, ValoreRotazione);
	DDX_Control(pDX, IDC_CMBAltezzaFondello, AltezzaFondelloControllo);
	DDX_Text(pDX, IDC_EDIT12, EstLineaDx);
	DDX_Text(pDX, IDC_EDIT3, EstLineaSx);
	DDX_Text(pDX, IDC_EDIT6, EstRettaPolilineaDx);
	DDX_Text(pDX, IDC_EDIT7, EstRettaPolilineaSx);
	DDX_Text(pDX, IDC_EDIT8, AngoloAlphaDx);
	DDX_Text(pDX, IDC_EDIT9, AngoloBetaSx);
	DDX_Text(pDX, IDC_EDIT10, FilletDx);
	DDX_Text(pDX, IDC_EDIT11, FilletSx);
}


BEGIN_MESSAGE_MAP(DialogPrincipale, CDialog)
	ON_BN_CLICKED(IDCANCEL, &DialogPrincipale::OnBnClickedCancel)	
	ON_CBN_SELCHANGE(IDC_COMBO1, &DialogPrincipale::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_CMBAltezzaFondello, &DialogPrincipale::OnCbnSelchangeCmbaltezzafondello)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogPrincipale::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &DialogPrincipale::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT2, &DialogPrincipale::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &DialogPrincipale::OnBnClickedOk)
	
	ON_CBN_SELCHANGE(IDC_CMBAltezzaTacco, &DialogPrincipale::OnCbnSelchangeCmbaltezzatacco)
	ON_BN_CLICKED(IDC_RADIO3, &DialogPrincipale::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &DialogPrincipale::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO7, &DialogPrincipale::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO2, &DialogPrincipale::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO4, &DialogPrincipale::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO8, &DialogPrincipale::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_CHECK1, &DialogPrincipale::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_RICHEDIT21, &DialogPrincipale::OnEnChangeRichedit21)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogPrincipale::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_CMBAltezzaFondello, &DialogPrincipale::OnCbnSelchangeCmbaltezzafondello)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogPrincipale::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT4, &DialogPrincipale::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &DialogPrincipale::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON5, &DialogPrincipale::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &DialogPrincipale::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &DialogPrincipale::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &DialogPrincipale::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON14, &DialogPrincipale::OnBnClickedButton14)
	
END_MESSAGE_MAP()


// gestori di messaggi DialogPrincipale

void DialogPrincipale::OnBnClickedCancel()
{
	OnCancel();
	//RhinoApp().RunScript( L"! _Undo", 0 );
}



void DialogPrincipale::OnCbnSelchangeCombo1()
{
	UpdateData(true);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnCbnSelchangeCombo5()
{
	UpdateData(true);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton1()
{	
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	UpdateData(true);
	 RhinoApp().RunScript( L"! _GenPianoVis", 0 );

 
}/*CHIUSURA DIALOGPRINCIPALE::ONBNCLICKEDBUTTON1*/

void DialogPrincipale::OnCbnSelchangeCombo2()
{
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeEdit2()
{
	UpdateData (TRUE);
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::KillDialog()
{
  //OnCancel();
	RhinoApp().CommandCanceled();
}
void DialogPrincipale::OnBnClickedOk()
{
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
	OnOK();
}

void DialogPrincipale::OnEnChangeEdit3()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnCbnSelchangeCmbaltezzatacco()
{
	UpdateData(true);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio3()
{
	UpdateData (TRUE);
	
	
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio1()
{	
	UpdateData (TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	StatusRadio7_Fondello_di_ferro = 0;
	StatusRadio8_Fondello_di_alluminio = -1;
	StatusRadio4_Iniezione_Disassata = 0;
	StatusRadio3_Iniezione_Centrale = -1;
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	UpdateData (FALSE);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio7()
{
	UpdateData (TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio2()
{
	UpdateData (TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	StatusRadio8_Fondello_di_alluminio = 0;
	StatusRadio7_Fondello_di_ferro = -1;
	StatusRadio4_Iniezione_Disassata = -1;
	StatusRadio3_Iniezione_Centrale = 0;
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	UpdateData (FALSE);

	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio4()
{
	UpdateData (TRUE);
	
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedRadio8()
{
	UpdateData (TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
}

void DialogPrincipale::OnBnClickedCheck1()
{
	if (CWnd::IsDlgButtonChecked(IDC_CHECK1) ) {
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO7)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO1)->EnableWindow(TRUE);
	//GetDlgItem(IDC_RADIO2)->GetCheckedRadioButton(IDC_RADIO2,IDC_RADIO2);
	StatusRadio2_Dissasata = 0;
	StatusRadio1_Centrale = -1;
	//CheckRadioButton(IDC_RADIO2,IDC_RADIO2,IDC_RADIO2);
	UpdateData(FALSE);
	}
	else {
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	}

	
	

	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeRichedit21()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton2()
{
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	UpdateData(true);
	RhinoApp().RunScript( L"! _GenCylinder", 0 );
}

void DialogPrincipale::OnCbnSelchangeCmbaltezzafondello()
{
	UpdateData(true);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton3()
{
		RhinoApp().RunScript( L"! _TraslaRuota", 0 );

	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeEdit4()
{
	UpdateData(true);
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeEdit5()
{
	UpdateData(true);
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invierà questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton5()
{
	//RhinoApp().RunScript( L"! _TCone", 0 );
	UpdateData(true);
	RhinoApp().RunScript( L"! _GenUgello", 0 );
	//RhinoApp().EnterCommand
	//RhinoApp().ExecuteCommand
	//RhinoApp().
	//RhinoApp().RunMenuScript( L"! d");
	//RhinoApp().RunScript( L"! _d", 0 );
	//RhinoApp().RunScript( L"! _6,5", 0 );
	//RhinoApp().Print( L"LAYER \ DOES NOT EXIST.\n" );



}

void DialogPrincipale::OnBnClickedButton6()
{
	 /*DialogPV dlg( CWnd::FromHandle(::RhinoApp().MainWnd()) );
	 dlg.DoModal();*/
	/*GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	UpdateData(true);
	RhinoApp().RunScript( L"! _DialogPV", 0 );*/

  
}

void DialogPrincipale::OnBnClickedButton8()
{
	RhinoApp().RunScript( L"! _TrimCylinder", 0);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton7()
{
	RhinoApp().RunScript( L"! _superUNDO", 0);
	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton14()
{
	RhinoApp().RunScript( L"! _Undo", 0 );
}
