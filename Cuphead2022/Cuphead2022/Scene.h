#pragma once

#ifndef __SCENE_H__
#define __SCENE_H__

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC dc) = 0;
	virtual void Release() = 0;
};


#endif