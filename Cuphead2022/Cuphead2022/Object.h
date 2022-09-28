#pragma once

#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object abstract
{
public:
	Object();
	virtual ~Object();

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC dc) = 0;
	virtual void Release() = 0;

public:
	const RECT& GetRect() { return _tRect; }
	const INFO& GetInfo() { return _tInfo; }
	const FRAME& GetFrame() { return _tFrame; }
	const GROUPID::ID GetGroupID() { return _eGroupID; }
	const bool GetIsDead() { return _isDead; }

public:
	void SetPos(float x, float y) { _tInfo.fX = x; _tInfo.fY = y; }
	void SetAngle(float angle) { _fAngle = angle; }
	void SetDead(bool value) { _isDead = value; }
	void SetFrameKey(TCHAR* frameKey) { _pFrameKey = frameKey; }

protected:
	void UpdateRect();
	virtual void FrameMove();

protected:
	INFO	_tInfo;
	RECT	_tRect;
	FRAME	_tFrame;

	bool	_isDead = false;
	float	_fAngle = 0.f;
	float	_fSpeed;

	TCHAR*	_pFrameKey = nullptr;

	GROUPID::ID		_eGroupID;
};

#endif