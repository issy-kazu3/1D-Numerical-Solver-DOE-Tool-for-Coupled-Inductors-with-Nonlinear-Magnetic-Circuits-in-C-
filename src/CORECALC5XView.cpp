// CORECALC5XView.cpp : CCORECALC5XView クラスの実装
//

#include "stdafx.h"
#include "CORECALC5X.h"

#include "CORECALC5XDoc.h"
#include "CORECALC5XView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCORECALC5XView

IMPLEMENT_DYNCREATE(CCORECALC5XView, CView)

BEGIN_MESSAGE_MAP(CCORECALC5XView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCORECALC5XView コンストラクション/デストラクション

CCORECALC5XView::CCORECALC5XView()
{
	// TODO: 構築コードをここに追加します。

}

CCORECALC5XView::~CCORECALC5XView()
{
}

BOOL CCORECALC5XView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CCORECALC5XView 描画

void CCORECALC5XView::OnDraw(CDC* pDC)
{
	CCORECALC5XDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	char str[1000];

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
	if(pDoc->percent==0){
//		pDC->ExtTextOut(0,0,ETO_OPAQUE   ,NULL,pDoc->txtout,NULL);
		pDC->TextOut(0,0,pDoc->txtout);

	}else if(pDoc->percent==100){
//		pDC->ExtTextOut(0,30,ETO_OPAQUE   ,NULL,pDoc->txtout,NULL);
		pDC->TextOut(0,30,pDoc->txtout);
	}else{
		pDoc->txtout="Status ";
		pDoc->txtout+=_itoa(pDoc->percent,str,10);
		pDoc->txtout+="% finished \n";
		pDC->TextOut(0,15,pDoc->txtout);


//		pDC->ExtTextOut(0,15,ETO_OPAQUE   ,NULL,pDoc->txtout,NULL);
	}

}


// CCORECALC5XView 印刷

BOOL CCORECALC5XView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CCORECALC5XView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CCORECALC5XView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CCORECALC5XView 診断

#ifdef _DEBUG
void CCORECALC5XView::AssertValid() const
{
	CView::AssertValid();
}

void CCORECALC5XView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCORECALC5XDoc* CCORECALC5XView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCORECALC5XDoc)));
	return (CCORECALC5XDoc*)m_pDocument;
}
#endif //_DEBUG


// CCORECALC5XView メッセージ ハンドラ

void CCORECALC5XView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO : ここに特定なコードを追加するか、もしくは基本クラスを呼び出してください。
	CCORECALC5XDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);

}
