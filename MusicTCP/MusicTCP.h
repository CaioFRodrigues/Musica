/*
UFRGS � Instituto de Inform�tica
INF01120 T�cnicas de Constru��o de Programas

3� Fase Trabalho Pr�tico
Ana Paula Mello
Caio Fonseca
Guilherme Cattani de Castro

2016/2 - Turma B

Professor: Marcelo Soares Pimenta
*/

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// CMusicTCPApp:
// See MusicTCP.cpp for the implementation of this class
//

class CMusicTCPApp : public CWinApp
{
public:
	CMusicTCPApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMusicTCPApp theApp;

