#pragma once

#ifndef __ABSTRACTFACTORY_H__
#define __ABSTRACTFACTORY_H__

class Object;

template <typename T>
class AbstractFactory
{
public:
	static Object* Create()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Object* Create(float _x, float _y)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_x, _y);

		return pObj;
	}

	static Object* Create(float _x, float _y, float _fAngle)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_x, _y);
		pObj->SetAngle(_fAngle);

		return pObj;
	}
};

#endif