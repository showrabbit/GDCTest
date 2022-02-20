#include "Engine.h"

Engine* Engine::m_Instance = NULL;

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::SetWorld(World* world)
{
	m_World = world;
}

World* Engine::GetWorld()
{
	return m_World;
}

Engine* Engine::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new Engine();
	}
	return m_Instance;
}

void Engine::Execute()
{
	if (m_World == NULL)
		return;

	m_World->Tick();
}