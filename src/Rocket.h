#pragma once
#ifndef __ROCKET__
#define __ROCKET__
#include "DisplayObject.h"
#include "Move.h"

class Rocket : public DisplayObject
{
public:
	Rocket();
	~Rocket();

	void draw() override;
	void update() override;
	void clean() override;

	void move(Move newMove);

	//getters and setters
	bool getIsMoving();
	void setIsMoving(bool newState);

private:
	float m_maxSpeed;

	bool m_isMoving;

	void m_checkBounds();
};

#endif /* defined (__ROCKET__) */