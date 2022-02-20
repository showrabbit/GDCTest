#pragma once

#include "Buffer.h"

struct ConstantBufferSlotIndex
{
	const static UINT CB_SLOT_WVP = 0;
	const static UINT CB_SLOT_LIGHT_START = 10;
	const static UINT CB_SLOT_LIGHT_END = 20;
	const static UINT CB_SLOT_OTHER = 21;

};




class ConstantBuffer : public Buffer
{
public:
	void SetStartSlot(UINT startSlot);
	UINT GetStartSlot();
protected:
	UINT m_StartSlot = 0;


};

__interface IConstantBufferGetter
{
	ConstantBuffer* GetConstantBuffer();
};
