#pragma once
#include "World.h"
class Engine
{
public:

	void SetWorld(World* world);
	World* GetWorld();
	void Execute();
	static Engine* GetInstance();

private:

	Engine();
	~Engine();

	World* m_World;
	static Engine* m_Instance;
};

