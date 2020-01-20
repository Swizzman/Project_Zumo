#include "GameEntity.h"

GameEntity::GameEntity(std::string texture)
{
	this->texture.loadFromFile("../images/" + texture);
	this->sprite.setTexture(this->texture);
	this->setOrigin(0, 0);
}

void GameEntity::setTexture(sf::Texture newTexture)
{
	this->texture = newTexture;
}

void GameEntity::setTextureRect(sf::IntRect intRect)
{
	sprite.setTextureRect(intRect);
}

sf::Vector2u GameEntity::getTextureSize() const
{
	return texture.getSize();
}



sf::FloatRect GameEntity::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void GameEntity::move(float x, float y)
{
	this->sprite.move(x, y);
}



void GameEntity::setOrigin(int x, int y)
{
	this->sprite.setOrigin(x, y);
}

sf::Vector2f GameEntity::getOrigin() const
{
	return this->sprite.getOrigin();
}

void GameEntity::setPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}

void GameEntity::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

sf::Vector2f GameEntity::getPosition() const
{
	return this->sprite.getPosition();
}

void GameEntity::setRotation(float angle)
{
	this->sprite.setRotation(angle);
}

float GameEntity::getRotation() const
{
	return this->sprite.getRotation();
}

void GameEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, sf::RenderStates::Default);
}
