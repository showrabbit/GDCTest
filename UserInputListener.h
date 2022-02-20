#pragma once
#include "UserInputParam.h"

//typedef void (*UserInputListenerHandler)(UserInputParam&);

__interface IUserInputListenerHandler
{
	void OnKeyboard(UserInputParam& p);
};

class UserInputListener
{
public:

	UserInputListener(IUserInputListenerHandler* handler);

	void Execute(UserInputParam& param);

protected:
	IUserInputListenerHandler* m_Handler;
};

