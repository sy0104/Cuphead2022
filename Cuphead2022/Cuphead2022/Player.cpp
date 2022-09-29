#include "stdafx.h"
#include "Player.h"
#include "BitmapManager.h"

Player::Player()
{
}

Player::~Player()
{
    Release();
}

void Player::Initialize()
{
#pragma region InsertImage
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Idle.bmp", L"Player_Idle");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Run.bmp", L"Player_Run");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Stretch.bmp", L"Stretch");
#pragma endregion

    _tInfo.fX = 200.f;
    _tInfo.fY = 550.f;
    _tInfo.iCX = 100;
    _tInfo.iCY = 155;

    _fSpeed = 8.f;

    _tFrame.iFrameStart = 0;
    _tFrame.iFrameEnd = 7;
    _tFrame.iFrameScene = 0;
    _tFrame.iBmpCX = 100;
    _tFrame.iBmpCY = 155;
    _tFrame.dwFrameSpeed = 70;
    _tFrame.dwFrameTime = GetTickCount64();
    _pFrameKey = (TCHAR*)(L"Player_Idle");

    _eGroupID = GROUPID::OBJECT;
}

int Player::Update()
{
    if (_isDead) return OBJ_DEAD;

    KeyCheck();
    SceneChange();
    FrameMove();
    UpdateRect();

    return OBJ_NOEVENT;
}

void Player::LateUpdate()
{
}

void Player::Render(HDC dc)
{
    UpdateRect();

    HDC hMemDC = BitmapManager::GetInstance()->FindImage(_pFrameKey);
    HDC hStretch = BitmapManager::GetInstance()->FindImage(L"Stretch");

    if (_eDir == DIR::RIGHT)
    {
        GdiTransparentBlt(dc
            , _tRect.left, _tRect.top
            , _tInfo.iCX, _tInfo.iCY
            , hMemDC
            , _tFrame.iFrameStart * _tFrame.iBmpCX, _tFrame.iFrameScene * _tFrame.iBmpCY
            , _tFrame.iBmpCX, _tFrame.iBmpCY
            , RGB(70, 70, 70));
    }

    else
    {
        StretchBlt(hStretch
            , 0, 0
            , _tFrame.iBmpCX, _tFrame.iBmpCY
            , hMemDC
            , _tFrame.iFrameStart * _tFrame.iBmpCX + _tFrame.iBmpCX, _tFrame.iFrameScene * _tFrame.iBmpCY
            , -_tFrame.iBmpCX, _tFrame.iBmpCY
            , SRCCOPY);

        GdiTransparentBlt(dc
            , _tRect.left, _tRect.top
            , _tInfo.iCX, _tInfo.iCY
            , hStretch
            , 0, 0
            , _tFrame.iBmpCX, _tFrame.iBmpCY
            , RGB(70, 70, 70));

    }
}

void Player::Release()
{
}

void Player::KeyCheck()
{
}

void Player::SceneChange()
{
    if (_ePreScene != _eCurScene)
    {
        switch (_eCurScene)
        {
        case STATE::IDLE:
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 70;
            _tFrame.iBmpCX = 100;
            _tFrame.iBmpCY = 155;
            break;
        case STATE::WALK:

            break;
        }
        _ePreScene = _eCurScene;
    }
}
