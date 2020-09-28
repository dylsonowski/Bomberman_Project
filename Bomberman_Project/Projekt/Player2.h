#pragma once
#include <SFML/Graphics.hpp>
#include "PlayableCharacter.h"
#include "Animation.h"

/*! Klasa pochodna dziedzicz¹ca po klasie "PlayableCharacter" reprezentuj¹ca gracza 2. */
class Player2: public PlayableCharacter
{
	public:
		/*!
			Konstruktor klasy przypisujacy odpowiednie tekstury, pozycje obiektom, punkty odniesienia tych¿e obiektów oraz inne niezbêdne parametry takie jak limit postawionych bomb.
			\param data
		*/
		Player2(GameDataRef data);

		/*! Destruktor domyœlny. */
		~Player2() = default;

		void drawPlayer() override;
		void playerBumpOff(float speedX, float speedY) override;
		void playerMovment(float dt) override;
		void spowningBombs() override;
		void explodingBomb() override;
		void playerUpdate() override;
		void setPlayerStatus(bool status) override;
		void setIfPlayerDeath(bool death) override;
		void playerDeathAnimation() override;
		void bombPlacedUpdate() override;

		const sf::Sprite &getSprite() const override;
		const sf::Sprite &getBombSprite(unsigned short int iterator) const override;
		const sf::Sprite &getBombExplosionSprite(unsigned short int iterator) const override;
		unsigned short int getPlayerDirection() override;
		bool getBombsStatus(unsigned short int iterator) override;
		unsigned short int getBombCount() override;
		bool getPlayerStatus() override;
		bool canSwitchState() override;
		Bomb *getBomb(unsigned short int iterator)override;
};

/*!
	\file Player2.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/