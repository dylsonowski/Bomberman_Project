#include "Player1.h"
#include "definitions.h"

Player1::Player1(GameDataRef data)
{
	_data = data;
	_bombLimit = PLAYER1_BOMB_LIMIT;
	_animations.emplace_back(Animation(&_data->_assets.getTexture("Player1 Frames"), sf::Vector2u(3, 4), PLAYERS_ANIMATION_DURATION));
	_playerSprite.setTexture(_data->_assets.getTexture("Player1 Frames"));

	sf::Vector2u _frameSize = _data->_assets.getTexture("Player1 Frames").getSize();
	_frameSize.x /= 3;
	_frameSize.y /= 4;

	_playerSprite.setTextureRect(sf::IntRect(_frameSize.x, _frameSize.y, _frameSize.x, _frameSize.y));
	_playerSprite.setOrigin(_playerSprite.getGlobalBounds().width / 2, _playerSprite.getGlobalBounds().height / 2);
	_playerSprite.setScale(PLAYER_SPRITE_SCALE, PLAYER_SPRITE_SCALE);
	_playerSprite.setPosition(PLAYER1_PLACMENT_X, PLAYER1_PLACMENT_Y);
}

void Player1::drawPlayer()
{
	_data->_window.draw(_playerSprite);

	for (int i = 0; i < _bombs.size(); i++)
	{
		_bombs.at(i).drawBomb();
	}
}

void Player1::playerBumpOff(float speedX, float speedY)
{
	_playerSprite.move(speedX, speedY);
}

void Player1::playerMovment(float dt)
{
	if (!_death)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_playerSprite.move(0, -PLAYERS_SPEED * dt);
			_playerDirection = 1;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			_playerSprite.move(0, PLAYERS_SPEED * dt);
			_playerDirection = 2;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_playerSprite.move(PLAYERS_SPEED * dt, 0);
			_playerDirection = 3;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_playerSprite.move(-PLAYERS_SPEED * dt, 0);
			_playerDirection = 4;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else
		{
			_playerSprite.move(0, 0);
			_animations.at(0).animationUpdate(1, 1);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
	}
}

void Player1::spowningBombs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _bombCooldown.getElapsedTime().asSeconds() > BOMB_COOLDOWN && _placedBombCount < _bombLimit)
	{
		_bombs.emplace_back(Bomb(_data, (int)_playerSprite.getPosition().x / ONE_BLOCK_WIDTH * ONE_BLOCK_WIDTH, (int)_playerSprite.getPosition().y / ONE_BLOCK_HEIGHT * ONE_BLOCK_HEIGHT));
		_itsMine = &_bombs.back();
		_placedBombCount++;
		_bombCooldown.restart();
	}
}

void Player1::explodingBomb()
{
	if (!_bombs.empty())
	{
		for (int i = 0; i < _bombs.size(); i++)
		{
			if (_bombs.at(i).isBombExploded())
			{
				_placedBombCount--;
				_bombs.erase(_bombs.begin());
			}
		}
	}
}

void Player1::playerUpdate()
{
	if (this->_clock.getElapsedTime().asSeconds() > 5)
	{
		this->_godMode = false;
		this->_clock.restart();
	}

	if (!_death)
		_timeBeforeDeath = _deathClock.getElapsedTime().asSeconds();
}

void Player1::setPlayerStatus(bool status)
{
	_godMode = status;
}

void Player1::setIfPlayerDeath(bool death)
{
	_death = death;
}

void Player1::playerDeathAnimation()
{
	if (_death)
	{
		_animations.emplace_back(Animation(&_data->_assets.getTexture("Player1 Death Frames"), sf::Vector2u(7, 1), DEATH_ANIMATION_DURATION));
		_playerSprite.setTexture(_data->_assets.getTexture("Player1 Death Frames"));
		_animations.at(1).animationUpdate(0, 0);
		_playerSprite.setTextureRect(_animations.at(1)._animateingObject);

		if (_deathClock.getElapsedTime().asSeconds() > (_timeBeforeDeath + SWITCHING_STATE_TIMER))
		{
			_switchState = true;
		}
	}
}

void Player1::bombPlacedUpdate()
{
	if (!_bombs.empty())
	{
		for (int i = 0; i < _bombs.size(); i++)
		{
			_bombs.at(i).bombUpdate();
		}
	}
}

bool Player1::getPlayerStatus()
{
	return _godMode;
}

bool Player1::canSwitchState()
{
	return _switchState;
}

Bomb *Player1::getBomb(unsigned short int iterator)
{
	if (!_bombs.empty())
		return &_bombs.at(iterator);
}

const sf::Sprite & Player1::getSprite() const
{
	return _playerSprite;
}

const sf::Sprite & Player1::getBombSprite(unsigned short int iterator) const
{
	if(!_bombs.empty())
		return _bombs.at(iterator).getSprite();
}

const sf::Sprite & Player1::getBombExplosionSprite(unsigned short int iterator) const
{
	if (!_bombs.empty())
		return _bombs.at(iterator).getExplosionSprite();
}

unsigned short int Player1::getPlayerDirection()
{
	return _playerDirection;
}

bool Player1::getBombsStatus(unsigned short int iterator)
{
	if (!_bombs.empty())
		return _bombs.at(iterator).getBombStatus();
	else
		return false;
}

unsigned short int Player1::getBombCount()
{
	return _placedBombCount;
}