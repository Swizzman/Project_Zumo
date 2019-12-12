#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class GameEntity : public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	GameEntity(std::string texture);
	sf::FloatRect getBounds() const;
	void setOrigin(int x, int y);
	void setPosition(int x, int y);
	sf::Vector2f getPosition() const;
	void setRotation(float angle);
	float getRotation() const;
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

