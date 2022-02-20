#include "LightBase.h"

LightBase::LightBase(UINT index)
{
	m_Index = index;
}

void LightBase::Bind()
{

}

UINT LightBase::GetIndex()
{
	return m_Index;
}

ConstantBuffer* LightBase::GetConstantBuffer()
{
	return m_ConstantBuffer;
}