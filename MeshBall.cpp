#include "MeshBall.h"

MeshBall::MeshBall(EntityDataType type) : Mesh(type)
{

}

MeshBall::~MeshBall()
{
	delete m_Vectors;
	delete m_Colors;
	delete m_Texcoords;
	//delete m_DataIndeies;
	delete m_Indeies;

	for (int i = 0; i < 4; i++)
	{
		OBJECT_DISPOSE(m_VertexBuffers[i]);
	}

	OBJECT_DISPOSE(m_IndexBuffer);
}

void MeshBall::Draw()
{

}

void MeshBall::SetData(Vector3 centerPos, float radius)
{
	int latitudeCount = 360 / 10;
	int longitudeCount = 360 / 10 + 2;

	m_Vectors = (Vector4*)malloc(sizeof(Vector4) * latitudeCount * longitudeCount);
	m_Colors = (Color*)malloc(sizeof(Color) * latitudeCount * longitudeCount);
	m_Texcoords = (Vector2*)malloc(sizeof(Vector2) * latitudeCount * longitudeCount);
	if (m_Vectors == NULL || m_Colors == NULL || m_Texcoords == NULL)
		return;

	// 北极
	m_Vectors[0] = { centerPos.X ,centerPos.Y + radius,centerPos.Z,0 };
	m_Colors[0] = { 1,1,1,1 };
	m_Texcoords[0] = { 1,1 };

	// 南极
	m_Vectors[1] = { centerPos.X ,centerPos.Y - radius,centerPos.Z,0 };
	m_Colors[1] = { 1,1,1,1 };
	m_Texcoords[1] = { 0,0 };



	for (int i = 2; i < longitudeCount; i++)
	{
		for (int j = 0; j < latitudeCount; j++)
		{
			auto latitude = (float)i / (float)latitudeCount * 360.0f;
			auto longitude = (float)j / (float)longitudeCount * 360.0f;


		}
	}

	for (int i = 0; i < 2; i++)
	{

	}
}

