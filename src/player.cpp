#include <player.h>

Player::Player() : EntityAnimation()
{   
    this->addTexture("assets/playerWalk.png");
    this->renderMethod = 1;
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
    this->setTextureColor(WHITE); 

    this->spriteCount = 4;
    this->spriteSize = 16;
    this->spriteFps = 4;
    this->spriteTime = 1.0f / spriteFps;

    isMoving = false;
    sprintSpeed = 2.5f;
    walkSpeed = 1.0f;
    momentum = 0.0f;
}   

Player::~Player() 
{   

}

void Player::update(float deltaTime) 
{   
  move(deltaTime);
  clamp();
}

float Player::lerp(float start, float end, float factor) {
    return start + factor * (end - start);
}

void Player::adjustPosition(float deltaTime, int switchInt)
{   
    // Adjust this value to control the speed of the transition
    float transitionFactor =  0.1f;
    
    // Gradually increase momentum towards sprintSpeed  else Gradually decrease momentum towards walkSpeed
    momentum = IsKeyDown(KEY_LEFT_CONTROL) ? this->lerp(momentum, sprintSpeed, transitionFactor) : this->lerp(momentum, walkSpeed, transitionFactor);

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

void Player::move(float deltaTime)
{
    if (IsKeyDown(KEY_W)) {
      this->adjustPosition(deltaTime, 1);
      animate(deltaTime);
    }
    else if (IsKeyDown(KEY_S)) {
      this->adjustPosition(deltaTime, 2);
      animate(deltaTime);
    }
    if (IsKeyDown(KEY_A)) {
      this->adjustPosition(deltaTime, 3);
      animate(deltaTime);
    }
    else if (IsKeyDown(KEY_D)) {
      this->adjustPosition(deltaTime, 4);
      animate(deltaTime);
    }
}

void Player::animate(float deltaTime)
{
  spriteTimer -= deltaTime;
    if(spriteTimer < 0)
    {
      spriteTimer = spriteTime;
      spriteIndex++;
      if (spriteIndex >= spriteCount)
      {
          spriteIndex = 0;
      }
    }
}

void Player::clamp()
{
    //drawtexture
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

  //for drawtexturePro textures
  /*if (this->dest.x < 0)
  {
    this->dest.x = 0;
  }
  if (this->dest.y < 0)
  {
    this->dest.y = 0;
  }
  if (this->dest.x + this->origin.x > SCREEN_WIDTH)
  {
    this->dest.x = SCREEN_WIDTH - this->origin.x;
  }
  if (this->dest.y + this->origin.y > SCREEN_HEIGHT)
  {
    this->dest.y = SCREEN_HEIGHT - this->origin.y;
  }*/
}