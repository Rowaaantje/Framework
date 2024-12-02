/*
* @todo
* why should enemy know everyting about player?
* only give the enemy access to the position of player
*/

#include <enemy.h>

Enemy::Enemy(Player* p1) : EntityAnimation()
{
	this->addTexture("assets/enemy.png");
    this->renderMethod = 1;
    this->setTextureColor(INVINSIBLE); 
    /*cast the time_t value to an unsigned int before 
    passing it to srand. This ensures that the value is correctly converted*/
    srand(static_cast<unsigned int>(time(NULL)));
    this->player = p1;
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
    behaviour(deltaTime);
}

void Enemy::randomPosition(float deltaTime)
{
    countdownTime = rand() % 4 + 1;
    
    if (sTime > 0)
	{
		sTime -= 1 * deltaTime;
	}
	else
	{
        // Generate random x and y coordinates within the screen bounds
        this->position.x = rand() % SCREEN_WIDTH + 20.0f;
        this->position.y = rand() % SCREEN_HEIGHT+ 20.0f;
    }
    sTime = countdownTime;
}

void Enemy::behaviour(float deltaTime)
{
    float speed = 0.5f;

    // Calculate the direction vector from the enemy to the player
    Vector2 direction = {player->position.x - this->position.x, player->position.y - this->position.y};

    // Move the enemy towards the player
    this->position.x += direction.x * speed * deltaTime;
    this->position.y += direction.y * speed * deltaTime;
}