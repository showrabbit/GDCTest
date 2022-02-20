#pragma once
#include "Buffer.h"
#include <D3D11.h>
#include "DeviceManager.h"

class VertexBuffer : public Buffer
{
public:
	VertexBuffer(D3D11_USAGE usage, int byteWidth);
	VertexBuffer(D3D11_USAGE usage, int byteWidth, void* initData);

protected:
	~VertexBuffer();

};

