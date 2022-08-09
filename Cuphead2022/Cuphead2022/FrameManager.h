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

	double		_dDeltaTime;
	double		_dSecondPerFrame;	// 1/60 �ɰ����� ���� ����

	int			_iFPS;
	TCHAR		_szFPS[32];
	double		_dFPSTime;
};


#endif