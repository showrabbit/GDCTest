#pragma once
#include <D3D11.h>

__interface IEntity
{
	void Draw();
};

enum EntityDataType
{
	Static,
	Dynamic
};

class Entity : public IEntity
{
public:
	Entity(EntityDataType dataType);
	~Entity();
	void Draw();
	D3D11_USAGE GetUseage();
protected:
	
	EntityDataType m_DataType;
private:
	


};

