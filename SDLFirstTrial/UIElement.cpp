#include "UIElement.h"
int UI::UIElement::count = 0;
UI::UIElement::UIElement()
{
	id = count++;
}

bool UI::UIElement::operator==(const UIElement& other) const 
{
	
	return this->id == other.id;
}
