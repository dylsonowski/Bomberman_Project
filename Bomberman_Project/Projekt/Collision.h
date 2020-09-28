#pragma once
#include <SFML/Graphics.hpp>

//! Klasa typu menad�er okre�lajaca czy zasz�a kolizja miedzy obiektami.
class Collision
{
	public:
		//! Konstruktor domy�lny.
		Collision() = default;

		//! Destruktor domy�lny.
		~Collision() = default;

		/*!
			Metoda sprawdzajaca zaj�cie kolizji. 
			\param object1 sprite pierwszego obiektu kt�rego kolizja jest sprawdzana.
			\param object2 sprite drugiego obiektu kt�rego kolizja jest sprawdzana.
			\return wartosc "true" je�li kolizja wyst�pi w przeciwnym razie wartos� "false".
		*/
		bool checkCollision(sf::Sprite object1, sf::Sprite object2);

		/*!
			Metoda sprawdzajaca zaj�cie kolizji miedzy obiektami. Ulepszona wersja metody "check Collision" umo�liwiajaca modernizacj� prostok�ta sprawdzaj�cego kolizj�. 
			\param object1 sprite pierwszego obiektu kt�rego kolizja jest sprawdzana.
			\param object2 sprite drugiego obiektu kt�rego kolizja jest sprawdzana.
			\param scale1X warto�� o jak� przeskalowa� obiekt pierwszy w osi x.
			\param scale1Y warto�� o jak� przeskalowa� obiekt pierwszy w osi y.
			\param scale2X warto�� o jak� przeskalowa� obiekt drugi w osi x.
			\param scale2Y warto�� o jak� przeskalowa� obiekt drugi w osi y.
			\return wartosc "true" je�li kolizja wyst�pi w przeciwnym razie wartos� "false".
		*/
		bool checkCollisionBetter(sf::Sprite object1, sf::Sprite object2, float scale1X, float scale1Y, float scale2X, float scale2Y);
};

/*!
	\file Collision.h
*/