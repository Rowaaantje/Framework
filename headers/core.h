/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef CORE_H
#define CORE_H


#include <scene.h>

class Core
{
public:
	Core();
	virtual ~Core();

    /// @brief Runs the game loop for a given scene.
    // 	This method starts the game loop, rendering the specified scene and updating the game state.
	/// @param scene A pointer to the Scene object to be rendered.
	void run(Scene* scene);

private:
	float _calculateDeltaTime();
	float deltaTime; ///< @brief deltaTime member

};

#endif /* CORE_H */
