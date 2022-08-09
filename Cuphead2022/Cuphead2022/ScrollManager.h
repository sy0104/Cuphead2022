#pragma once

#ifndef __SCROLLMANAGER_H__
#define __SCROLLMANAGER_H__

class ScrollManager
{
	DECLARE_SINGLETON(ScrollManager);

private:
	ScrollManager();
	~ScrollManager();

public:
	void ScrollLock();
	
public:
	const float GetScrollX() { return _fScrollX; }
	const float GetScrollY() { return _fScrollY; }

public:
	void SetScrollX(float x) { _fScrollX = x; }
	void SetScrollY(float y) { _fScrollY = y; }


private:
	float	_fScrollX = 0.f;
	float	_fScrollY = 0.f;
};

#endif