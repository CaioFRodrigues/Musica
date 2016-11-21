
// MusicTCP.h : main header file for the PROJECT_NAME application
//

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


class WorkerThread
{
public:
	WorkerThread();
	CWinThread *pThread;

	// Overrides
public:
	void playMusic();

	virtual BOOL InitInstance();

	// Implementation

	DECLARE_MESSAGE_MAP()
};

extern WorkerThread workerThread;