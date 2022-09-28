#pragma once

#ifndef __LOGO_H__
#define __LOGO_H__

#include "Scene.h"
class Logo : public Scene
{
public:
	Logo();
	virtual ~Logo();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;
};

#endif