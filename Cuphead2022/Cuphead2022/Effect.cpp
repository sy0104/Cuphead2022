#include "stdafx.h"
#include "Effect.h"
#include "JumpDust.h"

Effect::Effect()
{
}

Effect::Effect(float x, float y, EFFECT effect)
{
    Object* effectObj;

    switch (effect)
    {
    case JUMPDUST:
        effectObj = new JumpDust();
        effectObj->SetPos(x, y);
        effectObj->Initialize();
        break;
    }

    _eGroupID = GROUPID::EFFECT;
}

Effect::~Effect()
{
    Release();
}

void Effect::Initialize()
{
}

int Effect::Update()
{
    return 0;
}

void Effect::LateUpdate()
{
}

void Effect::Render(HDC dc)
{
}

void Effect::Release()
{
}

void Effect::FrameMove()
{
    if (_tFrame.dwFrameTime + _tFrame.dwFrameSpeed < GetTickCount64()) {
        ++_tFrame.iFrameStart;

        if (_tFrame.iFrameStart > _tFrame.iFrameEnd)
            _isDead = true;

        _tFrame.dwFrameTime = GetTickCount64();
    }
}
