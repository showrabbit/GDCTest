#pragma once
#include <d3d11.h>
#include "DeviceManager.h"
#include "Maths.h"


class Viewport
{
public:
	Viewport(int width, int height, float minDepth, float maxDepth, float topLeftX, float topLeftY);
	~Viewport();

	void Get(D3D11_VIEWPORT* viewPort);

private:

	int m_Width;
	int m_Height;
	float m_MinDepth;
	float m_MaxDepth;
	float m_TopLeftX;
	float m_TopLeftY;

};

