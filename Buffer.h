#pragma once
#include <d3d11.h>
#include "DeviceManager.h"
#include "Object.h"
class Buffer : public Object
{
public:
	Buffer();
	//ByteWidth value must be in multiples of 16
	void SetBuffer(D3D11_USAGE usage, UINT byteWidth, UINT bindFlags, UINT cpu,D3D11_SUBRESOURCE_DATA *pInit);
	ID3D11Buffer* GetBuffer();
	void UpdateData(void* data);
	void Map(void** data);
	void UnMap();
	void Dispose();

protected:
	ID3D11Buffer *m_Buffer;

};

