#ifndef MYSCENE_H
#define MYSCENE_H

#include "raylib.h" 

#include <fstream> // For file input/output operations
#include <sstream> // For string stream operations
#include <iostream> // For standard input/output operations

// Include custom headers for game components
#include <scene.h> // Header for the Scene class
#include <player.h> // Header for the Player class
#include <enemy.h> // Header for the Enemy class
#include <block.h> // Header for the Block class

//Class Definition: Your MyScene class inherits from a Scene
/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	// Constructor for MyScene, initializing with width, height, and window name
    MyScene(uint16_t width, uint16_t height, const char* windowName);
    // Destructor for MyScene, ensuring proper cleanup of resources
    virtual ~MyScene();

    // Update method for MyScene, called every frame
    virtual void update(float deltaTime);
    
    // Method to check for collisions between two entities
    bool collision(Entity* collisionA, Entity* collisionB);

    // Angle variable used for rotation calculations
    float angle = 0.0f;
    // Method to rotate one entity around another entity
    void rotateAround(Entity* entityA, Entity* entityB, float deltaTime);

    // Method to set a random position for enemies when a specific key is pressed
	bool iskeypressed;
    void randomEnemyPos(int keycode, float deltaTime);

private:
 	// Pointers to game entities
	Player* player;
	Block* block;
	Block* sword;
	// Vector of pointers to Enemy entities
    std::vector<Enemy *> enemies; // Vector of enemies in the scene

};

#endif /* SCENE00_H */
