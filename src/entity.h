#ifndef Entity_H
#define Entity_H

#include "raylib.h"
#include "config.h"
#include <iostream>

class Entity 
{
public:
	/// @brief Constructor of Entity
	Entity();
	/// @brief Destructor of Entity
	virtual ~Entity();

	/// @brief Update the entity.
	virtual void update(float deltaTime);

	void draw(float deltaTime);

	float width; // Rectangle width
    float height; // Rectangle height

	Vector2 position;
	Vector2 rotation;
	Vector3 scale;

	

    /// @brief Removes an entity from the scene
	/// @return void
    void removeEntity(Entity* entity);

private:
};

#endif /* Entity_H */
