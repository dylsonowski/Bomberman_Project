#include "Bomb.h"

Bomb::Bomb(GameDataRef data, int xCords, int yCords) : _data(data), _exploded(false), _destroyed(false)
{
	_animations.emplace_back(Animation(&_data->_assets.getTexture("Bomb Frames"), sf::Vector2u(4, 1), BOMBS_ANIMATION_DURATION));
	_bombSprite.setTexture(_data->_assets.getTexture("Bomb Frames"));

	sf::Vector2u _frameSize = _data->_assets.getTexture("Bomb Frames").getSize();
	_frameSize.x /= 4;

	_bombSprite.setTextureRect(sf::IntRect(_frameSize.x, 0, _frameSize.x, _frameSize.y));
	_bombSprite.setOrigin(_bombSprite.getGlobalBounds().width / 2, _bombSprite.getGlobalBounds().height / 2);
	_bombSprite.setScale(BOMB_SPRITE_SCALE, BOMB_SPRITE_SCALE);
	_bombSprite.setPosition(xCords + ONE_BLOCK_WIDTH / 2, yCords + ONE_BLOCK_HEIGHT / 2);

	_explosionSprite.setTexture(_data->_assets.getTexture("Explosion Frames"));

	sf::Vector2u _frameSize2 = _data->_assets.getTexture("Explosion Frames").getSize();
	_frameSize2.x /= 4;

	_explosionSprite.setTextureRect(sf::IntRect(_frameSize2.x * 3, 0, _frameSize2.x, _frameSize2.y));
	_explosionSprite.setOrigin(_explosionSprite.getGlobalBounds().width / 2, _explosionSprite.getGlobalBounds().height / 2);
	_explosionSprite.setPosition(xCords + ONE_BLOCK_WIDTH / 2, yCords + ONE_BLOCK_HEIGHT / 2);
}

void Bomb::drawBomb()
{
	_data->_window.draw(_bombSprite);

	if (_exploded)
		_data->_window.draw(_explosionSprite);
}

void Bomb::bombUpdate()
{
	if (!_exploded)
	{
		_animations.at(0).animationUpdate(0, 0);
		_bombSprite.setTextureRect(_animations.at(0)._animateingObject);
	}

	if (_explosionCountdown.getElapsedTime().asSeconds() > BOMB_TIMER)
	{
		_exploded = true;
		_animations.emplace_back(Animation(&_data->_assets.getTexture("Explosion Frames"), sf::Vector2u(4, 1), BOMB_EXPLOSION_ANIMATION_DURATION));
		_animations.at(1).animationUpdate(0, 0);
		_explosionSprite.setTextureRect(_animations.at(1)._animateingObject);

		if (_explosionCountdown.getElapsedTime().asSeconds() > BOMB_DESTRUCT_TIMER)
			_destroyed = true;
	}
}

const sf::Sprite & Bomb::getSprite() const
{
	return _bombSprite;
}

const sf::Sprite & Bomb::getExplosionSprite() const
{
	return _explosionSprite;
}

bool Bomb::getBombStatus()
{
	return _exploded;
}

bool Bomb::isBombExploded()
{
	return _destroyed;
}