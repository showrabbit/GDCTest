#include "Viewport.h"

Viewport::Viewport(int width, int height, float minDepth, float maxDepth, float topLeftX, float topLeftY)
{
	m_Width = width;
	m_Height = height;
	m_MinDepth = minDepth;
	m_MaxDepth = maxDepth;
	m_TopLeftX = topLeftX;
	m_TopLeftY = topLeftY;
}

Viewport::~Viewport()
{

}

void Viewport::Get(D3D11_VIEWPORT* viewPort)
{
	viewPort->Height = this->m_Height;
	viewPort->Width = this->m_Width;
	viewPort->MaxDepth = this->m_MaxDepth;
	viewPort->MinDepth = this->m_MinDepth;
	viewPort->TopLeftX = this->m_TopLeftX;
	viewPort->TopLeftY = this->m_TopLeftY;
}