#pragma once

#ifndef __MAPSCENE_H__
#define __MAPSCENE_H__
#include "Scene.h"

class MapScene : public Scene
{
public:
	MapScene();
	virtual ~MapScene();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC dc) override;
	virtual void Release() override;

};

#endif