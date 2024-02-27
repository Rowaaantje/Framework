#include "scene.h"

Scene::Scene(uint16_t width, uint16_t height, const char* windowName) : Entity() 
{
	std::cout << "################ new Scene ################" << std::endl;
	
    // Initialize the window for raylib
	InitWindow(width, height, windowName);
}

Scene::~Scene()
{
    CloseWindow();
}

void Scene::updateScene(float deltaTime)
{
    BeginDrawing();

        updateEntity(deltaTime);
        draw(deltaTime);
        
    EndDrawing();
}

void Scene::draw(float deltaTime)
{
    // Clear the background
    ClearBackground(GREEN);
    // updateEntity(this, deltaTime);
    for (Entity* entity : entities) {
        entity->draw(deltaTime);
    }
    DrawFPS(25, 25);
}

void Scene::addEntity(Entity* entity)
{
    entities.push_back(entity);
}

void Scene::updateEntity(float deltaTime)  
{
    // update() all childeren 
    for (Entity* entity : entities) {
        entity->update(deltaTime);
    }
}
