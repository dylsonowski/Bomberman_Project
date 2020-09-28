#pragma once
#include "Blocks.h"

//! Klasa pochodna dziedzicz¹ca po klasie "Blocks". Atrybur "_canBeDestroy" w tym przypadku przyjmuje wartoœæ "false". 
class WallBlock: public Blocks
{
	public:
		/*!
			Konstruktor klasy ustawiaj¹cy teksturê obiektu, jego pozycjê oraz punkt odniesienia wzglêdem którego bêd¹ wykonywane przekszta³cenia.
			\param data wskaŸnik wspó³dzielony z dostêpem do niezbêdnych menad¿erów.
			\param x_cord_value jeden z kordynatów okreœlajacych pozycjê danego bloku.
			\param y_cord_value jeden z kordynatów okreœlajacych pozycjê danego bloku.
		*/
		WallBlock(GameDataRef data, int x_cord_value, int y_cord_value);
		~WallBlock() = default;
	
		void drawBlocks() override;
		const sf::Sprite &getSprite() const override;
		bool getBlockState() override;
};

/*!
	\file WallBlock.h
*/