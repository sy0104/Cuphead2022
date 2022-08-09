#pragma once

#ifndef __KEYMANAGER_H__
#define __KEYMANAGER_H__

#define VK_MAX 0xff

class KeyManager
{
	DECLARE_SINGLETON(KeyManager);

private:
	KeyManager();
	~KeyManager();

public:
	bool KeyPressing(int key);
	bool KeyDown(int key);
	bool KeyUp(int key);
	void KeyUpdate();

private:
	bool	bKeyState[VK_MAX];
};

#endif