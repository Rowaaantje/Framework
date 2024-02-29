#ifndef CORE_H
#define CORE_H


#include "scene.h"

class Core
{
public:
	Core();
	virtual ~Core();

	void run(Scene* scene);

	/// @brief get deltaTime
	/// double internally, cast to float. glm and OpenGL expect floats.
	/// @return float deltaTime
	// float deltaTime() { return (float)_deltaTime; };

private:
	float _calculateDeltaTime();
	float _deltaTime; ///< @brief deltaTime member

};

#endif /* CORE_H */
