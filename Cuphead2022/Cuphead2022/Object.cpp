#include "stdafx.h"
#include "Object.h"
#include "TimeManager.h"

Object::Object()
{
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

void Object::FrameMove(const double& frameSpeed)
{
	_tFrame.dFrameStart += _tFrame.dFrameEnd * TimeManager::GetInstance()->GetDeltaTime() * frameSpeed;

	if (_tFrame.dFrameStart >= _tFrame.dFrameEnd)
		_tFrame.dFrameStart = 0.0;
}

