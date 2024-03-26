#ifndef SWORD_H
#define SWORD_H

// Include the EntityAnimation header file to inherit its properties and methods
#include <entityanimation.h>

/// @class Sword
/// @brief Represents a sword entity in the game, inheriting animation capabilities from EntityAnimation.
class Sword : public EntityAnimation 
{
public:
    /// @brief Constructor for the Sword class
    /// Initializes a new instance of the Sword class.
    Sword();

    /// @brief Destructor for the Sword class
    /// Cleans up resources when an instance of the Sword class is destroyed.
    virtual ~Sword();

    /// @brief Updates the sword's state based on the elapsed time
    /// @param deltaTime The time elapsed since the last frame.
    virtual void update(float deltaTime);

    /// @brief Draws the sword on the screen
    /// @param deltaTime The time elapsed since the last frame.
    void draw(float deltaTime);

private:
    // Private members and methods can be added here
};

#endif /* SWORD_H */