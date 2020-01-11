#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
class GameEntity : public sf::Drawable
{
private:

	sf::Sprite sprite;
	sf::Texture texture;

public:
	GameEntity(std::string texture);
	void setTexture(sf::Texture newTexture);
	void setTextureRect(sf::IntRect intRect);
	sf::Vector2u getTextureSize() const;
	sf::FloatRect getBounds() const;
	void move(int speedX, int speedY);
	void move(sf::Vector2f dir, int speed);
	void setOrigin(int x, int y);
	sf::Vector2f getOrigin() const;
	void setPosition(int x, int y);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	void setRotation(float angle);
	sf::Vector2f lerp(sf::Vector2f currentPos, sf::Vector2f destPos, float modifier);
	float getRotation() const;
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

