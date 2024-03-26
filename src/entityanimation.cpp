#include <entityanimation.h>

EntityAnimation::EntityAnimation() : Entity()
{
    //defualt values for sprite animation
    spriteCount = 1;
    spriteSize = 16;
    spriteFps = 4;
    spriteTime = 1.0f;
    spriteIndex = 0;
}

EntityAnimation::~EntityAnimation()
{

}

void EntityAnimation::update(float deltaTime)
{

}

void EntityAnimation::renderSelect()
{
    // Define the source rectangle on the texture. This specifies which part of the texture to draw.
    // spriteIndex * PLAYER_SIZE determines the x-coordinate of the top-left corner of the source rectangle.
    // This is useful for animating sprites by changing the source rectangle to different parts of the texture.
    Rectangle source = {(float)spriteIndex * spriteSize, 0, spriteSize, spriteSize};

    // Define the destination rectangle on the screen. This specifies where and how large the source rectangle should be drawn.
    // SCREEN_WIDTH/2 and SCREEN_HEIGHT/2 center the destination rectangle on the screen.
    Rectangle dest  = {position.x, position.y, spriteSize, spriteSize};

    // Define the origin point for rotation and scaling. This point is used as the pivot point for transformations.
    // dest.width/2 and dest.height/2 set the origin to the center of the destination rectangle, ensuring that the sprite scales and rotates around its center.
    Vector2 origin = {dest.width/2, dest.height/2};

    // was used to update animation not relavant any more
    // source.x = (float)spriteIndex * SPRITE_SIZE;

    switch (renderMethod)
    {
    case 1: 
        DrawTexturePro(this->texture(), source, dest, origin, 0, this->color());
        break;
    
    default:
        Entity::renderSelect();
        break;
    }
}
