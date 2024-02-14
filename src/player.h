#ifndef PLAYER_H
#define PLAYER_H

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

	Camera2D camera = { 0 };
	void draw(float deltaTime);

protected:
	Rectangle player;
	
private:

};

#endif /* PLAYER_H */
