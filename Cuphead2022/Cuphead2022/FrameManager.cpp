#include "stdafx.h"
#include "FrameManager.h"
#include "TimeManager.h"

FrameManager::FrameManager()
{
	ZeroMemory(&_cpuTick, sizeof(LARGE_INTEGER));
	ZeroMemory(&_beginTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&_endTime, sizeof(LARGE_INTEGER));
}

FrameManager::~FrameManager()
{
}

void FrameManager::Initialize(const double& dFramePerSecond)
{
	_dSecondPerFrame = 1.0 / dFramePerSecond;

	QueryPerformanceFrequency(&_cpuTick);
	QueryPerformanceCounter(&_endTime);
	QueryPerformanceCounter(&_beginTime);
}

void FrameManager::Render()
{
	_dFPSTime += TimeManager::GetInstance()->GetDeltaTime();

	if (_dFPSTime > 1.0)
	{
		//	swprintf_s(m_szFPS, L"FPS: %d", m_iFPS);
		_dFPSTime = 0.0;
		_iFPS = 0;
	}
}

bool FrameManager::Lock()
{
	QueryPerformanceFrequency(&_cpuTick);
	QueryPerformanceCounter(&_endTime);

	_dDeltaTime += double(_endTime.QuadPart - _beginTime.QuadPart) / _cpuTick.QuadPart;
	_beginTime = _endTime;

	if (_dSecondPerFrame < _dDeltaTime)
	{
		_dDeltaTime = 0.0;
		++_iFPS;
		return true;
	}

	return false;
}
