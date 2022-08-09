#include "stdafx.h"
#include "ScrollManager.h"

IMPLEMENT_SINGLETON(ScrollManager);

ScrollManager::ScrollManager()
{
}

ScrollManager::~ScrollManager()
{
}

void ScrollManager::ScrollLock()
{
	if (_fScrollX > 0)
		_fScrollX = 0.f;

	if (_fScrollX < -(TILEX * TILECX - WINCX))
		_fScrollX = -(TILEX * TILECX - WINCX);

	if (_fScrollY > 0)
		_fScrollY = 0.f;

	if (_fScrollY < -(TILEY * TILECY - WINCY))
		_fScrollY = -(TILEY * TILECY - WINCY);
}
