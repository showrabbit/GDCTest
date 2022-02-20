#include "LightManager.h"


LightManager::LightManager()
{
	m_Lights = new std::map<LightBase*, LightBase*>;
}

LightManager::~LightManager()
{
	for (auto it = m_Lights->begin(); it != m_Lights->end(); ++it)
	{
		(*it).second->Dispose();
	}
	m_Lights->clear();
	delete m_Lights;
}

LightBase* LightManager::Add(enum LightType type,UINT index)
{
	if (type == LightType::Diffuse)
	{
		LightDirect* light = new LightDirect(index);
		(*m_Lights)[(LightBase*)light] = light;
		return light;
	}
	return NULL;
}

void LightManager::Delete(LightBase* l)
{
	if (m_Lights->count(l) > 0)
	{
		m_Lights->erase(l);
	}
}

void LightManager::Filter(Camera* targetCamera, std::list<LightBase*>* lights)
{
	for (auto it = m_Lights->begin(); it != m_Lights->end(); ++it)
	{
		// 根据摄像机过滤光源
		lights->insert(lights->end(), (*it).second);
	}
}
