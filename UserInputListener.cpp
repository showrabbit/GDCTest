#include "UserInputListener.h"

UserInputListener::UserInputListener(IUserInputListenerHandler* handler)
{
	m_Handler = handler;
}

void UserInputListener::Execute(UserInputParam& param)
{
	m_Handler->OnKeyboard(param);
}