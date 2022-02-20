#pragma once
#include "Singleton.h"
#include "UserInputListener.h"
#include "UserInputParam.h"
#include <map>
#include <list>

using namespace std;

typedef std::list<UserInputListener*> UserInputListenerList;

class UserInputManager : public Singleton<UserInputManager>
{
public:

	void Register(enum UserInputType type, UserInputListener* l);
	void UnRegister(enum UserInputType type, UserInputListener* l);

	void Trigger(UserInputType type, UserInputParam& param);

protected:
	bool IsContain(UserInputType type, UserInputListener* l);
	std::map<UserInputType, UserInputListenerList> m_Listeners;
};

