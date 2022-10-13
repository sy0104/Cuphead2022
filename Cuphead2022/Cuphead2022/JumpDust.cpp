#include "stdafx.h"
#include "JumpDust.h"
#include "BitmapManager.h"

JumpDust::JumpDust()
{
}

JumpDust::~JumpDust()
{
    Release();
}

void JumpDust::Initialize()
{
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/JumpDust.bmp", L"Player_JumpDust");

    _tInfo.iCX = 285;
    _tInfo.iCY = 152;

    _tFrame.iFrameStart = 0;
    _tFrame.iFrameEnd = 13;
    _tFrame.iFrameScene = 0;
    _tFrame.dwFrameSpeed = 20;
    _tFrame.dwFrameTime = GetTickCount64();
    _pFrameKey = (TCHAR*)(L"Player_JumpDust");
    _eGroupID = GROUPID::EFFECT;
}

int JumpDust::Update()
{
    if (_isDead) return OBJ_DEAD;

    FrameMove();
    UpdateRect();

    return OBJ_NOEVENT;
}

void JumpDust::LateUpdate()
{
}

void JumpDust::Render(HDC dc)
{
    UpdateRect();

    HDC hMemDC = BitmapManager::GetInstance()->FindImage(_pFrameKey);

    GdiTransparentBlt(dc
        , _tRect.left, _tRect.top
        , _tInfo.iCX, _tInfo.iCY
        , hMemDC
        , _tFrame.iFrameStart * _tInfo.iCX, _tFrame.iFrameScene * _tInfo.iCY
        , _tInfo.iCX, _tInfo.iCY
        , RGB(70, 70, 70));
}

void JumpDust::Release()
{
}

void JumpDust::FrameMove()
{
    if (_tFrame.dwFrameTime + _tFrame.dwFrameSpeed < GetTickCount64()) {
        ++_tFrame.iFrameStart;

        if (_tFrame.iFrameStart > _tFrame.iFrameEnd)
            _isDead = true;

        _tFrame.dwFrameTime = GetTickCount64();
    }
}
