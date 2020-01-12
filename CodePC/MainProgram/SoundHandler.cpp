#include "SoundHandler.h"

SoundHandler::SoundHandler()
{
	shootBuffer.loadFromFile("../DataFiles/Sounds/Ball_Click1.wav");
	collisionBuffer.loadFromFile("../DataFiles/Sounds/Ball_Collision.wav");


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

