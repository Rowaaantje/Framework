#ifndef MYSCENE_H
#define MYSCENE_H

#include "raylib.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <scene.h>
#include <player.h>
#include <enemy.h>
#include <block.h>

///Class Definition: Your MyScene class inherits from a Scene
/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	MyScene(uint16_t width, uint16_t height, const char* windowName);
	virtual ~MyScene();

	virtual void update(float deltaTime);
	
	bool collision(Entity* collisionA, Entity* collisionB);
	void Zoom(float deltaTime);

    float angle = 0.0f;

	void rotate(Entity* entityA, Entity* entityB, float deltaTime);

private:
	Player* player;
	Enemy* enemy;
	Block* block;
	Block* coli;

};

#endif /* SCENE00_H */
