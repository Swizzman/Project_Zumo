#include "SoundHandler.h"

SoundHandler::SoundHandler()
{
	shootBuffer.loadFromFile("../DataFiles/Sounds/Ball_Click1.wav");
	collisionBuffer.loadFromFile("../DataFiles/Sounds/Ball_Collision.wav");
	destroyBuffer.loadFromFile("../DataFiles/Sounds/Balls_Destroyed1.wav");


}

void SoundHandler::shoot()
{
	sound.setBuffer(shootBuffer);
	sound.play();
}

void SoundHandler::collision()
{
	sound.setBuffer(collisionBuffer);
	sound.play();
}

void SoundHandler::destroyBalls()
{
	sound.setBuffer(destroyBuffer);
	sound.play();
}
