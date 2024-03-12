#ifndef PLAYER_H
#define PLAYER_H

#include <entity.h>
#include <iostream>

#define PLAYER_SIZE 16
#define PLAYER_COUNT 4
#define PLAYER_FPS 4
#define PLAYER_TIME 1.0f / PLAYER_FPS

///Class Definition: Your Player class inherits from a Entity 
class Player : public Entity 
{
public:
	Player();
	virtual ~Player();
	virtual void update(float deltaTime);

	Vector3 velocity;

	bool isMoving;
    float momentum;
	float walkSpeed = 0.0f;
	float sprintSpeed = 0.0f;

	Vector2 newScaleX {0.0f, 0.0f}; // updating to newScaleX
	Vector2 newScaleY {0.0f, 0.0f}; // updating to newScaleY

	
	void adjustPosition(float deltaTime, int switchInt);
	void Move(float deltaTime);
	void animate(float deltaTime);
	void updateSourceRectangle();

	float lerp(float start, float end, float factor);
	void synchronizeWithEntity();
	void clamp();


	//not yet needed :3
	Rectangle getSource() { return source; };
	Rectangle getDest() { return dest; };
	Vector2 getOrigin() { return origin; };


protected:
	//animplayer
	Texture2D atlas;
	int spriteIndex = 0;
	float playerTimer = PLAYER_TIME;

private:
	
};

#endif /* PLAYER_H */