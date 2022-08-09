#pragma once

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	float	fX;
	float	fY;
	int		iCX;
	int		iCY;
}INFO;

typedef struct tagFrame
{
	double	dFrameStart;
	double	dFrameEnd;
	double	dFrameScene;
	DWORD	dwFrameSpeed;
	DWORD	dwFrameTime;
}FRAME;


#endif