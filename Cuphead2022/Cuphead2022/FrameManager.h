#pragma once

#ifndef __FRAMEMANAGER_H__
#define __FRAMEMANAGER_H__

class FrameManager
{
public:
	FrameManager();
	~FrameManager();

public:
	void Initialize(const double& dFramePerSecond);
	void Render();
	bool Lock();

private:
	// ������ ����
	LARGE_INTEGER	_cpuTick;
	LARGE_INTEGER	_beginTime;
	LARGE_INTEGER	_endTime;

	double		_dDeltaTime = 0.0;
	double		_dSecondPerFrame = 0.0;	// 1/60 �ɰ����� ���� ����

	int			_iFPS = 0;
	TCHAR		_szFPS[32] = L"";
	double		_dFPSTime = 0.0;
};


#endif