#include "entity.h"

Entity::Entity() 
{
    position = Vector3{0.0f, 0.0f, 0.0f};
    rotation = Vector3{0.0f, 0.0f, 0.0f};
    scale = Vector3{100.0f, 100.0f, 0.0f};
}   

Entity::~Entity() 
{
	
}

void Entity::update(float deltaTime) 
{
   
}

void Entity::draw(float deltaTime)
{

}

void Entity::removeEntity(Entity* entity)
{
    delete entity;
}



