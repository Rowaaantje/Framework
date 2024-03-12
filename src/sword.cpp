#include <sword.h>

Sword::Sword() : Entity()
{
    this->addTexture("assets/sword_loyal.png");
    this->renderMethod = 1;
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
    this->setTextureColor(WHITE); 

    // Define the source rectangle on the texture. This specifies which part of the texture to draw.
    // spriteIndex * SWORD_SIZE determines the x-coordinate of the top-left corner of the source rectangle.
    // This is useful for animating sprites by changing the source rectangle to different parts of the texture.
    this->source = {(float)spriteIndex * SWORD_SIZE, 0, SWORD_SIZE, SWORD_SIZE};

    // Define the destination rectangle on the screen. This specifies where and how large the source rectangle should be drawn.
    // SCREEN_WIDTH/2 and SCREEN_HEIGHT/2 center the destination rectangle on the screen.
    this->dest = {SCREEN_WIDTH/2, SCREEN_WIDTH/2, SWORD_SIZE, SWORD_SIZE};

    // Define the origin point for rotation and scaling. This point is used as the pivot point for transformations.
    // dest.width/2 and dest.height/2 set the origin to the center of the destination rectangle, ensuring that the sprite scales and rotates around its center.
    this->origin = {dest.width/2, dest.height/2}; // Set the origin to the center of the destination rectangle
}   

Sword::~Sword() 
{
}

void Sword::draw(float deltaTime) 
{

}

void Sword::update(float deltaTime) 
{
}
