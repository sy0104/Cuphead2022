#pragma once

#ifndef __MAINGAME_H__
#define __MAINGAME_H__

class FrameManager;
class Object;

class MainGame final
{
public:
	MainGame();
	~MainGame();

public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(const FrameManager& frameManager);
	void Release();
};


#endif