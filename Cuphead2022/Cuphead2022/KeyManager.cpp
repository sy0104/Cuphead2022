#include "stdafx.h"
#include "KeyManager.h"

IMPLEMENT_SINGLETON(KeyManager);

KeyManager::KeyManager()
{
	ZeroMemory(bKeyState, sizeof(bKeyState));
}

KeyManager::~KeyManager()
{
}

bool KeyManager::KeyPressing(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;
	return false;
}

bool KeyManager::KeyDown(int key)
{
	if (!bKeyState[key] && (GetAsyncKeyState(key) & 0x8000))
	{
		bKeyState[key] = !bKeyState[key];
		return true;
	}
	return false;
}

bool KeyManager::KeyUp(int key)
{
	if (bKeyState[key] && !(GetAsyncKeyState(key) & 0x8000))
	{
		bKeyState[key] = !bKeyState[key];
		return true;
	}
	return false;
}

void KeyManager::KeyUpdate()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		if (bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))
			bKeyState[i] = !bKeyState[i];
		if (!bKeyState[i] && (GetAsyncKeyState(i) & 0x8000))
			bKeyState[i] = !bKeyState[i];
	}
}
