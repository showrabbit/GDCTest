#pragma once
#include "Effect.h"
#include <Windows.h>

class EffectInputLayoutElementDesc
{
public:
	static void Create(enum EffectType type, UINT* elementCount, D3D11_INPUT_ELEMENT_DESC** layout);
};

