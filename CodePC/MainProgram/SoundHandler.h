#pragma once
#include <SFML/Audio.hpp>
class SoundHandler
{
private:
	sf::SoundBuffer shootBuffer;
	sf::SoundBuffer collisionBuffer;
	sf::SoundBuffer destroyBuffer;
	sf::Sound sound;
public:
	SoundHandler();
	void shoot();
	void collision();
	void destroyBalls();
};

