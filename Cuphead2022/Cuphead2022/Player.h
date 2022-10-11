#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	virtual ~Player();

public:
	enum STATE { INTRO, IDLE, RUN, JUMP,	// 기본 동작
				AIM_STRAIGHT, AIM_UP, AIM_DOWN, AIM_DIAUP, AIM_DIADOWN,		// 에임
				PARRY, SHOOT, HIT, DEATH, GHOST,	// 공격, 피격
				STATE_END };
	enum DIR { LEFT, RIGHT, UP, DOWN, DIR_END };

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;
	virtual void FrameMove() override;

private:
	void KeyCheck();
	void Jumping();
	void SceneChange();

private:
	STATE	_ePreScene = STATE::INTRO;
	STATE	_eCurScene = STATE::INTRO;
	DIR		_eDir = DIR::RIGHT;

	bool	_isIntro = false;
	bool	_isAim = false;
	bool	_isMove = false;
	bool	_isJump = false;

	float	_fJumpTime = 0.f;
	float	_fJumpSpeed = 0.f;
	float	_fJumpPower = 20.f;
};

