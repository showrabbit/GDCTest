#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(int count)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = sizeof(WORD) * count;
	desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	desc.CPUAccessFlags = 0;

	auto device = DeviceManager::GetInstance()->GetDevice();
	HRESULT hr = device->CreateBuffer(&desc, NULL, &m_Buffer);
	if (!CheckHR(hr))
		return;
}
