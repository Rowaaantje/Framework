#include <player.h>
#include <rshapes.c> //draw

Player::Player() : Entity()
{   
    this->addTexture("assets/playerWalk.png");
    this->renderMethod = 1;
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
    this->setTextureColor(WHITE); 
    
    //if animation is needed add update the soucre 

    // Define the source rectangle on the texture. This specifies which part of the texture to draw.
    // spriteIndex * PLAYER_SIZE determines the x-coordinate of the top-left corner of the source rectangle.
    // This is useful for animating sprites by changing the source rectangle to different parts of the texture.
    this->source = {(float)spriteIndex * PLAYER_SIZE, 0, PLAYER_SIZE, PLAYER_SIZE};

    // Define the destination rectangle on the screen. This specifies where and how large the source rectangle should be drawn.
    // SCREEN_WIDTH/2 and SCREEN_HEIGHT/2 center the destination rectangle on the screen.
    this->dest = {SCREEN_WIDTH/2, SCREEN_WIDTH/2, PLAYER_SIZE, PLAYER_SIZE};

    // Define the origin point for rotation and scaling. This point is used as the pivot point for transformations.
    // dest.width/2 and dest.height/2 set the origin to the center of the destination rectangle, ensuring that the sprite scales and rotates around its center.
    this->origin = {dest.width/2, dest.height/2}; // Set the origin to the center of the destination rectangle

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
    // DrawTexturePro(atlas, this->source, this->dest,  this->origin, 0, BLACK);
    //We need to update the source rectangle every time spriteIndex changes. 
    
    
    Move(deltaTime);
    clamp();


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

    switch (switchInt)
    {
    case  1:
        this->dest.y -= momentum; // Up
        break;

    case  2:
        this->dest.y += momentum; // Down
        break;

    case  3:
        this->dest.x -= momentum; // Left
        break;
    
    case  4:
        this->dest.x += momentum; // Right
        break;
    }
}

void Player::Move(float deltaTime)
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
  playerTimer -= deltaTime;
    if(playerTimer < 0)
    {
        playerTimer = PLAYER_TIME;
        spriteIndex++;
        if (spriteIndex >= PLAYER_COUNT)
        {
            spriteIndex = 0;
        }
      updateSourceRectangle();
    }
}

void Player::updateSourceRectangle() 
{
    this->source.x = (float)spriteIndex * PLAYER_SIZE;
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
  if (this->dest.x < 0)
  {
    this->dest.x = 0;
  }
  if (this->dest.y < 0)
  {
    this->dest.y = 0;
  }
  if (this->dest.x + this->source.x > SCREEN_WIDTH)
  {
    this->dest.x = SCREEN_WIDTH - this->source.x;
  }
  if (this->dest.y + this->source.y > SCREEN_HEIGHT)
  {
    this->dest.y = SCREEN_HEIGHT - this->source.y;
  }

}