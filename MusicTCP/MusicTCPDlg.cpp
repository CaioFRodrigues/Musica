/*
UFRGS – Instituto de Informática
INF01120 Técnicas de Construção de Programas

3ª Fase Trabalho Prático
Ana Paula Mello
Caio Fonseca
Guilherme Cattani de Castro

2016/2 - Turma B

Professor: Marcelo Soares Pimenta
*/

#include "stdafx.h"
#include "MusicTCP.h"
#include "MusicTCPDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include<string.h>
#include<string>
#include "CFugueLib.h"
#include "Music.h"
#include "Text.h"
#include "atlstr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region Dialog Initialization
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMusicTCPDlg dialog



CMusicTCPDlg::CMusicTCPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MUSICTCP_DIALOG, pParent)
	, textInBox(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMusicTCPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, textBox, textInBox);
	DDX_Control(pDX, textBox, textBoxControl);
}

BEGIN_MESSAGE_MAP(CMusicTCPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BtLoadTxt, &CMusicTCPDlg::OnBnClickedBtloadtxt)
	ON_BN_CLICKED(BtPlayMusic, &CMusicTCPDlg::OnBnClickedBtplaymusic)
	ON_BN_CLICKED(BtSaveMusic, &CMusicTCPDlg::OnBnClickedBtsavemusic)
	ON_BN_CLICKED(BtSaveText, &CMusicTCPDlg::OnBnClickedBtsavetext)
	ON_BN_CLICKED(BtCleanText, &CMusicTCPDlg::OnBnClickedBtcleantext)
END_MESSAGE_MAP()


// CMusicTCPDlg message handlers

BOOL CMusicTCPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMusicTCPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMusicTCPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMusicTCPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
#pragma endregion

#pragma region Button handling

void CMusicTCPDlg::OnBnClickedBtloadtxt()
{
	// szFilters is a text string that includes two file name filters:
	// "*.my" for "MyType Files" and "*.*' for "All Files."
	TCHAR szFilters[] = _T("Text files (*.txt)|*.txt|All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(TRUE, _T("txt"), _T("*.txt"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		std::string line;
		std::ifstream inputFile;
		inputFile.open(pathName);

		while (getline(inputFile, line))    //read input file until the end
		{
			multiLineTextInBox += line + "\r\n";
		}

		UpdateData();
		textInBox = multiLineTextInBox.c_str();
		UpdateData(FALSE);

	}
}

void CMusicTCPDlg::OnBnClickedBtplaymusic()
{
	Music music;
	Text text;

	if (CFugue::GetMidiOutPortCount() <= 0)
	{
		std::cerr << "No MIDI Output Ports found!";
		exit(-1);
	}

	UpdateData();

	CString textInBoxCeeString;
	textBoxControl.GetWindowTextW(textInBoxCeeString);
	
	CT2CA pszConvertedAnsiString(textInBox.GetString());
	std::string textInBoxString(pszConvertedAnsiString);
	if (multiLineTextInBox.compare(textInBoxString)){
		multiLineTextInBox = textInBoxString;
	}

	UpdateData(FALSE);

	if(!multiLineTextInBox.empty())
		music.playMusic(text.convertCharacter(multiLineTextInBox));
}

void CMusicTCPDlg::OnBnClickedBtsavemusic()
{
	Music music;
	Text text;

	TCHAR szFilters[] = _T("Midi files (*.midi)|*.midi|All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(FALSE, _T(""), _T(""),
		OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		UpdateData();
		CString textInBoxCeeString;
		textBoxControl.GetWindowTextW(textInBoxCeeString);

		CT2CA pszConvertedAnsiString(textInBox.GetString());
		std::string textInBoxString(pszConvertedAnsiString);
		if (multiLineTextInBox.compare(textInBoxString)) {
			multiLineTextInBox = textInBoxString;
		}

		UpdateData(FALSE);

		if (!multiLineTextInBox.empty())
			music.saveMusic(text.convertCharacter(multiLineTextInBox), pathName);
	}
		

}

void CMusicTCPDlg::OnBnClickedBtsavetext()
{
	// szFilters is a text string that includes two file name filters:
	// "*.my" for "MyType Files" and "*.*' for "All Files."
	TCHAR szFilters[] = _T("Text files (*.txt)|*.txt|All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(FALSE, _T(""), _T(""),
		OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		UpdateData();
		CString pathName = fileDlg.GetPathName();

		std::ofstream outputFile;
		outputFile.open(pathName);
		CT2CA pszConvertedAnsiString(textInBox.GetString());
		std::string outputText(pszConvertedAnsiString);
		outputFile << outputText;
		
		
		UpdateData(FALSE);




	}
}

void CMusicTCPDlg::OnBnClickedBtcleantext()
{
	UpdateData();
	textInBox = "";
	UpdateData(FALSE);
}
#pragma endregion