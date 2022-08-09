#include "stdafx.h"
#include "TimeManager.h"

IMPLEMENT_SINGLETON(TimeManager);

TimeManager::TimeManager()
{
}

TimeManager::~TimeManager()
{
}

HRESULT TimeManager::Initialize()
{
	_dDeltaTime = 0.0;

	QueryPerformanceFrequency(&_cpuTick);

	QueryPerformanceCounter(&_preTime);
	QueryPerformanceCounter(&_curTime);

	return S_OK;
}

void TimeManager::Update()
{
	QueryPerformanceFrequency(&_cpuTick);
	QueryPerformanceCounter(&_curTime);

	_dDeltaTime = double(_curTime.QuadPart - _preTime.QuadPart) / _cpuTick.QuadPart;

	_preTime = _curTime;
}
