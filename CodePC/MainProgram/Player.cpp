#include "Player.h"

Player::Player(std::string texture):GameEntity(texture)
{
	this->shootBall = nullptr;
	this->lives = 20;
	this->offset = getPosition() - (sf::Vector2f)mouse.getPosition();
	setOrigin(getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2);
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
		/*Lägg in funktion här*/
		shot = true;
		releaseBall();
	}
	return shot;
}



void Player::rotate(sf::RenderWindow &window)
{
	if (shootBall != nullptr)
	{
		shootBall->setPosition(getOrigin().x + getBounds().width / 2, getOrigin().y);
	}
	this->offset = (sf::Vector2f)mouse.getPosition(window) - getPosition();
	setRotation(atan2f(offset.y, offset.x) * (180 / 3.14));
}
