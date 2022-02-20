#include "RasterizerState.h"


RasterizerState::RasterizerState()
{

}

RasterizerState::~RasterizerState()
{

}

void RasterizerState::Init(
	D3D11_FILL_MODE fillMode,
	D3D11_CULL_MODE cullMode,
	BOOL clockWise,
	INT depthBias,
	FLOAT deptBiasClamp,
	FLOAT slopeScaleDepthBias,
	BOOL depthClipEnable,
	BOOL scissorEnable,
	BOOL multisampleEnable,
	BOOL antialiassedLineEnable)
{
	auto device = DeviceManager::GetInstance()->GetDevice();

	D3D11_RASTERIZER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));
	desc.FillMode = fillMode;
	desc.CullMode = cullMode;
	desc.FrontCounterClockwise = clockWise;
	desc.DepthBias = depthBias;
	desc.DepthBiasClamp = deptBiasClamp;
	desc.SlopeScaledDepthBias = slopeScaleDepthBias;
	desc.DepthClipEnable = depthClipEnable;
	desc.ScissorEnable = scissorEnable;
	desc.MultisampleEnable = multisampleEnable;
	desc.AntialiasedLineEnable = antialiassedLineEnable;
	CheckHR(device->CreateRasterizerState(&desc, &m_State));
}

void RasterizerState::Get(ID3D11RasterizerState** state)
{
	*state = m_State;
}