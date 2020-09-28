#include "Player2.h"
#include "definitions.h"

Player2::Player2(GameDataRef data)
{
	_data = data;
	_bombLimit = PLAYER2_BOMB_LIMIT;
	_animations.emplace_back(Animation(&_data->_assets.getTexture("Player2 Frames"), sf::Vector2u(3, 4), PLAYERS_ANIMATION_DURATION));
	_playerSprite.setTexture(_data->_assets.getTexture("Player2 Frames"));

	sf::Vector2u _frameSize = _data->_assets.getTexture("Player2 Frames").getSize();
	_frameSize.x /= 3;
	_frameSize.y /= 4;

	_playerSprite.setTextureRect(sf::IntRect(_frameSize.x, _frameSize.y, _frameSize.x, _frameSize.y));
	_playerSprite.setOrigin(_playerSprite.getGlobalBounds().width / 2, _playerSprite.getGlobalBounds().height / 2);
	_playerSprite.setScale(PLAYER_SPRITE_SCALE, PLAYER_SPRITE_SCALE);
	_playerSprite.setPosition(PLAYER2_PLACMENT_X, PLAYER2_PLACMENT_Y);
}

void Player2::drawPlayer()
{
	_data->_window.draw(_playerSprite);

	for (int i = 0; i < _bombs.size(); i++)
	{
		_bombs.at(i).drawBomb();
	}
}

void Player2::playerBumpOff(float speedX, float speedY)
{
	_playerSprite.move(speedX, speedY);
}

void Player2::playerMovment(float dt)
{
	if (!_death)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_playerSprite.move(0, -PLAYERS_SPEED * dt);
			_playerDirection = 1;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_playerSprite.move(0, PLAYERS_SPEED * dt);
			_playerDirection = 2;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_playerSprite.move(PLAYERS_SPEED * dt, 0);
			_playerDirection = 3;

			_animations.at(0).animationUpdate(_playerDirection - 1, 0);
			_playerSprite.setTextureRect(_animations.at(0)._animateingObject);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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

void Player2::spowningBombs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _bombCooldown.getElapsedTime().asSeconds() > BOMB_COOLDOWN && _placedBombCount < _bombLimit)
	{
		_bombs.emplace_back(Bomb(_data, (int)_playerSprite.getPosition().x / ONE_BLOCK_WIDTH * ONE_BLOCK_WIDTH, (int)_playerSprite.getPosition().y / ONE_BLOCK_HEIGHT * ONE_BLOCK_HEIGHT));
		_itsMine = &_bombs.back();
		_placedBombCount++;
		_bombCooldown.restart();
	}
}

void Player2::explodingBomb()
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

void Player2::playerUpdate()
{
	if (this->_clock.getElapsedTime().asSeconds() > 5)
	{
		this->_godMode = false;
		this->_clock.restart();
	}

	if (!_death)
		_timeBeforeDeath = _deathClock.getElapsedTime().asSeconds();
}

void Player2::setPlayerStatus(bool status)
{
	_godMode = status;
}

void Player2::setIfPlayerDeath(bool death)
{
	_death = death;
}

void Player2::playerDeathAnimation()
{
	if (_death)
	{
		_animations.emplace_back(Animation(&_data->_assets.getTexture("Player2 Death Frames"), sf::Vector2u(7, 1), DEATH_ANIMATION_DURATION));
		_playerSprite.setTexture(_data->_assets.getTexture("Player2 Death Frames"));
		_animations.at(1).animationUpdate(0, 0);
		_playerSprite.setTextureRect(_animations.at(1)._animateingObject);

		if (_deathClock.getElapsedTime().asSeconds() > (_timeBeforeDeath + SWITCHING_STATE_TIMER))
		{
			_switchState = true;
		}
	}
}

void Player2::bombPlacedUpdate()
{
	if (!_bombs.empty())
	{
		for (int i = 0; i < _bombs.size(); i++)
		{
			_bombs.at(i).bombUpdate();
		}
	}
}

bool Player2::getPlayerStatus()
{
	return _godMode;
}

bool Player2::canSwitchState()
{
	return _switchState;
}

Bomb *Player2::getBomb(unsigned short int iterator)
{
	if (!_bombs.empty())
		return &_bombs.at(iterator);
}

const sf::Sprite & Player2::getSprite() const
{
	return _playerSprite;
}

const sf::Sprite & Player2::getBombSprite(unsigned short int iterator) const
{
	if (!_bombs.empty())
		return _bombs.at(iterator).getSprite();
}

const sf::Sprite & Player2::getBombExplosionSprite(unsigned short int iterator) const
{
	if (!_bombs.empty())
		return _bombs.at(iterator).getExplosionSprite();
}

unsigned short int Player2::getPlayerDirection()
{
	return _playerDirection;
}

bool Player2::getBombsStatus(unsigned short int iterator)
{
	if (!_bombs.empty())
		return _bombs.at(iterator).getBombStatus();
	else
		return false;
}

unsigned short int Player2::getBombCount()
{
	return _placedBombCount;
}