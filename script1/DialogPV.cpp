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
