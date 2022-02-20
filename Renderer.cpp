#include "Renderer.h"

Renderer::Renderer(IEffect* effect, IEntity* entity)
{
	m_Effect = effect;
	m_Entity = entity;
}

Renderer::~Renderer()
{

}

IEffect* Renderer::GetEffect()
{
	return m_Effect;
}

IEntity* Renderer::GetEntity()
{
	return m_Entity;
}