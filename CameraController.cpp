#include "CameraController.h"



CameraController::CameraController(Camera* camera, enum UserInputType inputType)
{
	m_Camera = camera;
	//UserInputListenerHandler handler = OnKeyBoard;
	m_Listener = new UserInputListener(this);
	UserInputManager::Instance().Register(UserInputType::Keyboard, m_Listener);
}

CameraController::~CameraController()
{
	UserInputManager::Instance().UnRegister(UserInputType::Keyboard, m_Listener);
}

void CameraController::OnKeyboard(UserInputParam& p)
{
	if (p.Key == UserInputKeyboardValue::A)
	{
		auto pos = m_Camera->GetPos();
		pos.X += 0.1;
		m_Camera->SetPos(pos);
	}
	else if (p.Key == UserInputKeyboardValue::D)
	{
		auto pos = m_Camera->GetPos();
		pos.X -= 0.1;
		m_Camera->SetPos(pos);
	}
	else if (p.Key == UserInputKeyboardValue::E)
	{
		auto pos = m_Camera->GetPos();
		pos.Y -= 0.1;
		m_Camera->SetPos(pos);
	}
	else if (p.Key == UserInputKeyboardValue::Q)
	{
		auto pos = m_Camera->GetPos();
		pos.Y += 0.1;
		m_Camera->SetPos(pos);
	}
	else if (p.Key == UserInputKeyboardValue::S)
	{
		auto pos = m_Camera->GetPos();
		pos.Z -= 0.1;
		m_Camera->SetPos(pos);
	}
	else if (p.Key == UserInputKeyboardValue::W)
	{
		auto pos = m_Camera->GetPos();
		pos.Z += 0.1;
		m_Camera->SetPos(pos);
	}
}