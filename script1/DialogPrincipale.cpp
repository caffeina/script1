// DialogPrincipale.cpp : file di implementazione
//

#include "stdafx.h"
#include "DialogPrincipale.h"
#include "Resource.h"
#include "script1PlugIn.h"
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
	, ValIniezioneDisassamento(_T("-12"))
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
	, LayerPV(_T("pv"))
	, NomeTacchificio(_T("Monti"))
	, mmTacchificio(_T("4"))
	, numeroArticolo(_T("12345"))
	, mmnumeroArticolo(_T("4"))
	, codiceCliente(_T("ClienteCOD"))
	, mmcodiceCliente(_T("4"))
	, taglia(_T("00"))
	, mmtaglia(_T("6"))
	, tipologiafont(_T("MecSoft_Font-1"))
	, StatoTipologiaStampo(_T("Rocchetto Normale"))
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
	DDX_Text(pDX, IDC_EDIT1, LayerPV);
	DDX_Text(pDX, IDC_EDIT13, NomeTacchificio);
	DDX_Text(pDX, IDC_EDIT17, mmTacchificio);
	DDX_Text(pDX, IDC_EDIT14, numeroArticolo);
	DDX_Text(pDX, IDC_EDIT18, mmnumeroArticolo);
	DDX_Text(pDX, IDC_EDIT15, codiceCliente);
	DDX_Text(pDX, IDC_EDIT20, mmcodiceCliente);
	DDX_Text(pDX, IDC_EDIT16, taglia);
	DDX_Text(pDX, IDC_EDIT19, mmtaglia);
	DDX_Text(pDX, IDC_EDIT21, tipologiafont);
	DDX_CBString(pDX, IDC_COMBO2, StatoTipologiaStampo);
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
	ON_BN_CLICKED(IDC_BUTTON4, &DialogPrincipale::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT1, &DialogPrincipale::OnEnChangeEdit1)
END_MESSAGE_MAP()


// gestori di messaggi DialogPrincipale

void DialogPrincipale::OnBnClickedCancel()
{
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	UpdateData(true);
	//OnCancel();
	//RhinoApp().RunScript( L"! _Undo", 0 );
	 //RhinoApp().RunScript( L"_-Line 0,0,0 10,10,0", 0 );
  //RhinoApp().RunScript( L"_SelLast", 0 );
  //RhinoApp().RunScript( L"_-Properties _Object _Color _Object 255,0,0 _Enter _Enter", 0 );
  //RhinoApp().RunScript( L"_-Circle 0,0,0 10", 0 );
  //RhinoApp().RunScript( L"_SelLast", 0 );
  //RhinoApp().RunScript( L"_-Properties _Object _Color _Object 0,0,255 _Enter _Enter", 0 );
  //RhinoApp().RunScript( L"_-TextObject Prova 10,10,0", 0 );
  // ::RhinoApp().RunScript(L"! _-TextObject ");
  //RhinoApp().RunScript(L"_-TextObject GroupOutput=No FontName=McSoft_Font-1 Italic=No Bold=No Height=30 Output=Curves Test 0,0,0");
  //RhinoApp().RunScript(L"_-TextObject _R=No FontName=Arial Italic=No Bold=No Height=10 Output=Curves Test 0,0,0");
	
  //UpdateData(true);

}



void DialogPrincipale::OnCbnSelchangeCombo1()
{
	// x conotrollare UpdateData(true);
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
	CComboBox *combo= (CComboBox *)GetDlgItem(IDC_COMBO2);
	UpdateData(true);
	CString strCBText;
	int nIndex = combo->GetCurSel();
	combo->GetLBText( nIndex, strCBText);
	CComboBox *combo2= (CComboBox *)GetDlgItem(IDC_CMBAltezzaTacco);
	if((strCBText)==("Rocchetto Normale")||(strCBText)==("Rocchetto Trasversale"))
	{
		combo2->ResetContent();
		combo2->AddString(L"140");
		combo2->AddString(L"160");
		combo2->AddString(L"180");
		//combo2->GetLBText( nIndex, strCBText);
		//if((strCBText)==("150")){combo2->DeleteString(1);}
		/*if((strCBText)==("150"))combo2->DeleteString(3);
		combo2->DeleteString(5);
		combo2->DeleteString(6);*/
	}
	else
	{
		combo2->ResetContent();
		combo2->AddString(L"140");
		combo2->AddString(L"150");
		combo2->AddString(L"160");
		combo2->AddString(L"170");
		combo2->AddString(L"180");
		combo2->AddString(L"190");
		combo2->AddString(L"200");
	}

	
}

void DialogPrincipale::OnEnChangeEdit2()
{
	UpdateData (TRUE);
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invier� questa notifica a meno che non si esegua l'override della funzione CDialog::OnInitDialog()
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
	// invier� questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
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
	//GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE); fix bug segnalato da Cristiano
	//GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE); fix bug segnalato da Cristiano
	GetDlgItem(IDC_RADIO7)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(TRUE);
	//GetDlgItem(IDC_COMBO1)->EnableWindow(TRUE); fix bug segnalato da Cristiano
	//GetDlgItem(IDC_RADIO2)->GetCheckedRadioButton(IDC_RADIO2,IDC_RADIO2);
	StatusRadio2_Dissasata = 0;
	StatusRadio1_Centrale = -1;
	//CheckRadioButton(IDC_RADIO2,IDC_RADIO2,IDC_RADIO2);
	//UpdateData(FALSE);  commentato per baco cancellazione altezza stampo
	}
	else {
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	//GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	//GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
	//GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	//UpdateData(FALSE); commentato per baco cancellazione altezza stampo
	}

	
	

	// TODO: aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeRichedit21()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invier� questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

