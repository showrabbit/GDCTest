#include "RenderTarget.h"

RenderTarget::RenderTarget(RenderTargetType type, int width, int height)
{
	m_Type = type;
	m_Width = width;
	m_Height = height;
	Init(m_Width, m_Height);
}

void RenderTarget::Init(int width, int height)
{
	switch (m_Type)
	{
	case Window:
	{
		IDXGISwapChain* swapChain = DeviceManager::GetInstance()->GetSwapChain();

		CheckHR(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_RenderTarget));

		auto device = DeviceManager::GetInstance()->GetDevice();
		CheckHR(device->CreateRenderTargetView(m_RenderTarget, NULL, &m_RenderTargetView));
	}break;

	case Texture:
	{

	}break;

	default:
		break;
	}
}

void RenderTarget::Get(ID3D11RenderTargetView** view, ID3D11Texture2D** texture)
{
	if (m_RenderTargetView == NULL)
	{
		Init(m_Width, m_Height);
	}
	*view = m_RenderTargetView;
	*texture = m_RenderTarget;
}