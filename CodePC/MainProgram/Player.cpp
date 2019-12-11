#include "Player.h"

Player::Player(std::string texture):GameEntity(texture)
{
}

void Player::rotate()
{
	setRotation(atan2f(mouse.getPosition().x, getPosition().x));
}
