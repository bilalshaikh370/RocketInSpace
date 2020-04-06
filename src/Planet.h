#pragma once
#ifndef __PLANET__
#define __PLANET__
#include "DisplayObject.h"
class Planet : public DisplayObject
{
public:
	Planet();
	~Planet();

	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};
#endif /* defined (__PLANET__) */

