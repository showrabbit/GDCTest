#include "Entity.h"

Entity::Entity(EntityDataType dataType)
{
	m_DataType = dataType;
}

Entity::~Entity()
{

}

void Entity::Draw()
{

}

D3D11_USAGE Entity::GetUseage()
{
	D3D11_USAGE usage = D3D11_USAGE_DEFAULT;

	switch (m_DataType)
	{
	case Static:
	{
		usage = D3D11_USAGE_DEFAULT;
	}break;
	case Dynamic:
	{
		usage = D3D11_USAGE_DYNAMIC;
	}break;
	default:
		break;
	}
	return usage;
}