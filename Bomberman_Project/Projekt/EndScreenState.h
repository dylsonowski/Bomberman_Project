#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "States.h"
#include "definitions.h"

//! Klasa ekranu koñca gry
/*! Klasa pochodna dziedzicz¹ca po klasie "States". Reprezentuje ekran koñcowy na którym wyœwietlana jest informacja o zwyciêzcy. */
class EndScreenState: public States
{
	public:
		/*!
			Konstruktor klasy przydzielaj¹cy odpowiednie tekstury oraz treœæ informacji o zwyciêzcy w zale¿nosci od zaistnia³ej sytuacji.
			\param data
			\param Win jesli przyjmie wartosc "true" oznaczaa to ze zwyciezc¹ jest gracz 1 w przeciwnym razie gracz 2.
			\param draw okreœla czy nastapi³ remis.
		*/
		EndScreenState(GameDataRef data, bool Win, bool draw);

		//! Destruktor domyœlny.
		~EndScreenState() = default;

		/*! 
			Metoda odziedziczona z klasy bazowej w której przypisywane s¹ odpowiednie tekstury, pozycje spriteów oraz ich punkty odniesienia.
			Wykonywane jest to w oparciu o informacjê czy nast¹pi³ remis oraz kto zwycie¿y³. 
		*/
		void Init() override;

		/*! Metoda odziedziczona z klasy bazowej która przechwytuje wszystkie wydarzenia dziejace sie na oknie takie jak wy³¹czenie go, przeniesienie lub zminimalizowanie. */
		void HInput() override;

		/*! Metoda odziedziczona z klasy bazowej która odpowiada za wyœwietlenie odpowiedniego spritea po up³ywie 10 sekund. */
		void Update(float dt) override;

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiektów na ekranie. */
		void Draw() override;

	private:
		GameDataRef _data;
		sf::Sprite _Winbackground;	/*!< Sprite wyswietlany jako t³o. */
		sf::Text _winnerMark;  /*!< Tekst wyœwietlaj¹cy informacje na temat zwyciêzcy. */
		sf::Sprite _surprise;  /*!< Sprite wyswietlajacy sie po 10 sekundach. */
		sf::Clock _clock;  /*!< Zegar odlicz¹cy czas do wyswietlenia spritea "surprise". */
		bool _isWinerP1;  /*!< Informacja czy zwyciêzc¹ jest gracz 1. */
		bool _draw;  /*!< informacja czy nastapi³ remis. */
};

/*!
	\file EndScreenState.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/