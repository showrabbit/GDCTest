#include "UserInputKeyboard.h"

void UserInputKeyboard::Trigger(UINT key)
{
	if (key == 0x57 || key == 0x77)
	{
		// w
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::W;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}
	else if (key == 0x41 || key == 0x61)
	{
		//A
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::A;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}
	else if (key == 0x53 || key == 0x73)
	{
		// S
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::S;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}
	else if (key == 0x44 || key == 0x64)
	{
		// D
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::D;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}
	else if (key == 0x45 || key == 0x65)
	{
		// e
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::E;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}
	else if (key == 0x51 || key == 0x71)
	{
		// Q
		UserInputParam p = {};
		p.Key = UserInputKeyboardValue::Q;
		UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
	}


	//if(key == VK_DOWN)

	//UserInputParam p = {};
	//p.Key = key;
	//UserInputManager::Instance().Trigger(UserInputType::Keyboard, p);
}