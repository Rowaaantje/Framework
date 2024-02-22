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

void Scene::update(float deltaTime)
{
    
}

void Scene::run(float deltaTime)
{
    BeginDrawing();

        update(deltaTime);
        draw(deltaTime);
        
    EndDrawing();
}

void Scene::draw(float deltaTime)
{
    // Clear the background
    ClearBackground(GREEN);
    updateEntity(this, deltaTime);
    DrawFPS(25, 25);
}

void Scene::addEntity(Entity* entity)
{
    entities.push_back(entity);
}

void Scene::updateEntity(Entity* entity, float deltaTime) 
{
    entity->update(deltaTime);

    //update() all childeren 
    // for (Entity* entity : entities) {
    //     entity->draw(deltaTime);
    // }
}
