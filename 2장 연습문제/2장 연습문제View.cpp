
// 2장 연습문제View.cpp: CMy2장연습문제View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2장 연습문제.h"
#endif

#include "2장 연습문제Doc.h"
#include "2장 연습문제View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2장연습문제View

IMPLEMENT_DYNCREATE(CMy2장연습문제View, CView)

BEGIN_MESSAGE_MAP(CMy2장연습문제View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMy2장연습문제View 생성/소멸

CMy2장연습문제View::CMy2장연습문제View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy2장연습문제View::~CMy2장연습문제View()
{
}

BOOL CMy2장연습문제View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2장연습문제View 그리기

void CMy2장연습문제View::OnDraw(CDC*pDC)
{
	CMy2장연습문제Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	pDC->TextOut(m_ptMouseMove.x, m_ptMouseMove.y, m_strMouseMove);
	
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy2장연습문제View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2장연습문제View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2장연습문제View 진단

#ifdef _DEBUG
void CMy2장연습문제View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2장연습문제View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2장연습문제Doc* CMy2장연습문제View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2장연습문제Doc)));
	return (CMy2장연습문제Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2장연습문제View 메시지 처리기


void CMy2장연습문제View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptMouseMove = point;
	m_strMouseMove.Format(_T("X: %d Y: %d"), m_ptMouseMove.x, m_ptMouseMove.y);
	Invalidate();

	CRect;

	CView::OnMouseMove(nFlags, point);
}


int CMy2장연습문제View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	

	return 0;
}
