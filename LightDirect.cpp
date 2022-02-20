#include "LightDirect.h"

LightDirect::LightDirect(UINT index) : LightBase(index)
{
	m_Data = NULL;
}

void LightDirect::Bind()
{
	/*if (m_ConstantBuffer == NULL)
	{
		m_ConstantBuffer = new ConstantBuffer();
		m_ConstantBuffer->SetBuffer(D3D11_USAGE_DEFAULT, sizeof(LightDiffuseData), D3D11_BIND_CONSTANT_BUFFER, 0);
		m_ConstantBuffer->SetStartSlot(1);
		m_ConstantBuffer->UpdateData((void**)m_Data);
	}*/
}

void LightDirect::Dispose()
{
	delete m_Data;
	OBJECT_DISPOSE(m_ConstantBuffer);
}


void LightDirect::Set(Color& c, Vector4& pos, Vector4& dir)
{
	/*m_Color = c;
	m_Pos = pos;
	m_Dir = dir;*/
	m_Data = (LightDirectData*)malloc(sizeof(LightDirectData));
	if (m_Data == NULL)
		return;
	m_Data->Color = c;
	m_Data->Pos = pos;
	m_Data->Dir = dir;
	m_ConstantBuffer = new ConstantBuffer();
	m_ConstantBuffer->SetBuffer(D3D11_USAGE_DEFAULT, sizeof(LightDirectData), D3D11_BIND_CONSTANT_BUFFER, 0, NULL);
	m_ConstantBuffer->SetStartSlot(ConstantBufferSlotIndex::CB_SLOT_LIGHT_START + m_Index);
	m_ConstantBuffer->UpdateData((void*)m_Data);
	/*void* pData = NULL;
	m_ConstantBuffer->Map(&pData);
	pData = m_Data;
	m_ConstantBuffer->UnMap();*/
}

