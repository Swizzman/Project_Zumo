#include "GameEntity.h"

GameEntity::GameEntity(std::string texture)
{
	this->texture.loadFromFile("../images/" + texture);
	this->sprite.setTexture(this->texture);
}

sf::FloatRect GameEntity::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void GameEntity::move(int speedX, int speedY)
{
	this->sprite.move(speedX, speedY);
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

sf::Vector2f GameEntity::getPosition() const
{
	return this->sprite.getPosition();
}

void GameEntity::setRotation(float angle)
{
	this->sprite.setRotation(angle);
}

sf::Vector2f GameEntity::lerp(sf::Vector2f currentPos, sf::Vector2f destPos, float modifier)
{
	return currentPos + (destPos - currentPos) * modifier;
}

float GameEntity::getRotation() const
{
	return this->sprite.getRotation();
}

void GameEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, sf::RenderStates::Default);
}
