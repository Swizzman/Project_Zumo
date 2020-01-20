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
	void move(float x, float y);
	virtual void moveSpecific() = 0;
	void setOrigin(int x, int y);
	sf::Vector2f getOrigin() const;
	void setPosition(int x, int y);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	void setRotation(float angle);
	float getRotation() const;
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

