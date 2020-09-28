#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "States.h"
#include "definitions.h"

//! Klasa ekranu ko�ca gry
/*! Klasa pochodna dziedzicz�ca po klasie "States". Reprezentuje ekran ko�cowy na kt�rym wy�wietlana jest informacja o zwyci�zcy. */
class EndScreenState: public States
{
	public:
		/*!
			Konstruktor klasy przydzielaj�cy odpowiednie tekstury oraz tre�� informacji o zwyci�zcy w zale�nosci od zaistnia�ej sytuacji.
			\param data
			\param Win jesli przyjmie wartosc "true" oznaczaa to ze zwyciezc� jest gracz 1 w przeciwnym razie gracz 2.
			\param draw okre�la czy nastapi� remis.
		*/
		EndScreenState(GameDataRef data, bool Win, bool draw);

		//! Destruktor domy�lny.
		~EndScreenState() = default;

		/*! 
			Metoda odziedziczona z klasy bazowej w kt�rej przypisywane s� odpowiednie tekstury, pozycje sprite�w oraz ich punkty odniesienia.
			Wykonywane jest to w oparciu o informacj� czy nast�pi� remis oraz kto zwycie�y�. 
		*/
		void Init() override;

		/*! Metoda odziedziczona z klasy bazowej kt�ra przechwytuje wszystkie wydarzenia dziejace sie na oknie takie jak wy��czenie go, przeniesienie lub zminimalizowanie. */
		void HInput() override;

		/*! Metoda odziedziczona z klasy bazowej kt�ra odpowiada za wy�wietlenie odpowiedniego spritea po up�ywie 10 sekund. */
		void Update(float dt) override;

		/*!  Metoda odziedziczona z klasy bazowej odpowiedzialna za rysowanie obiekt�w na ekranie. */
		void Draw() override;

	private:
		GameDataRef _data;
		sf::Sprite _Winbackground;	/*!< Sprite wyswietlany jako t�o. */
		sf::Text _winnerMark;  /*!< Tekst wy�wietlaj�cy informacje na temat zwyci�zcy. */
		sf::Sprite _surprise;  /*!< Sprite wyswietlajacy sie po 10 sekundach. */
		sf::Clock _clock;  /*!< Zegar odlicz�cy czas do wyswietlenia spritea "surprise". */
		bool _isWinerP1;  /*!< Informacja czy zwyci�zc� jest gracz 1. */
		bool _draw;  /*!< informacja czy nastapi� remis. */
};

/*!
	\file EndScreenState.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/