#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "Ocean.h"
#include "Cloud.h"
#include "Config.h"
#include "Rocket.h"
#include "space.h"
#include "Planet.h"
#include "Diamonds.h"

//Name : Bilal Shaikh (301093908)


class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	
	Diamonds* m_pDiamonds;
	
	Rocket* m_pRocket;
	Space* m_pSpace;

	int m_PlanetNum = Config::PLANET_NUM;
	std::vector<Planet*> m_pPlanets;
	void m_buildPlanets();

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
