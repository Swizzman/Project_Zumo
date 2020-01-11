#include "Logo.h"

Logo::Logo():GameEntity("logo.png")
{
	intRect = sf::IntRect(0, 0, getTextureSize().x / 30, getTextureSize().y);
	setTextureRect(intRect);
}

Logo::~Logo()
{
}

void Logo::nextFrame()
{
	this->intRect.left = (this->intRect.left + this->intRect.width) % getTextureSize().x;
	setTextureRect(intRect);
}
