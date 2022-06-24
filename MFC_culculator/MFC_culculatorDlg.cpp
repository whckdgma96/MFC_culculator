
// MFC_culculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_culculator.h"
#include "MFC_culculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define plu 1
#define min 2
#define mul 3
#define div 4
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCculculatorDlg 대화 상자



CMFCculculatorDlg::CMFCculculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CULCULATOR_DIALOG, pParent)
	/*, answer(_T(""))
	, formula(_T(""))*/
{
	answer = _T("");
	formula = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bEqualClk = false;
}

void CMFCculculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, answer);
	DDX_Text(pDX, IDC_EDIT2, formula);
}

BEGIN_MESSAGE_MAP(CMFCculculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BUTTON_0, &CMFCculculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(BUTTON_1, &CMFCculculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(BUTTON_2, &CMFCculculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(BUTTON_3, &CMFCculculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(BUTTON_4, &CMFCculculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(BUTTON_5, &CMFCculculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(BUTTON_6, &CMFCculculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(BUTTON_7, &CMFCculculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(BUTTON_8, &CMFCculculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(BUTTON_9, &CMFCculculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(BUTTON_cle, &CMFCculculatorDlg::OnBnClickedcle)
	ON_BN_CLICKED(BUTTON_dot, &CMFCculculatorDlg::OnBnClickeddot)
	ON_BN_CLICKED(BUTTON_plu, &CMFCculculatorDlg::OnBnClickedplu)
	ON_BN_CLICKED(BUTTON_min, &CMFCculculatorDlg::OnBnClickedmin)
	ON_BN_CLICKED(BUTTON_mul, &CMFCculculatorDlg::OnBnClickedmul)
	ON_BN_CLICKED(BUTTON_div, &CMFCculculatorDlg::OnBnClickeddiv)
	ON_BN_CLICKED(BUTTON_eql, &CMFCculculatorDlg::OnBnClickedeql)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCculculatorDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCculculatorDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CMFCculculatorDlg 메시지 처리기

BOOL CMFCculculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCculculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCculculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCculculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCculculatorDlg::OnBnClicked0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("0");
	formul_buf += _T("0");
	UpdateData(false);

}


void CMFCculculatorDlg::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("1");
	formul_buf += _T("1");
	UpdateData(false);

}


void CMFCculculatorDlg::OnBnClicked2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("2");
	formul_buf += _T("2");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("3");
	formul_buf += _T("3");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("4");
	formul_buf += _T("4");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("5");
	formul_buf += _T("5");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("6");
	formul_buf += _T("6");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("7");
	formul_buf += _T("7");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("8");
	formul_buf += _T("8");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClicked9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T("9");
	formul_buf += _T("9");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClickedcle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	formula.Empty();
	answer.Empty();
	formul_buf.Empty();
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClickeddot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		formula.Empty();
		m_bEqualClk = false;
	}
	formula += _T(".");
	formul_buf += _T(".");
	UpdateData(false);
}


void CMFCculculatorDlg::OnBnClickedplu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_cType = plu;
	formula.Empty();
	formul_buf += _T("+");

}


void CMFCculculatorDlg::OnBnClickedmin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_cType = min;
	formula.Empty();
	formul_buf += _T("-");
}


void CMFCculculatorDlg::OnBnClickedmul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_cType = mul;
	formula.Empty();
	formul_buf += _T("×");
}


void CMFCculculatorDlg::OnBnClickeddiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_cType = div;
	formula.Empty();
	formul_buf += _T("÷");
}


void CMFCculculatorDlg::OnBnClickedeql()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double op1, op2;
	double result = 0;
	op1 = _tstof(formul_buf);
	op2 = _tstof(formula);

	switch (m_cType) {
	case plu:
		result = op1 + op2;
		break;
	case min:
		result = op1 - op2;
		break;
	case mul:
		result = op1 * op2;
		break;
	case div:
		result = op1 / op2;
		break;
	}
	formula =formul_buf;
	answer.Format(_T("%.6f"), result);
	formul_buf.Format(_T("%.6f"), result);
	UpdateData(false);
	m_bEqualClk = true;
	
}


void CMFCculculatorDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCculculatorDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
