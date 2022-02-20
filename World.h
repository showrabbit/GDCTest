#pragma once

#include "Renderer.h"
#include "Camera.h"
#include <list>
#include <d3d11.h>
#include "Entity.h"
#include "LightManager.h"

using namespace std;

class World
{
public:
	void AddRender(Renderer* render);
	void RemoveRender(Renderer* render);
	void SetMainCamera(Camera* camera);
	Camera* GetMainCamera();

	void Tick();

private:
	std::list<Renderer*> m_Renders;
	Camera* m_MainCamera;
};

