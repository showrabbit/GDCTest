#pragma once
#include "Camera.h"
#include "LightBase.h"
#include "LightDirect.h"
#include "Singleton.h"
#include <map>
#include <list>

enum LightType
{
	Diffuse,
};

class LightManager : public Singleton<LightManager>
{
public:
	LightManager();
	~LightManager();
	LightBase* Add(enum LightType type,UINT index);
	void Delete(LightBase* light);
	// 根据摄像机绑定对应的light
	void Filter(Camera* targetCamera, std::list<LightBase*> *lights);

private:
	std::map<LightBase*, LightBase*> *m_Lights;
};

