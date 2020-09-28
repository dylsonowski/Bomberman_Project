#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "States.h"
#include "definitions.h"

//! Menu g��wne
/*! Klasa pochodna dziedzicz�ca z klasy "States". Obs�uguje ona dzia�anie menu g��wnego gry. */
class MainMenuState : public States
{
	public:
		/*!
			Konstruktor klasy przydzielajacy odpowiednie warto�ci atrybut�w.
			\param data
		*/
		MainMenuState(GameDataRef data);

		//! Destruktor domy�lny.
		~MainMenuState() = default;

		/*! Metoda odziedziczona z klasy bazowej w przechwytywane s� wszystkie akcje gracza takie jak zamkni�cie okna aplikacji oraz zmiana kursora myszy w przypadku najechania na opcje w menu. */
		void HInput() override;
		void Update(float dt) override { }	//Nie potrzebne poniewa� nie wprowadzane s� �adne zmiany go "Game Logic"

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiekt�w na ekranie. */
		void Draw() override;

		/*! Metoda odziedziczona z klasy bazowej w kt�rej przypisywane s� odpowiednie tekstury, pozycje sprite�w oraz ich punkty odniesienia. */
		void Init() override;

	private:
		GameDataRef _data;
		sf::Sprite _background;  /*!< Sprite reprezentuj�cy t�o menu. */
		sf::Sprite _title;  /*!< Sprite reprezentuj�cy tytu� gry. */
		sf::Sprite _play;  /*!< Sprite reprezentuj�cy guzik "Play". */
		sf::Sprite _exit;  /*!< Sprite reprezentuj�cy guzik "Exit". */
};

/*!
	\file MainMenuState.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/