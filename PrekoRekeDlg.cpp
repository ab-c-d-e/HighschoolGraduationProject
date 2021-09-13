// PPRekeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrekoReke.h"
#include "PrekoRekeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




CPrekoRekeDlg::CPrekoRekeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PREKOREKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	visinaStaze = 80;
	duzinaStaze = 900;
	Deo deo1(1, 0, 0, 0, 50);
	Deo deo2(2, duzinaStaze, visinaStaze, 1, 50);
	Deo deo3(3, 0, 2 * visinaStaze, 2, 50);
	Deo deo4(1, duzinaStaze, 3 * visinaStaze, 3, 50);
	Deo deo5(2, 0, 4 * visinaStaze, 4, 50);
	Deo deo6(3, duzinaStaze, 5 * visinaStaze, 5, 50);

	objekti.push_back(deo1);
	objekti.push_back(deo2);
	objekti.push_back(deo3);
	objekti.push_back(deo4);
	objekti.push_back(deo5);
	objekti.push_back(deo6);

	okvirLevo = 0; okvirGore =40; okvirDesno = 1000; okvirDole = 500;

	sirinaSlike.push_back(0);
	sirinaSlike.push_back(150);
	sirinaSlike.push_back(250);
	sirinaSlike.push_back(150);

	pomerajDela = 5;


	//	int tip, int xPos, int yPos, int staza, int preostalo = 10
	Xpos = 500;
	Ypos = 580;
	Xkey = rand() % 900;
	Xkey1 = rand() % 900;
	Ykey = 3;
	red = 7; ind = 1; t = 0;
	kraj = false;
	x1 = objekti[0].xPos + 400;
	x2 =objekti[0].xPos + 800;
	x3 = objekti[3].xPos - 400;
	x4 =  objekti[3].xPos - 800;
	x5= objekti[1].xPos - 800;
	x6 = objekti[4].xPos + 600;
	brojac = 0; p = 0;
	novi = false;
	max = 0;
}

void CPrekoRekeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrekoRekeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPPRekeDlg message handlers

