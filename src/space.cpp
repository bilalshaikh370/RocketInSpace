#include "space.h"
#include "Game.h"

Space::Space()
{
	TheTextureManager::Instance()->load("../Assets/textures/back.png",
		"Space", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Space");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, -960.0f));
	setIsColliding(false);
	setType(SPACE);
	setVelocity(glm::vec2(0.0f, 5.0f));

}

Space::~Space()
{
}

void Space::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("Space", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Space::update()
{
	m_move();
	m_checkBounds();
}

void Space::clean()
{
}

void Space::m_move()
{
	setPosition(getPosition() + getVelocity());
}

void Space::m_checkBounds()
{
	if (getPosition().y >= 0.0f)
	{
		m_reset();
	}
}

void Space::m_reset()
{
	setPosition(glm::vec2(0.0f, -960.0f));
}
