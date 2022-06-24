
// MFC_culculatorDlg.h: 헤더 파일
//

#pragma once


// CMFCculculatorDlg 대화 상자
class CMFCculculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCculculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CULCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_cType;
	bool m_bEqualClk;
	CString answer;
	CString formula;
	CString formul_buf;

	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedcle();
	afx_msg void OnBnClickeddot();
	afx_msg void OnBnClickedplu();
	afx_msg void OnBnClickedmin();
	afx_msg void OnBnClickedmul();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedeql();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
