#ifndef PLAYER_H
#define PLAYER_H

#include <entityanimation.h>
#include <iostream>

/// @class Player
/// @brief A class representing the player entity in the game.
class Player : public EntityAnimation 
{
public:
    /// @brief Default constructor for Player.
    Player();
    
    /// @brief Virtual destructor for Player.
    virtual ~Player();

    /// @brief Updates the player based on the delta time.
    /// @param deltaTime The time elapsed since the last frame.
    virtual void update(float deltaTime) override;
    
    /// @brief Vector3 representing the player's velocity.
    Vector3 velocity;

    /// @brief Boolean indicating if the player is currently moving.
    bool isMoving;
    
    /// @brief Float representing the player's momentum.
    float momentum;
    
    /// @brief Float representing the player's walk speed.
    float walkSpeed;
    
    /// @brief Float representing the player's sprint speed.
    float sprintSpeed;

    /// @brief Adjusts the player's position based on the delta time and switch integer.
    /// @param deltaTime The time elapsed since the last frame.
    /// @param switchInt An integer used to switch between different movement states.
    void adjustPosition(float deltaTime, int switchInt);
    
    /// @brief Moves the player based on the delta time.
    /// @param deltaTime The time elapsed since the last frame.
    void move(float deltaTime);
    
    /// @brief Animates the player based on the delta time.
    /// @param deltaTime The time elapsed since the last frame.
    void animate(float deltaTime);

    /// @brief Linear interpolation function.
    /// @param start The start value.
    /// @param end The end value.
    /// @param factor The interpolation factor.
    /// @return The interpolated value.
    float lerp(float start, float end, float factor);
    
    /// @brief Synchronizes the player's position with the entity's position.
    void synchronizeWithEntity();
    
    /// @brief Clamps the player's position to prevent it from going out of bounds.
    void clamp();

private:
	
};

#endif /* PLAYER_H */
