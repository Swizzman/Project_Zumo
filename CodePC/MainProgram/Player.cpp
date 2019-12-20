#include "Player.h"

Player::Player( int xSize, int ySize):GameEntity("player.png")
{
	this->shootBall = nullptr;
	this->lives = 20;
	this->offset = getPosition() - (sf::Vector2f)mouse.getPosition();
	this->setOrigin(getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2);
	this->setPosition(xSize / 2, ySize / 2);
}

int Player::getLives() const
{
	return lives;
}

void Player::recieveBall(Ball* ballPtr)
{
	shootBall = ballPtr;
}

void Player::releaseBall()
{
	shootBall = nullptr;
}

bool Player::shoot()
{
	bool shot = false;
	if (shootBall != nullptr && mouse.isButtonPressed(sf::Mouse::Button::Left))
	{

		shootBall->setRotation(0.f);
		shot = true;
		releaseBall();
	}
	return shot;
}



void Player::rotate(sf::RenderWindow &window)
{
	this->offset = (sf::Vector2f)mouse.getPosition(window) - getPosition();
	float rotation = atan2f(offset.y, offset.x) * (180 / 3.14);
	if (shootBall != nullptr)
	{
		shootBall->setPosition(getPosition().x , getPosition().y);
		shootBall->setRotation(rotation);
	}

	
	setRotation(rotation);
}

sf::Vector2f Player::getMousePos() const
{
	return (sf::Vector2f)mouse.getPosition();
}
