#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"

/*! Struktura zawieraj¹ca w sobie obiekty klas które obs³uguj¹ istotne zda¿enia w grze. */
struct GameData					
{
	AssetManager _assets;	/*!< Obiekt klasy zajmuj¹cej sie ³¹dowaniem odpowiednich tekstur oraz czcionek. */
	StateMachine _state;	/*!< Obiekt klasy która zajmuje sie prze³¹czaniem pomiêdzy poszczególnymi stanami gry. */
	InputManager _input;	/*!< Obiekt klasy która zajmuje sie obs³ug¹ zda¿eñ zwi¹zanych z mysz¹. */
	sf::RenderWindow _window;	/*!< Obiekt klasy z biblioteki SFML który reprezentuje okno na którym bêdzie wyœwietlana ca³a aplikacja. */
};

//! Inteligentny wskaŸnik
/*! WskaŸnik ten umo¿liwia na konfortowy dostêp do sk³adowych struktury "GameData". Nadany zosta³ mu tu alias "GameDataRef" aby unikn¹æ niepotrzebnego pisania d³ugiej formu³y. */
typedef std::shared_ptr<GameData> GameDataRef;

//! G³ówna klasa gry
/*! Klasa niezbêdna do dzia³ania ca³ej aplikacji. Zawiera ona w sobie wszystkie inne klasy s³u¿¹dze do zarz¹dzania aplikacj¹. W tej klasie zawarte s¹ równie¿ bardzo wazne parametry programu. */
class Game
{
	public:
		//! Konstruktor klasy.
		/*! 
			Przyjmuje trzy argumenty oraz na ich podstawie tworzy okno aplikacji. W kostruktorze jest takze przydzielany pierwszy stan gry, jest on wymagany poniewa¿ w przeciwnym razie
			nast¹pi³by krytyczny b³¹d.
			\param width szerokoœæ okna.
			\param height wysokoœæ okna.
			\param title tekst jaki ma pojawiaæ sie jako nazwa w górnym lewym rogu okna.
		*/
		Game(const int width, const int height, std::string title);

		//! Destruktor
		/*! Destruktor moze pozostaæ domyœlny poniewa¿ klasa nie musi zwalniaæ pamieci */
		~Game() = default;  

		//! Game Loop
		/*! Funkcja w której zawarta jest g³ówna pêtla gry. Dokonuje ona zmiany stanu(jeœli jest potrzebna) oraz ustawia maksymalny limit kaltek na sekundê na 60 */
		void Run();  

	private:
		GameDataRef _data = std::make_shared<GameData>();	/*!< Utworzony wskaŸnik wspó³dzielony który pozwala na dostêp do elementów sk³adowych struktury "GameData". WskaŸnik ten jest przekazywany do wszystkich innych klas które potrzebuja dostêpu do elementów tej struktury. */
		const float dt = 1.0f / 60.0f;	/*!< Zmienna potrzebna do obliczeñ aby gra by³a niezale¿na od iloœci klatek */
};

/*! 
	\file Game.h
*/