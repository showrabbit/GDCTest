#pragma once

#include "RenderTargetType.h"
#include "Maths.h"
#include "RasterizerState.h"
#include "WVPConstantBuffer.h"
#include "Viewport.h"
#include "RenderTarget.h"
#include "DepthStencilView.h"

class Camera
{
public:

	Camera(int width, int height, float minZ, float maxZ, float fov, float aspect, RenderTargetType type);
	~Camera();
	void BeiginDraw();
	void EndDraw();

	void InitViewMatrix();

	void SetPos(Vector3& pos);
	void SetLookAt(Vector3& lookAt);
	void SetUp(Vector3& up);
	void SetRight(Vector3& right);
	void SetRasterizerState(RasterizerState** state);

	void Make();
	const Vector3& GetPos();
	const Vector3& GetLookAt();
	const Vector3& GetUp();
	Matrix* GetWorldMatrix();
	Matrix* GetViewMatrix();
	Matrix* GetProjMatrix();
	Matrix* GetViewportMatrix();
	WVPConstantBuffer* GetConstantBuffer();
protected:
	void CreateProjMatrix(float minZ, float maxZ, float fov, float aspect);
	void CreateViewMatrix();

private:

	Vector3 m_Pos;
	Vector3 m_LookAt;
	Vector3 m_Up;
	Vector3 m_Right;
	Matrix m_WorldMatrix;
	Matrix m_ViewMatrix;
	Matrix m_ProjMatrix;
	Matrix m_ViewportMatrix;

	RasterizerState* m_RasterizerState;
	Viewport* m_Viewport;
	RenderTarget* m_RenderTarget;
	DepthStencilView* m_DepthStencilView;
	WVPConstantBuffer* m_ConstantBuffer;
};

