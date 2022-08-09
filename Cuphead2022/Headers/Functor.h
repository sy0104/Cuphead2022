#pragma once

#ifndef __FUNCTOR_H__
#define __FUNCTOR_H__

class CStrCmp
{
public:
	CStrCmp(const TCHAR* _str) : m_String(_str) {}

public:
	template <typename T>
	bool operator()(T& _iter)
	{
		return !lstrcmp(m_String, _iter.first);
	}


private:
	const TCHAR*	m_String;
};

#endif