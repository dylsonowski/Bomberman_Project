#include "WallBlock.h"
#include "definitions.h"

WallBlock::WallBlock(GameDataRef data, int x_cord_value, int y_cord_value)
{
	_data = data;
	_canBeDestroy = false;
	_blockSprite.setTexture(_data->_assets.getTexture("Wall Block"));
	_blockSprite.setOrigin(_blockSprite.getGlobalBounds().width / 2, _blockSprite.getGlobalBounds().height / 2);
	_blockSprite.setPosition(x_cord_value + ONE_BLOCK_WIDTH / 2, y_cord_value + ONE_BLOCK_HEIGHT / 2);
}

void WallBlock::drawBlocks()
{
	_data->_window.draw(_blockSprite);
}

const sf::Sprite & WallBlock::getSprite() const
{
	return _blockSprite;
}

bool WallBlock::getBlockState()
{
	return _canBeDestroy;
}