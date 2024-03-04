#include <enemy.h>

Enemy::Enemy() : Entity()
{
	this->addTexture("assets/player1.png");
    this->position.x = 200;
    this->position.y = 200;
    this->setTextureColor(WHITE); 
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
    
}


