#pragma once

#ifndef __BITMAPMANAGER_H__
#define __BITMAPMANAGER_H__

class MyBitmap;

class BitmapManager
{
	DECLARE_SINGLETON(BitmapManager);

private:
	BitmapManager();
	~BitmapManager();

public:
	void InsertBmp(const TCHAR* filePath, const TCHAR* imageKey);
	HDC FindImage(const TCHAR* imageKey);
	void Release();

private:
	map<const TCHAR*, MyBitmap*>	_mapBit;
};

#endif