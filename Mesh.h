#pragma once

#include "Entity.h"
class Mesh : public Entity
{
public:
	Mesh(EntityDataType type);
	~Mesh();
	virtual void Draw();
};

