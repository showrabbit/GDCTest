#include "UserInputManager.h"

void UserInputManager::Register(enum UserInputType type, UserInputListener* l)
{
	if (IsContain(type, l))
	{
		return;
	}

	//if (m_Listeners == nullptr)
	//{
	//	m_Listeners = new std::map<UserInputType, std::list<UserInputListener*>>();
	//}
	if (m_Listeners.count(type) <= 0)
	{
		std::list<UserInputListener*> list = {};
		m_Listeners.emplace(type, list);
	}

	auto it = m_Listeners.find(type);
	it->second.insert(it->second.end(), l);

}

void UserInputManager::UnRegister(enum UserInputType type, UserInputListener* l)
{
	if (!IsContain(type, l))
	{
		return;
	}

	auto listener = m_Listeners.find(type);
	listener->second.remove(l);
}



void UserInputManager::Trigger(UserInputType type, UserInputParam& param)
{
	auto listener = m_Listeners.find(type);
	if (listener == m_Listeners.end())
		return;
	auto datas = listener->second;
	auto its = datas.begin();
	while (its != datas.end())
	{
		auto l = (*its);
		its++;
		l->Execute(param);
	}
}

bool UserInputManager::IsContain(UserInputType type, UserInputListener* l)
{
	auto typeCount = m_Listeners.count(type);
	if (typeCount <= 0)
		return false;

	auto listener = m_Listeners.find(type);

	for (auto it = listener->second.begin(); it != listener->second.end(); ++it)
	{
		if ((*it) == l)
		{
			return true;
		}
	}
	return false;
}