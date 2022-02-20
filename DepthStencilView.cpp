#include "DepthStencilView.h"


DepthStencilView::DepthStencilView(int width, int height, DXGI_FORMAT format)
{
	Init(width, height, format);
}

DepthStencilView::~DepthStencilView()
{

}

void DepthStencilView::Get(ID3D11DepthStencilView** view, ID3D11Texture2D** buffer)
{
	*view = m_View;
	*buffer = m_Buffer;
}

void DepthStencilView::Init(int width, int height, DXGI_FORMAT format)
{
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_TEXTURE2D_DESC));
	desc.Width = width;
	desc.Height = height;
	desc.Format = format;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.CPUAccessFlags = 0;
	desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	desc.MiscFlags = 0;
	auto device = DeviceManager::GetInstance()->GetDevice();
	CheckHR(device->CreateTexture2D(&desc, nullptr, &m_Buffer));

	D3D11_DEPTH_STENCIL_VIEW_DESC viewDesc;
	ZeroMemory(&viewDesc, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
	viewDesc.Format = format;
	viewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	viewDesc.Texture2D.MipSlice = 0;

	CheckHR(device->CreateDepthStencilView(m_Buffer, &viewDesc, &m_View));
	

}