//ReflectionWnd.cpp : Implementation of CReflectionWnd

//***************************************************************************//
//                                                                           //
//  This file was created using the CWindowImpl ATL Object Wizard            //
//  By Erik Thompson 2000                                                  //
//	Version 1.1                                                              //
//  Email questions and comments to ErikT@RadBytes.com                       //
//                                                                           //
//***************************************************************************//

#include "stdafx.h"
#include "ReflectionWnd.h"

/////////////////////////////////////////////////////////////////////////////
// CReflectionWnd

CReflectionWnd::CReflectionWnd()
{
}

CReflectionWnd::~CReflectionWnd()
{
	if (IsWindow())	DestroyWindow();
}

const DWORD DEFAULT_TOOLBAR_STYLE = 
		/*Window styles:*/ WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | //���Toolbar, ������WS_CLIPCHILDREN
		/*Toolbar styles:*/ TBSTYLE_FLAT | TBSTYLE_LIST | 
            TBSTYLE_TOOLTIPS | TBSTYLE_TRANSPARENT | TBSTYLE_CUSTOMERASE |TBSTYLE_WRAPABLE |   //��Щ������Toolbar��û��
		/*Common Control styles:*/ CCS_TOP | CCS_NODIVIDER | CCS_NOPARENTALIGN | CCS_NORESIZE;

LRESULT CReflectionWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    BOOL bRet = FALSE;
	RECT rect;
	GetClientRect(&rect);
    FTLTRACE(TEXT("%s, m_hWnd=0x%x, rect=%s\n"), TEXT(__FUNCTION__), m_hWnd, CFRectDumpInfo(rect).GetConvertedInfo());

    //�ڴ˴�������ʵ��ToolBar
	API_VERIFY(NULL != m_ToolbarWnd.Create(m_hWnd, rect, TEXT("m_ToolbarWnd"), DEFAULT_TOOLBAR_STYLE));
	return 0;
}