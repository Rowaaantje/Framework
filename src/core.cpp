#include <core.h>

Core::Core()
{
	_deltaTime = 0;
}

Core::~Core()
{

}

void Core::run(Scene* scene)
{
	// update our _deltaTime
	_calculateDeltaTime();

	scene->tick(_deltaTime);
}

float Core::_calculateDeltaTime()
{
	_deltaTime = GetFrameTime();

	return _deltaTime;
}