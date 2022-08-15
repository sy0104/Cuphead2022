#include "stdafx.h"
#include "SceneManager.h"
#include "MapScene.h"
#include "TestScene.h"

IMPLEMENT_SINGLETON(SceneManager);

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	_pScene->Update();
}

void SceneManager::LateUpdate()
{
	_pScene->LateUpdate();
}

void SceneManager::Render(HDC dc)
{
	_pScene->Render(dc);
}

void SceneManager::Release()
{
	SAFE_DELETE(_pScene);
}

void SceneManager::SceneChange(SCENEID eID)
{
	_eCurScene = eID;

	if (_ePreScene != _eCurScene)
	{
		SAFE_DELETE(_pScene);

		switch (_eCurScene)
		{
		case MAP:
			_pScene = new MapScene;
			break;
		case TEST:
			_pScene = new TestScene;
			break;
		}
		_pScene->Initialize();
		_ePreScene = _eCurScene;
	}

}
