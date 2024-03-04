#ifndef PLAYER_H
#define PLAYER_H

#include <entity.h>
#include <iostream>

///Class Definition: Your Player class inherits from a Entity 
class Player : public Entity 
{
public:
	Player();
	virtual ~Player();
	virtual void update(float deltaTime);

	Vector3 velocity;
	double _Sqrt2 = sqrt(2);

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
	void clamp();

protected:
	// Rectangle player;
	// Texture2D playerTexture;
	// Image player3;

private:
	Rectangle kaas;
	Texture2D playerTexture;

};

#endif /* PLAYER_H */