#pragma once

#include "ConstantBuffer.h"
#include "Maths.h"
#include "Common.h"

struct WVPConstantBufferData
{
	Matrix World;
	Matrix View;
	Matrix Project;
};


class WVPConstantBuffer : public ConstantBuffer
{
public:
	WVPConstantBuffer();
	~WVPConstantBuffer();
	void Update(Matrix world, Matrix view, Matrix proj);
protected:
	WVPConstantBufferData* m_Data;
};

