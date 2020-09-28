#include "Animation.h"
#include "definitions.h"

Animation::Animation(sf::Texture * texture, sf::Vector2u frameCount, float totalTime) : _frameCount(frameCount), _totalAnimationTime(totalTime)
{
	_currentFrame.x = 0;
	_animateingObject.width = texture->getSize().x / float(frameCount.x);
	_animateingObject.height = texture->getSize().y / float(frameCount.y);
}

void Animation::animationUpdate(unsigned int row, unsigned int column)
{
	_currentFrame.y = row;

	if ((_clock.getElapsedTime().asSeconds() >= _totalAnimationTime / _frameCount.x) && column == 0)
	{
		_currentFrame.x++;

		if (_currentFrame.x >= _frameCount.x)
		{
			_currentFrame.x = 0;
		}

		_clock.restart();
	}

	if(column != 0)
		_currentFrame.x = column;

	_animateingObject.left = _currentFrame.x * _animateingObject.width;
	_animateingObject.top = _currentFrame.y * _animateingObject.height;
}