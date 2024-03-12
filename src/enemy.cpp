#include <enemy.h>

Enemy::Enemy(Player* player) : Entity()
{
	this->addTexture("assets/player1.png");
    this->renderMethod = 0;
    this->setTextureColor(INVINSIBLE); 
    /*cast the time_t value to an unsigned int before 
    passing it to srand. This ensures that the value is correctly converted*/
    srand(static_cast<unsigned int>(time(NULL)));
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
    
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
