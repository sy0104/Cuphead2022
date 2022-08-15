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
    _tInfo.iCY = 150;

    _fSpeed = 8.f;

    _tFrame.dFrameStart = 0;
    _tFrame.dFrameEnd = 6;
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
            , _tFrame.dFrameStart * 164, _tFrame.dFrameScene * 80
            , 164, 80
            , RGB(40, 40, 40));
    }

    else
    {
        StretchBlt(hStretch
            , 0, 0
            , 155, 175
            , hMemDC
            , _tFrame.dFrameStart * 155 + 155, _tFrame.dFrameScene * 175
            , -155, 175
            , SRCCOPY);

        GdiTransparentBlt(dc
            , _tRect.left, _tRect.top
            , _tInfo.iCX, _tInfo.iCY
            , hStretch
            , 0, 0
            , 155, 175
            , RGB(40, 40, 40));

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
            _tFrame.dFrameStart = 0;
            _tFrame.dFrameEnd = 4;
            _tFrame.dFrameScene = 0;
            _tFrame.dwFrameSpeed = 150;
            break;
        case STATE::WALK:

            break;
        }
        _ePreScene = _eCurScene;
    }
}
