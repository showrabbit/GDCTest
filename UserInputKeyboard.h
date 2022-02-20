#pragma once
#include <Windows.h>
#include "UserInputManager.h"
using namespace std;


enum UserInputKeyboardValue
{
	A = 0x41,
	D = 0x44,
	E = 0x45,
	Q = 0x51,
	S = 0x53,
	W = 0x57
};



class UserInputKeyboard
{
public:

	void Trigger(UINT key);

protected:


};

