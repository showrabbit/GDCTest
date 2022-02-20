#pragma once

#include "LightBase.h"
#include "Maths.h"
struct LightDirectData
{
	Color Color;
	Vector4 Pos;
	Vector4 Dir;
};

class LightDirect : public LightBase
{
public:
	LightDirect(UINT index);
	void Bind();
	void Set(Color& c, Vector4& pos, Vector4& dir);
	void Dispose();
	
private:
	LightDirectData *m_Data;
	/*Color m_Color;
	Vector3 m_Pos;
	Vector3 m_Dir;*/
};

