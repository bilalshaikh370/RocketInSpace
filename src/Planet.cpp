#include "Planet.h"
#include "Game.h"

Planet::Planet()
{
	TheTextureManager::Instance()->load("../Assets/textures/rock.png",
		"Planet", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("Planet");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::PLANET);


	TheSoundManager::Instance()->load("../Assets/audio/collision.wav", "thunder", SOUND_SFX);
}

Planet::~Planet()
= default;

void Planet::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("Planet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 128, true);
}

void Planet::update()
{
	m_move();
	m_checkBounds();
}

void Planet::clean()
{
}

void Planet::m_reset()
{
	// speed changes
	const auto randomVelocityX = Util::RandomRange(-2, 2);
	const auto randomVelocityY = Util::RandomRange(5, 10);
	setVelocity(glm::vec2(randomVelocityX, randomVelocityY));

	// positional changes
	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Planet::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Planet::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}
