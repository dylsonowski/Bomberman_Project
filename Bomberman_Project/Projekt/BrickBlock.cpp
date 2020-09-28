#include "BrickBlock.h"
#include "definitions.h"

BrickBlock::BrickBlock(GameDataRef data, int x_cord_value, int y_cord_value)
{
	_data = data;
	_canBeDestroy = true;
	_blockSprite.setTexture(_data->_assets.getTexture("Brick Block"));
	_blockSprite.setOrigin(_blockSprite.getGlobalBounds().width / 2, _blockSprite.getGlobalBounds().height / 2);
	_blockSprite.setPosition(x_cord_value + ONE_BLOCK_WIDTH / 2, y_cord_value + ONE_BLOCK_HEIGHT / 2);
}

void BrickBlock::drawBlocks()
{
	_data->_window.draw(_blockSprite);
}

const sf::Sprite & BrickBlock::getSprite() const
{
	return _blockSprite;
}

bool BrickBlock::getBlockState()
{
	return _canBeDestroy;
}