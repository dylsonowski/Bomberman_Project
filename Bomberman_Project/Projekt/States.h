#pragma once

//! Klasa abstrakcyjna reperentujaca kazdy stan istniej¹cy w aplikacji. 
class States
{
	public:
		//! Wirtualny destruktor.
		virtual ~States() {}

		//! Metoda czysto wirtualna inicjalizujaca wszystkie obiekty niezbêdne do dzia³ania.
		virtual void Init() = 0;

		/*!
			Metoda czysto wirtualna w której odbywaj¹ sie wszystkie zmiany w "Game Logic".
			\param dt wartoœæ zmienno przecinkowa uwzglêdniana w obliczeniach do stworzenia "Frame independent game"
		*/
		virtual void Update(float dt) = 0;

		//! Metoda czysto wirtualna odpowiedzialna za rysowanie obiektów na ekranie. 
		virtual void Draw() = 0;

		//! Metoda czysto wirtualna odpowiedzialna za os³ugê wszystkiech zdarzeñ na oknie.
		virtual void HInput() = 0;
};

/*!
	\file States.h
*/