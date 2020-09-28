#pragma once
#include <SFML/Graphics.hpp>

//! Menad¿er myszy
/*! Klasa obs³uguj¹ca wszystkie zdarzenia zwiazane z mysz¹. */
class InputManager
{
	public:
		//! Konsturktor domyœlny.
		InputManager() = default;

		//! Destruktor domyœlny.
		~InputManager() = default;

		/*! 
			Metoda sprawdzajaca czy u¿ytkownik klikn¹³ w sprita.
			\param object obiekt klasy biblioteki SFML reprezentuj¹cy spritea dla którego sprawdzamy klikniêcie.
			\param button obiekt klasy biblioteki SFML reprezentuj¹cy klawisz myszy który nale¿y nacisn¹æ aby wykonaæ jak¹œ akcjê.
			\param window obiekt klasy "RenderWindow" który reprezentuje okno na którym rozpatrywane jest dane zdarzenie. Parametr musi byæ przekazany po przez referencje.
			\return "true" je¿eli sprite zosta³ klikniêty w przeciwnym razie "false".
		*/
		bool SpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);	

		/*!
			Metoda wykorzystywana tak¿e w funkcji "SpriteClicked" pozwalaj¹ca okreœlic czy u¿ytkownik najecha³ kursorem myszy na spritea.
			\param object obiekt klasy biblioteki SFML reprezentuj¹cy obrazek który jest sprawdzany.
			\param window obiekt klasy "RenderWindow" który reprezentuje okno na którym rozpatrywane jest dane zdarzenie. Parametr musi byæ przekazany po przez referencje.
			\return "true" je¿eli kursor myszy znajduje sie nad rozpatrywanym obiektem, "false" w przeciwnym wypadku.
		*/
		bool isMouseUnder(sf::Sprite object, sf::RenderWindow& window);	 

		/*!
			Metoda pozwalaj¹ca okreœlic po³ozenie kursora myszy.
			\param window obiekt klasy "RenderWindow" który reprezentuje okno na którym maj¹ byæ dokonywane obliczenia.
			\return Wektor liczb ca³kowitych przechowujacy kordynaty x oraz y pozycji kursora.
		*/
		sf::Vector2i MousePosition(sf::RenderWindow window);	
};

/*!
	\file InputManager.h
*/