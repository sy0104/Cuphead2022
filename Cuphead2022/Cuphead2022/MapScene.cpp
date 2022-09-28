#include "stdafx.h"
#include "MapScene.h"
#include "ObjectManager.h"
#include "ScrollManager.h"
#include "BitmapManager.h"

MapScene::MapScene()
{
}

MapScene::~MapScene()
{
	Release();
}

void MapScene::Initialize()
{
	BitmapManager::GetInstance()->InsertBitmap(L"../Image/Background/Map.bmp", L"Map");
}

void MapScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void MapScene::LateUpdate()
{
	ObjectManager::GetInstance()->LateUpdate();
}

void MapScene::Render(HDC dc)
{
	int iScrollX = (int)ScrollManager::GetInstance()->GetScrollX();
	int iScrollY = (int)ScrollManager::GetInstance()->GetScrollY();

	HDC hMemDC = BitmapManager::GetInstance()->FindImage(L"Map");
	//BitBlt(dc, 0, 0, WINCX, WINCY, hMemDC, -iScrollX, -iScrollY, SRCCOPY);

	ObjectManager::GetInstance()->Render(dc);
}

void MapScene::Release()
{
	//ObjectManager::GetInstance()->DeleteID(OBJID::PLAYER);
}
