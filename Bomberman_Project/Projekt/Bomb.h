#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "definitions.h"
#include "Animation.h"
#include <vector>

//! Klasa bomby
/*! Reprezentuje obiekt bomby któr¹ k³adzie kazdy z graczy. */
class Bomb
{
	public:
		/*!
			Konstruktor klasy wykonuj¹cy wszystkie niezbêdne operacje przy tworzeniu obiektu. Przydziela domyœlne tekstury aby mozna by³o wykonywaæ na nich obliczenia do kolizji,
			tym te¿ teksturom przydziela pozycje, punkt odniesienia oraz skaluje je jeœli jest taka potrzeba. W konstuktorze tworzony jest takze obiekt klasy "Animation" i trafia do 
			kontenera.
			\param data
			\param xCords jeden z kordynatów okreœlajacych pozycjê bomby.
			\param yCords jeden z kordynatów okreœlajacych pozycjê bomby.
		*/
		Bomb(GameDataRef data, int xCords, int yCords);

		//! Destruktor domyœlny.
		~Bomb() = default;

		/*!	Metoda pozwalajaca na wyrysowanie bomby oraz jeœli jest taka potrzeba ognia eksplozji. */
		void drawBomb();

		/*!
			Metoda odpowiada za odgrywanie odpowiednich animacji. Jeœli bomba nie wybuch³a odgrywana jest domyœlna animacja gdy jednak wybuch nastapi do kontenera dodawany jest kolejny 
			obiekt animacji i nastêpuje jego odegranie.
		*/
		void bombUpdate();

		/*!
			Typowa metoda typu "getter" pozwalaj¹ca na odczyt prywatnego atrybutu klasy.
			\return sprite bomby po przez referencje.
		*/
		const sf::Sprite &getSprite() const;

		/*!
			Typowa metoda typu "getter" pozwalaj¹ca na odczyt prywatnego atrybutu klasy.
			\return sprite wybuchu po przez referencje.
		*/
		const sf::Sprite &getExplosionSprite() const;

		/*!
			Typowa metoda typu "getter" pozwalaj¹ca na odczyt prywatnego atrybutu klasy.
			\return informacja czy nast¹pi³a eksplozja bomby.
		*/
		bool getBombStatus();

		/*!
			Typowa metoda typu "getter" pozwalaj¹ca na odczyt prywatnego atrybutu klasy.
			\return informacja czy obiekt bomby moze zostaæ zniszczony.
		*/
		bool isBombExploded();

	private:
		GameDataRef _data;
		sf::Sprite _bombSprite;	/*!< Sprite bomby. */
		sf::Sprite _explosionSprite;  /*!< Sprite wybuchu. */
		std::vector<Animation> _animations;	/*!< Kontener STLa przechowuj¹cy obiekty klasy "Animation". Kontener ten dzia³a jak tablica jednowymiarowa. */
		bool _exploded;	/*!< Wartoœæ okreœlajaca czy bomba wybuch³a czy nie. */
		bool _destroyed;  /*!< Wartoœæ okreœlajaca czy bomba mo¿e zostaæ usuniêta. */
		sf::Clock _explosionCountdown;	/*!< Zegar odliczajacy czas do wybuchu bomby oraz jej zniszczenia. */
};

/*!
	\file Bomb.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/