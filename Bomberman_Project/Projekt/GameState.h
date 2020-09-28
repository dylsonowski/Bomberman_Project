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
/*! Klasa pochodna dziedziczaca z klasy "States". Obs³uguje ca³y proces rozgrywki. */
class GameState: public States
{
	public:
		/*!
			Konstruktor klasy ustawiaj¹cy stan rozgrywki na "_plaeying".
			\param data
		*/
		GameState(GameDataRef data);

		//! Destruktor klasy zwalniaj¹cy pamiêæ z obiektów utworzonych za pomoc¹ klauzuli "new".
		~GameState();

		/*!
			Metoda odziedziczona z klasy bazowej w której przypisywane s¹ odpowiednie tekstury, pozycje spriteów oraz ich punkty odniesienia. Metoda ta tworzy takze potrzebne obiekty
			z uzyciem wskaŸników oraz klauzuli "new".
		*/
		void Init() override;

		/*! Metoda odziedziczona z klasy bazowej która przechwytuje wszystkie wydarzenia dziejace sie na oknie takie jak wy³¹czenie go, przeniesienie lub zminimalizowanie. */
		void HInput() override;

		/*! 
			Metoda odziedziczona z klasy bazowej w której nastêpuja wszelkie zmiany w logice gry takie jak wykrywanie kolizji lub zmiany statusów obiektów.
			\param dt liczba zmiennoprzecinkowa u¿ywana w obliczeniach do uniezale¿nienia gry od ilosci klatek.
		*/
		void Update(float dt) override;

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiektów na ekranie. */
		void Draw() override;

	private:
		GameDataRef _data;	
		sf::Sprite _plate;	/*!< Sprite reprezenrujacy plansze na której przebiega rozgrywka. */
		HUD *_hud;  /*!< WskaŸnik umo¿liwiajacy stworzenie obiektu klasy "HUD". */
		Blocks *_blocks[31][17];  /*!< Tablica dwuwymiarowa przechowuj¹ca wskaŸniki na obiektry bloków. Moga to byæ obiekty "WallBlock" lub "BrickBlock". */
		Player1 *_player1;  /*!< WskaŸnik umo¿liwiajacy stworzenie obiektu klasy "Player1". */
		Player2 *_player2;	/*!< WskaŸnik umo¿liwiajacy stworzenie obiektu klasy "Player2". */
		Collision collision;  /*!< Obiekt klasy "Collision" potrzebny do u¿ywania metod tej klasy. */
		short int _gameState;  /*!< Wartoœæ definiujaca stan rozgrywki. Enum w którym poszczególne stany s¹ zdefiniowane znajduje siê w pliku "definitions". */
};

/*!
	\file GameState.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/