#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(D3D11_USAGE usage, int byteWidth)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	desc.Usage = usage;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	switch (usage)
	{

	case D3D11_USAGE_DEFAULT:
		desc.CPUAccessFlags = 0;
		break;
	case D3D11_USAGE_IMMUTABLE:
		desc.CPUAccessFlags = 0;
		break;
	case D3D11_USAGE_DYNAMIC:
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		break;
	case D3D11_USAGE_STAGING:
		desc.CPUAccessFlags = 0;
		break;

	default:
		break;
	}

	desc.ByteWidth = byteWidth;
	auto device = DeviceManager::GetInstance()->GetDevice();
	CheckHR(device->CreateBuffer(&desc, NULL, &m_Buffer));
}

VertexBuffer::VertexBuffer(D3D11_USAGE usage, int byteWidth, void* initData)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	desc.Usage = usage;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	switch (usage)
	{

	case D3D11_USAGE_DEFAULT:
		desc.CPUAccessFlags = 0;
		break;
	case D3D11_USAGE_IMMUTABLE:
		desc.CPUAccessFlags = 0;
		break;
	case D3D11_USAGE_DYNAMIC:
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		break;
	case D3D11_USAGE_STAGING:
		desc.CPUAccessFlags = 0;
		break;

	default:
		break;
	}

	desc.ByteWidth = byteWidth;
	auto device = DeviceManager::GetInstance()->GetDevice();

	D3D11_SUBRESOURCE_DATA subData;
	ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
	subData.pSysMem = initData;

	CheckHR(device->CreateBuffer(&desc, &subData, &m_Buffer));
}

VertexBuffer::~VertexBuffer()
{
	m_Buffer->Release();
}