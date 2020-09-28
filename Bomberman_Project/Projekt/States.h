#pragma once

//! Klasa abstrakcyjna reperentujaca kazdy stan istniej�cy w aplikacji. 
class States
{
	public:
		//! Wirtualny destruktor.
		virtual ~States() {}

		//! Metoda czysto wirtualna inicjalizujaca wszystkie obiekty niezb�dne do dzia�ania.
		virtual void Init() = 0;

		/*!
			Metoda czysto wirtualna w kt�rej odbywaj� sie wszystkie zmiany w "Game Logic".
			\param dt warto�� zmienno przecinkowa uwzgl�dniana w obliczeniach do stworzenia "Frame independent game"
		*/
		virtual void Update(float dt) = 0;

		//! Metoda czysto wirtualna odpowiedzialna za rysowanie obiekt�w na ekranie. 
		virtual void Draw() = 0;

		//! Metoda czysto wirtualna odpowiedzialna za os�ug� wszystkiech zdarze� na oknie.
		virtual void HInput() = 0;
};

/*!
	\file States.h
*/