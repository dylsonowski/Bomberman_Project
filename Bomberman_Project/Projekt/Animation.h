#pragma once
#include <SFML/Graphics.hpp>
#include "definitions.h"

//! Klasa animacji
/* Klasa odpowiedzialna za odgrywanie animacji poszczególnych obiektów */
class Animation
{
	public:
		/*!
			Konstruktor klasy dokonuj¹cy podstawowych obliczeñ niezbêdnych do poprawnego dzia³ania animacji. W konstruktorze nastêpuje podzielenie otrzymanej tekstury na klatki animacji.
			\param texture wskaŸnik na teksturê w której zawarte s¹ wszystkie klatki odtwarzanej animacji. 
			\param framCount wektor liczb ca³kowitych bez znaku przechowujacy iloœæ klatek w teksturze. Ile jest ich w jednym rzêdzie oraz jednej kolumnie.
			\param totalTime liczba zmiennoprzecinkowa okreœlajaca d³ugosæ animacji.
		*/
		Animation(sf::Texture * texture, sf::Vector2u frameCount, float totalTime);

		//! Konstruktor domyœlny.
		~Animation() = default;

		/*!
			Metoda wykonuj¹ca ca³¹ animacjê na podstawie przekazanego w argumentach kunktu startowego.
			\param row numer rzêdu tekstury od którego ma rozpocz¹æ sie animacja.
			\param column numer kolumny tekstury od którego ma rozpocz¹æ sie animacja.
		*/
		void animationUpdate(unsigned int row, unsigned int column);

		sf::IntRect _animateingObject;	/*!< Obiekt klasy biblioteki SFML który reprezentuje prostok¹t o zadanych wymiarach. Ta wersja posiada wspó³rzêdne i wymiary ca³kowite. */

	private:
		sf::Vector2u _frameCount;	/*!< Wektor liczb ca³kowitych bez znaku przechowujacy liczbe klatek animacji. Atrybut ten jest przekazany w konstruktorze po przez liste inicjalizacyjn¹. */
		sf::Vector2u _currentFrame;	 /*!< Wektor liczb ca³kowitych bez znaku przechowujacy kordynaty obecnie wyœwietlanej klatki. */
		float _totalAnimationTime;	/*!< Atrybut przechowujacy ca³kowity czas animacji. */
		sf::Clock _clock;	/*!< Obiekt klasy biblioteki SFML tworz¹cy zegar. */
};

/*!
	\file Animation.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/