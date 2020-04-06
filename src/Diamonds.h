#pragma once
#ifndef __DIAMONDS__
#define __DIAMONDS__
#include "DisplayObject.h"

class Diamonds : public DisplayObject
{
public:
	Diamonds();
	~Diamonds();

	void draw() override;
	void update() override;
	void clean() override;

private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

#endif /* defined (__DIAMONDS__) */