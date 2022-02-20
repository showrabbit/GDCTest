#include "WVPConstantBuffer.h"

WVPConstantBuffer::WVPConstantBuffer()
{

}

WVPConstantBuffer::~WVPConstantBuffer()
{
	if (m_Data != NULL)
	{
		delete m_Data;
	}
	if (m_Buffer != NULL)
	{
		m_Buffer->Release();
	}
}


void WVPConstantBuffer::Update(Matrix world, Matrix view, Matrix proj)
{
	if (m_Buffer == NULL)
	{
		SetBuffer(D3D11_USAGE_DEFAULT, sizeof(WVPConstantBufferData), D3D11_BIND_CONSTANT_BUFFER, 0, NULL);
		m_Data = new WVPConstantBufferData();
	}

	m_Data->World = Matrix::Transpose(&world);
	m_Data->View = Matrix::Transpose(&view);
	m_Data->Project = Matrix::Transpose(&proj);

	UpdateData((void*)m_Data);

}