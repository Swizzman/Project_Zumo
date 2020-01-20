#pragma once
#include <SFML/Graphics.hpp>
class Logo : public sf::Drawable
{
private:
	sf::IntRect intRect;

	sf::Sprite sprite;
	sf::Texture texture;
public:
	Logo();
	void setPosition(int x, int y);
	virtual ~Logo();
	void nextFrame();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

