#pragma once
#include "DeviceManager.h"
#include "Effect.h"
#include "Entity.h"
class Renderer
{
public:
	Renderer(IEffect* effect, IEntity* entity);
	~Renderer();
	IEffect* GetEffect();
	IEntity* GetEntity();
protected:
	IEffect* m_Effect;
	IEntity* m_Entity;
};

