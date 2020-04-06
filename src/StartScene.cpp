#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	//m_pOcean->draw();
	m_pSpace->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
	m_pInstructionButton->draw();
	m_pQuitButton->draw();
	
}

void StartScene::update()
{
	//m_pOcean->update();
	m_pSpace->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	m_pInstructionButton->setMousePosition(m_mousePosition);
	m_pInstructionButton->ButtonClick();
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

}

void StartScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				m_pInstructionButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				m_pInstructionButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;





			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	/*m_pOcean = new Ocean();
	addChild(m_pOcean);*/
	m_pSpace = new Space();
		addChild(m_pSpace);

	
	SDL_Color Green = { 0, 255, 255, 255 };
	m_pStartLabel = new Label("Rocket in Space", "Dock51", 80, Green, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pStartButton = new StartButton();
	/*m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));*/
	addChild(m_pStartButton);

	m_pInstructionButton = new InstructionButton();
	//m_pInstructionButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.3f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pInstructionButton);

	m_pQuitButton = new QuitButton();
	//m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pQuitButton);
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
