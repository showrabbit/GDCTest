#pragma once
#include <d3d11.h>
#include "DeviceManager.h"
#include "Common.h"

class DepthStencilView
{
public:
	DepthStencilView(int width, int height, DXGI_FORMAT format);
	void Get(ID3D11DepthStencilView** view, ID3D11Texture2D** buffer);

protected:
	~DepthStencilView();
	void Init(int widht, int height, DXGI_FORMAT format);

private:
	ID3D11DepthStencilView* m_View;
	ID3D11Texture2D* m_Buffer;
};

