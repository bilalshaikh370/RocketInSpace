#pragma once
#ifndef __INSTRUCTION_BUTTON__
#define __INSTRUCTION_BUTTON__

#include "Button.h"

class InstructionButton : public Button
{
public:
	InstructionButton();
	~InstructionButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRUCTION_BUTTON__) */