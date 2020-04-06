#pragma once
#ifndef __SPACE__
#define __SPACE__

#include "DisplayObject.h"

class Space : public DisplayObject
{
public:
	Space();
	~Space();

	void draw() override;
	void update() override;
	void clean() override;
private:
	void m_move();
	void m_checkBounds();
	void m_reset();
};

#endif /* defined (__SPACE__) */