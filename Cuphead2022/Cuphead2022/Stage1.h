#pragma once
#include "Scene.h"

class Stage1 : public Scene
{
public:
	Stage1();
	virtual ~Stage1();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;
};

