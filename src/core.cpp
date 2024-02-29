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
	_calculateDeltaTime();

	scene->updateScene(_deltaTime);
}

float Core::_calculateDeltaTime()
{
	_deltaTime = GetFrameTime();

	return _deltaTime;
}