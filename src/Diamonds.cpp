#include "Diamonds.h"
#include "Game.h"

Diamonds::Diamonds()
{
	TheTextureManager::Instance()->load("../Assets/textures/diamond.png",
		"Diamonds", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Diamonds");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::DIAMONDS);
	setVelocity(glm::vec2(0.0f, 5.0f));

	TheSoundManager::Instance()->load("../Assets/audio/sfx.wav", "yay", SOUND_SFX);


}

Diamonds::~Diamonds()
{
}

void Diamonds::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("Diamonds", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Diamonds::update()
{
	m_move();
	m_checkBounds();
}

void Diamonds::clean()
{
}

void Diamonds::m_reset()
{
	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Diamonds::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Diamonds::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}
