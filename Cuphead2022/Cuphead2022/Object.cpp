#include "stdafx.h"
#include "Object.h"
#include "TimeManager.h"

Object::Object()
{
	ZeroMemory(&_tInfo, sizeof(_tInfo));
	ZeroMemory(&_tRect, sizeof(_tRect));
	ZeroMemory(&_tFrame, sizeof(_tFrame));
}

Object::~Object()
{
}

void Object::UpdateRect()
{
	_tRect.left = (LONG)(_tInfo.fX - (_tInfo.iCX >> 1));
	_tRect.top = (LONG)(_tInfo.fY - (_tInfo.iCY >> 1));
	_tRect.right = (LONG)(_tInfo.fX + (_tInfo.iCX >> 1));
	_tRect.bottom = (LONG)(_tInfo.fY + (_tInfo.iCY >> 1));
}

void Object::FrameMove()
{
	if (_tFrame.dwFrameTime + _tFrame.dwFrameSpeed < GetTickCount64()) {
		++_tFrame.iFrameStart;

		if (_tFrame.iFrameStart > _tFrame.iFrameEnd)
			_tFrame.iFrameStart = 0;

		_tFrame.dwFrameTime = GetTickCount64();
	}
}

