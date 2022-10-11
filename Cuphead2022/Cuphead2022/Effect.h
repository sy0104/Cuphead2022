#pragma once
#include "Object.h"
class Effect : public Object
{
public:
	enum EFFECT { JUMPDUST, };

public:
	Effect();
	Effect(float x, float y, EFFECT effect);
	virtual ~Effect();

protected:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;
	virtual void FrameMove() override;
};

