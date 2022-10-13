#pragma once
#include "Object.h"
class JumpDust : public Object
{
public:
	JumpDust();
	virtual ~JumpDust();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;
	virtual void FrameMove() override;
};

