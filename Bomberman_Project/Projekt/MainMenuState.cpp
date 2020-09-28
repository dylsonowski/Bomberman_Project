#include "MainMenuState.h"
#include "EndScreenState.h"
#include "GameState.h"

MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{
}

void MainMenuState::HInput()
{
	sf::Event _event;
	sf::Cursor _hand;
	sf::Cursor _default;

	while (_data->_window.pollEvent(_event))
	{
		
		if ((sf::Event::Closed == _event.type) || (_data->_input.SpriteClicked(_exit, sf::Mouse::Left, _data->_window)) || _data->_assets._closeWindow)
		{
			_data->_window.close();
		}

		if (_data->_input.SpriteClicked(_play, sf::Mouse::Left, _data->_window))
		{
			_data->_state.AddState(StateRef(new GameState(_data)));
		}

		if (_hand.loadFromSystem(sf::Cursor::Hand) && _default.loadFromSystem(sf::Cursor::Arrow))
		{
			if (_data->_input.isMouseUnder(_play, _data->_window))
			{
				_play.setColor(sf::Color::Red);
				_data->_window.setMouseCursor(_hand);
			}
			else
			{
				_play.setColor(sf::Color::White);
				_data->_window.setMouseCursor(_default);
			}

			if (_data->_input.isMouseUnder(_exit, _data->_window))
			{
				_exit.setColor(sf::Color::Red);
				_data->_window.setMouseCursor(_hand);
			}
			else
			{
				_exit.setColor(sf::Color::White);
			}
		}
		else {}
	}
}

void MainMenuState::Init()
{
	_data->_assets.LoadTexture("Menu Background", MENU_BACKGROUND_FILE);
	_data->_assets.LoadTexture("Menu Title", MENU_TITLE_FILE);
	_data->_assets.LoadTexture("Menu Play", MENU_PLAY_BUTTON_FILE);
	_data->_assets.LoadTexture("Menu Exit", MENU_EXIT_BUTTON_FILE);

	if (!_data->_assets._closeWindow)
	{
		_background.setTexture(_data->_assets.getTexture("Menu Background"));
		_background.setOrigin(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2);
		_background.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

		_title.setTexture(_data->_assets.getTexture("Menu Title"));
		_title.setOrigin(_title.getGlobalBounds().width / 2, _title.getGlobalBounds().height / 2);
		_title.setPosition(WINDOW_WIDTH / 2, _title.getGlobalBounds().height / 2);

		_play.setTexture(_data->_assets.getTexture("Menu Play"));
		_play.setPosition(WINDOW_WIDTH / 2 + WINDOW_WIDTH / 5, WINDOW_HEIGHT / 3);

		_exit.setTexture(_data->_assets.getTexture("Menu Exit"));
		_exit.setPosition(WINDOW_WIDTH / 2 + WINDOW_WIDTH / 5, (WINDOW_HEIGHT / 3) + _exit.getGlobalBounds().height + 10);
	}
}

void MainMenuState::Draw()
{
	_data->_window.clear();

	_data->_window.draw(_background);
	_data->_window.draw(_title);
	_data->_window.draw(_play);
	_data->_window.draw(_exit);

	_data->_window.display();
}