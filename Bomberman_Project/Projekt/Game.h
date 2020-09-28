#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"

/*! Struktura zawieraj�ca w sobie obiekty klas kt�re obs�uguj� istotne zda�enia w grze. */
struct GameData					
{
	AssetManager _assets;	/*!< Obiekt klasy zajmuj�cej sie ��dowaniem odpowiednich tekstur oraz czcionek. */
	StateMachine _state;	/*!< Obiekt klasy kt�ra zajmuje sie prze��czaniem pomi�dzy poszczeg�lnymi stanami gry. */
	InputManager _input;	/*!< Obiekt klasy kt�ra zajmuje sie obs�ug� zda�e� zwi�zanych z mysz�. */
	sf::RenderWindow _window;	/*!< Obiekt klasy z biblioteki SFML kt�ry reprezentuje okno na kt�rym b�dzie wy�wietlana ca�a aplikacja. */
};

//! Inteligentny wska�nik
/*! Wska�nik ten umo�liwia na konfortowy dost�p do sk�adowych struktury "GameData". Nadany zosta� mu tu alias "GameDataRef" aby unikn�� niepotrzebnego pisania d�ugiej formu�y. */
typedef std::shared_ptr<GameData> GameDataRef;

//! G��wna klasa gry
/*! Klasa niezb�dna do dzia�ania ca�ej aplikacji. Zawiera ona w sobie wszystkie inne klasy s�u��dze do zarz�dzania aplikacj�. W tej klasie zawarte s� r�wnie� bardzo wazne parametry programu. */
class Game
{
	public:
		//! Konstruktor klasy.
		/*! 
			Przyjmuje trzy argumenty oraz na ich podstawie tworzy okno aplikacji. W kostruktorze jest takze przydzielany pierwszy stan gry, jest on wymagany poniewa� w przeciwnym razie
			nast�pi�by krytyczny b��d.
			\param width szeroko�� okna.
			\param height wysoko�� okna.
			\param title tekst jaki ma pojawia� sie jako nazwa w g�rnym lewym rogu okna.
		*/
		Game(const int width, const int height, std::string title);

		//! Destruktor
		/*! Destruktor moze pozosta� domy�lny poniewa� klasa nie musi zwalnia� pamieci */
		~Game() = default;  

		//! Game Loop
		/*! Funkcja w kt�rej zawarta jest g��wna p�tla gry. Dokonuje ona zmiany stanu(je�li jest potrzebna) oraz ustawia maksymalny limit kaltek na sekund� na 60 */
		void Run();  

	private:
		GameDataRef _data = std::make_shared<GameData>();	/*!< Utworzony wska�nik wsp�dzielony kt�ry pozwala na dost�p do element�w sk�adowych struktury "GameData". Wska�nik ten jest przekazywany do wszystkich innych klas kt�re potrzebuja dost�pu do element�w tej struktury. */
		const float dt = 1.0f / 60.0f;	/*!< Zmienna potrzebna do oblicze� aby gra by�a niezale�na od ilo�ci klatek */
};

/*! 
	\file Game.h
*/