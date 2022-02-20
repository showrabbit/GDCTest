#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <D3Dcompiler.h>
#include "DeviceManager.h"
#include "ConstantBuffer.h"
#include "Common.h"
#include "EffectInputLayoutElementDesc.h"

enum EffectType
{
	Base,
	Normal,
	NormalS,
	NormalT,
};

__interface IEffect
{
	void BindInputLayout();
	void BindConstantBufferVS(ConstantBuffer* cb);
	void BindVS();
	void BindConstantBufferPS(ConstantBuffer* cb);
	void BindPS();
	void BindBlendState();
	void BindDepthStencilState();
};

class Effect : public IEffect
{
public:
	Effect(enum EffectType type, const char* fileName, const char* vertexFun, const char* fragFun);
	void BindInputLayout();
	void BindConstantBufferVS(ConstantBuffer* cb);
	void BindConstantBufferVS(UINT startSlot, UINT num, ConstantBuffer** cb);
	void BindVS();
	void BindConstantBufferPS(ConstantBuffer* cb);
	void BindConstantBufferPS(UINT startSlot, UINT num, ConstantBuffer** cb);
	void BindPS();
	void BindBlendState();
	void BindDepthStencilState();

	void SetBlendState(
		bool isAlphaTo,
		bool isIndependent,
		bool isUse,
		D3D11_BLEND srcBlend,
		D3D11_BLEND descBlend,
		D3D11_BLEND_OP blendOp,
		D3D11_BLEND srcBlendAlpha,
		D3D11_BLEND descBlendAlpha,
		D3D11_BLEND_OP blendOpAlpha,
		UINT8 writeMask
	);

	void SetDepthStencilState(
		bool isUseDepth,
		D3D11_DEPTH_WRITE_MASK depthWriteMask,
		D3D11_COMPARISON_FUNC depthFunc,
		bool isUseStencil,
		UINT stencilReadMask,
		UINT stencilWriteMask,
		D3D11_DEPTH_STENCILOP_DESC* frontFace,
		D3D11_DEPTH_STENCILOP_DESC* backFace
	);

	void SetStencilRef(UINT stencilRef);
protected:
	~Effect();
	void CreateVertexShader(enum EffectType type, const char* fileName, const char* vertexFun);
	void CreatePixelShader(const char* fileName, const char* fragFun);
	HRESULT CompileShaderFromFile(LPCSTR fileName, LPCSTR entry, LPCSTR shader, ID3DBlob** blob);
private:
	EffectType m_Type;
	ID3D11VertexShader* m_VertexShader;
	ID3D11InputLayout* m_InputLayout;
	ID3D11PixelShader* m_PixelShader;
	ID3D11BlendState* m_BlendState;
	ID3D11DepthStencilState* m_DepthStencilState;
	ID3D11DepthStencilView* m_DepthStencilView;
	UINT m_StenciRef = 0;
};

