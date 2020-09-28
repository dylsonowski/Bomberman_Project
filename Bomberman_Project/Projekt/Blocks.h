#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

//! Klasa abstrakcyjna reprezentuj¹ca wszystkie bloki na planszy.
class Blocks
{
	public:
		//! Wirtualny destruktor.
		virtual ~Blocks() {}
		
		//! Metoda czysto wirtualna pozwalajaca na wyœwietlenie bloków na planszy.
		virtual void drawBlocks() = 0;

		/*!
			Metoda czysto wirtualna umo¿liwiajaca na dostêp do spritu bloku.
			\return referencje na obiekt klasy "Sprite". 
		*/
		virtual const sf::Sprite &getSprite() const = 0;

		/*! 
			Metoda czysto wirtualna dzia³ajaca jako "getter" to znaczy pozwalaj¹ca na podgl¹d prywatnych atrybutów klasy.
			\return  wartoœæ "true" lub "false" w zale¿noœci czy dany obiekt moze zostaæ zniszczony czy nie.
		*/
		virtual bool getBlockState() = 0;

	protected:
		GameDataRef _data;	/*!< Wspó³dzielony wskaŸnik umo¿liwiajacy na dostêp do elementów struktury "GameData" */
		sf::Sprite _blockSprite;  /*< Obiekt klasy "Sprite" reprezentujacy obrazek danego bloku. */
		bool _canBeDestroy;	 /*!< Wartoœæ mówi¹ca czy dany blok moze byæ zniczszony czy nie. */
};

/*!
	\file Blocks.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/