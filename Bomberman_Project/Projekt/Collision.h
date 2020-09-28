#pragma once
#include <SFML/Graphics.hpp>

//! Klasa typu menad¿er okreœlajaca czy zasz³a kolizja miedzy obiektami.
class Collision
{
	public:
		//! Konstruktor domyœlny.
		Collision() = default;

		//! Destruktor domyœlny.
		~Collision() = default;

		/*!
			Metoda sprawdzajaca zajœcie kolizji. 
			\param object1 sprite pierwszego obiektu którego kolizja jest sprawdzana.
			\param object2 sprite drugiego obiektu którego kolizja jest sprawdzana.
			\return wartosc "true" jeœli kolizja wyst¹pi w przeciwnym razie wartosæ "false".
		*/
		bool checkCollision(sf::Sprite object1, sf::Sprite object2);

		/*!
			Metoda sprawdzajaca zajœcie kolizji miedzy obiektami. Ulepszona wersja metody "check Collision" umo¿liwiajaca modernizacjê prostok¹ta sprawdzaj¹cego kolizjê. 
			\param object1 sprite pierwszego obiektu którego kolizja jest sprawdzana.
			\param object2 sprite drugiego obiektu którego kolizja jest sprawdzana.
			\param scale1X wartoœæ o jak¹ przeskalowaæ obiekt pierwszy w osi x.
			\param scale1Y wartoœæ o jak¹ przeskalowaæ obiekt pierwszy w osi y.
			\param scale2X wartoœæ o jak¹ przeskalowaæ obiekt drugi w osi x.
			\param scale2Y wartoœæ o jak¹ przeskalowaæ obiekt drugi w osi y.
			\return wartosc "true" jeœli kolizja wyst¹pi w przeciwnym razie wartosæ "false".
		*/
		bool checkCollisionBetter(sf::Sprite object1, sf::Sprite object2, float scale1X, float scale1Y, float scale2X, float scale2Y);
};

/*!
	\file Collision.h
*/