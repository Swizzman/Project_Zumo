#include "Player.h"

Player::Player( int xSize, int ySize):GameEntity("player.png")
{
	dir = sf::Vector2f(0, 0);
	this->shootBall = nullptr;
	this->lives = 30;
	this->score = 0;
	this->ballMoving = false;
	this->offset = getPosition() - (sf::Vector2f)mouse.getPosition();
	this->setOrigin(getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2);
	this->setPosition(xSize / 2, ySize / 2);
}

int Player::getLives() const
{
	return lives;
}

int Player::getScore() const
{
	return this->score;
}

void Player::setDirection()
{
	sf::Vector2f dist = (sf::Vector2f)this->getMousePos() - shootBall->getPosition();
	float magni = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
	dir = sf::Vector2f(dist.x / magni, dist.y / magni);

}

void Player::increaseScore(int increase)
{
	this->score += increase;
}

void Player::decreaseLives()
{
	this->lives--;
}

void Player::receiveBall(Ball* ballPtr)
{
	ballMoving = false;
	shootBall = ballPtr;
	shootBall->setMovingSpeed(20);
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
		ballMoving = true;
		shootBall->setRotation(0.f);
		shot = true;
	}
	return shot;
}



void Player::rotate(sf::RenderWindow &window)
{
	this->offset = (sf::Vector2f)mouse.getPosition(window) - getPosition();
	float rotation = atan2f(offset.y, offset.x) * (180 / 3.14);
	if (shootBall != nullptr && !ballMoving)
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

Player::~Player()
{
}

void Player::moveSpecific()
{
	shootBall->move(dir.x * shootBall->getMovingSpeed(), dir.y * shootBall->getMovingSpeed());
}
