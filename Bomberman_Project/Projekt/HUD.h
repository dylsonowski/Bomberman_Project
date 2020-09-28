#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "definitions.h"

//! Interfejs u¿ytkownika.
/*! Klasa zawierajaca oraz wyœwietlaj¹ca informacje niezbêdne dla graczy takie jak ¿ycia obu graczy oraz czas do konca rozgrywki. */
class HUD
{
	public:
		/*!
			Konstruktor klasy przypisuj¹cy odpowiednie tekstury do spritów, ustawiaj¹cy pozycje obiektów oraz ich punkt odniesienia. Jest on odpowiedzialny tak¿e za ustawienie parametrów tekstu
			zawierajacego pozosta³y czas.
			\param data
		*/
		HUD(GameDataRef data);

		/*! Destruktor zwalniaj¹cy pamieæ zajêt¹ przez tablice które zawieraja spritey ¿yæ graczy.*/
		~HUD();

		/*! Metoda odpowiedzialna za wyrysowanie obiektów na ekranie. */
		void Draw();

		/*! Metoda odpowiedzialna za zmnieszanie pozosta³ego czasu rozgrywki wraz z up³ywem czasu. */
		void countdownTimerUpdate();

		/*!
			Metoda typu "Setter" pozwalajaca na zmianê wartosci prywatnego atrybutu klasy. W tym przypadku jest to zmniejszenie liczby ¿yæ gracza przy trafieniu.
			\param p1Hit wskazuje czy trafienie nastapi³o w gracza 1.
			\param p2Hit wskazuje czy trafienie nastapi³o w gracza 2.
		*/
		void updateLifes(bool p1Hit, bool p2Hit);


		/*!
			Metoda typu "Getter" zezwalajaca na podejrzenie wartosci prywatnego atrybutu.
			\param numer gracza którego liczbe ¿yæ trzeba podejrzec.
			\return liczba ¿yæ danego gracza.
		*/
		unsigned short int getNumberOfLifes(unsigned short int _playerID);

		/*!
			Metoda typu "Getter" zezwalajaca na podejrzenie wartosci prywatnego atrybutu.
			\return pozosta³y czas rozgrywki (w sekundach).
		*/
		int getTimeLeft();

	private:
		GameDataRef _data;
		sf::Sprite _p1Lifes[PLAYER_NUMBER_OF_LIFES];  /*!< Tablica jednowymiarowa przechowujaca spritey ¿yæ gracza 1. */
		sf::Sprite _p2Lifes[PLAYER_NUMBER_OF_LIFES];  /*!< Tablica jednowymiarowa przechowujaca spritey ¿yæ gracza 2. */
		unsigned short int _p1LifesNumber;  /*!< Liczba ¿yc pozosta³ych graczowi 1. */
		unsigned short int _p2LifesNumber;  /*!< Liczba ¿yc pozosta³ych graczowi 1. */
		sf::Text _timer;  /*!< Czas na rozgrywkê. */
		sf::Clock _countingDownClock;  /*!< Zegar s³u¿¹cy do odmierzania czasu do koñca rozgrywki. */
		sf::Time _seconds;  /*!< Ilosæ czasu jaka up³ynê³a. */
		int _timeLeft;  /*!< Wartoœæ czasu jaka pozosta³a do konca rozgrywki (w sekundach). */
};

/*!
	\file HUD.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/