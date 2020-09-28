#include "Game.h"
#include "MainMenuState.h"

Game::Game(const int width, const int height, std::string title)
{
	_data->_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar); 
	_data->_state.AddState(StateRef(new MainMenuState(_data)));
}

void Game::Run()
{
	_data->_window.setFramerateLimit(60);

	while (_data->_window.isOpen())
	{
		_data->_state.StateChange();				
		_data->_state.ActiveState()->HInput();		
		_data->_state.ActiveState()->Update(dt);	
		_data->_state.ActiveState()->Draw();
	}
}