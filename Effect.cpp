#include "Effect.h"

Effect::Effect(enum EffectType type, const char* fileName, const char* vertexFun, const char* fragFun)
{
	CreateVertexShader(type, fileName, vertexFun);
	CreatePixelShader(fileName, fragFun);
}


void Effect::CreateVertexShader(enum EffectType type, const char* fileName, const char* vertexFun)
{
	ID3DBlob* blob = NULL;
	HRESULT hr;
	hr = CompileShaderFromFile(fileName, vertexFun, "vs_4_0", &blob);
	if (!CheckHR(hr))
		return;
	auto device = DeviceManager::GetInstance()->GetDevice();
	hr = device->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &m_VertexShader);
	if (!CheckHR(hr))
		return;
	D3D11_INPUT_ELEMENT_DESC* layout;
	UINT size = 0;
	EffectInputLayoutElementDesc::Create(type, &size, &layout);
	void* bufferPointer = blob->GetBufferPointer();
	UINT bufferSize = blob->GetBufferSize();

	hr = device->CreateInputLayout(layout, size, bufferPointer, bufferSize, &m_InputLayout);
	if (!CheckHR(hr))
	{
		blob->Release();
		return;
	}

}

void Effect::CreatePixelShader(const char* fileName, const char* fragFun)
{
	ID3DBlob* blob = NULL;
	HRESULT hr = CompileShaderFromFile(fileName, fragFun, "ps_4_0", &blob);
	if (!CheckHR(hr))
	{
		return;
	}

	auto device = DeviceManager::GetInstance()->GetDevice();
	hr = device->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &m_PixelShader);
	if (!CheckHR(hr))
	{
		blob->Release();
		return;
	}

}

Effect::~Effect()
{
	if (m_InputLayout)
	{
		m_InputLayout->Release();
	}
	if (m_VertexShader)
	{
		m_VertexShader->Release();
	}
	if (m_PixelShader)
	{
		m_PixelShader->Release();
	}


}

HRESULT Effect::CompileShaderFromFile(LPCSTR fileName, LPCSTR entry, LPCSTR shader, ID3DBlob** blob)
{
	HRESULT hr = S_OK;
	DWORD flag = D3DCOMPILE_ENABLE_STRICTNESS;
	ID3DBlob* errorBlob;
	hr = D3DX11CompileFromFileA(fileName, NULL, NULL, entry, shader, flag, 0, NULL, blob, &errorBlob, NULL);
	if (!CheckHR(hr))
	{
		if (errorBlob)
		{
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
			errorBlob->Release();
		}
		return hr;
	}
	if (errorBlob)
	{
		errorBlob->Release();
	}
	return hr;
}

void Effect::BindConstantBufferVS(ConstantBuffer* cb)
{
	//BindConstantBufferVS(cb->GetStartSlot(), 1U, &cb);
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	auto buffer = cb->GetBuffer();
	context->VSSetConstantBuffers(cb->GetStartSlot(), 1, &buffer);
}

void Effect::BindConstantBufferVS(UINT startSlot, UINT num, ConstantBuffer** cb)
{
	ID3D11Buffer** buffers = (ID3D11Buffer**)malloc(sizeof(ID3D11Buffer*) * num);
	for (int i = 0; i < num; i++)
	{
		buffers[i] = cb[i]->GetBuffer();
	}
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->VSSetConstantBuffers(startSlot, num, buffers);

	free(buffers);
}

void Effect::BindVS()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->VSSetShader(m_VertexShader, NULL, 0);
}

void Effect::BindConstantBufferPS(ConstantBuffer* cb)
{
	BindConstantBufferPS(cb->GetStartSlot(), 1, &cb);
}

void Effect::BindConstantBufferPS(UINT startSlot, UINT num, ConstantBuffer** cb)
{
	ID3D11Buffer** buffers = (ID3D11Buffer**)malloc(sizeof(ID3D11Buffer*) * num);
	for (int i = 0; i < num; i++)
	{
		buffers[i] = cb[i]->GetBuffer();
	}
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->PSSetConstantBuffers(startSlot, num, buffers);

	free(buffers);
}

void Effect::BindPS()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->PSSetShader(m_PixelShader, NULL, 0);
}

void Effect::BindInputLayout()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->IASetInputLayout(m_InputLayout);
}

void Effect::BindBlendState()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();

	context->OMSetBlendState(m_BlendState, NULL, 0xfffffff);
}

void Effect::BindDepthStencilState()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->OMSetDepthStencilState(m_DepthStencilState, m_StenciRef);
}

void Effect::SetBlendState(
	bool isAlphaTo,
	bool isIndependent = false,
	bool isUse = false,
	D3D11_BLEND srcBlend = D3D11_BLEND_ONE,
	D3D11_BLEND descBlend = D3D11_BLEND_ZERO,
	D3D11_BLEND_OP blendOp = D3D11_BLEND_OP_ADD,
	D3D11_BLEND srcBlendAlpha = D3D11_BLEND_ONE,
	D3D11_BLEND descBlendAlpha = D3D11_BLEND_ZERO,
	D3D11_BLEND_OP blendOpAlpha = D3D11_BLEND_OP_ADD,
	UINT8 writeMask = D3D11_COLOR_WRITE_ENABLE_ALL
)
{
	D3D11_BLEND_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));
	desc.AlphaToCoverageEnable = isAlphaTo;
	desc.IndependentBlendEnable = isIndependent;
	desc.RenderTarget[0].BlendEnable = isUse;
	desc.RenderTarget[0].BlendOp = blendOp;
	desc.RenderTarget[0].BlendOpAlpha = blendOpAlpha;
	desc.RenderTarget[0].DestBlend = descBlend;
	desc.RenderTarget[0].DestBlendAlpha = descBlendAlpha;
	desc.RenderTarget[0].RenderTargetWriteMask = writeMask;
	desc.RenderTarget[0].SrcBlend = srcBlend;
	desc.RenderTarget[0].SrcBlendAlpha = srcBlendAlpha;

	auto device = DeviceManager::GetInstance()->GetDevice();
	device->CreateBlendState(&desc, &m_BlendState);
}


void Effect::SetDepthStencilState(
	bool isUseDepth,
	D3D11_DEPTH_WRITE_MASK depthWriteMask,
	D3D11_COMPARISON_FUNC depthFunc,
	bool isUseStencil,
	UINT stencilReadMask,
	UINT stencilWriteMask,
	D3D11_DEPTH_STENCILOP_DESC* frontFace,
	D3D11_DEPTH_STENCILOP_DESC* backFace
)
{
	D3D11_DEPTH_STENCIL_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_DEPTH_STENCIL_DESC));

	desc.DepthEnable = isUseDepth;
	desc.DepthWriteMask = depthWriteMask;
	desc.DepthFunc = depthFunc;

	desc.StencilEnable = isUseStencil;
	desc.StencilReadMask = stencilReadMask;
	desc.StencilWriteMask = stencilWriteMask;

	desc.FrontFace = *frontFace;
	desc.BackFace = *backFace;

	auto device = DeviceManager::GetInstance()->GetDevice();
	device->CreateDepthStencilState(&desc, &m_DepthStencilState);
}

void Effect::SetStencilRef(UINT ref)
{
	m_StenciRef = ref;
}