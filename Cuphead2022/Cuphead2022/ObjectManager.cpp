#include "stdafx.h"
#include "ObjectManager.h"
#include "Object.h"
#include "CollisionManager.h"

IMPLEMENT_SINGLETON(ObjectManager);

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(OBJID::ID eID, Object* pObj)
{
	_listObject[eID].emplace_back(pObj);
}

void ObjectManager::Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		auto&& iter = _listObject[i].begin();

		for (; iter != _listObject[i].end(); )
		{
			int iEvent = (*iter)->Update();
			if (iEvent == OBJ_DEAD)
			{
				SAFE_DELETE(*iter);
				iter = _listObject[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void ObjectManager::LateUpdate()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : _listObject[i])
		{
			pObj->LateUpdate();
			if (_listObject[i].empty())
			{
				for (int i = 0; i < GROUPID::END; ++i)
					_listRender[i].clear();
				break;
			}

			GROUPID::ID eID = pObj->GetGroupID();
			_listRender[eID].emplace_back(pObj);
		}
	}

}

void ObjectManager::Render(HDC dc)
{
	for (int i = 0; i < GROUPID::END; ++i)
	{
		if (i == GROUPID::OBJECT)
			_listRender[i].sort(CompareX<Object*>);

		for (auto& pObj : _listRender[i])
			pObj->Render(dc);

		_listRender[i].clear();
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for_each(_listObject[i].begin(), _listObject[i].end(), Safe_Delete<Object*>);
		_listObject[i].clear();
	}
}

Object* ObjectManager::GetPlayer()
{
	return _listObject[OBJID::PLAYER].front();
}

Object* ObjectManager::GetTarget(OBJID::ID eID, Object* pObj)
{
	//if (_listObject[eID].empty())
	//	return nullptr;

	Object* pTarget = nullptr;
	//float	fDis = 0.f;

	//for (auto& obj : _listObject[eID])
	//{
	//	float fX = pObj->Get_Info().fX - obj->Get_Info().fX;
	//	float fY = pObj->Get_Info().fY - obj->Get_Info().fY;
	//	float fDia = sqrtf(fX * fX + fY * fY);

	//	if (!pTarget || fDis > fDia)
	//	{
	//		pTarget = obj;
	//		fDis = fDia;
	//	}
	//}

	return pTarget;
}

void ObjectManager::DeleteID(OBJID::ID eID)
{
	for_each(_listObject[eID].begin(), _listObject[eID].end(), Safe_Delete<Object*>);
	_listObject[eID].clear();
}
