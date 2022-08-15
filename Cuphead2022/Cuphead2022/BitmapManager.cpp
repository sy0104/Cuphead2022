#include "stdafx.h"
#include "BitmapManager.h"
#include "MyBitmap.h"

IMPLEMENT_SINGLETON(BitmapManager);

BitmapManager::BitmapManager()
{
}

BitmapManager::~BitmapManager()
{
	Release();
}

void BitmapManager::InsertBmp(const TCHAR* filePath, const TCHAR* imageKey)
{
	auto&& iter = find_if(_mapBit.begin(), _mapBit.end(), CStrCmp(imageKey));

	if (_mapBit.end() == iter)
	{
		MyBitmap* pBmp = new MyBitmap;
		pBmp->Load_Bmp(filePath);

		_mapBit.emplace(imageKey, pBmp);
	}
}

HDC BitmapManager::FindImage(const TCHAR* imageKey)
{
	auto&& iter = find_if(_mapBit.begin(), _mapBit.end(), CStrCmp(imageKey));

	if (_mapBit.end() == iter)
		return nullptr;

	return iter->second->Get_MemDC();
}

void BitmapManager::Release()
{
	for (auto& iter : _mapBit)
		SAFE_DELETE(iter.second);

	_mapBit.clear();
}
