#pragma once
#include "DeviceManager.h"
#include "RenderTargetType.h"
#include<D3D11.h>


class RenderTarget
{
public:
	RenderTarget(RenderTargetType type, int width, int height);

	void Init(int width, int height);
	void Get(ID3D11RenderTargetView** view, ID3D11Texture2D** texture);
protected:
	RenderTargetType m_Type;
	int m_Width;
	int m_Height;
	ID3D11RenderTargetView* m_RenderTargetView;
	ID3D11Texture2D* m_RenderTarget;

};

