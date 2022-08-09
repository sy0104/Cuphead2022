#include "stdafx.h"
#include "MyBitmap.h"

MyBitmap::MyBitmap()
{
}

MyBitmap::~MyBitmap()
{
	Release();
}

void MyBitmap::Load_Bmp(const TCHAR* _pFilePath)
{
	HDC hDC = GetDC(g_hWnd);
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	m_hBitmap = (HBITMAP)LoadImage(NULL, _pFilePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_hOldBmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

}

void MyBitmap::Release()
{
	SelectObject(m_hMemDC, m_hOldBmp);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}
