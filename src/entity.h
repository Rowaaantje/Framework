#ifndef Entity_H
#define Entity_H

#include "config.h"
#include <iostream>
#include "raylib.h"

///Class Definition: Your Player class inherits from a Scene
/// @brief The Player class is the Scene implementation.
class Entity 
{
public:
	Entity();
	virtual ~Entity();
	virtual void update(float deltaTime);

	float width; // Rectangle width
    float height;// Rectangle height

	Vector2 position {0.0f, 0.0f};
	Vector2 rotation {0.0f, 0.0f};
	Vector3 scale {1.0f, 1.0f, 0.0f};

private:

};

#endif /* Entity_H */
