#include "EndScreenState.h"

EndScreenState::EndScreenState(GameDataRef data, bool Win, bool draw) : _data(data), _isWinerP1(Win), _draw(draw)
{
}

void EndScreenState::Init()
{
	_data->_assets.LoadTexture("Victory Background", VICTORY_SCREEN_BACKGROUND);
	_data->_assets.LoadTexture("Game Over Background", GAME_OVER_SCREEN_BACKGROUND);
	_data->_assets.LoadTexture("Surprise", END_SCREEN_SURPRISE);
	_data->_assets.LoadFont("Bomberman Font", BOMBERMAN_FONT);

	if (!_data->_assets._closeWindow)
	{
		if (!_draw)
		{
			_Winbackground.setTexture(_data->_assets.getTexture("Victory Background"));
			_Winbackground.setOrigin(_Winbackground.getGlobalBounds().width / 2, _Winbackground.getGlobalBounds().height / 2);
			_Winbackground.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

			_surprise.setTexture(_data->_assets.getTexture("Surprise"));
			_surprise.setOrigin(_surprise.getGlobalBounds().width / 2, _surprise.getGlobalBounds().height / 2);
			_surprise.setPosition((WINDOW_WIDTH / 2) + (WINDOW_WIDTH / 4), WINDOW_HEIGHT / 2);

			_winnerMark.setFont(_data->_assets.getFont("Bomberman Font"));
			_winnerMark.setCharacterSize(30.0f);
			_winnerMark.setOrigin(_winnerMark.getGlobalBounds().width / 2, _winnerMark.getGlobalBounds().height / 2);
			_winnerMark.setPosition(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 4);

			if (_isWinerP1)
			{
				_winnerMark.setString("And the winner is Player 1");
			}
			else
			{
				_winnerMark.setString("And the winner is Player 2");
			}
		}
		else
		{
			_Winbackground.setTexture(_data->_assets.getTexture("Game Over Background"));
			_Winbackground.setOrigin(_Winbackground.getGlobalBounds().width / 2, _Winbackground.getGlobalBounds().height / 2);
			_Winbackground.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
	}
}

void EndScreenState::HInput()
{
	sf::Event _event;

	while (_data->_window.pollEvent(_event))
	{
		if ((sf::Event::Closed == _event.type) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) || _data->_assets._closeWindow)
		{
			_data->_window.close();
		}
	}
}

void EndScreenState::Update(float dt)
{
	if (!_draw)
	{
		if (_clock.getElapsedTime().asSeconds() > END_SCREEN_SURPRISE_APPEAR)
		{
			_surprise.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
	}
}

void EndScreenState::Draw()
{
	_data->_window.clear(sf::Color(223, 171, 88, 255));

	if (!_draw)
		_data->_window.draw(_surprise);

	_data->_window.draw(_Winbackground);

	if (!_draw)
		_data->_window.draw(_winnerMark);

	_data->_window.display();
}