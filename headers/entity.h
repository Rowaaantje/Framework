#ifndef Entity_H
#define Entity_H

#include "raylib.h"
#include <config.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

class Entity 
{
public:
	/// @brief Constructor of Entity
	Entity();
	/// @brief Destructor of Entity
	virtual ~Entity();

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

	/// @brief Update the entity.
	virtual void update(float deltaTime) = 0;
	
	void draw(float deltaTime);
	/// @brief Adds an entity to the scene
	/// @return void
    void addEntity(Entity* entity);
	/// @brief Removes an entity from the scene
	/// @return void
    void removeEntity(Entity* entity);

protected:
	std::vector<Entity*> entities;

private:
};

#endif /* Entity_H */
