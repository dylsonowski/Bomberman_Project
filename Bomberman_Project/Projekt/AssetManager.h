#pragma once
#include <map>
#include <SFML/Graphics.hpp>

//! Menad�er zasob�w
/*!
	Klasa pozwalajaca na zarz�dzanie potrzebnymi teksturami lub czcionkami. Posiada w sobie tak�e walidacje danych aby w przypadku b��du przy za�adowaniu zasob�w mo�na by�o zamknac aplikacje
	bez zatrzymania programu przez system operacyjny.
*/
class AssetManager
{
	public:
		//! Konsruktor domy�lny.
		AssetManager() = default;

		//! Destruktor domy�lny.
		~AssetManager() = default;

		/*!
			Metoda pozwalajaca na za�adowanie odpowiednich tekstur. U�ywana jest przy inicjalizacji ka�dego ze stan�w gry. We wn�trzu funkcji odbywa sie procedura walidacji danych kt�ra
			w razie potrzeby prze��cza flag� "_closeWindow" na true.
			\param name jest to nazwa tekstury kt�ra u�ywana jest do poprawnego umieszczenia zasobu w kontenerze.
			\param file_name nazwa pliku z kt�rego dana tekstura ma zosta� odczytana.
		*/
		void LoadTexture(std::string name, std::string file_name);	

		/*!
			Metoda wyszukuj�ca w kontenerze tekstur�.
			\param name nazwa zasobu po kt�rej kontener b�dzie przeszukiwany.
			\return Referencje do wyszukanego zasobu je�eli zostanie on odnaleziony. W przeciwnym razie zwraca iterator end().
		*/
		sf::Texture& getTexture(std::string name);	

		/*!
			Metoda pozwalajaca na za�adowanie odpowiednich czcionek. U�ywana jest przy inicjalizacji ka�dego ze stan�w gry. We wn�trzu funkcji odbywa sie procedura walidacji danych kt�ra
			w razie potrzeby prze��cza flag� "_closeWindow" na true.
			\param name jest to nazwa czcionki kt�ra u�ywana jest do poprawnego umieszczenia zasobu w kontenerze.
			\param file_name nazwa pliku z kt�rego dana czcionka ma zosta� odczytana.
		*/
		void LoadFont(std::string name, std::string file_name);	

		/*!
			Metoda wyszukuj�ca w kontenerze czcionk�.
			\param name nazwa zasobu po kt�rej kontener b�dzie przeszukiwany.
			\return Referencje do wyszukanego zasobu je�eli zostanie on odnaleziony. W przeciwnym razie zwraca iterator end().
		*/
		sf::Font& getFont(std::string name);	

		bool _closeWindow = false;	/*< Publiczna flaga boolowa pozwalaj�ca na zamkni�cie aplikacji w przypadku wyst�pienia b��du podczas �adowania zasob�w. */

	private:
		std::map<std::string, sf::Texture> _texture;  /*< Kontener STL typu mapa pozwalajacy na przechowywanie za�adowanych tekstur. Konteer funkcjonuje na zasadzie drzewa BST */
		std::map<std::string, sf::Font> _font;	/*< Kontener STL typu mapa pozwalajacy na przechowywanie za�adowanych czcionek. Konteer funkcjonuje na zasadzie drzewa BST */
};

/*!
	\file AssetManager.h
*/