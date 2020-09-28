#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

//! Klasa abstrakcyjna reprezentuj�ca wszystkie bloki na planszy.
class Blocks
{
	public:
		//! Wirtualny destruktor.
		virtual ~Blocks() {}
		
		//! Metoda czysto wirtualna pozwalajaca na wy�wietlenie blok�w na planszy.
		virtual void drawBlocks() = 0;

		/*!
			Metoda czysto wirtualna umo�liwiajaca na dost�p do spritu bloku.
			\return referencje na obiekt klasy "Sprite". 
		*/
		virtual const sf::Sprite &getSprite() const = 0;

		/*! 
			Metoda czysto wirtualna dzia�ajaca jako "getter" to znaczy pozwalaj�ca na podgl�d prywatnych atrybut�w klasy.
			\return  warto�� "true" lub "false" w zale�no�ci czy dany obiekt moze zosta� zniszczony czy nie.
		*/
		virtual bool getBlockState() = 0;

	protected:
		GameDataRef _data;	/*!< Wsp�dzielony wska�nik umo�liwiajacy na dost�p do element�w struktury "GameData" */
		sf::Sprite _blockSprite;  /*< Obiekt klasy "Sprite" reprezentujacy obrazek danego bloku. */
		bool _canBeDestroy;	 /*!< Warto�� m�wi�ca czy dany blok moze by� zniczszony czy nie. */
};

/*!
	\file Blocks.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/