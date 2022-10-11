#include "stdafx.h"
#include "TestScene.h"
#include "BitmapManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
	Release();
}

void TestScene::Initialize()
{
	BitmapManager::GetInstance()->InsertBmp(L"../Image/Background/TestScene.bmp", L"TestScene");

	// °´Ã¼ »ý¼º
	_pPlayer = AbstractFactory<Player>::Create();
	ObjectManager::GetInstance()->AddObject(OBJID::PLAYER, _pPlayer);
}

void TestScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void TestScene::LateUpdate()
{
	ObjectManager::GetInstance()->LateUpdate();
}

void TestScene::Render(HDC dc)
{
	HDC hMemDC = BitmapManager::GetInstance()->FindImage(L"TestScene");
	BitBlt(dc, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	ObjectManager::GetInstance()->Render(dc);
}

void TestScene::Release()
{
	ObjectManager::GetInstance()->DeleteID(OBJID::PLAYER);
}
