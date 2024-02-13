#ifndef MYSCENE_H
#define MYSCENE_H

#include "config.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "raylib.h"
#include "player.h"
#include "cameraF.h"
#include "block.h"

///Class Definition: Your MyScene class inherits from a Scene
/// @brief The MyScene class is the Scene implementation.
class MyScene // : public Scene
{
public:
	MyScene();
	virtual ~MyScene();
	virtual void update(float deltaTime);
	void Movement(float deltaTime);
	bool collision(Entity* collisionA, Entity* collisionB);
	void Zoom(float deltaTime);


private:
	Player* player;
	Block* block;

};

#endif /* SCENE00_H */
