// core.cpp

#include "core.h"

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

	scene->updateScene((float)_deltaTime);
}

double Core::_calculateDeltaTime()
{
	static double lastTime = GetTime();
	double startTime = GetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}