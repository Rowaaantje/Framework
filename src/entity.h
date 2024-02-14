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
	// Pure virtual method to be implemented by derived classes

	float width; // Rectangle width
    float height;// Rectangle height

	Vector2 position {0.0f, 0.0f};
	Vector2 rotation {0.0f, 0.0f};
	Vector3 scale {1.0f, 1.0f, 0.0f};

private:

};

#endif /* Entity_H */
