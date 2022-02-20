#include "Main.h"
#include "UserInputKeyboard.h"
#include "LightManager.h"



HWND g_WinHwnd;

UserInputKeyboard g_InputKeyboard;


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"Test";
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
	if (!RegisterClassEx(&wcex))
		return E_FAIL;

	// Create window
	//g_hInst = hInstance;
	RECT rc = { 0, 0, 640, 480 };
	//AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	g_WinHwnd = CreateWindow(L"Test", L"Test",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
		NULL);
	if (!g_WinHwnd)
		return E_FAIL;

	ShowWindow(g_WinHwnd, nCmdShow);

	return S_OK;
}

void UserInput(MSG msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		g_InputKeyboard.Trigger(msg.wParam);
	}
	else if (msg.message == WM_CHAR)
	{
		g_InputKeyboard.Trigger(msg.wParam);
	}

}

void Render()
{
	DeviceManager::GetInstance()->BeginDraw();

	Engine::GetInstance()->Execute();

	DeviceManager::GetInstance()->EndDraw();
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPre, LPSTR cmdLine, int show)
{
	UNREFERENCED_PARAMETER(hPre);
	UNREFERENCED_PARAMETER(cmdLine);

	if (FAILED(InitWindow(hInstance, show)))
		return 0;

	DeviceManager::GetInstance()->Init(640, 460, g_WinHwnd);

	World* world = new World();
	Camera* camera = new Camera(640, 480, 1.0f, 100.f, 3.14159f / 4.0f, 640.0f / 480.f, RenderTargetType::Window);
	CameraController* cameraCtr = new CameraController(camera, UserInputType::Keyboard);
	world->SetMainCamera(camera);

	Vector3 lookAt = { 0,1,0 };
	Vector3 up = { 0,1,0 };
	Vector3 pos = { 0,0,-10 };
	camera->SetLookAt(lookAt);
	camera->SetPos(pos);
	camera->SetUp(up);
	camera->InitViewMatrix();

	RasterizerState* rs = new RasterizerState();
	rs->Init(D3D11_FILL_SOLID, D3D11_CULL_BACK, false);
	camera->SetRasterizerState(&rs);

	Engine::GetInstance()->SetWorld(world);

	auto light = (LightDirect*)LightManager::Instance().Add(LightType::Diffuse, 1);
	Color lightColor = { 1,1,1,1 };
	Vector4 lightPos = { 0,0,-10,1 };
	Vector4 lightDir = { 0,0,-1,1 };

	light->Set(lightColor, lightPos, lightDir);

	Effect* effect = new Effect(EffectType::Normal, "D:/Project/C++/GDCTest/LightEffect.hlsl", "VS", "PS");
	//Effect* effect = new Effect(EffectType::NormalT, "D:/Project/C++/GDCTest/NormalEffect.hlsl", "VS", "PS");

	/*D3D11_DEPTH_STENCILOP_DESC frontFace;
	ZeroMemory(&frontFace, sizeof(D3D11_DEPTH_STENCILOP_DESC));
	frontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	frontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	frontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	frontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;

	D3D11_DEPTH_STENCILOP_DESC backFace;
	ZeroMemory(&backFace, sizeof(D3D11_DEPTH_STENCILOP_DESC));
	backFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	backFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	backFace.StencilFunc = D3D11_COMPARISON_NEVER;
	backFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;

	effect->SetDepthStencilState(
		true,
		D3D11_DEPTH_WRITE_MASK_ALL,
		D3D11_COMPARISON_LESS,
		true,
		D3D11_DEFAULT_STENCIL_READ_MASK,
		D3D11_DEFAULT_STENCIL_WRITE_MASK,
		&frontFace,
		&backFace
	);
	effect->SetStencilRef(1);*/

	MeshCube* cube = new MeshCube(EntityDataType::Static);
	Vector4 center = { 0,0,1,0 };
	cube->SetData(center, 2, 2, 2, { 1,1,1,1 });
	Renderer* render = new Renderer((IEffect*)effect, (IEntity*)cube);
	world->AddRender(render);

	auto worldMat = camera->GetWorldMatrix();
	auto viewMat = camera->GetViewMatrix();
	auto proMat = camera->GetProjMatrix();
	auto viewportMat = camera->GetViewportMatrix();

	Vector4 test = { 0 };
	cube->GetVector(0, test);
	Vector4 trans = { 0 };
	Vector4::Dot(&test, worldMat, &trans);
	Vector4::Dot(&trans, viewMat, &test);
	Vector4::Dot(&test, proMat, &trans);//View
	// clip
	if ((trans.X < -trans.W || trans.X > trans.W) &&
		(trans.Y < -trans.W || trans.Y > trans.W) &&
		(trans.Z < 0 || trans.Z > trans.W))
	{
		// cliped
	}
	Vector4 temp = { trans.X / trans.W  ,trans.Y / trans.W ,trans.Z / trans.W, 1 };//NDC
	Vector4::Dot(&temp, viewportMat, &trans);//Viewport trans
	//光栅化 线段插值(ddx),面片插值
	//viewport->screen 


	Vector4 trans1 = { 0 };
	Vector4 test1 = { 0 };
	cube->GetVector(1, test1);
	Vector4::Dot(&test1, worldMat, &trans1);
	Vector4::Dot(&trans1, viewMat, &test1);
	Vector4::Dot(&test1, proMat, &trans1);
	Vector4 temp1 = { trans1.X / trans1.W ,trans1.Y / trans1.W ,trans1.Z / trans1.W, 1 };
	Vector4::Dot(&temp1, viewportMat, &trans1);

	Vector4 trans2 = { 0 };
	Vector4 test2 = { 0 };
	cube->GetVector(2, test2);
	Vector4::Dot(&test2, worldMat, &trans2);
	Vector4::Dot(&trans2, viewMat, &test2);
	Vector4::Dot(&test2, proMat, &trans2);
	Vector4 temp2 = { trans2.X / trans2.W ,trans2.Y / trans2.W ,trans2.Z / trans2.W, 1 };
	Vector4::Dot(&temp2, viewportMat, &trans2);


	/*effect->SetBlendState(
		false,
		false,
		true,
		D3D11_BLEND_SRC_ALPHA,
		D3D11_BLEND_INV_SRC_ALPHA,
		D3D11_BLEND_OP_ADD,
		D3D11_BLEND_ONE,
		D3D11_BLEND_ZERO,
		D3D11_BLEND_OP_ADD
	);*/

	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		else
		{

			UserInput(msg);
			Render();
		}
	}

	DeviceManager::GetInstance()->Dispose();
	return 0;
}

