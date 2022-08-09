#pragma once

#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

class Object;

class ObjectManager
{
	DECLARE_SINGLETON(ObjectManager);

private:
	ObjectManager();
	~ObjectManager();

public:
	void AddObject(OBJID::ID eID, Object* pObj);
	void Update();
	void LateUpdate();
	void Render(HDC dc);
	void Release();

public:
	Object* GetPlayer();
	Object* GetTarget(OBJID::ID eID, Object* pObj);
	list<Object*>& GetList(OBJID::ID eID) { return _listObject[eID]; }

public:
	void DeleteID(OBJID::ID eID);

private:
	list<Object*>			_listObject[OBJID::END];
	list<Object*>			_listRender[GROUPID::END];
};

#endif