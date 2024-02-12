#ifndef MYSCENE_H
#define MYSCENE_H


#include <fstream>
#include <sstream>
#include <iostream>

#include "raylib.h"
#include "player.h"
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
	
private:
	Player* player;
	Block* block;

};

#endif /* SCENE00_H */
