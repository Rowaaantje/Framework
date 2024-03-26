#ifndef ENEMY_H
#define ENEMY_H

#include <entityanimation.h>
#include <player.h>

class Enemy : public EntityAnimation 
{
public:
    /// @brief Constructor for the Enemy class
    /// Initializes a new instance of the Enemy class with a reference to the Player object.
    /// @param player A pointer to the Player object.
    Enemy(Player* player); 

    /// @brief Destructor for the Enemy class
    /// Cleans up resources when an instance of the Enemy class is destroyed.
    virtual ~Enemy();

    /// @brief Updates the enemy's state based on the elapsed time
    /// @param deltaTime The time elapsed since the last frame.
    void update(float deltaTime);

    /// @brief Sets a random position for the enemy
    /// @param deltaTime The time elapsed since the last frame.
    void randomPosition(float deltaTime);

    /// @brief Defines the behavior of the enemy based on the elapsed time
    /// @param deltaTime The time elapsed since the last frame.
    void behaviour(float deltaTime);

private:
    /// @brief A pointer to the Player object.
    Player* player;

    /// @brief Time variable used for random positioning.
    float sTime;
    /// @brief Countdown time for random positioning.
    float countdownTime;
};

#endif /* ENEMY_H */