#include "ConstantBuffer.h"

void ConstantBuffer::SetStartSlot(UINT startSlot)
{
	m_StartSlot = startSlot;
}

UINT ConstantBuffer::GetStartSlot()
{
	return m_StartSlot;
}