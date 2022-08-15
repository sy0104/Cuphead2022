#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	virtual ~Player();

public:
	enum STATE { IDLE, WALK, STATE_END };
	enum DIR { LEFT, RIGHT, UP, DOWN, DIR_END };

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;

private:
	void KeyCheck();
	void SceneChange();

private:
	STATE	_ePreScene = STATE::IDLE;
	STATE	_eCurScene = STATE::IDLE;
	DIR		_eDir = DIR::RIGHT;

};

