#pragma once

#ifndef __DEFINE_H__
#define __DEFINE_H__

#define WINCX 1200
#define WINCY 700

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

#define OBJ_DEAD	1
#define OBJ_NOEVENT 0

#define PI 3.1415f

#define TILECX 64
#define TILECY 53

#define TILEX 30
#define TILEY 20


#define DECLARE_SINGLETON(Class)		\
public:									\
static Class* GetInstance()				\
{										\
	if (nullptr == _pInstance)			\
		_pInstance = new Class;			\
	return _pInstance;					\
}										\
static void DestroyInstance()			\
{										\
	if (_pInstance)						\
	{									\
		delete _pInstance;				\
		_pInstance = nullptr;			\
	}									\
}										\
private:								\
	static Class* _pInstance;

#define IMPLEMENT_SINGLETON(Class)		\
Class* Class::_pInstance = nullptr;


#endif