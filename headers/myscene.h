/*
* Copyright 2024 Rowan Pijnaker
*/

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
#include <sword.h> // Header for the Block class

/// @class MyScene
/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
    /// @brief Constructor for MyScene, initializing with width, height, and window name.
    /// @param width The width of the scene.
    /// @param height The height of the scene.
    /// @param windowName The name of the window.
    MyScene(uint16_t width, uint16_t height, const char* windowName);

    /// @brief Destructor for MyScene, ensuring proper cleanup of resources.
    virtual ~MyScene();

    /// @brief Update method for MyScene, called every frame.
    /// @param deltaTime The time elapsed since the last frame.
    virtual void update(float deltaTime);
    
    /// @brief Angle variable used for rotation calculations.
    float angle = 0.0f;
    /// @brief Indicates whether a specific key has been pressed.
    bool iskeypressed;

    /// @brief Method to check for collisions between two entities.
    /// @param collisionA The first entity to check for collision.
    /// @param collisionB The second entity to check for collision.
    /// @param specific Whether to perform a specific collision check.
    /// @return true if a collision is detected, false otherwise.
    bool collision(Entity* collisionA, Entity* collisionB, bool specific);

    /// @brief Method to rotate one entity around another entity.
    /// @param entityA The entity to rotate.
    /// @param entityB The entity around which entityA will be rotated.
    /// @param deltaTime The time elapsed since the last frame.
    void rotate(Entity* entityA, Entity* entityB, float deltaTime);

    /// @brief Method to update the camera.
    /// @param deltaTime The time elapsed since the last frame.
    void updateCamera(float deltaTime);

    /// @brief Method to set a random position for enemies when a specific key is pressed.
    /// @param keycode The key code of the key pressed.
    /// @param deltaTime The time elapsed since the last frame.
    void randomEnemyPos(int keycode, float deltaTime);

    void spawner(float deltatime);

private:
    // Pointers to game entities
    Player* player;
    Sword* sword;
    // Vector of pointers to Enemy entities
    std::vector<Enemy *> enemies; // Vector of enemies in the scene
};

#endif /* MYSCENE_H */