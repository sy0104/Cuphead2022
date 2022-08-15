#pragma once

#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

class Scene;

class SceneManager
{
	DECLARE_SINGLETON(SceneManager);

private:
	SceneManager();
	~SceneManager();

public:
	enum SCENEID { LOGO, MAP, TEST, END };

public:
	void Update();
	void LateUpdate();
	void Render(HDC dc);
	void Release();

public:
	void SceneChange(SCENEID eID);

private:
	Scene*		_pScene = nullptr;
	SCENEID		_ePreScene = SCENEID::END;
	SCENEID		_eCurScene = SCENEID::END;
};

#endif