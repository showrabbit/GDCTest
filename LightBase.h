#pragma once

#include "ConstantBuffer.h"

class LightBase : public Object,public IConstantBufferGetter
{
public:
	LightBase(UINT index);
	UINT GetIndex();
	ConstantBuffer* GetConstantBuffer();
	virtual void Bind();
protected:
	UINT m_Index;
	ConstantBuffer* m_ConstantBuffer;
};

