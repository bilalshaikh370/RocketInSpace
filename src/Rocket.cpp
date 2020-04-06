#include "Rocket.h"
#include "Game.h"

Rocket::Rocket() :m_maxSpeed(5.0f), m_isMoving(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/Rocket.png",
		"Rocket", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Rocket");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::ROCKET);
	setVelocity(glm::vec2(0.0f, 0.0f));

}

Rocket::~Rocket()
{
}

void Rocket::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("Rocket", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Rocket::update()
{

	/*auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	const auto deltaTime = TheGame::Instance()->getDeltaTime();
	setVelocity(glm::vec2(currentVelocity.x * (1.0f - deltaTime * 5.0f), currentVelocity.y));


	auto deltax = currentPosition.x + currentVelocity.x;
	setPosition(glm::vec2(deltax, currentPosition.y));*/

	m_checkBounds();
}

void Rocket::clean()
{
}

void Rocket::move(Move newMove)
{
	auto currentVelocity = getVelocity();


	switch (newMove)
	{
	case RIGHT:
		setVelocity(glm::vec2(1.0f * m_maxSpeed, 0.0f));
		break;
	case LEFT:
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, 0.0f));
		break;
	}
}

bool Rocket::getIsMoving()
{
	return m_isMoving;
}

void Rocket::setIsMoving(bool newState)
{
	m_isMoving = newState;
}

void Rocket::m_checkBounds()
{
	// check right bounds
	if (getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
	}

	// check left bounds
	if (getPosition().x <= getWidth() * 0.5f)
	{
		setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
	}
}
