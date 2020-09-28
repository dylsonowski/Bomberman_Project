#include "GameState.h"
#include "WallBlock.h"
#include "BrickBlock.h"
#include "EndScreenState.h"
#include <time.h>

GameState::GameState(GameDataRef data) : _data(data)
{
	_gameState = GameStates::_plaeying;
}

GameState::~GameState()
{
	delete _hud;
	delete _player1;
	delete _player2;

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			delete _blocks[i][j];
		}
	}
}

void GameState::Init()
{
	srand(time(NULL));
	_data->_assets.LoadTexture("Plate", GAME_STATE_PLATE);
	_data->_assets.LoadTexture("Life", PLAYER_LIFE_SPRITE);
	_data->_assets.LoadTexture("Life Player 2", PLAYER2_LIFE_SPRITE);
	_data->_assets.LoadFont("Bomberman Font", BOMBERMAN_FONT);
	_data->_assets.LoadTexture("Wall Block", WALL_BLOCK_SPRITE);
	_data->_assets.LoadTexture("Brick Block", BRICK_BLOCK_SPRITE);
	_data->_assets.LoadTexture("Player1 Frames", PLAYER1_ANIMATION_FRAMES);
	_data->_assets.LoadTexture("Player2 Frames", PLAYER2_ANIMATION_FRAMES);
	_data->_assets.LoadTexture("Bomb Frames", BOMB_ANIMATION_FRAMES);
	_data->_assets.LoadTexture("Explosion Frames", EXPLOSION_ANIMATION_FRAMES);
	_data->_assets.LoadTexture("Player1 Death Frames", PLAYER1_DEATH_ANIMATION_FRAMES);
	_data->_assets.LoadTexture("Player2 Death Frames", PLAYER2_DEATH_ANIMATION_FRAMES);

	if (!_data->_assets._closeWindow)
	{
		_plate.setTexture(_data->_assets.getTexture("Plate"));
		_plate.setOrigin(_plate.getGlobalBounds().width / 2, _plate.getGlobalBounds().height / 2);
		_plate.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

		_hud = new HUD(_data);
		_player1 = new Player1(_data);
		_player2 = new Player2(_data);

		sf::Vector2u _tempSpriteSize = _data->_assets.getTexture("Wall Block").getSize();
		for (int i = 0; i < 31; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				int _randXValue = rand() % 31;
				int _randYValue = rand() % 17;

				if (j == 0 || j == 16 || i == 0 || i == 30 || (j % 2 == 0 && i % 2 == 0))
				{
					_blocks[i][j] = new WallBlock(_data, 0 + _tempSpriteSize.x * i, (_tempSpriteSize.y * 3) + _tempSpriteSize.y * j);
				}
				else if ((j == 1 && i == 29) || (j == 1 && i == 28) || (j == 2 && i == 29) || (j == 14 && i == 1) || (j == 15 && i == 1) || (j == 15 && i == 2))
				{
					continue;
				}
				else if ((j >= _randYValue && j <= _randXValue) || (i >= _randYValue && i <= _randXValue))
				{
					_blocks[i][j] = new BrickBlock(_data, 0 + _tempSpriteSize.x * i, (_tempSpriteSize.y * 3) + _tempSpriteSize.y * j);
				}
			}
		}
	}
}

void GameState::HInput()
{
	sf::Event _event;

	while (_data->_window.pollEvent(_event))
	{
		if (sf::Event::Closed == _event.type || _data->_assets._closeWindow)
		{
			_data->_window.close();
		}
	}
}

