#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	virtual ~Player();

public:
	enum STATE { INTRO, IDLE, RUN, AIM_STRAIGHT, AIM_UP, AIM_DOWN, AIM_DIAUP, AIM_DIADOWN,
				 JUMP, PARRY, SHOOT, HIT, DEATH, GHOST, STATE_END };
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

	bool	_isAim = false;
	bool	_isMove = false;
	bool	_isJump = false;

};

