#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "definitions.h"
#include "Animation.h"
#include <vector>

//! Klasa bomby
/*! Reprezentuje obiekt bomby kt�r� k�adzie kazdy z graczy. */
class Bomb
{
	public:
		/*!
			Konstruktor klasy wykonuj�cy wszystkie niezb�dne operacje przy tworzeniu obiektu. Przydziela domy�lne tekstury aby mozna by�o wykonywa� na nich obliczenia do kolizji,
			tym te� teksturom przydziela pozycje, punkt odniesienia oraz skaluje je je�li jest taka potrzeba. W konstuktorze tworzony jest takze obiekt klasy "Animation" i trafia do 
			kontenera.
			\param data
			\param xCords jeden z kordynat�w okre�lajacych pozycj� bomby.
			\param yCords jeden z kordynat�w okre�lajacych pozycj� bomby.
		*/
		Bomb(GameDataRef data, int xCords, int yCords);

		//! Destruktor domy�lny.
		~Bomb() = default;

		/*!	Metoda pozwalajaca na wyrysowanie bomby oraz je�li jest taka potrzeba ognia eksplozji. */
		void drawBomb();

		/*!
			Metoda odpowiada za odgrywanie odpowiednich animacji. Je�li bomba nie wybuch�a odgrywana jest domy�lna animacja gdy jednak wybuch nastapi do kontenera dodawany jest kolejny 
			obiekt animacji i nast�puje jego odegranie.
		*/
		void bombUpdate();

		/*!
			Typowa metoda typu "getter" pozwalaj�ca na odczyt prywatnego atrybutu klasy.
			\return sprite bomby po przez referencje.
		*/
		const sf::Sprite &getSprite() const;

		/*!
			Typowa metoda typu "getter" pozwalaj�ca na odczyt prywatnego atrybutu klasy.
			\return sprite wybuchu po przez referencje.
		*/
		const sf::Sprite &getExplosionSprite() const;

		/*!
			Typowa metoda typu "getter" pozwalaj�ca na odczyt prywatnego atrybutu klasy.
			\return informacja czy nast�pi�a eksplozja bomby.
		*/
		bool getBombStatus();

		/*!
			Typowa metoda typu "getter" pozwalaj�ca na odczyt prywatnego atrybutu klasy.
			\return informacja czy obiekt bomby moze zosta� zniszczony.
		*/
		bool isBombExploded();

	private:
		GameDataRef _data;
		sf::Sprite _bombSprite;	/*!< Sprite bomby. */
		sf::Sprite _explosionSprite;  /*!< Sprite wybuchu. */
		std::vector<Animation> _animations;	/*!< Kontener STLa przechowuj�cy obiekty klasy "Animation". Kontener ten dzia�a jak tablica jednowymiarowa. */
		bool _exploded;	/*!< Warto�� okre�lajaca czy bomba wybuch�a czy nie. */
		bool _destroyed;  /*!< Warto�� okre�lajaca czy bomba mo�e zosta� usuni�ta. */
		sf::Clock _explosionCountdown;	/*!< Zegar odliczajacy czas do wybuchu bomby oraz jej zniszczenia. */
};

/*!
	\file Bomb.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/