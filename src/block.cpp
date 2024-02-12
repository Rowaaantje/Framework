#include "Block.h"



Block::Block() : Entity(), block ({ position.x, position.y, scale.x, scale.y })
{
    //constructor
    // Rectangle block = { position.x, position.y, scale.x, scale.y };
}   

Block::~Block() 
{
	// deconstruct and delete the Tree
}

void Block::update(float deltaTime) 
{
    DrawRectangleRec(block, RED); //draw Rectangle

    block.x = position.x;
    block.y = position.y;
    block.width = scale.x;
    block.height = scale.y;
}