#include "player.h"

Player::Player() : Entity()
// , player({ position.x, position.y, scale.x, scale.y })
{
    // Initialize the player rectangle here, using the initial position and scale from the Entity
    player.x = this->position.x;
    player.y = this->position.y;
    player.width = this->scale.x;
    player.height = this->scale.y;

	isMoving = false;
    sprintSpeed = 5.0f;
	walkSpeed = 2.0f;
    momentum = 0.0f;

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

void Player::synchronizeWithEntity()
{
    player.x = this->position.x;
    player.y = this->position.y;
    player.width = this->scale.x;
    player.height = this->scale.y;
}

void Player::update(float deltaTime) 
{

    synchronizeWithEntity();

    Move(deltaTime);

    draw(deltaTime);
}
// simple linear interpolation function
float Player::lerp(float start, float end, float factor) {
    return start + factor * (end - start);
}

void Player::adjustPosition(float deltaTime, int switchInt)
{   
    // Adjust this value to control the speed of the transition
    float transitionFactor =  0.1f;
    
    // Gradually increase momentum towards sprintSpeed  else Gradually decrease momentum towards walkSpeed
    //
    momentum = IsKeyDown(KEY_LEFT_CONTROL) ? this->lerp(momentum, sprintSpeed, transitionFactor) : this->lerp(momentum, walkSpeed, transitionFactor);

    // // Check if Ctrl key is pressed to determine the momentum
    // momentum = IsKeyDown(KEY_LEFT_CONTROL) ? sprintSpeed : walkSpeed;

    switch (switchInt)
    {
    case  1:
        this->position.y -= momentum; // Up
        break;

    case  2:
        this->position.y += momentum; // Down
        break;

    case  3:
        this->position.x -= momentum; // Left
        break;
    
    case  4:
        this->position.x += momentum; // Right
        break;
    }
}

void Player::Move(float deltaTime)
{
    if (IsKeyDown(KEY_W)) this->adjustPosition(deltaTime, 1);
    else if (IsKeyDown(KEY_S)) this->adjustPosition(deltaTime, 2);
    if (IsKeyDown(KEY_A)) this->adjustPosition(deltaTime, 3);
    else if (IsKeyDown(KEY_D)) this->adjustPosition(deltaTime, 4);

	std::cout << "speed " << momentum << std::endl;

    // std::cout << "x = " << this->position.x <<  " y = " << this->position.y << std::endl;
}
