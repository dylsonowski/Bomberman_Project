#include "InputManager.h"

bool InputManager::SpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))	 
	{
		if (isMouseUnder(object, window))	
		{
			return true;
		}
	}
	return false;
}

bool InputManager::isMouseUnder(sf::Sprite object, sf::RenderWindow& window)
{
	sf::IntRect ButtonColide(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

	if (ButtonColide.contains(sf::Mouse::getPosition(window)))
	{
		return true;
	}
	return false;
}

sf::Vector2i InputManager::MousePosition(sf::RenderWindow window)
{
	return sf::Mouse::getPosition(window);
}