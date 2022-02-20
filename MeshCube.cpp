#include "MeshCube.h"


MeshCube::MeshCube(EntityDataType type) : Mesh(type)
{

}
MeshCube::~MeshCube()
{

}

void MeshCube::SetData(Vector4 center, float length, float width, float height, Color color)
{
	float halfLength = length * 0.5f;
	float halfWidth = width * 0.5f;
	float halfHeight = height * 0.5f;

	/*


			5		6
			|		|
			|		|
		8	|	7	|
		|	1	|	2
		|		|
		|		|
		4		3



	*/

	Vector4 vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8;
	vec1 = { center.X - halfLength,center.Y - halfHeight,center.Z + halfWidth,1 };
	vec2 = { center.X + halfLength,center.Y - halfHeight,center.Z + halfWidth,1 };
	vec3 = { center.X + halfLength,center.Y - halfHeight,center.Z - halfWidth,1 };
	vec4 = { center.X - halfLength,center.Y - halfHeight,center.Z - halfWidth,1 };

	vec5 = { center.X - halfLength,center.Y + halfHeight,center.Z + halfWidth,1 };
	vec6 = { center.X + halfLength,center.Y + halfHeight,center.Z + halfWidth,1 };
	vec7 = { center.X + halfLength,center.Y + halfHeight,center.Z - halfWidth,1 };
	vec8 = { center.X - halfLength,center.Y + halfHeight,center.Z - halfWidth,1 };

	Vector3 normal = { 0,0,0 };
	Vector3 tempV1 = { 0 }, tempV2 = { 0 };
	// bottom r
	tempV1 = { vec4.X,vec4.Y,vec4.Z };
	tempV2 = { vec3.X,vec3.Y,vec3.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[0] = vec4;
	m_Normals[0] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[0] = { 1,0,0,1 };

	m_Vectors[1] = vec3;
	m_Normals[1] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[1] = { 1,0,0,1 };

	m_Vectors[2] = vec2;
	m_Normals[2] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[2] = { 1,0,0,1 };

	m_Vectors[3] = vec1;
	m_Normals[3] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[3] = { 1,0,0,1 };

	// up r
	tempV1 = { vec5.X,vec5.Y,vec5.Z };
	tempV2 = { vec6.X,vec6.Y,vec6.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[4] = vec5;
	m_Normals[4] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[4] = { 1,0,0,1 };

	m_Vectors[5] = vec6;
	m_Normals[5] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[5] = { 1,0,0,1 };

	m_Vectors[6] = vec7;
	m_Normals[6] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[6] = { 1,0,0,1 };

	m_Vectors[7] = vec8;
	m_Normals[7] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[7] = { 1,0,0,1 };

	// right g
	tempV1 = { vec7.X,vec7.Y,vec7.Z };
	tempV2 = { vec6.X,vec6.Y,vec6.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[8] = vec7;
	m_Normals[8] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[8] = { 0,1,0,1 };

	m_Vectors[9] = vec6;
	m_Normals[9] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[9] = { 0,1,0,1 };

	m_Vectors[10] = vec2;
	m_Normals[10] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[10] = { 0,1,0,1 };

	m_Vectors[11] = vec3;
	m_Normals[11] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[11] = { 0,1,0,1 };

	// left g
	tempV1 = { vec5.X,vec5.Y,vec5.Z };
	tempV2 = { vec8.X,vec8.Y,vec8.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[12] = vec5;
	m_Normals[12] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[12] = { 0,1,0,1 };

	m_Vectors[13] = vec8;
	m_Normals[13] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[13] = { 0,1,0,1 };

	m_Vectors[14] = vec4;
	m_Normals[14] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[14] = { 0,1,0,1 };

	m_Vectors[15] = vec1;
	m_Normals[15] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[15] = { 0,1,0,1 };

	// back b
	tempV1 = { vec8.X,vec8.Y,vec8.Z };
	tempV2 = { vec7.X,vec7.Y,vec7.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[16] = vec8;
	m_Normals[16] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[16] = { 0,0,1,1 };

	m_Vectors[17] = vec7;
	m_Normals[17] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[17] = { 0,0,1,1 };

	m_Vectors[18] = vec3;
	m_Normals[18] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[18] = { 0,0,1,1 };

	m_Vectors[19] = vec4;
	m_Normals[19] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[19] = { 0,0,1,1 };

	// foward b
	tempV1 = { vec6.X,vec6.Y,vec6.Z };
	tempV2 = { vec5.X,vec5.Y,vec5.Z };
	Vector3::Cross(&tempV1, &tempV2, &normal);
	Vector3::Normalize(&normal);
	m_Vectors[20] = vec6;
	m_Normals[20] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[20] = { 0,0,1,1 };

	m_Vectors[21] = vec5;
	m_Normals[21] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[21] = { 0,0,1,1 };

	m_Vectors[22] = vec1;
	m_Normals[22] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[22] = { 0,0,1,1 };

	m_Vectors[23] = vec2;
	m_Normals[23] = { normal.X,normal.Y,normal.Z,1 };
	m_Colors[23] = { 0,0,1,1 };


	for (int i = 0; i < 24; i++)
	{
		/*if (i < 8)
			m_Colors[i] = { 1,1,1,1 };
		else if (i < 16)
			m_Colors[i] = { 1,1,1,1 };
		else
			m_Colors[i] = { 1,1,1,1 };*/
		m_DataIndeies[i] = i;
		//m_Colors[i].R = (float)i / 24.0f;
	}

	for (int i = 0; i < 6; i++)
	{
		m_Indeies[i * 6] = i * 4;
		m_Indeies[i * 6 + 1] = i * 4 + 1;
		m_Indeies[i * 6 + 2] = i * 4 + 2;
		m_Indeies[i * 6 + 3] = i * 4 + 2;
		m_Indeies[i * 6 + 4] = i * 4 + 3;
		m_Indeies[i * 6 + 5] = i * 4;

		m_Texcoords[i * 4] = { 0,0 };
		m_Texcoords[i * 4 + 1] = { 1,0 };
		m_Texcoords[i * 4 + 2] = { 1,1 };
		m_Texcoords[i * 4 + 3] = { 0,1 };
	}



	D3D11_USAGE  useage = GetUseage();
	m_VertexBuffers[0] = new VertexBuffer(useage, sizeof(Vector4) * 24);
	m_VertexBuffers[1] = new VertexBuffer(useage, sizeof(Vector4) * 24);
	m_VertexBuffers[2] = new VertexBuffer(useage, sizeof(Vector4) * 24);
	m_VertexBuffers[3] = new VertexBuffer(useage, sizeof(Vector2) * 24);

	m_IndexBuffer = new IndexBuffer(36);

}

void MeshCube::Draw()
{
	switch (m_DataType)
	{
	case Static:

		if (!m_IsBind)
		{
			m_VertexBuffers[0]->UpdateData((void*)m_Vectors);
			m_VertexBuffers[1]->UpdateData((void*)m_Normals);
			m_VertexBuffers[2]->UpdateData((void*)m_Colors);
			m_VertexBuffers[3]->UpdateData((void*)m_Texcoords);
			m_IndexBuffer->UpdateData((void*)m_Indeies);

			m_IsBind = true;
		}
		break;
	case Dynamic:

		void* lockData = NULL;
		m_VertexBuffers[0]->Map(&lockData);
		memcpy(lockData, (void*)m_Vectors, sizeof(Vector4) * 24);
		m_VertexBuffers[0]->UnMap();

		m_VertexBuffers[1]->Map(&lockData);
		memcpy(lockData, (void*)m_Normals, sizeof(Vector4) * 24);
		m_VertexBuffers[1]->UnMap();

		m_VertexBuffers[2]->Map(&lockData);
		memcpy(lockData, (void*)m_Colors, sizeof(Color) * 24);
		m_VertexBuffers[2]->UnMap();

		m_VertexBuffers[3]->Map(&lockData);
		memcpy(lockData, (void*)m_Texcoords, sizeof(Vector2) * 24);
		m_VertexBuffers[3]->UnMap();

		m_IndexBuffer->UpdateData((void*)m_Indeies);

		break;
	}

	auto context = DeviceManager::GetInstance()->GetDeviceContext();
	ID3D11Buffer* buffers[4] =
	{
		m_VertexBuffers[0]->GetBuffer(),
		m_VertexBuffers[1]->GetBuffer(),
		m_VertexBuffers[2]->GetBuffer(),
		m_VertexBuffers[3]->GetBuffer(),
	};

	UINT strIndies[4] =
	{
		sizeof(Vector4),
		sizeof(Vector4),
		sizeof(Color),
		sizeof(Vector2),
		//sizeof(int)
	};

	UINT offset[4] =
	{
		0,0,0,0
	};

	context->IASetVertexBuffers(0, 4, buffers, strIndies, offset);
	context->IASetIndexBuffer(m_IndexBuffer->GetBuffer(), DXGI_FORMAT_R16_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context->DrawIndexed(36, 0, 0);
}

void MeshCube::GetVector(int index, Vector4& vector)
{
	vector.X = m_Vectors[index].X;
	vector.Y = m_Vectors[index].Y;
	vector.Z = m_Vectors[index].Z;
	vector.W = m_Vectors[index].W;
}