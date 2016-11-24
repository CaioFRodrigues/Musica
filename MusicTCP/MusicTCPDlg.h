
// MusicTCPDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <string>


// CMusicTCPDlg dialog
class CMusicTCPDlg : public CDialogEx
{
// Construction
public:
	CMusicTCPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSICTCP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString textInBox;
	std::string multiLineTextInBox;
	afx_msg void OnBnClickedBtloadtxt();
	afx_msg void OnBnClickedBtplaymusic();
	afx_msg void OnBnClickedBtsavemusic();
	afx_msg void OnBnClickedBtsavetext();
	afx_msg void OnBnClickedBtcleantext();
};
