#pragma once

#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__

class TimeManager
{
	DECLARE_SINGLETON(TimeManager);
	
private:
	TimeManager();
	~TimeManager();

public:
	HRESULT Initialize();
	void Update();

public:
	double GetDeltaTime() { return _dDeltaTime; }

private:
	LARGE_INTEGER	_cpuTick;
	LARGE_INTEGER	_preTime;
	LARGE_INTEGER	_curTime;
	double			_dDeltaTime;
};

#endif