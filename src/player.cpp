#include "player.h"

Player::Player() : Entity(), player({ position.x, position.y, scale.x, scale.y })
{
    //constructor
    // Rectangle player = { position.x, position.y, scale.x, scale.y };

}   

Player::~Player() 
{
	// deconstruct and delete the Tree
}

void Player::update(float deltaTime) 
{
    DrawRectangleRec(player, BLUE); 
    
    // playerCam->position = this->position;

    player.x = position.x;
    player.y = position.y;
    player.width = scale.x;
    player.height = scale.y;

    // todo
    // You can directly modify the position and scale fields of the Entity class

    // position.x += deltaTime * velocity.x;
    // position.y += deltaTime * velocity.y;

    // Similarly for scale, if needed
    // scale.x = newScaleX;
    // scale.y = newScaleY;
}