#include "DeviceManager.h"

DeviceManager* DeviceManager::m_Instance = NULL;
DeviceManager::DeviceManager()
{
	
}

DeviceManager::~DeviceManager()
{

}

HRESULT DeviceManager::Init(int width, int height, HWND hwnd)
{
	HRESULT hr = S_OK;
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(DXGI_SWAP_CHAIN_DESC));

	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;

	D3D_FEATURE_LEVEL levels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};

	UINT numLevels = ARRAYSIZE(levels);

	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, levels, numLevels, D3D11_SDK_VERSION, &sd, &m_SwapChain, &m_Device, &m_FeatureLevel, &m_DeviceContext);

	if (CheckHR(hr))
	{
		return hr;
	}

	return S_OK;
}

void DeviceManager::BeginDraw()
{

}

void DeviceManager::EndDraw()
{
	m_SwapChain->Present(0, 0);
}

void DeviceManager::Dispose()
{
	if (m_DeviceContext)
	{
		m_DeviceContext->ClearState();
		
	}
	if (m_RenderTarget)
		m_RenderTarget->Release();
	if (m_SwapChain)
		m_SwapChain->Release();
	if (m_DeviceContext)
		m_DeviceContext->Release();
	if (m_Device)
		m_Device->Release();
}

ID3D11Device* DeviceManager::GetDevice()
{
	return m_Device;
}

ID3D11DeviceContext* DeviceManager::GetDeviceContext()
{
	return m_DeviceContext;
}

IDXGISwapChain* DeviceManager::GetSwapChain()
{
	return m_SwapChain;
}

DeviceManager* DeviceManager::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new DeviceManager();
	}
	return m_Instance;
}
