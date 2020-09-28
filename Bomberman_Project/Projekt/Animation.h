#pragma once
#include <SFML/Graphics.hpp>
#include "definitions.h"

//! Klasa animacji
/* Klasa odpowiedzialna za odgrywanie animacji poszczeg�lnych obiekt�w */
class Animation
{
	public:
		/*!
			Konstruktor klasy dokonuj�cy podstawowych oblicze� niezb�dnych do poprawnego dzia�ania animacji. W konstruktorze nast�puje podzielenie otrzymanej tekstury na klatki animacji.
			\param texture wska�nik na tekstur� w kt�rej zawarte s� wszystkie klatki odtwarzanej animacji. 
			\param framCount wektor liczb ca�kowitych bez znaku przechowujacy ilo�� klatek w teksturze. Ile jest ich w jednym rz�dzie oraz jednej kolumnie.
			\param totalTime liczba zmiennoprzecinkowa okre�lajaca d�ugos� animacji.
		*/
		Animation(sf::Texture * texture, sf::Vector2u frameCount, float totalTime);

		//! Konstruktor domy�lny.
		~Animation() = default;

		/*!
			Metoda wykonuj�ca ca�� animacj� na podstawie przekazanego w argumentach kunktu startowego.
			\param row numer rz�du tekstury od kt�rego ma rozpocz�� sie animacja.
			\param column numer kolumny tekstury od kt�rego ma rozpocz�� sie animacja.
		*/
		void animationUpdate(unsigned int row, unsigned int column);

		sf::IntRect _animateingObject;	/*!< Obiekt klasy biblioteki SFML kt�ry reprezentuje prostok�t o zadanych wymiarach. Ta wersja posiada wsp�rz�dne i wymiary ca�kowite. */

	private:
		sf::Vector2u _frameCount;	/*!< Wektor liczb ca�kowitych bez znaku przechowujacy liczbe klatek animacji. Atrybut ten jest przekazany w konstruktorze po przez liste inicjalizacyjn�. */
		sf::Vector2u _currentFrame;	 /*!< Wektor liczb ca�kowitych bez znaku przechowujacy kordynaty obecnie wy�wietlanej klatki. */
		float _totalAnimationTime;	/*!< Atrybut przechowujacy ca�kowity czas animacji. */
		sf::Clock _clock;	/*!< Obiekt klasy biblioteki SFML tworz�cy zegar. */
};

/*!
	\file Animation.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/