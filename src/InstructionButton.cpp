#include "InstructionButton.h"
#include "Game.h"

InstructionButton::InstructionButton()
// call super constructor
	:Button(
		"../Assets/textures/InstructionButton.png",
		"InstructonButton",
		INSTRUCTION_BUTTON, glm::vec2(300.0f, 280.0f)), m_isClicked(false)
{

}

InstructionButton::~InstructionButton()
{
}

bool InstructionButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->changeSceneState(INSTRUCTION_SCENE);
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


