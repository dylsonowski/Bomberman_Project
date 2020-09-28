#pragma once
#include <memory>
#include <stack>
#include "States.h"

//! Istota stan�w gry.
/*! Inteligentny wska�nik typu "unique_ptr" u�ywany do prze��cznia stan�w. Nadano mu alias (StateRef) w celu unikni�cia potrzeby pisania d�ugiej formu�y. */
typedef std::unique_ptr<States> StateRef;

//! Maszyna zmiany stan�w.
/*! Klasa zajmujaca sie prze��czniem mi�dzy stanami. Poniewa� gra zawiera tylko 3 stany dzia�a ona tylko w jedna strone. */
class StateMachine
{
	public:
		//! Kostruktor domy�lny.
		StateMachine() = default;

		//! Destruktor domy�lny.
		~StateMachine() = default;

		/*!
			Za pomoc� semantyki przeniesienia (move()) metoda przypisuje warto�� argumentu do prywatnego atrybutu "_newState". W metodzie nast�puje r�wnie� prze��czenie flagi "_adding" na "true".
			\param newState stan gry kt�ry chcemy za�adowa�.
		*/
		void AddState(StateRef newState);

		//! Z pomoc� semantyki przeniesienia "_newState" umieszczany jest w kontenerze stosu oraz wywo�ywana jest jego metoda "Init()" aby umo�liwi� przygotowanie niezb�dnych element�w stanu. Flaga "_addning" ponownie przyjmuje warot�� "false".
		void StateChange();

		/*!
			Metoda typu "Getter" pozwalaj�ca na dost�p do prywatnego atrybutu.
			\return Referencj� na obecnie aktywny stan.
		*/
		StateRef& ActiveState();

	private:
		std::stack<StateRef> _states;  /*!< Kontener STL przechowuj�cy w sobie wska�niki unikatowe na poszczeg�lne stany. */
		StateRef _newstate;  /*!< Unikalny wska�nik na obecnie aktywny stan. */
		bool _adding;  /*!< Warto�� boolowa zabezpieczajaca metod� "StateChange" przed wykonaniem e�eli nie ma aktywnego stanu. */
};

/*!
	\file StateMachine.h
*/