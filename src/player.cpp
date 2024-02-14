#include "player.h"

Player::Player() : Entity(), player({ position.x, position.y, scale.x, scale.y })
{
    //constructor
    // Rectangle player = { position.x, position.y, scale.x, scale.y };
    // camera.target = Vector2{ this->position.x , this->position.y  };
    // camera.offset = Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
    // camera.rotation = 0.0f;
    // camera.zoom = 1.0f;
}   

Player::~Player() 
{
	// deconstruct and delete the Tree
}

void Player::draw(float deltaTime) 
{
    DrawRectangleRec(player, BLUE); 
}

void Player::update(float deltaTime) 
{
    draw(deltaTime);
    
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
