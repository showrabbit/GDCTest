#pragma once
#include "Mesh.h"
#include "Maths.h"
#include "DeviceManager.h"
#include <D3D11.h>
#include "IndexBuffer.h"
#include "VertexBuffer.h"


class MeshCube : public Mesh
{
public:
	MeshCube(EntityDataType type);
	~MeshCube();
	void SetData(Vector4 center, float length, float width, float height, Color color);
	void Draw();
	void GetVector(int index, Vector4& vector);
protected:
	Vector4 m_Vectors[24];
	Vector4 m_Normals[24];
	Color  m_Colors[24];
	Vector2 m_Texcoords[24];
	int m_DataIndeies[24];
	WORD m_Indeies[36];

	/*
	* vector
	* normal
	* color
	* tex
	*/
	VertexBuffer* m_VertexBuffers[4];
	IndexBuffer* m_IndexBuffer;
	bool m_IsBind = false;

};

