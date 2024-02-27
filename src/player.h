#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <iostream>

///Class Definition: Your Player class inherits from a Entity 
class Player : public Entity 
{
public:
	Player();
	virtual ~Player();
	virtual void update(float deltaTime);

	Vector2 velocity;

	bool isMoving;
    float momentum;
	float walkSpeed = 0.0f;
	float sprintSpeed = 0.0f;

	Vector2 newScaleX {0.0f, 0.0f}; // updating to newScaleX
	Vector2 newScaleY {0.0f, 0.0f}; // updating to newScaleY

	void draw(float deltaTime);
	void adjustPosition(float deltaTime, int switchInt);
	void Move(float deltaTime);
	float lerp(float start, float end, float factor);
	void synchronizeWithEntity();
	void handleplayer(float deltatime);

protected:
	Rectangle player;
	
private:

};

#endif /* PLAYER_H */