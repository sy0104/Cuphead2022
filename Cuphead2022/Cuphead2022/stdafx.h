// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <time.h>

using namespace std;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif // _DEBUG


#include "Include.h"

// �������� �߰�
#include <io.h>
#include "fmod.h"
#pragma comment (lib, "fmodex_vc.lib")