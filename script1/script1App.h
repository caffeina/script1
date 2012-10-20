/////////////////////////////////////////////////////////////////////////////
// script1App.h : main header file for the script1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "Resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// Cscript1App
// See script1App.cpp for the implementation of this class
//

class Cscript1App : public CWinApp
{
public:
	Cscript1App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
