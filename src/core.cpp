#include <core.h>

Core::Core()
{
}

Core::~Core()
{

}

void Core::run(Scene* scene)
{
	// update our _deltaTime
	deltaTime = GetFrameTime();
	// _calculateDeltaTime();
	scene->tick(deltaTime);
}

float Core::_calculateDeltaTime()
{
	deltaTime = GetFrameTime();

	return deltaTime;
}