#include "Tap.h"

Interaction::Tap::Tap(int x, int y, int button):positionX(x), positionY(y), button(button) { }

int Interaction::Tap::getPositionX() const
{
	return positionX;
}

int Interaction::Tap::getPositionY() const
{
	return positionY;
}

int Interaction::Tap::getButton() const
{
	return button;
}
