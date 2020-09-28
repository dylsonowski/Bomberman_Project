#pragma once
#include <SFML/Graphics.hpp>
#include "PlayableCharacter.h"
#include "Animation.h"

/*! Klasa pochodna dziedzicz�ca po klasie "PlayableCharacter" reprezentuj�ca gracza 1. */
class Player1: public PlayableCharacter
{
	public:
		/*!
			Konstruktor klasy przypisujacy odpowiednie tekstury, pozycje obiektom, punkty odniesienia tych�e obiekt�w oraz inne niezb�dne parametry takie jak limit postawionych bomb.
			\param data
		*/
		Player1(GameDataRef data);

		/*! Destruktor domy�lny. */
		~Player1() = default;

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
	\file Player1.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/