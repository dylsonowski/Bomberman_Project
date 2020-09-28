#include "Collision.h"

bool Collision::checkCollision(sf::Sprite object1, sf::Sprite object2)
{
	sf::Rect<float> rect1 = object1.getGlobalBounds();
	sf::Rect<float> rect2 = object2.getGlobalBounds();

	if (rect1.intersects(rect2))
		return true;
	else
		return false;
}

bool Collision::checkCollisionBetter(sf::Sprite object1, sf::Sprite object2, float scale1X, float scale1Y, float scale2X, float scale2Y)
{
	object1.setScale(scale1X, scale1Y);
	object2.setScale(scale2X, scale2Y);

	sf::Rect<float> rect1 = object1.getGlobalBounds();
	sf::Rect<float> rect2 = object2.getGlobalBounds();

	if (rect1.intersects(rect2))
		return true;
	else
		return false;
}