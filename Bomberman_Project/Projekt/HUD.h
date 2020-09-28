#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "definitions.h"

//! Interfejs u�ytkownika.
/*! Klasa zawierajaca oraz wy�wietlaj�ca informacje niezb�dne dla graczy takie jak �ycia obu graczy oraz czas do konca rozgrywki. */
class HUD
{
	public:
		/*!
			Konstruktor klasy przypisuj�cy odpowiednie tekstury do sprit�w, ustawiaj�cy pozycje obiekt�w oraz ich punkt odniesienia. Jest on odpowiedzialny tak�e za ustawienie parametr�w tekstu
			zawierajacego pozosta�y czas.
			\param data
		*/
		HUD(GameDataRef data);

		/*! Destruktor zwalniaj�cy pamie� zaj�t� przez tablice kt�re zawieraja spritey �y� graczy.*/
		~HUD();

		/*! Metoda odpowiedzialna za wyrysowanie obiekt�w na ekranie. */
		void Draw();

		/*! Metoda odpowiedzialna za zmnieszanie pozosta�ego czasu rozgrywki wraz z up�ywem czasu. */
		void countdownTimerUpdate();

		/*!
			Metoda typu "Setter" pozwalajaca na zmian� wartosci prywatnego atrybutu klasy. W tym przypadku jest to zmniejszenie liczby �y� gracza przy trafieniu.
			\param p1Hit wskazuje czy trafienie nastapi�o w gracza 1.
			\param p2Hit wskazuje czy trafienie nastapi�o w gracza 2.
		*/
		void updateLifes(bool p1Hit, bool p2Hit);


		/*!
			Metoda typu "Getter" zezwalajaca na podejrzenie wartosci prywatnego atrybutu.
			\param numer gracza kt�rego liczbe �y� trzeba podejrzec.
			\return liczba �y� danego gracza.
		*/
		unsigned short int getNumberOfLifes(unsigned short int _playerID);

		/*!
			Metoda typu "Getter" zezwalajaca na podejrzenie wartosci prywatnego atrybutu.
			\return pozosta�y czas rozgrywki (w sekundach).
		*/
		int getTimeLeft();

	private:
		GameDataRef _data;
		sf::Sprite _p1Lifes[PLAYER_NUMBER_OF_LIFES];  /*!< Tablica jednowymiarowa przechowujaca spritey �y� gracza 1. */
		sf::Sprite _p2Lifes[PLAYER_NUMBER_OF_LIFES];  /*!< Tablica jednowymiarowa przechowujaca spritey �y� gracza 2. */
		unsigned short int _p1LifesNumber;  /*!< Liczba �yc pozosta�ych graczowi 1. */
		unsigned short int _p2LifesNumber;  /*!< Liczba �yc pozosta�ych graczowi 1. */
		sf::Text _timer;  /*!< Czas na rozgrywk�. */
		sf::Clock _countingDownClock;  /*!< Zegar s�u��cy do odmierzania czasu do ko�ca rozgrywki. */
		sf::Time _seconds;  /*!< Ilos� czasu jaka up�yn�a. */
		int _timeLeft;  /*!< Warto�� czasu jaka pozosta�a do konca rozgrywki (w sekundach). */
};

/*!
	\file HUD.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/