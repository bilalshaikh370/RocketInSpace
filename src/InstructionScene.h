#pragma once
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__

#include "Scene.h"
#include "Label.h"
#include "space.h"
#include "StartButton.h"


class InstructionScene : public Scene
{
public:
	// constructor
	InstructionScene();
	// destructor
	~InstructionScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// Game Objects
	Label* m_pStartLabel;
	Label* m_pStartLabel2;
	Label* m_pStartLabel3;

	StartButton* m_pStartButton;
	
	Space* m_pSpace;

	// private data member
	glm::vec2 m_mousePosition;

};

#endif /* defined (__START_SCENE__) */