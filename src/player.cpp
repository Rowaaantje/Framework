#include <player.h>

Player::Player() : Entity()
// , player({ position.x, position.y, scale.x, scale.y })
{
    synchronizeWithEntity();
    this->addTexture("assets/player1.png");
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
    this->setTextureColor(WHITE);  

	isMoving = false;
    sprintSpeed = 5.0f;
	walkSpeed = 2.0f;
    momentum = 0.0f;
}   

Player::~Player() 
{   
	// deconstruct and delete the Tree
    // UnloadTexture(playerTexture);
}

void Player::draw(float deltaTime) 
{
    // Assuming you have a method to get the texture by name

    // DrawRectangleRec(kaas, SEMI_TRANSPARENT_BLACK); 
    // Vector2 center = { kaas.x + kaas.width / 2.0f, kaas.y + kaas.height / 2.0f };

    // DrawRectanglePro(kaas, { kaas.x / playerTexture.width, kaas.y / playerTexture.height }, 0.0f,  SEMI_TRANSPARENT_BLACK);
    
    // Draw the texture centered within the rectangle
    // DrawTexture(playerTexture, center.x - this->size().x / 2, center.y - this->size().y / 2, WHITE);

    // Draw the texture centered within the rectangle
    // DrawTexture(kaas, center.x - texture.width().x / 2, center.y - texture.height / 2, SEMI_TRANSPARENT_BLACK);
    
    // DrawTexture(playerTexture, player.x, player.y, WHITE);
}

void Player::synchronizeWithEntity()
{
    kaas.x = this->position.x;
    kaas.y = this->position.y;
    kaas.width = this->scale.x;
    kaas.height = this->scale.y;
}

void Player::update(float deltaTime) 
{
    Move(deltaTime);
    clamp();
    
    synchronizeWithEntity();
    draw(deltaTime);
    // std::cout << "x = " << this->position.x <<  " y = " << this->position.y << std::endl;
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
    
	// std::cout << "speed " << momentum << std::endl;
}

void Player::clamp()
{
  if (this->position.x < 0)
  {
    this->position.x = 0;
  }
  if (this->position.y < 0)
  {
    this->position.y = 0;
  }
  if (this->position.x + this->size().x > SCREEN_WIDTH)
  {
    this->position.x = SCREEN_WIDTH - this->size().x;
  }
  if (this->position.y + this->size().y > SCREEN_HEIGHT)
  {
    this->position.y = SCREEN_HEIGHT - this->size().y;
  }
}
