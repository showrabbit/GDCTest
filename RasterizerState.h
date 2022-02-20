#pragma once
#include<D3D11.h>
#include "DeviceManager.h"
#include "Common.h"


class RasterizerState
{
public:
	RasterizerState();
	~RasterizerState();
	void Init(
		D3D11_FILL_MODE fillMode = D3D11_FILL_SOLID,
		D3D11_CULL_MODE cullMode = D3D11_CULL_BACK,
		BOOL clockWise = true,
		INT depthBias = 0,
		FLOAT deptBiasClamp = 0.0f,
		FLOAT slopeScaleDepthBias = 1.0f,
		BOOL depthClipEnable = false,
		BOOL scissorEnable = false,
		BOOL multisampleEnable = false,
		BOOL antialiassedLineEnable = false
	);
	void Get(ID3D11RasterizerState** state);

protected:

private:
	ID3D11RasterizerState* m_State = NULL;
};

