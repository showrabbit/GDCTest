#include "EffectInputLayoutElementDesc.h"


void EffectInputLayoutElementDesc::Create(enum EffectType type, UINT* elementCount, D3D11_INPUT_ELEMENT_DESC** layout)
{
	switch (type)
	{
	case Base:
		(*layout) = (D3D11_INPUT_ELEMENT_DESC*)malloc(sizeof(D3D11_INPUT_ELEMENT_DESC) * 3);
		ZeroMemory((*layout), sizeof(D3D11_INPUT_ELEMENT_DESC) * 3);
		if ((*layout) == NULL)
			return;
		(*layout)[0] = { "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[1] = { "COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,1,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[2] = { "TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,2,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*elementCount) = 3;
		break;
	case Normal:
		(*layout) = (D3D11_INPUT_ELEMENT_DESC*)malloc(sizeof(D3D11_INPUT_ELEMENT_DESC) * 4);
		ZeroMemory((*layout), sizeof(D3D11_INPUT_ELEMENT_DESC) * 4);
		if ((*layout) == NULL)
			return;
		(*layout)[0] = { "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[1] = { "NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,1,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[2] = { "COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,2,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[3] = { "TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,3,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*elementCount) = 4;
		break;
	case NormalT:
		(*layout) = (D3D11_INPUT_ELEMENT_DESC*)malloc(sizeof(D3D11_INPUT_ELEMENT_DESC) * 4);
		ZeroMemory((*layout), sizeof(D3D11_INPUT_ELEMENT_DESC) * 4);
		if ((*layout) == NULL)
			return;
		(*layout)[0] = { "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[1] = { "COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,1,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[2] = { "TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,2,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*layout)[3] = { "TEXCOORD",1,DXGI_FORMAT_R32_SINT,3,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*elementCount) = 4;
		break;
	case NormalS:
		(*layout) = (D3D11_INPUT_ELEMENT_DESC*)malloc(sizeof(D3D11_INPUT_ELEMENT_DESC) * 1);
		ZeroMemory((*layout), sizeof(sizeof(D3D11_INPUT_ELEMENT_DESC) * 1));
		if ((*layout) == NULL)
			return;
		(*layout)[0] = { "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 };
		(*elementCount) = 1;
	default:
		break;
	}
}