void GameState::Update(float dt)
{
	if (!_data->_assets._closeWindow)
		_hud->countdownTimerUpdate();

	if (GameStates::_plaeying == _gameState && !_data->_assets._closeWindow)
	{
		_player1->playerMovment(dt);
		_player1->spowningBombs();
		_player1->playerUpdate();

		_player2->playerMovment(dt);
		_player2->spowningBombs();
		_player2->playerUpdate();
	}

	if (!_data->_assets._closeWindow)
	{
		_player1->bombPlacedUpdate();
		_player1->explodingBomb();

		_player2->bombPlacedUpdate();
		_player2->explodingBomb();


		if (_hud->getNumberOfLifes(1) == 0)
		{
			_gameState = GameStates::_gameOver;
			_player1->setIfPlayerDeath(true);
			_player1->playerDeathAnimation();
		}

		if (_hud->getNumberOfLifes(2) == 0)
		{
			_gameState = GameStates::_gameOver;
			_player2->setIfPlayerDeath(true);
			_player2->playerDeathAnimation();
		}


		if (_player2->canSwitchState() || (_hud->getTimeLeft() == 0 && _hud->getNumberOfLifes(1) > _hud->getNumberOfLifes(2)))
		{
			_data->_state.AddState(StateRef(new EndScreenState(_data, true, false)));
		}
		else if (_player1->canSwitchState() || (_hud->getTimeLeft() == 0 && _hud->getNumberOfLifes(1) < _hud->getNumberOfLifes(2)))
		{
			_data->_state.AddState(StateRef(new EndScreenState(_data, false, false)));
		}
		else if (_hud->getTimeLeft() == 0 && _hud->getNumberOfLifes(1) == _hud->getNumberOfLifes(2))
		{
			_data->_state.AddState(StateRef(new EndScreenState(_data, false, true)));
		}

		if (_player1->_itsMine && !collision.checkCollision(_player1->getSprite(), _player1->_itsMine->getSprite()))
			_player1->_itsMine = nullptr;

		if (_player2->_itsMine && !collision.checkCollision(_player2->getSprite(), _player2->_itsMine->getSprite()))
			_player2->_itsMine = nullptr;

		for (int i = 0; i < 31; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (_blocks[i][j] != nullptr)
				{
					if (collision.checkCollisionBetter(_player1->getSprite(), _blocks[i][j]->getSprite(), 1, 1, 0.95f, 0.95f))
					{
						if (_player1->getPlayerDirection() == 1)
							_player1->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 2)
							_player1->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 3)
							_player1->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player1->getPlayerDirection() == 4)
							_player1->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}

					if (collision.checkCollisionBetter(_player2->getSprite(), _blocks[i][j]->getSprite(), 1, 1, 0.95f, 0.95f))
					{
						if (_player2->getPlayerDirection() == 1)
							_player2->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 2)
							_player2->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 3)
							_player2->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player2->getPlayerDirection() == 4)
							_player2->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}
				}

				for (int k = 0; k < _player1->getBombCount(); k++)
				{
					if (_player1->getBombsStatus(k))
					{
						if (_blocks[i][j] != nullptr)
						{
							if ((collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _blocks[i][j]->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _blocks[i][j]->getSprite(), 1, 0.053f, 1, 1)) && _blocks[i][j]->getBlockState())
							{
								delete _blocks[i][j];
								_blocks[i][j] = nullptr;
							}
						}

						if (GameStates::_plaeying == _gameState)
						{
							if ((collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _player1->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _player1->getSprite(), 1, 0.053f, 1, 1)) && !_player1->getPlayerStatus())
							{
								_player1->setPlayerStatus(true);
								_hud->updateLifes(true, false);
							}
							else if ((collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _player2->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player1->getBombExplosionSprite(k), _player2->getSprite(), 1, 0.053f, 1, 1)) && !_player2->getPlayerStatus())
							{
								_player2->setPlayerStatus(true);
								_hud->updateLifes(false, true);
							}
						}
					}

					if (_player1->_itsMine != _player1->getBomb(k) && collision.checkCollision(_player1->getSprite(), _player1->getBombSprite(k)))
					{
						if (_player1->getPlayerDirection() == 1)
							_player1->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 2)
							_player1->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 3)
							_player1->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player1->getPlayerDirection() == 4)
							_player1->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}

					if (collision.checkCollision(_player2->getSprite(), _player1->getBombSprite(k)))
					{
						if (_player2->getPlayerDirection() == 1)
							_player2->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 2)
							_player2->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 3)
							_player2->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player2->getPlayerDirection() == 4)
							_player2->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}
				}

				for (int k = 0; k < _player2->getBombCount(); k++)
				{
					if (_player2->getBombsStatus(k))
					{
						if (_blocks[i][j] != nullptr)
						{
							if ((collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _blocks[i][j]->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _blocks[i][j]->getSprite(), 1, 0.053f, 1, 1)) && _blocks[i][j]->getBlockState())
							{
								delete _blocks[i][j];
								_blocks[i][j] = nullptr;
							}
						}

						if (GameStates::_plaeying == _gameState)
						{
							if ((collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _player2->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _player2->getSprite(), 1, 0.053f, 1, 1)) && !_player2->getPlayerStatus())
							{
								_player2->setPlayerStatus(true);
								_hud->updateLifes(false, true);
							}
							else if ((collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _player1->getSprite(), 0.053f, 1, 1, 1) ||
								collision.checkCollisionBetter(_player2->getBombExplosionSprite(k), _player1->getSprite(), 1, 0.053f, 1, 1)) && !_player1->getPlayerStatus())
							{
								_player1->setPlayerStatus(true);
								_hud->updateLifes(true, false);
							}
						}
					}

					if (_player2->_itsMine != _player2->getBomb(k) && collision.checkCollision(_player2->getSprite(), _player2->getBombSprite(k)))
					{
						if (_player2->getPlayerDirection() == 1)
							_player2->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 2)
							_player2->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player2->getPlayerDirection() == 3)
							_player2->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player2->getPlayerDirection() == 4)
							_player2->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}

					if (collision.checkCollision(_player1->getSprite(), _player2->getBombSprite(k)))
					{
						if (_player1->getPlayerDirection() == 1)
							_player1->playerBumpOff(0, PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 2)
							_player1->playerBumpOff(0, -PLAYERS_BUMPOF_SPEED);
						else if (_player1->getPlayerDirection() == 3)
							_player1->playerBumpOff(-PLAYERS_BUMPOF_SPEED, 0);
						else if (_player1->getPlayerDirection() == 4)
							_player1->playerBumpOff(PLAYERS_BUMPOF_SPEED, 0);
						else
						{
						}
					}
				}
			}
		}
	}
}

void GameState::Draw()
{
	_data->_window.clear();

	if (!_data->_assets._closeWindow)
	{
		_data->_window.draw(_plate);
		_hud->Draw();

		for (int i = 0; i < 31; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (_blocks[i][j] != nullptr)
					_blocks[i][j]->drawBlocks();
			}
		}

		_player1->drawPlayer();
		_player2->drawPlayer();
	}

	_data->_window.display();
}