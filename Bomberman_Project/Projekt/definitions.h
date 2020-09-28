#pragma once

//Screen
#define WINDOW_WIDTH 1178
#define WINDOW_HEIGHT 760

//Main Menu
#define MENU_BACKGROUND_FILE "Resources/Menu/Main_Menu.jpg"
#define MENU_TITLE_FILE "Resources/Menu/Menu_title.png"
#define MENU_PLAY_BUTTON_FILE "Resources/Menu/Menu_play.png"
#define MENU_EXIT_BUTTON_FILE "Resources/Menu/Menu_exit.png"

//End Game
#define END_SCREEN_SURPRISE_APPEAR 10.0f
#define VICTORY_SCREEN_BACKGROUND "Resources/End/Viktory_screen_3.png"
#define GAME_OVER_SCREEN_BACKGROUND "Resources/End/Game_over_screen.png"
#define END_SCREEN_SURPRISE "Resources/End/surprise.png"
#define BOMBERMAN_FONT "Resources/Fonts/3Dventure.ttf"

//HUD
#define PLAYER_NUMBER_OF_LIFES 3
#define PLAYTIME 600
#define PLAYER_LIFE_SPRITE "Resources/Board/HUD/Plate_life.png"
#define PLAYER2_LIFE_SPRITE "Resources/Board/HUD/Plate_life2.png"

//Animations
#define PLAYER1_ANIMATION_FRAMES "Resources/Player/Player1_movment_frames.png"
#define PLAYER2_ANIMATION_FRAMES "Resources/Player/Player2_movment_frames.png"
#define PLAYERS_ANIMATION_DURATION 0.4f
#define BOMB_ANIMATION_FRAMES "Resources/Player/Bombs/Bombs_frames.png"
#define EXPLOSION_ANIMATION_FRAMES "Resources/Player/Bombs/Explosion_frames.png"
#define BOMBS_ANIMATION_DURATION 0.8f
#define BOMB_EXPLOSION_ANIMATION_DURATION 0.3f
#define PLAYER1_DEATH_ANIMATION_FRAMES "Resources/Player/Player1_death_frames.png"
#define PLAYER2_DEATH_ANIMATION_FRAMES "Resources/Player/Player2_death_frames.png"
#define DEATH_ANIMATION_DURATION 1.5f

//Game State
#define GAME_STATE_PLATE "Resources/Board/Plate.png"
#define WALL_BLOCK_SPRITE "Resources/Board/Wall_block.png"
#define BRICK_BLOCK_SPRITE "Resources/Board/Brick_block.png"
#define ONE_BLOCK_WIDTH 38
#define ONE_BLOCK_HEIGHT 38
#define SWITCHING_STATE_TIMER 1.5f
enum GameStates
{
	_plaeying,
	_gameOver
};

//Players
#define PLAYER1_PLACMENT_X 57
#define PLAYER1_PLACMENT_Y 702
#define PLAYER2_PLACMENT_X 1120
#define PLAYER2_PLACMENT_Y 170
#define PLAYER1_BOMB_LIMIT 2
#define PLAYER2_BOMB_LIMIT 2
#define PLAYERS_SPEED 250.0f
#define PLAYER_SPRITE_SCALE 1.7f
#define PLAYERS_BUMPOF_SPEED 4.17f

//Bombs
#define BOMB_SPRITE_SCALE 2.0f
#define BOMB_COOLDOWN 0.3f
#define BOMB_TIMER 1.5f
#define BOMB_DESTRUCT_TIMER 1.8f
#define BOMB_EXPLOSION_SPRITE_SCALE 2.375f