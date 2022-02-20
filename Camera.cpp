#include "Camera.h"


Camera::Camera(int width, int height, float minZ, float maxZ, float fov, float aspect, RenderTargetType type)
{
	m_WorldMatrix = {};
	ZeroMemory(&m_WorldMatrix, sizeof(Matrix));
	m_WorldMatrix = Matrix::Identity;
	CreateProjMatrix(minZ, maxZ, fov, aspect);
	m_ViewportMatrix =
	{
		width * 0.5f,0,0,0,
		0,height * 0.5f,0,0,
		0,0,(maxZ - minZ) * 0.5f,0,
		width * 0.5f,height * 0.5f,(minZ + maxZ) * 0.5f,1
	};

	m_Viewport = new Viewport(width, height, 0.f, 1.f, 0.f, 0.f);
	m_RenderTarget = new RenderTarget(type, width, height);
	m_ConstantBuffer = new WVPConstantBuffer();
	m_DepthStencilView = new DepthStencilView(width, height, DXGI_FORMAT_D32_FLOAT_S8X24_UINT);

}

Camera::~Camera()
{
	delete m_Viewport;
	delete m_RenderTarget;
}

void Camera::BeiginDraw()
{
	auto deviceContext = DeviceManager::GetInstance()->GetDeviceContext();
	if (m_RasterizerState != NULL)
	{
		ID3D11RasterizerState* state = NULL;
		m_RasterizerState->Get(&state);
		deviceContext->RSSetState(state);
	}

	ID3D11RenderTargetView* view = NULL;
	ID3D11Texture2D* texture = NULL;
	m_RenderTarget->Get(&view, &texture);

	ID3D11DepthStencilView* depthStencil;
	ID3D11Texture2D* depthStencilBuffer;
	m_DepthStencilView->Get(&depthStencil, &depthStencilBuffer);
	deviceContext->OMSetRenderTargets(1, &view, depthStencil);

	D3D11_VIEWPORT viewPort;
	m_Viewport->Get(&viewPort);
	deviceContext->RSSetViewports(1, &viewPort);
	float clearColor[4] = { 0.f,0.125,0.3f,1.f };
	deviceContext->ClearRenderTargetView(view, clearColor);
	deviceContext->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0.f);

	CreateViewMatrix();

	m_ConstantBuffer->Update(m_WorldMatrix, m_ViewMatrix, m_ProjMatrix);
}

void Camera::EndDraw()
{

}

void Camera::InitViewMatrix()
{
	CreateViewMatrix();
}

const Vector3& Camera::GetPos()
{
	return m_Pos;
}

const Vector3& Camera::GetLookAt()
{
	return m_LookAt;
}

const Vector3& Camera::GetUp()
{
	return m_Up;
}

Matrix* Camera::GetWorldMatrix()
{
	return &m_WorldMatrix;
}


Matrix* Camera::GetViewMatrix()
{
	return &m_ViewMatrix;
}


Matrix* Camera::GetProjMatrix()
{
	return &m_ProjMatrix;
}

Matrix* Camera::GetViewportMatrix()
{
	return &m_ViewportMatrix;
}

WVPConstantBuffer* Camera::GetConstantBuffer()
{
	return m_ConstantBuffer;
}

void Camera::SetPos(Vector3& pos)
{
	m_Pos = pos;
}


void Camera::SetLookAt(Vector3& lookAt)
{
	m_LookAt = lookAt;
}


void Camera::SetUp(Vector3& up)
{
	m_Up = up;
}

void Camera::SetRight(Vector3& right)
{
	m_Right = right;
}

void Camera::SetRasterizerState(RasterizerState** state)
{
	m_RasterizerState = *state;
}

void Camera::Make()
{

}

void Camera::CreateViewMatrix()
{
	m_ViewMatrix = {};

	Vector3 xAxis, yAxis, zAxis;
	zAxis = { m_LookAt.X - m_Pos.X,m_LookAt.Y - m_Pos.Y,m_LookAt.Z - m_Pos.Z };
	Vector3::Normalize(&zAxis);

	Vector3::Cross(&m_Up, &zAxis, &xAxis);
	Vector3::Normalize(&xAxis);

	Vector3::Cross(&zAxis, &xAxis, &yAxis);
	Vector3::Normalize(&yAxis);

	float x = -Vector3::Dot(&m_Pos, &xAxis);
	float y = -Vector3::Dot(&m_Pos, &yAxis);
	float z = -Vector3::Dot(&m_Pos, &zAxis);

	m_ViewMatrix =
	{
		xAxis.X,yAxis.X,zAxis.X,0,
		xAxis.Y,yAxis.Y,zAxis.Y,0,
		xAxis.Z,yAxis.Z,zAxis.Z,0,
		x,y,z,1
	};


}
void Camera::CreateProjMatrix(float minZ, float maxZ, float fov, float aspect)
{
	m_ProjMatrix = {};
	ZeroMemory(&m_ProjMatrix, sizeof(Matrix));
	m_ProjMatrix =
	{
		1.0f / tanf(fov * 0.5f) / aspect,0.f,0.f,0.f,
		0.f,1.f / tanf(fov * 0.5f),0.f,0.f,
		0.f,0.f,maxZ / (maxZ - minZ),1.0f,
		0.f,0.f,minZ * maxZ / (minZ - maxZ),0.f
	};

}