#include "stdafx.h"
#include "Player.h"
#include "BitmapManager.h"
#include "KeyManager.h"
#include "ObjectManager.h"
#include "Effect.h"
#include "JumpDust.h"

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
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Intro.bmp", L"Player_Intro");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Idle.bmp", L"Player_Idle");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Run_Normal.bmp", L"Player_Run");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Aim_Straight.bmp", L"Player_AimStraight");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Aim_Up.bmp", L"Player_AimUp");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Aim_Down.bmp", L"Player_AimDown");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Stretch.bmp", L"Stretch");
    BitmapManager::GetInstance()->InsertBmp(L"../Image/Cuphead/Jump.bmp", L"Player_Jump");
#pragma endregion

    _tInfo.fX = 200.f;
    _tInfo.fY = 550.f;
    _tInfo.iCX = 149;
    _tInfo.iCY = 166;

    _fSpeed = 6.f;

    _tFrame.iFrameStart = 0;
    _tFrame.iFrameEnd = 27;
    _tFrame.iFrameScene = 0;
    _tFrame.dwFrameSpeed = 70;
    _tFrame.dwFrameTime = GetTickCount64();
    _pFrameKey = (TCHAR*)(L"Player_Intro");

    _eGroupID = GROUPID::OBJECT;
}

int Player::Update()
{
    if (_isDead) return OBJ_DEAD;

    KeyCheck();
    Jumping();
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

    if (_eDir == DIR::RIGHT) {
        GdiTransparentBlt(dc
            , _tRect.left, _tRect.top
            , _tInfo.iCX, _tInfo.iCY
            , hMemDC
            , _tFrame.iFrameStart * _tInfo.iCX, _tFrame.iFrameScene * _tInfo.iCY
            , _tInfo.iCX, _tInfo.iCY
            , RGB(70, 70, 70));
    }

    else {
        StretchBlt(hStretch
            , 0, 0
            , _tInfo.iCX, _tInfo.iCY
            , hMemDC
            , _tFrame.iFrameStart * _tInfo.iCX + _tInfo.iCX, _tFrame.iFrameScene * _tInfo.iCY
            , -_tInfo.iCX, _tInfo.iCY
            , SRCCOPY);

        GdiTransparentBlt(dc
            , _tRect.left, _tRect.top
            , _tInfo.iCX, _tInfo.iCY
            , hStretch
            , 0, 0
            , _tInfo.iCX, _tInfo.iCY
            , RGB(70, 70, 70));

    }
}

void Player::Release()
{
}

void Player::FrameMove()
{
    if (_tFrame.dwFrameTime + _tFrame.dwFrameSpeed < GetTickCount64()) {
        ++_tFrame.iFrameStart;

        if (_tFrame.iFrameStart > _tFrame.iFrameEnd) {
            if (_eCurScene == INTRO) {
                _eCurScene = IDLE;
                _isIntro = true;
            }
            _tFrame.iFrameStart = 0;
        }

        _tFrame.dwFrameTime = GetTickCount64();
    }
}

