#pragma once
#include <SFML/Graphics.hpp>

//! Menad�er myszy
/*! Klasa obs�uguj�ca wszystkie zdarzenia zwiazane z mysz�. */
class InputManager
{
	public:
		//! Konsturktor domy�lny.
		InputManager() = default;

		//! Destruktor domy�lny.
		~InputManager() = default;

		/*! 
			Metoda sprawdzajaca czy u�ytkownik klikn�� w sprita.
			\param object obiekt klasy biblioteki SFML reprezentuj�cy spritea dla kt�rego sprawdzamy klikni�cie.
			\param button obiekt klasy biblioteki SFML reprezentuj�cy klawisz myszy kt�ry nale�y nacisn�� aby wykona� jak�� akcj�.
			\param window obiekt klasy "RenderWindow" kt�ry reprezentuje okno na kt�rym rozpatrywane jest dane zdarzenie. Parametr musi by� przekazany po przez referencje.
			\return "true" je�eli sprite zosta� klikni�ty w przeciwnym razie "false".
		*/
		bool SpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);	

		/*!
			Metoda wykorzystywana tak�e w funkcji "SpriteClicked" pozwalaj�ca okre�lic czy u�ytkownik najecha� kursorem myszy na spritea.
			\param object obiekt klasy biblioteki SFML reprezentuj�cy obrazek kt�ry jest sprawdzany.
			\param window obiekt klasy "RenderWindow" kt�ry reprezentuje okno na kt�rym rozpatrywane jest dane zdarzenie. Parametr musi by� przekazany po przez referencje.
			\return "true" je�eli kursor myszy znajduje sie nad rozpatrywanym obiektem, "false" w przeciwnym wypadku.
		*/
		bool isMouseUnder(sf::Sprite object, sf::RenderWindow& window);	 

		/*!
			Metoda pozwalaj�ca okre�lic po�ozenie kursora myszy.
			\param window obiekt klasy "RenderWindow" kt�ry reprezentuje okno na kt�rym maj� by� dokonywane obliczenia.
			\return Wektor liczb ca�kowitych przechowujacy kordynaty x oraz y pozycji kursora.
		*/
		sf::Vector2i MousePosition(sf::RenderWindow window);	
};

/*!
	\file InputManager.h
*/