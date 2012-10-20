#pragma once
#include "Resource.h"		// main symbols
#include "afxwin.h"

// finestra di dialogo DialogPrincipale

class DialogPrincipale : public CRhinoDialog  //sostituito CDialog, preferisco il dialog della sdk, nello
{
	DECLARE_DYNAMIC(DialogPrincipale)

public:
	DialogPrincipale(CWnd* pParent);   // costruttore standard, MODIFICATO nello! agg. tolto , CRhinoDoc& m_doc
	virtual ~DialogPrincipale();

// Dati della finestra di dialogo
	enum { IDD = IDD_DIALOG1 };
	CComboBox m_comboAltTacco;

	//void SetPointValue( int item, const ON_3dPoint& pt );
	void KillDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Supporto DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedCancel();	
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnEnChangeEdit2();

protected:
	CRhino4Interface m_Interface;
	CRhinoScript m_RhinoScript;

public:
	
	// valore disassamento. inseriti il valore massimo e minimo.
	int VAR_Valore_Disassamento;
	int StatusRadio1_Centrale;
	int StatusRadio2_Dissasata;
	int StatusRadio3_Iniezione_Centrale;
	int StatusRadio4_Iniezione_Disassata;
	int StatusRadio7_Fondello_di_ferro;
	int StatusRadio8_Fondello_di_alluminio;

	//CRhinoDoc& m_doc; tolto m_doc
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnCbnSelchangeCmbaltezzatacco();
	CString VAR_Altezza_Tacco;
public:
	afx_msg void OnBnClickedRadio3();
public:
	afx_msg void OnBnClickedRadio1();
public:
	afx_msg void OnBnClickedRadio7();
public:
	afx_msg void OnBnClickedRadio2();
public:
	afx_msg void OnBnClickedRadio4();
public:
	afx_msg void OnBnClickedRadio8();
public:
	afx_msg void OnBnClickedCheck1();
public:
	afx_msg void OnEnChangeRichedit21();
public:
	// valore iniezione (da non confondere dal dissasamento della spina) disassata, puo' essere +-12
	CString ValIniezioneDisassamento;
public:
	// di default e' 20
	CString ValoreAltezzaFondello;
public:
	// variabile controllo check presenza tacco spina
	CButton StatusCheckTaccoSpina;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCmbaltezzafondello();
public:
	afx_msg void OnBnClickedButton3();
public:
	CString ValoreTraslazione;
public:
	afx_msg void OnEnChangeEdit4();
public:
	afx_msg void OnEnChangeEdit5();
public:
	CString ValoreRotazione;
public:
	// con questo dovrebbe funzionare
	CComboBox AltezzaFondelloControllo;
public:
	afx_msg void OnBnClickedButton5();
};