void Player::KeyCheck()
{
    if (!_isIntro) return;

    // 이동
    if (KeyManager::GetInstance()->KeyPressing(VK_RIGHT) && !_isAim/* && !_isJump*/) {
        _isMove = true;
        _tInfo.fX += _fSpeed;
        if (!_isJump) {
            _eCurScene = STATE::RUN;
            _eDir = DIR::RIGHT;
        }
    }

    else if (KeyManager::GetInstance()->KeyPressing(VK_LEFT) && !_isAim/* && !_isJump*/) {
        _isMove = true;
        _tInfo.fX -= _fSpeed;
        if (!_isJump) {
            _eCurScene = STATE::RUN;
            _eDir = DIR::LEFT;
        }
    }

    else if (KeyManager::GetInstance()->KeyUp(VK_RIGHT) || KeyManager::GetInstance()->KeyUp(VK_LEFT))
        _isMove = false;

    // 에임
    if (KeyManager::GetInstance()->KeyPressing('C')) {
        _isAim = true;

        if (KeyManager::GetInstance()->KeyPressing(VK_RIGHT)) {
            _eDir = DIR::RIGHT;
            if (KeyManager::GetInstance()->KeyPressing(VK_UP)) _eCurScene = STATE::AIM_DIAUP;
            else if (KeyManager::GetInstance()->KeyPressing(VK_DOWN)) _eCurScene = STATE::AIM_DIADOWN;
            else _eCurScene = STATE::AIM_STRAIGHT;
        }
        else if (KeyManager::GetInstance()->KeyPressing(VK_LEFT)) {
            _eDir = DIR::LEFT;
            if (KeyManager::GetInstance()->KeyPressing(VK_UP)) _eCurScene = STATE::AIM_DIAUP;
            else if (KeyManager::GetInstance()->KeyPressing(VK_DOWN)) _eCurScene = STATE::AIM_DIADOWN;
            else _eCurScene = STATE::AIM_STRAIGHT;
        }
        else if (KeyManager::GetInstance()->KeyPressing(VK_UP)) {
            _eCurScene = STATE::AIM_UP;
        }
        else if (KeyManager::GetInstance()->KeyPressing(VK_DOWN)) {
            _eCurScene = STATE::AIM_DOWN;
        }
    }

    else if (KeyManager::GetInstance()->KeyUp('C')) _isAim = false;

    // 점프
    if (KeyManager::GetInstance()->KeyDown(VK_SPACE)) {
        _isJump = true;
        _eCurScene = STATE::JUMP;
    }

    else if (!_isMove && !_isAim && !_isJump) _eCurScene = STATE::IDLE;
}

void Player::Jumping()
{
    if (!_isJump) return;

    // 자연스러운 점프로 수정 필요
    _fJumpSpeed = _fJumpPower * _fJumpTime - 9.8f * _fJumpTime * _fJumpTime * 0.5f;
    if (_fJumpSpeed < -15.f) _fJumpSpeed = -15.f;

    _tInfo.fY -= _fJumpSpeed;
    _fJumpTime += 0.2f;

    if (_tInfo.fY > 550.f + (_tInfo.iCY >> 1)) {
        if (_isJump) {
            Object* jumpDust = AbstractFactory<JumpDust>::Create(_tInfo.fX, _tInfo.fY);
            ObjectManager::GetInstance()->AddObject(OBJID::EFFECT, jumpDust);
            _isJump = false;
        }

        _tInfo.fY = 550.f;
        _fJumpTime = 0.f;
        _fJumpSpeed = 0.f;
        _eCurScene = IDLE;
    }
}

void Player::SceneChange()
{
    if (_ePreScene != _eCurScene)
    {
        switch (_eCurScene)
        {
        case STATE::IDLE:
            _tInfo.iCX = 100;
            _tInfo.iCY = 155;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 70;
            _pFrameKey = (TCHAR*)(L"Player_Idle");
            break;
        case STATE::RUN:
            _tInfo.iCX = 135;
            _tInfo.iCY = 170;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 15;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_Run");
            break;
        case STATE::JUMP:
            _tInfo.iCX = 88;
            _tInfo.iCY = 109;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_Jump");
            break;
        case STATE::DUCK:
            _tInfo.iCX = 88;
            _tInfo.iCY = 109;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_Duck");
            break;
        case STATE::AIM_STRAIGHT:
            _tInfo.iCX = 134;
            _tInfo.iCY = 161;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_AimStraight");
            break;
        case STATE::AIM_UP:
            _tInfo.iCX = 108;
            _tInfo.iCY = 175;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_AimUp");
            break;
        case STATE::AIM_DOWN:
            _tInfo.iCX = 103;
            _tInfo.iCY = 168;
            _tFrame.iFrameStart = 0;
            _tFrame.iFrameEnd = 7;
            _tFrame.iFrameScene = 0;
            _tFrame.dwFrameSpeed = 50;
            _pFrameKey = (TCHAR*)(L"Player_AimDown");
            break;
        case STATE::AIM_DIAUP:

            break;
        case STATE::AIM_DIADOWN:

            break;
        }

        _tFrame.dwFrameTime = GetTickCount64();
        _ePreScene = _eCurScene;
    }
}
