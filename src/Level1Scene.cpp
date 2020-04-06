#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "ScoreBoardManager.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//m_pOcean->draw();
	
	m_pSpace->draw();
	
	
	//m_pIsland->draw();
	m_pDiamonds->draw();
	
	//m_pPlane->draw();

	m_pRocket->draw();

	for (auto planet : m_pPlanets)
	{
		planet->draw();
	}

	ScoreBoardManager::Instance()->Draw();
}

void Level1Scene::update()
{
	//m_pOcean->update();

	//TheSoundManager::Instance()->load("../Assets/audio/rain.wav", "thunder", SOUND_SFX);

	m_pSpace->update();
	//m_pIsland->update();
	m_pDiamonds->update();

	//m_pPlane->setPosition(glm::vec2(m_mousePosition.x, m_pPlane->getPosition().y));
	//m_pPlane->update();

	m_pRocket->setPosition(glm::vec2(m_mousePosition.x, m_pRocket->getPosition().y));
	m_pRocket->update();
	//CollisionManager::AABBCheck(m_pPlane, m_pIsland);

	CollisionManager::squaredRadiusCheck(m_pRocket, m_pDiamonds);

	for (auto planet: m_pPlanets)
	{
		planet->update();
		CollisionManager::squaredRadiusCheck(m_pRocket, planet);
	}
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	auto wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
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
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
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
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				m_pRocket->move(LEFT);
				break;
			case SDLK_d:
				m_pRocket->move(RIGHT);
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				m_pRocket->setIsMoving(false);
				break;
			case SDLK_d:
				m_pRocket->setIsMoving(false);
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	/*m_pOcean = new Ocean();
	addChild(m_pOcean);*/

	//m_pIsland = new Island(); // instantiates Island
	//addChild(m_pIsland);
	
	m_pDiamonds = new Diamonds(); // instantiates Island
	addChild(m_pDiamonds);

	//m_pPlane = new Plane(); // instantiates Plane
	//addChild(m_pPlane);

	m_pRocket = new Rocket();
	addChild(m_pRocket);

	m_pSpace = new Space();
	addChild(m_pSpace);

	// instantiate Cloud Pool
	m_buildPlanets();
	TheSoundManager::Instance()->load("../Assets/audio/rain.wav", "thunder", SOUND_SFX);
	ScoreBoardManager::Instance()->Start();
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::m_buildPlanets()
{
	for (auto i = 0; i < m_PlanetNum; ++i)
	{
		auto planet = new Planet();
		m_pPlanets.push_back(planet);
		addChild(planet);
	}
}

