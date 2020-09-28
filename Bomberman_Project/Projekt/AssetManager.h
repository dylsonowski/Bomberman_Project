#pragma once
#include <map>
#include <SFML/Graphics.hpp>

//! Menad¿er zasobów
/*!
	Klasa pozwalajaca na zarz¹dzanie potrzebnymi teksturami lub czcionkami. Posiada w sobie tak¿e walidacje danych aby w przypadku b³êdu przy za³adowaniu zasobów mo¿na by³o zamknac aplikacje
	bez zatrzymania programu przez system operacyjny.
*/
class AssetManager
{
	public:
		//! Konsruktor domyœlny.
		AssetManager() = default;

		//! Destruktor domyœlny.
		~AssetManager() = default;

		/*!
			Metoda pozwalajaca na za³adowanie odpowiednich tekstur. U¿ywana jest przy inicjalizacji ka¿dego ze stanów gry. We wnêtrzu funkcji odbywa sie procedura walidacji danych która
			w razie potrzeby prze³¹cza flagê "_closeWindow" na true.
			\param name jest to nazwa tekstury która u¿ywana jest do poprawnego umieszczenia zasobu w kontenerze.
			\param file_name nazwa pliku z którego dana tekstura ma zostaæ odczytana.
		*/
		void LoadTexture(std::string name, std::string file_name);	

		/*!
			Metoda wyszukuj¹ca w kontenerze teksturê.
			\param name nazwa zasobu po której kontener bêdzie przeszukiwany.
			\return Referencje do wyszukanego zasobu je¿eli zostanie on odnaleziony. W przeciwnym razie zwraca iterator end().
		*/
		sf::Texture& getTexture(std::string name);	

		/*!
			Metoda pozwalajaca na za³adowanie odpowiednich czcionek. U¿ywana jest przy inicjalizacji ka¿dego ze stanów gry. We wnêtrzu funkcji odbywa sie procedura walidacji danych która
			w razie potrzeby prze³¹cza flagê "_closeWindow" na true.
			\param name jest to nazwa czcionki która u¿ywana jest do poprawnego umieszczenia zasobu w kontenerze.
			\param file_name nazwa pliku z którego dana czcionka ma zostaæ odczytana.
		*/
		void LoadFont(std::string name, std::string file_name);	

		/*!
			Metoda wyszukuj¹ca w kontenerze czcionkê.
			\param name nazwa zasobu po której kontener bêdzie przeszukiwany.
			\return Referencje do wyszukanego zasobu je¿eli zostanie on odnaleziony. W przeciwnym razie zwraca iterator end().
		*/
		sf::Font& getFont(std::string name);	

		bool _closeWindow = false;	/*< Publiczna flaga boolowa pozwalaj¹ca na zamkniêcie aplikacji w przypadku wyst¹pienia b³êdu podczas ³adowania zasobów. */

	private:
		std::map<std::string, sf::Texture> _texture;  /*< Kontener STL typu mapa pozwalajacy na przechowywanie za³adowanych tekstur. Konteer funkcjonuje na zasadzie drzewa BST */
		std::map<std::string, sf::Font> _font;	/*< Kontener STL typu mapa pozwalajacy na przechowywanie za³adowanych czcionek. Konteer funkcjonuje na zasadzie drzewa BST */
};

/*!
	\file AssetManager.h
*/