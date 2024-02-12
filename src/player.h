#ifndef Player_H
#define Player_H

#include "entity.h"
#include <iostream>

///Class Definition: Your Player class inherits from a Scene
/// @brief The Player class is the Scene implementation.
class Player : public Entity 
{
public:
	Player();
	virtual ~Player();
	virtual void update(float deltaTime);
	
	Vector3 scale {100, 100, 0};
	Vector2 newScaleX {0.0, 0.0}; // updating to newScaleX
	Vector2 newScaleY {0.0, 0.0}; // updating to newScaleY


	Rectangle player;
	
private:

};

#endif /* Player_H */
