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
	int		iFrameStart;
	int		iFrameEnd;
	int		iFrameScene;
	int		iBmpCX;
	int		iBmpCY;
	DWORD	dwFrameSpeed;
	DWORD	dwFrameTime;
}FRAME;


#endif