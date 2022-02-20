#pragma once
#include "Camera.h"
#include "UserInputListener.h"
#include "UserInputManager.h"
#include "UserInputKeyboard.h"

class CameraController : public IUserInputListenerHandler
{
public:
	CameraController(Camera* camera,enum UserInputType inputType);
	~CameraController();

protected:
	void OnKeyboard(UserInputParam& p);
	
	
	Camera* m_Camera;
	UserInputListener* m_Listener;

};