BOOL CPrekoRekeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	CClientDC dc(this);

	truckLBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));
	truckLDC.CreateCompatibleDC(&dc);
	oldBmptruckL = truckLDC.SelectObject(&truckLBMP);


	truckRBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	truckRDC.CreateCompatibleDC(&dc);
	oldBmptruckR = truckRDC.SelectObject(&truckRBMP);

	stoneBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	stoneDC.CreateCompatibleDC(&dc);
	oldBmpstone = stoneDC.SelectObject(&stoneBMP);


	dragBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));
	dragDC.CreateCompatibleDC(&dc);
	oldBmpdrag = dragDC.SelectObject(&dragBMP);

	drag1BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
	drag1DC.CreateCompatibleDC(&dc);
	oldBmpdrag1 = drag1DC.SelectObject(&drag1BMP);

	dragRBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));
	dragRDC.CreateCompatibleDC(&dc);
	oldBmpdragR = dragRDC.SelectObject(&dragRBMP);

	dragLBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)));
	dragLDC.CreateCompatibleDC(&dc);
	oldBmpdragL = dragLDC.SelectObject(&dragLBMP);

	overBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8)));
	overDC.CreateCompatibleDC(&dc);
	oldBmpover = overDC.SelectObject(&overBMP);

	congrBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP12)));
	congrDC.CreateCompatibleDC(&dc);
	oldBmpcongr = congrDC.SelectObject(&congrBMP);

	keyBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));
	keyDC.CreateCompatibleDC(&dc);
	oldBmpkey = keyDC.SelectObject(&keyBMP);

	key1BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP10)));
	key1DC.CreateCompatibleDC(&dc);
	oldBmpkey1 = key1DC.SelectObject(&key1BMP);

	pozBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP11)));
	pozDC.CreateCompatibleDC(&dc);
	oldBmppoz = pozDC.SelectObject(&pozBMP);

	cov1BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP13)));
	cov1DC.CreateCompatibleDC(&dc);
	oldBmpcov1 = cov1DC.SelectObject(&cov1BMP);

	cov2BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP14)));
	cov2DC.CreateCompatibleDC(&dc);
	oldBmpcov2 = cov2DC.SelectObject(&cov2BMP);


	frogjump1BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP15)));
	frogjump1DC.CreateCompatibleDC(&dc);
	oldBmpfrogjump1 = cov2DC.SelectObject(&frogjump1BMP);

	//NUMBERS
	A0BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP16)));
	A0DC.CreateCompatibleDC(&dc);
	oldBmpA0 = A0DC.SelectObject(&A0BMP);

	A1BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP17)));
	A1DC.CreateCompatibleDC(&dc);
	oldBmpA1 = A1DC.SelectObject(&A1BMP);

	A2BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP18)));
	A2DC.CreateCompatibleDC(&dc);
	oldBmpA2 = A2DC.SelectObject(&A2BMP);

	A3BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP19)));
	A3DC.CreateCompatibleDC(&dc);
	oldBmpA3 = A3DC.SelectObject(&A3BMP);

	A4BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP20)));
	A4DC.CreateCompatibleDC(&dc);
	oldBmpA4 = A4DC.SelectObject(&A4BMP);

	A5BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP21)));
	A5DC.CreateCompatibleDC(&dc);
	oldBmpA5 = A5DC.SelectObject(&A5BMP);

	A6BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP22)));
	A6DC.CreateCompatibleDC(&dc);
	oldBmpA6 = A6DC.SelectObject(&A6BMP);

	A7BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP23)));
	A7DC.CreateCompatibleDC(&dc);
	oldBmpA7 = A7DC.SelectObject(&A7BMP);

	A8BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP24)));
	A8DC.CreateCompatibleDC(&dc);
	oldBmpA8 = A8DC.SelectObject(&A8BMP);

	A9BMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP25)));
	A9DC.CreateCompatibleDC(&dc);
	oldBmpA9 = A9DC.SelectObject(&A9BMP);

	TrenBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP26)));
	TrenDC.CreateCompatibleDC(&dc);
	oldBmpTren = TrenDC.SelectObject(&TrenBMP);

	RekordBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP27)));
	RekordDC.CreateCompatibleDC(&dc);
	oldBmpRekord = RekordDC.SelectObject(&RekordBMP);

	NoviBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP28)));
	NoviDC.CreateCompatibleDC(&dc);
	oldBmpNovi = NoviDC.SelectObject(&NoviBMP);

	EndBMP.Attach(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP29)));
	EndDC.CreateCompatibleDC(&dc);
	oldBmpEnd = EndDC.SelectObject(&EndBMP);


	SetTimer(1, 100, NULL);


	//CDC stoneDC, truckLDC, truckRDC;
	//CBitmap stoneBMP, truckLBMP, truckRBMP;
	//CBitmap *oldBmpstone, *oldBmptruckL, *oldBmptruckR;


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPrekoRekeDlg::OnPaint()
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
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
			if(!kraj)
			{
				dc.BitBlt(0, 0, 2000, 780, &pozDC, 0, 0, SRCCOPY);

			
				//dc.TransparentBlt(, 0, 30, 34, &cov2DC, 0, 0, 30, 34, RGB(255, 255, 255));
				
				int i;
				for (i = 0; i < objekti.size(); i++)
				{
					switch (objekti[i].tip)
					{
					case 1:
						//dc.BitBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 80, 180, 80, &truckLDC, 0, 0, SRCCOPY);
						if (i == 0)
						{
							dc.TransparentBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x1, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x2, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
						}
						if (i == 3)
						{
							dc.TransparentBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x3, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x4, okvirGore + objekti[i].yPos + 70, 180, 80, &truckLDC, 0, 0, 180, 65, RGB(255, 255, 255));
						}

						break;
					case 2:
						//dc.BitBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 80, 250, 80, &truckRDC, 0, 0, SRCCOPY);
						if (i == 1)
						{
							dc.TransparentBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 70, 250, 80, &truckRDC, 0, 0, 250, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x5, okvirGore + objekti[i].yPos + 80, 250, 70, &truckRDC, 0, 0, 250, 65, RGB(255, 255, 255));

						}
						if (i == 4)
						{
							dc.TransparentBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 70, 250, 80, &truckRDC, 0, 0, 250, 65, RGB(255, 255, 255));
							dc.TransparentBlt(okvirLevo + x6, okvirGore + objekti[i].yPos + 70, 250, 80, &truckRDC, 0, 0, 250, 65, RGB(255, 255, 255));

						}
						break;
					case 3:
						dc.TransparentBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 70, 180, 80, &stoneDC, 0, 0, 150, 75, RGB(255, 255, 255));
						//dc.BitBlt(okvirLevo + objekti[i].xPos, okvirGore + objekti[i].yPos + 80, 250, 80, &stoneDC, 0, 0, SRCCOPY);
					}

					dc.TransparentBlt(970, 550, 105, 89, &cov1DC, 0, 0, 105, 89, RGB(255, 255, 255));
					//dc.TransparentBlt(970, 530, 105, 110, &cov2DC, 0, 0, 105, 110, RGB(255, 255, 255));
				}

				if (ind == 1)
				{
					//dc.BitBlt(Xpos, Ypos, 100, 90, &dragDC, 0, 0, SRCCOPY);
					dc.TransparentBlt(Xpos, Ypos, 100, 90, &dragDC, 0, 0, 100, 90, RGB(255, 255, 255));
				}
				if (ind == 2)
				{
					//dc.BitBlt(Xpos, Ypos, 100, 90, &drag1DC, 0, 0, SRCCOPY);
					dc.TransparentBlt(Xpos, Ypos, 100, 90, &drag1DC, 0, 0, 100, 90, RGB(255, 255, 255));
				}
				if (ind == 3)
				{
					//dc.BitBlt(Xpos, Ypos, 100, 90, &dragLDC, 0, 0, SRCCOPY);
					if (red == 2)
					{
						dc.TransparentBlt(Xpos - 3, Ypos + 15, 100, 90, &dragLDC, 0, 0, 90, 90, RGB(255, 255, 255));
					}
					else
					dc.TransparentBlt(Xpos-3, Ypos+5, 100, 90, &dragLDC, 0, 0, 90, 90, RGB(255, 255, 255));
				}
				if (ind == 4)
				{
					//dc.BitBlt(Xpos, Ypos, 100, 90, &dragRDC, 0, 0, SRCCOPY);
					if (red==2)
					{
						dc.TransparentBlt(Xpos - 3, Ypos + 15, 100, 90, &dragRDC, 0, 0, 90, 90, RGB(255, 255, 255));
					}
					else
					dc.TransparentBlt(Xpos-3, Ypos+5, 100, 90, &dragRDC, 0, 0, 90, 90, RGB(255, 255, 255));
					
				}
				if (!(Xpos + 70 >= Xkey&&Xpos <= Xkey + 50 && red == 0) && t % 2 == 0)
				{
					//Xkey = rand() % 700;
					dc.TransparentBlt(Xkey, Ykey, 70, 70, &keyDC, 0, 0, 70, 70, RGB(255, 255, 255));
					Xkey1 = rand() % 900;
				}
				else if (t % 2 == 0)
				{
					//dc.TransparentBlt(0, 0, 100, 90, &key1DC, 0, 0, 50, 50, RGB(255, 255, 255));
					//dc.TransparentBlt(0, 0, 70, 60, &cov2DC, 0, 0, 50,50, RGB(255, 255, 255));
					
					t++;
					if (t > max)
					{
						max = t;
						novi = true;
					}
					pomerajDela++;
				}
				if (!(Xpos + 70 >= Xkey1&&Xpos <= Xkey1 + 50 && red == 7) && t % 2 == 1)
				{
					//dc.TransparentBlt(0, 0, 100, 90, &key1DC, 0, 0, 50, 50, RGB(255, 255, 255));
					//Xkey= rand() % 700;
					dc.TransparentBlt(Xkey1, Ykey + 585, 70, 70, &keyDC, 0, 0, 70, 70, RGB(255, 255, 255));
					//dc.BitBlt(Xpos, Ypos, 100, 90, &drag1DC, 0, 0, SRCCOPY);
					Xkey = rand() % 900;

				}
				else if (t % 2 == 1)
				{
					//dc.TransparentBlt(0, 0, 100, 90, &key1DC, 0, 0, 50, 50, RGB(255, 255, 255));
					//dc.TransparentBlt(0, 0, 30, 34, &cov2DC, 0, 0, 30, 34, RGB(255, 255, 255));
					t++;
					if (t > max) 
					{ 
						max = t;
						novi = true; 
					}
					pomerajDela++;
				}
				if(t==0) dc.TransparentBlt(980, 570, 50, 50, &A0DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if(t==1) dc.TransparentBlt(980, 570, 50, 50, &A1DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 2) dc.TransparentBlt(980, 570, 50, 50, &A2DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 3) dc.TransparentBlt(980, 570, 50, 50, &A3DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 4) dc.TransparentBlt(980, 570, 50, 50, &A4DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 5) dc.TransparentBlt(980, 570, 50, 50, &A5DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 6) dc.TransparentBlt(980, 570, 50, 50, &A6DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 7) dc.TransparentBlt(980, 570, 50, 50, &A7DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 8) dc.TransparentBlt(980, 570, 50, 50, &A8DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 9) dc.TransparentBlt(980, 570, 50, 50, &A9DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else
				{
					//dc.TransparentBlt(980, 570, 50, 50, &A10DC, 0, 0, 50, 50, RGB(255, 255, 255));
					kraj = true;
				}

				
			}
			else
			{
				if(t<10) dc.BitBlt(0, 0, 2000, 780, &overDC, 0, 0, SRCCOPY);

				dc.TransparentBlt(210, 260, 300, 50, &TrenDC, 0, 0, 300, 50, RGB(255, 255, 255));
				dc.TransparentBlt(270, 310, 300, 50, &RekordDC, 0, 0, 300, 50, RGB(255, 255, 255));
				if(novi) dc.TransparentBlt(100, 100, 850, 50, &NoviDC, 0, 0, 800, 50, RGB(255, 255, 255));
				if (t == 0) dc.TransparentBlt(520, 260, 50, 50, &A0DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 1) dc.TransparentBlt(520, 260, 50, 50, &A1DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 2) dc.TransparentBlt(520, 260, 50, 50, &A2DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 3) dc.TransparentBlt(520, 260, 50, 50, &A3DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 4) dc.TransparentBlt(520, 260, 50, 50, &A4DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 5) dc.TransparentBlt(520, 260, 50, 50, &A5DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 6) dc.TransparentBlt(520, 260, 50, 50, &A6DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 7) dc.TransparentBlt(520, 260, 50, 50, &A7DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 8) dc.TransparentBlt(520, 260, 50, 50, &A8DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (t == 9) dc.TransparentBlt(520, 260, 50, 50, &A9DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if(t==10) dc.BitBlt(0, 0, 2000, 780, &EndDC, 0, 0, SRCCOPY);

				if (max == 0) dc.TransparentBlt(520, 310, 50, 50, &A0DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 1) dc.TransparentBlt(520, 310, 50, 50, &A1DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 2) dc.TransparentBlt(520, 310, 50, 50, &A2DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 3) dc.TransparentBlt(520, 310, 50, 50, &A3DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 4) dc.TransparentBlt(520, 310, 50, 50, &A4DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 5) dc.TransparentBlt(520, 310, 50, 50, &A5DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 6) dc.TransparentBlt(520, 310, 50, 50, &A6DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 7) dc.TransparentBlt(520, 310, 50, 50, &A7DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 8) dc.TransparentBlt(520, 310, 50, 50, &A8DC, 0, 0, 50, 50, RGB(255, 255, 255));
				else if (max == 9) dc.TransparentBlt(520, 310, 50, 50, &A9DC, 0, 0, 50, 50, RGB(255, 255, 255));

				if (p == 1)
				{
					

					objekti[0].xPos = 0;
					objekti[1].xPos = duzinaStaze;
					objekti[2].xPos = 0;
					objekti[3].xPos = duzinaStaze;
					objekti[4].xPos = 0;
					objekti[5].xPos = duzinaStaze;
					kraj = false;
					Xpos = 500;
					Ypos = 580;
					Xkey = rand() % 700;
					Xkey1 = rand() % 700;
					Ykey = 3;
					red = 7; ind = 1; t = 0;
					x1 = objekti[0].xPos + 400;
					x2 = objekti[0].xPos + 800;
					x3 = objekti[3].xPos - 400;
					x4 = objekti[3].xPos - 800;
					x5 = objekti[1].xPos - 800;
					x6 = objekti[4].xPos + 600;
					brojac = 0;
					p = 0;
					novi = false;
					
				}
			}


		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPrekoRekeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrekoRekeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// rTODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		int i;
		for (i = 0; i < objekti.size(); i++)
		{

			if (objekti[i].staza % 2 == 0)
			{
				objekti[i].xPos += pomerajDela;

				if (objekti[i].xPos > 1000) { objekti[i].xPos = -230; }

				if (i == 0)
				{
					x1 += pomerajDela;
					x2 += pomerajDela;

					if (x1 > 1000) { x1 = -230; }
					if (x2 > 1000) { x2 = -230; }

				}
				else if (i == 4)
				{
					x6 += pomerajDela;

					if (x6 > 1000) { x6 = -230; }
				}

				if (red == 1)
				{
					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x1&&Xpos <= x1 + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x2&&Xpos <= x2 + sirinaSlike[objekti[i].tip] && i == red - 1))Xpos += pomerajDela;
					else if (i == red - 1) kraj = true;

				}
				else if (red == 3)
				{
					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1))Xpos += pomerajDela;
					else if (i == red - 1) kraj = true;
				}

				else if (red == 5)
				{

					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x6&&Xpos <= x6 + sirinaSlike[objekti[i].tip] && i == red - 1)) Xpos += pomerajDela;
					else if (i == red - 1) kraj = true;
				}

			}
			else
			{

				objekti[i].xPos -= pomerajDela;

				if (objekti[i].xPos < -230) { objekti[i].xPos = 1000; }

				if (i == 3)
				{
					x3 -= pomerajDela;
					x4 -= pomerajDela;

					if (x3 < -230) { x3 = 1000; }
					if (x4 < -230) { x4 = 1000; }

				}
				else if (i == 1)
				{
					x5 -= pomerajDela;

					if (x5 < -230) { x5 = 1000; }
				}

				if (red== 2)
				{
					
					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x5&&Xpos <= x5 + sirinaSlike[objekti[i].tip] && i == red - 1)) Xpos -= pomerajDela;
					else if (i == red - 1) kraj = true;

				}
				else if (red == 4)
				{

					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x3&&Xpos <= x3 + sirinaSlike[objekti[i].tip] && i == red - 1) ||
						(Xpos + 70 >= x4&&Xpos <= x4 + sirinaSlike[objekti[i].tip] && i == red - 1))Xpos -= pomerajDela;
					else if (i == red - 1) kraj = true;
				}

				else if (red == 6)
				{

					if ((Xpos + 70 >= objekti[i].xPos&&Xpos <= objekti[i].xPos + sirinaSlike[objekti[i].tip] && i == red - 1)) Xpos -= pomerajDela;
					else if (i == red - 1) kraj = true;
				}
			}
		}
	}
	Invalidate();

	CDialogEx::OnTimer(nIDEvent);
}
BOOL CPrekoRekeDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_UP)
		{
			if ((ind == 1) && (Ypos >= 50)) {
				Ypos -= 85; red--;
			}
			ind = 1;
		}
		else if (pMsg->wParam == VK_DOWN)
		{
			if ((ind == 2) && (Ypos <= 500)) {
				Ypos += 85; red++;
			}
			ind = 2;
		}
		else if (pMsg->wParam == VK_LEFT)
		{
			if ((ind == 3) && (Xpos >= 20))
				Xpos -= 20;
			ind = 3;
		}
		else if (pMsg->wParam == VK_RIGHT)
		{
			if ((ind == 4) && (Xpos <= 1000))
				Xpos += 20;
			ind = 4;
		}
	else if(kraj) p = 1;
	}
	return CDialog::PreTranslateMessage(pMsg);
}