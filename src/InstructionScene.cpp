#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

//Name : Bilal Shaikh (301093908)


InstructionScene::InstructionScene()
{
	InstructionScene::start();
}

InstructionScene::~InstructionScene()
{
}

void InstructionScene::draw()
{
	//m_pOcean->draw();
	m_pSpace->draw();
	m_pStartLabel->draw();
	m_pStartLabel2->draw();
	m_pStartLabel3->draw();
	m_pStartButton->draw();
	

}

void InstructionScene::update()
{
	//m_pOcean->update();
	m_pSpace->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	
}

void InstructionScene::clean()
{
	delete m_pStartLabel;
delete m_pStartLabel2;
delete m_pStartLabel3;

	
	removeAllChildren();
}

void InstructionScene::handleEvents()
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
			
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				
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
void InstructionScene::start()
{
	/*m_pOcean = new Ocean();
	addChild(m_pOcean);*/
	m_pSpace = new Space();
	addChild(m_pSpace);


	SDL_Color Green = { 0, 255, 255, 255 };
	m_pStartLabel = new Label("Rocket in Space Game You Are Controlling Rocket ", "Dock51", 20, Green,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);
	m_pStartLabel2 = new Label(" With Your Mouse Collect Diamonds To Gain High Score", "Dock51", 20, Green,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 120.0f));
	m_pStartLabel2->setParent(this);
	addChild(m_pStartLabel2);

	m_pStartLabel3 = new Label(" While Escaping The Rocks", "Dock51", 20, Green,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 140.0f));
	m_pStartLabel3->setParent(this);
	addChild(m_pStartLabel3);

	m_pStartButton = new StartButton();
	/*m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));*/
	addChild(m_pStartButton);


}

glm::vec2 InstructionScene::getMousePosition()
{
	return m_mousePosition;
}
