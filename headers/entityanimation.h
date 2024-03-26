#ifndef ENTITYANIMATION_H
#define ENTITYANIMATION_H

#include <entity.h>

/// @class EntityAnimation
/// @brief A class representing an animated entity in the game.
/// 
/// This class extends the Entity class to include animation functionality.
/// It manages the animation state, including the current sprite, animation speed,
/// and the total number of sprites.
class EntityAnimation: public Entity
{
public:
    /// @brief Default constructor for EntityAnimation.
    EntityAnimation();

    /// @brief Virtual destructor for EntityAnimation.
    virtual ~EntityAnimation(); 

    /// @brief Updates the animation based on the delta time.
    /// @param deltaTime The time elapsed since the last frame.
    void update(float deltaTime);

    /// @brief Overrides the renderSelect method from the Entity class.
    void renderSelect() override;

    /// @brief Total number of sprites for the animation.
    float spriteCount; 

    /// @brief Size of each sprite in the animation.
    float spriteSize; 

    /// @brief Frames per second for the animation.
    float spriteFps; 

    /// @brief Time per frame for the animation.
    float spriteTime; 

    /// @brief Current sprite index for the animation.
    int spriteIndex; 

    /// @brief Timer for the sprite animation.
    float spriteTimer = spriteTime; 

private:

};

#endif /* ENTITYANIMATION_H */
