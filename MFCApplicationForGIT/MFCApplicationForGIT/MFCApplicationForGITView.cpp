
// MFCApplicationForGITView.cpp : implementation of the CMFCApplicationForGITView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplicationForGIT.h"
#endif

#include "MFCApplicationForGITDoc.h"
#include "MFCApplicationForGITView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationForGITView

IMPLEMENT_DYNCREATE(CMFCApplicationForGITView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationForGITView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationForGITView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationForGITView construction/destruction

CMFCApplicationForGITView::CMFCApplicationForGITView() noexcept
{
	// TODO: add construction code here

}

CMFCApplicationForGITView::~CMFCApplicationForGITView()
{
}

BOOL CMFCApplicationForGITView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationForGITView drawing

void CMFCApplicationForGITView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationForGITDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplicationForGITView printing


void CMFCApplicationForGITView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationForGITView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationForGITView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplicationForGITView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplicationForGITView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationForGITView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationForGITView diagnostics

#ifdef _DEBUG
void CMFCApplicationForGITView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationForGITView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationForGITDoc* CMFCApplicationForGITView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationForGITDoc)));
	return (CMFCApplicationForGITDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationForGITView message handlers
