#pragma once

#ifndef __TESTSCENE_H__
#define __TESTSCENE_H__

#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;

private:
	Object*		_pPlayer = nullptr;
};


#endif