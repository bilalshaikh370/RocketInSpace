#include "StartButton.h"
#include "Game.h"

StartButton::StartButton()
	// call super constructor
	:Button(
		"../Assets/textures/StartButton1.png",
		"startButton",
		START_BUTTON, glm::vec2(300.0f, 200.0f)), m_isClicked(false)
{
	
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			Game::Instance()->changeSceneState(LEVEL1_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


