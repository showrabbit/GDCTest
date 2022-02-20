#include "World.h"

void World::AddRender(Renderer* render)
{
	m_Renders.insert(m_Renders.end(), render);
}

void World::RemoveRender(Renderer* render)
{
	m_Renders.remove(render);
}

void World::SetMainCamera(Camera* camera)
{
	m_MainCamera = camera;
}

Camera* World::GetMainCamera()
{
	return m_MainCamera;
}

void World::Tick()
{
	if (m_MainCamera == NULL)
		return;
	m_MainCamera->BeiginDraw();

	std::list<LightBase*>* lights = new std::list<LightBase*>;
	LightManager::Instance().Filter(m_MainCamera, lights);
	if (m_Renders.size() > 0)
	{
		list<Renderer*>::iterator it;
		for (it = m_Renders.begin(); it != m_Renders.end(); ++it)
		{
			IEffect* effect = (*it)->GetEffect();
			effect->BindDepthStencilState();
			effect->BindBlendState();
			effect->BindInputLayout();
			ConstantBuffer* cb = m_MainCamera->GetConstantBuffer();
			effect->BindVS();
			effect->BindConstantBufferVS(cb);
			effect->BindPS();
			effect->BindConstantBufferPS(cb);

			if (lights->size() > 0)
			{
				for (auto light = lights->begin(); light != lights->end(); ++light)
				{
					(*light)->Bind();
					auto lightCB = (*light)->GetConstantBuffer();
					if (lightCB == NULL)
						continue;
					effect->BindConstantBufferVS(lightCB);
					effect->BindConstantBufferPS(lightCB);
					IEntity* entity = (*it)->GetEntity();
					entity->Draw();
				}
			}
			else
			{
				IEntity* entity = (*it)->GetEntity();
				entity->Draw();
			}
		}
	}
	delete lights;
	m_MainCamera->EndDraw();
}