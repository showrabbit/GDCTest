#include "Buffer.h"

Buffer::Buffer()
{

}

void Buffer::Dispose()
{
	if (m_Buffer != NULL)
	{
		m_Buffer->Release();
	}
}

void Buffer::SetBuffer(D3D11_USAGE usage, UINT byteWidth, UINT bindFlags, UINT cpu, D3D11_SUBRESOURCE_DATA* pInit)
{
	if (m_Buffer != NULL)
	{
		m_Buffer->Release();
		m_Buffer = NULL;
	}

	auto device = DeviceManager::GetInstance()->GetDevice();

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	desc.Usage = usage;
	desc.ByteWidth = byteWidth;
	desc.BindFlags = bindFlags;
	desc.CPUAccessFlags = cpu;

	CheckHR(device->CreateBuffer(&desc, pInit, &m_Buffer));

}

ID3D11Buffer* Buffer::GetBuffer()
{
	return m_Buffer;
}

void Buffer::UpdateData(void* data)
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->UpdateSubresource(m_Buffer, 0, NULL, data, 0, 0);
}

void Buffer::Map(void** data)
{
	D3D11_MAPPED_SUBRESOURCE resource;
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->Map(m_Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	*data = resource.pData;
}

void Buffer::UnMap()
{
	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	context->Unmap(m_Buffer, 0);

}