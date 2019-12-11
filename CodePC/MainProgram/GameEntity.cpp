#include "GameEntity.h"

GameEntity::GameEntity(std::string texture)
{
	this->texture.loadFromFile("../bin/images/" + texture);
	this->sprite.setTexture(this->texture);
}

sf::FloatRect GameEntity::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void GameEntity::setOrigin(int x, int y)
{
	this->sprite.setOrigin(x, y);
}

void GameEntity::setPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}

sf::Vector2f GameEntity::getPosition() const
{
	return this->sprite.getPosition();
}

void GameEntity::setRotation(float angle)
{
	this->sprite.setRotation(angle);
}

void GameEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, sf::RenderStates::Default);
}
