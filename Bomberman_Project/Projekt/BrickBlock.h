#pragma once
#include "Blocks.h"

//! Klasa pochodna dziedzicz�ca po klasie "Blocks". Atrybur "_canBeDestroy" w tym przypadku przyjmuje warto�� "true". 
class BrickBlock: public Blocks
{
	public:
		/*!
			Konstruktor klasy ustawiaj�cy tekstur� obiektu, jego pozycj� oraz punkt odniesienia wzgl�dem kt�rego b�d� wykonywane przekszta�cenia.
			\param data wska�nik wsp�dzielony z dost�pem do niezb�dnych menad�er�w.
			\param x_cord_value jeden z kordynat�w okre�lajacych pozycj� danego bloku.
			\param y_cord_value jeden z kordynat�w okre�lajacych pozycj� danego bloku.
		*/
		BrickBlock(GameDataRef data, int x_cord_value, int y_cord_value);
		~BrickBlock() = default;

		void drawBlocks() override;
		const sf::Sprite &getSprite() const override;
		bool getBlockState() override;
};

/*!
	\file BrickBlock.h
*/