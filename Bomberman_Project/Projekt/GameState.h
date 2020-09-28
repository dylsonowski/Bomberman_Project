#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "States.h"
#include "definitions.h"
#include "HUD.h"
#include "Blocks.h"
#include "Player1.h"
#include "Player2.h"
#include "Collision.h"

//! Klasa rozgrywki
/*! Klasa pochodna dziedziczaca z klasy "States". Obs�uguje ca�y proces rozgrywki. */
class GameState: public States
{
	public:
		/*!
			Konstruktor klasy ustawiaj�cy stan rozgrywki na "_plaeying".
			\param data
		*/
		GameState(GameDataRef data);

		//! Destruktor klasy zwalniaj�cy pami�� z obiekt�w utworzonych za pomoc� klauzuli "new".
		~GameState();

		/*!
			Metoda odziedziczona z klasy bazowej w kt�rej przypisywane s� odpowiednie tekstury, pozycje sprite�w oraz ich punkty odniesienia. Metoda ta tworzy takze potrzebne obiekty
			z uzyciem wska�nik�w oraz klauzuli "new".
		*/
		void Init() override;

		/*! Metoda odziedziczona z klasy bazowej kt�ra przechwytuje wszystkie wydarzenia dziejace sie na oknie takie jak wy��czenie go, przeniesienie lub zminimalizowanie. */
		void HInput() override;

		/*! 
			Metoda odziedziczona z klasy bazowej w kt�rej nast�puja wszelkie zmiany w logice gry takie jak wykrywanie kolizji lub zmiany status�w obiekt�w.
			\param dt liczba zmiennoprzecinkowa u�ywana w obliczeniach do uniezale�nienia gry od ilosci klatek.
		*/
		void Update(float dt) override;

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiekt�w na ekranie. */
		void Draw() override;

	private:
		GameDataRef _data;	
		sf::Sprite _plate;	/*!< Sprite reprezenrujacy plansze na kt�rej przebiega rozgrywka. */
		HUD *_hud;  /*!< Wska�nik umo�liwiajacy stworzenie obiektu klasy "HUD". */
		Blocks *_blocks[31][17];  /*!< Tablica dwuwymiarowa przechowuj�ca wska�niki na obiektry blok�w. Moga to by� obiekty "WallBlock" lub "BrickBlock". */
		Player1 *_player1;  /*!< Wska�nik umo�liwiajacy stworzenie obiektu klasy "Player1". */
		Player2 *_player2;	/*!< Wska�nik umo�liwiajacy stworzenie obiektu klasy "Player2". */
		Collision collision;  /*!< Obiekt klasy "Collision" potrzebny do u�ywania metod tej klasy. */
		short int _gameState;  /*!< Warto�� definiujaca stan rozgrywki. Enum w kt�rym poszczeg�lne stany s� zdefiniowane znajduje si� w pliku "definitions". */
};

/*!
	\file GameState.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/