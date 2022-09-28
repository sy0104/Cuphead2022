#include "stdafx.h"
#include "Logo.h"
#include "BitmapManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Initialize()
{
	BitmapManager::GetInstance()->InsertBmp(L"../Image/Background/Logo.bmp", L"Logo");
}

void Logo::Update()
{
}

void Logo::LateUpdate()
{
}

void Logo::Render(HDC dc)
{
	HDC hMemDC = BitmapManager::GetInstance()->FindImage(L"Logo");
	BitBlt(dc, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void Logo::Release()
{
}
