#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "States.h"
#include "definitions.h"

//! Menu g³ówne
/*! Klasa pochodna dziedzicz¹ca z klasy "States". Obs³uguje ona dzia³anie menu g³ównego gry. */
class MainMenuState : public States
{
	public:
		/*!
			Konstruktor klasy przydzielajacy odpowiednie wartoœci atrybutów.
			\param data
		*/
		MainMenuState(GameDataRef data);

		//! Destruktor domyœlny.
		~MainMenuState() = default;

		/*! Metoda odziedziczona z klasy bazowej w przechwytywane s¹ wszystkie akcje gracza takie jak zamkniêcie okna aplikacji oraz zmiana kursora myszy w przypadku najechania na opcje w menu. */
		void HInput() override;
		void Update(float dt) override { }	//Nie potrzebne poniewa¿ nie wprowadzane s¹ ¿adne zmiany go "Game Logic"

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiektów na ekranie. */
		void Draw() override;

		/*! Metoda odziedziczona z klasy bazowej w której przypisywane s¹ odpowiednie tekstury, pozycje spriteów oraz ich punkty odniesienia. */
		void Init() override;

	private:
		GameDataRef _data;
		sf::Sprite _background;  /*!< Sprite reprezentuj¹cy t³o menu. */
		sf::Sprite _title;  /*!< Sprite reprezentuj¹cy tytu³ gry. */
		sf::Sprite _play;  /*!< Sprite reprezentuj¹cy guzik "Play". */
		sf::Sprite _exit;  /*!< Sprite reprezentuj¹cy guzik "Exit". */
};

/*!
	\file MainMenuState.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/