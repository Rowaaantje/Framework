#include <Block.h>

Block::Block() : Entity()
{
    this->addTexture("assets/sword1.png");
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
    this->setTextureColor(WHITE); 
}   

Block::~Block() 
{
	// deconstruct and delete the Tree
}

void Block::draw(float deltaTime) 
{
    // DrawRectangleRec(block, RED); //draw Rectangle
}

void Block::update(float deltaTime) 
{
    // draw(deltaTime);
    
    // block.x = position.x;
    // block.y = position.y;
    // block.width = scale.x;
    // block.height = scale.y;
}
