#include "HUD.h"

HUD::HUD(GameDataRef data) : _data(data), _p1LifesNumber(PLAYER_NUMBER_OF_LIFES), _p2LifesNumber(PLAYER_NUMBER_OF_LIFES), _seconds(sf::seconds(PLAYTIME))
{
	_timer.setFont(_data->_assets.getFont("Bomberman Font"));
	_timer.setCharacterSize(30.0f);
	_timer.setString("Time left: ");
	_timer.setOrigin(_timer.getGlobalBounds().width / 2, _timer.getGlobalBounds().height / 2);
	_timer.setPosition(WINDOW_WIDTH / 2, _timer.getGlobalBounds().height * 3);
	_timeLeft = _seconds.asSeconds();

	sf::Vector2u _tempSpriteSize = _data->_assets.getTexture("Life").getSize();

	for (int i = 0; i < PLAYER_NUMBER_OF_LIFES; i++)
	{
		_p1Lifes[i].setTexture(_data->_assets.getTexture("Life"));
		_p1Lifes[i].setOrigin(_p1Lifes[i].getGlobalBounds().width / 2, _p1Lifes[i].getGlobalBounds().height / 2);
		_p1Lifes[i].setPosition(_p1Lifes[i].getGlobalBounds().width + (_tempSpriteSize.x + 5) * i, _p1Lifes[i].getGlobalBounds().height + _p1Lifes[i].getGlobalBounds().height / 2);

		_p2Lifes[i].setTexture(_data->_assets.getTexture("Life Player 2"));
		_p2Lifes[i].setOrigin(_p2Lifes[i].getGlobalBounds().width / 2, _p2Lifes[i].getGlobalBounds().height / 2);
		_p2Lifes[i].setPosition(WINDOW_WIDTH - _p2Lifes[i].getGlobalBounds().width - (_tempSpriteSize.x + 5) * i, _p2Lifes[i].getGlobalBounds().height + _p2Lifes[i].getGlobalBounds().height / 2);
	}
}

HUD::~HUD()
{
	delete _p1Lifes, _p2Lifes;
}

void HUD::Draw()
{
	_data->_window.draw(_timer);

	for (int i = 0; i < PLAYER_NUMBER_OF_LIFES; i++)
	{
		_data->_window.draw(_p1Lifes[i]);
		_data->_window.draw(_p2Lifes[i]);
	}
}

unsigned short int HUD::getNumberOfLifes(unsigned short int _playerID)
{
	if (_playerID == 1)
		return _p1LifesNumber;
	else if (_playerID == 2)
		return _p2LifesNumber;
}

void HUD::countdownTimerUpdate()
{
	_timeLeft = _seconds.asSeconds() - _countingDownClock.getElapsedTime().asSeconds();
	_timer.setString("Time Left: " + std::to_string(_timeLeft));
}

int HUD::getTimeLeft()
{
	return _timeLeft;
}

void HUD::updateLifes(bool p1Hit, bool p2Hit)
{
	if ((p1Hit) && (_p1LifesNumber > 0))
	{
		_p1Lifes[_p1LifesNumber - 1].setColor(sf::Color(0, 0, 0, 0));
		_p1LifesNumber--;
	}
	else if ((p2Hit) && (_p2LifesNumber > 0))
	{
		_p2Lifes[_p2LifesNumber - 1].setColor(sf::Color(0, 0, 0, 0));
		_p2LifesNumber--;
	}
}