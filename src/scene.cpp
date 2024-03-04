#include <scene.h>

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

void Scene::tick(float deltaTime)
{
    BeginDrawing();
        this->updateEntity(this, deltaTime);
        this->update(deltaTime);
        // draw();
    EndDrawing();
}

void Scene::draw()
{
}

void Scene::updateEntity(Entity* child, float deltaTime)  
{
    // update() all childeren 
    for (Entity* child : this->children()) {
        child->update(deltaTime);
    }

    // Clear the background
    ClearBackground(BLACK);
    DrawFPS(25, 25);

    //draw all children 
    for (Entity* child : this->children())
    {
        DrawTexture(child->texture(), child->position.x, child->position.y, child->color());
    }
}