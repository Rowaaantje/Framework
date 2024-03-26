#include <sword.h>

Sword::Sword() : EntityAnimation()
{
    this->addTexture("assets/sword_loyal.png");
    this->renderMethod = 1;
    this->setTextureColor(WHITE); 
}   

Sword::~Sword() 
{
    
}

void Sword::draw(float deltaTime) 
{

}

void Sword::update(float deltaTime) 
{

}
