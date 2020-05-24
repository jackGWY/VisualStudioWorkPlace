
// MFCHelloView.cpp : CMFCHelloView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCHello.h"
#endif

#include "MFCHelloDoc.h"
#include "MFCHelloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHelloView

IMPLEMENT_DYNCREATE(CMFCHelloView, CView)

BEGIN_MESSAGE_MAP(CMFCHelloView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCHelloView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCHelloView ����/����

CMFCHelloView::CMFCHelloView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCHelloView::~CMFCHelloView()
{
}

BOOL CMFCHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCHelloView ����

void CMFCHelloView::OnDraw(CDC* /*pDC*/)
{
	CMFCHelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCHelloView ��ӡ


void CMFCHelloView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCHelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCHelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCHelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CMFCHelloView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCHelloView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCHelloView ���

#ifdef _DEBUG
void CMFCHelloView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHelloDoc* CMFCHelloView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHelloDoc)));
	return (CMFCHelloDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHelloView ��Ϣ�������
