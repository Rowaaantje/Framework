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

void Scene::draw(float deltaTime)
{
    // Start drawing
    BeginDrawing();
    
    // Clear the background
    ClearBackground(GREEN);

    DrawFPS(300,  300);
    drawAllEntities(deltaTime);
    
    // End drawing
    EndDrawing();
}

void Scene::run(float deltaTime)
{
    while (!WindowShouldClose())
    {
        update(deltaTime);
        draw(deltaTime);
    }
}

void Scene::drawAllEntities(float deltaTime) {
    // for (Entity* entity : entities) {
    //     entity->draw();
    // }
}

void Scene::addEntity(Entity* entity)
{
    entities.push_back(entity);
}

