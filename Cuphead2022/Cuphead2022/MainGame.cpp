#include "stdafx.h"
#include "MainGame.h"
#include "ObjectManager.h"
#include "BitmapManager.h"
#include "SceneManager.h"
#include "KeyManager.h"
#include "ScrollManager.h"
#include "SoundManager.h"
#include "TimeManager.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	//SoundManager::Get_Instance()->Initialize();
	BitmapManager::GetInstance()->InsertBmp(L"../Image/Background/Background.bmp", L"Back");
	BitmapManager::GetInstance()->InsertBmp(L"../Image/Background/BackBuffer.bmp", L"BackBuffer");

	_DC = GetDC(g_hWnd);

	TimeManager::GetInstance()->Initialize();
	SceneManager::GetInstance()->SceneChange(SceneManager::TEST);
}

void MainGame::Update()
{
	SceneManager::GetInstance()->Update();
}

void MainGame::LateUpdate()
{
	SceneManager::GetInstance()->LateUpdate();
	KeyManager::GetInstance()->KeyUpdate();
	TimeManager::GetInstance()->Update();
	ScrollManager::GetInstance()->ScrollLock();
}

void MainGame::Render()
{
	HDC hMemDC = BitmapManager::GetInstance()->FindImage(L"Back");
	HDC hBackBuffer = BitmapManager::GetInstance()->FindImage(L"BackBuffer");

	BitBlt(hBackBuffer, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	
	SceneManager::GetInstance()->Render(hBackBuffer);
	
	BitBlt(_DC, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);
}

void MainGame::Release()
{
	ReleaseDC(g_hWnd, _DC);

	KeyManager::DestroyInstance();
	TimeManager::DestroyInstance();
	ScrollManager::DestroyInstance();
	BitmapManager::DestroyInstance();
	SceneManager::DestroyInstance();
	//SoundManager::Destroy_Instance();

	ObjectManager::DestroyInstance();
}
