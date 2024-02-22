#include "entity.h"

Entity::Entity() 
{
    Vector2 position {0.0f, 0.0f};
	Vector2 rotation {0.0f, 0.0f};
	Vector3 scale {1.0f, 1.0f, 0.0f};
}   

Entity::~Entity() 
{
	// deconstruct and delete the Tree
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