Cscript1PlugIn& plugin = script1PlugIn();

 
void DialogPrincipale::OnBnClickedButton2()
{
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(TRUE);
	UpdateData(true);
				//inizio risoluzione baco altezza tacco vuoto
	CComboBox *combo= (CComboBox *)GetDlgItem(IDC_CMBAltezzaTacco);
	UpdateData(true);
	CString strCBText;
	int nIndex = combo->GetCurSel();
	combo->GetLBText( nIndex, strCBText);
	
	if((strCBText)==("") )return; 
	// se mancava l'altezza stampo succedeva un casino
				//fine inizio risoluzione baco altezza tacco vuoto
	
	RhinoApp().RunScript( L"! _GenPianoVis", 0);
	RhinoApp().RunScript( L"! _GenCylinder", 0);
	UpdateData(true);
	RhinoApp().RunScript( L"! _GenUgello", 0);
	RhinoApp().RunScript( L"! _GenSpineCentraggio", 0);
	RhinoApp().RunScript( L"! _BeginMarcatura", 0);
	//const wchar_t* provashell = L"_-TextObject GroupOutput=No FontName=Arial Italic=No Bold=No Height=6 Output=Curves AllowOpenCurves=Yes Monti 0,0,0";
	ON_wString Nameshell,Nameshell1,Nameshell2,Nameshell3,Nameshell4;
	Nameshell.Format( L"_-TextObject GroupOutput=No FontName=%s Italic=No Bold=No Height=%s Output=Curves AllowOpenCurves=Yes %s 0,0,0",plugin.m_dialog->tipologiafont,plugin.m_dialog->mmTacchificio,plugin.m_dialog->NomeTacchificio); 
	Nameshell1.Format( L"_-TextObject GroupOutput=No FontName=%s Italic=No Bold=No Height=%s Output=Curves AllowOpenCurves=Yes _%s 10,-7,0",plugin.m_dialog->tipologiafont,plugin.m_dialog->mmnumeroArticolo,plugin.m_dialog->numeroArticolo);
	Nameshell2.Format( L"_-TextObject GroupOutput=No FontName=%s Italic=No Bold=No Height=%s Output=Curves AllowOpenCurves=Yes _%s 3,-20,0",plugin.m_dialog->tipologiafont,plugin.m_dialog->mmtaglia,plugin.m_dialog->taglia);
	Nameshell3.Format( L"_-TextObject GroupOutput=No FontName=%s Italic=No Bold=No Height=%s Output=Curves AllowOpenCurves=Yes _%s 0,-30,0",plugin.m_dialog->tipologiafont,plugin.m_dialog->mmcodiceCliente,plugin.m_dialog->codiceCliente);
	RhinoApp().RunScript(Nameshell);
	RhinoApp().RunScript( L"! _EndMarcatura", 0);
	RhinoApp().RunScript( L"! _BeginMarcatura", 0);
	RhinoApp().RunScript(Nameshell1);
	RhinoApp().RunScript( L"! _EndMarcatura", 0);
	RhinoApp().RunScript( L"! _BeginMarcatura", 0);
	RhinoApp().RunScript(Nameshell2);
	RhinoApp().RunScript( L"! EndMarcaturaTaglia", 0);
	/*RhinoApp().RunScript( L"_SelLast", 0 );
	RhinoApp().RunScript( L"_-Rotate 3,-20,0 90", 0 );*/
	RhinoApp().RunScript( L"! _BeginMarcatura", 0);
	RhinoApp().RunScript(Nameshell3);
	RhinoApp().RunScript( L"! _EndMarcatura", 0);
	//RhinoApp().Print( L"LAYER \"%s\" DOES NOT EXIST.\n", plugin.m_dialog->LayerPV );
	RhinoApp().Print( L"! _GenUgello");

	/*RhinoApp().RunScript( L"! _BeginMarcatura", 0);
	RhinoApp().RunScript( L"_-TextObject GroupOutput=No FontName=Arial Italic=No Bold=No Height=6 Output=Curves AllowOpenCurves=Yes |12345 10,0,0");
	RhinoApp().RunScript( L"! _EndMarcatura", 0);*/
	//McSoft_Font-1

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
	// invier� questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnEnChangeEdit5()
{
	UpdateData(true);
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invier� questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}

void DialogPrincipale::OnBnClickedButton5()
{
	UpdateData(true);
	RhinoApp().RunScript( L"! _GenUgello", 0 );
}

void DialogPrincipale::OnBnClickedButton6()
{
	RhinoApp().RunScript( L"!_TrimMatrix", 0 ); 
	RhinoApp().RunScript( L"! _AssegnaOggettiLayer", 0);
	//RhinoApp().RunScript(L"_Trim");
}

void DialogPrincipale::OnBnClickedButton8()
{
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	UpdateData(true);
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

void DialogPrincipale::OnBnClickedButton4()
{	
	
}

void DialogPrincipale::OnEnChangeEdit1()
{
	// TODO:  Se si tratta di un controllo RICHEDIT, il controllo non
	// invier� questa notifica a meno che non si esegua l'override della funzione CRhinoDialog::OnInitDialog()
	// e venga eseguita la chiamata a CRichEditCtrl().SetEventMask()
	// con il flag ENM_CHANGE introdotto dall'operatore OR nella maschera.

	// TODO:  Aggiungere qui il codice per la gestione della notifica del controllo.
}
