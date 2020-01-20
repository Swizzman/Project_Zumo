#include "Logo.h"

Logo::Logo()
{
	this->texture.loadFromFile("../images/logo.png");
	intRect = sf::IntRect(0, 0, this->texture.getSize().x / 30, this->texture.getSize().y);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(this->intRect);
}

void Logo::setPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}


Logo::~Logo()
{
}

void Logo::nextFrame()
{
	this->intRect.left = (this->intRect.left + this->intRect.width) % this->texture.getSize().x;
	this->sprite.setTextureRect(this->intRect);
}

void Logo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, sf::RenderStates::Default);
}
