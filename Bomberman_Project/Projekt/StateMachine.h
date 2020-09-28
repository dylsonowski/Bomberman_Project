#pragma once
#include <memory>
#include <stack>
#include "States.h"

//! Istota stanów gry.
/*! Inteligentny wskaŸnik typu "unique_ptr" u¿ywany do prze³¹cznia stanów. Nadano mu alias (StateRef) w celu unikniêcia potrzeby pisania d³ugiej formu³y. */
typedef std::unique_ptr<States> StateRef;

//! Maszyna zmiany stanów.
/*! Klasa zajmujaca sie prze³¹czniem miêdzy stanami. Poniewa¿ gra zawiera tylko 3 stany dzia³a ona tylko w jedna strone. */
class StateMachine
{
	public:
		//! Kostruktor domyœlny.
		StateMachine() = default;

		//! Destruktor domyœlny.
		~StateMachine() = default;

		/*!
			Za pomoc¹ semantyki przeniesienia (move()) metoda przypisuje wartoœæ argumentu do prywatnego atrybutu "_newState". W metodzie nastêpuje równie¿ prze³¹czenie flagi "_adding" na "true".
			\param newState stan gry który chcemy za³adowaæ.
		*/
		void AddState(StateRef newState);

		//! Z pomoc¹ semantyki przeniesienia "_newState" umieszczany jest w kontenerze stosu oraz wywo³ywana jest jego metoda "Init()" aby umo¿liwiæ przygotowanie niezbêdnych elementów stanu. Flaga "_addning" ponownie przyjmuje warotœæ "false".
		void StateChange();

		/*!
			Metoda typu "Getter" pozwalaj¹ca na dostêp do prywatnego atrybutu.
			\return Referencjê na obecnie aktywny stan.
		*/
		StateRef& ActiveState();

	private:
		std::stack<StateRef> _states;  /*!< Kontener STL przechowuj¹cy w sobie wskaŸniki unikatowe na poszczególne stany. */
		StateRef _newstate;  /*!< Unikalny wskaŸnik na obecnie aktywny stan. */
		bool _adding;  /*!< Wartoœæ boolowa zabezpieczajaca metodê "StateChange" przed wykonaniem e¿eli nie ma aktywnego stanu. */
};

/*!
	\file StateMachine.h
*/