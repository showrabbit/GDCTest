#pragma once
#include "Mesh.h"
#include "Maths.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class MeshBall : public Mesh
{
public:
	MeshBall(EntityDataType type);
	~MeshBall();
	void SetData(Vector3 centerPos, float radius);
	void Draw();
private:

	Vector4* m_Vectors;
	Color* m_Colors;
	Vector2* m_Texcoords;
	//int* m_DataIndeies;
	WORD* m_Indeies;


	VertexBuffer* m_VertexBuffers[3];
	IndexBuffer* m_IndexBuffer;
	bool m_IsBind = false;
};

