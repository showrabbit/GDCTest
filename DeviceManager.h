#pragma once

#include <d3d11.h>
#include "Common.h"

class DeviceManager
{
public:
	HRESULT Init(int width, int height, HWND hwnd);
	void BeginDraw();
	void EndDraw();

	void Dispose();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
	IDXGISwapChain* GetSwapChain();
	static DeviceManager* GetInstance();

private:
	DeviceManager();
	~DeviceManager();

	static DeviceManager* m_Instance;

	ID3D11Device* m_Device = NULL;
	ID3D11DeviceContext* m_DeviceContext = NULL;
	ID3D11RenderTargetView* m_RenderTarget = NULL;
	IDXGISwapChain* m_SwapChain = NULL;
	D3D_FEATURE_LEVEL m_FeatureLevel;
};

