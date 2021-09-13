
// PrekoRekeDlg.h : header file
//
#pragma once

#include "Strukture.h"
#include <vector>

using namespace std;

// CPPRekeDlg dialog
class CPrekoRekeDlg : public CDialogEx
{
	// Construction
public:
	CPrekoRekeDlg(CWnd* pParent = NULL);	// standard constructor

										// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PPREKE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	CDC stoneDC, truckLDC, truckRDC, dragDC, drag1DC, dragRDC, dragLDC,overDC,keyDC,key1DC,pozDC,congrDC,cov1DC,cov2DC,frogjump1DC,A0DC,A1DC, A2DC, A3DC, A4DC, A5DC, A6DC, A7DC, A8DC, A9DC, A10DC,TrenDC,
		RekordDC,NoviDC,EndDC;
	CBitmap stoneBMP, truckLBMP, truckRBMP, dragBMP, drag1BMP, dragRBMP, dragLBMP,overBMP,keyBMP,key1BMP,pozBMP,congrBMP,cov1BMP,cov2BMP,frogjump1BMP,A0BMP,A1BMP, A2BMP, A3BMP, A4BMP, A5BMP, A6BMP, A7BMP, A8BMP, A9BMP, A10BMP,TrenBMP,
		RekordBMP,NoviBMP,EndBMP;
	CBitmap *oldBmpstone, *oldBmptruckL, *oldBmptruckR, *oldBmpdrag, *oldBmpdrag1, *oldBmpdragR, *oldBmpdragL,*oldBmpover,*oldBmpkey, *oldBmpkey1,*oldBmppoz,*oldBmpcongr,*oldBmpcov1,*oldBmpcov2,*oldBmpfrogjump1,*oldBmpA0,*oldBmpA1, *oldBmpA2, *oldBmpA3, *oldBmpA4, *oldBmpA5, *oldBmpA6, *oldBmpA7, *oldBmpA8, *oldBmpA9, *oldBmpA10,*oldBmpTren,
		*oldBmpRekord,*oldBmpNovi,*oldBmpEnd;
	vector<Deo> objekti;
	int okvirLevo, okvirGore, okvirDesno, okvirDole,granicaR1,granicaR2,granicaR0;
	int visinaSlike;
	vector<int> sirinaSlike;
	int pomerajDela;
	int x1, x2,x3,x4,x5,x6,brojac;
	int visinaStaze, duzinaStaze;
	int Xpos, Ypos;
	int ind;
	int red;
	int Xkey, Ykey,t,Xkey1;
	bool kraj ,p,novi;
	int max;

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	BOOL PreTranslateMessage(MSG * pMsg);
};
