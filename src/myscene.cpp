#include <myscene.h>

// #include <rshapes.c> //rember

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    player = new Player();
    enemy = new Enemy();
    block = new Block();
    coli = new Block();


    // block->position = Vector3{600, 100};
    // player->position = Vector3{width / 2.0f, height / 2.0f};
    addChild(player);
    addChild(enemy);
    addChild(block);
    addChild(coli);
}   

MyScene::~MyScene() 
{
    removeChild(player);
    removeChild(enemy);
    removeChild(block);
    removeChild(coli);
}

void MyScene::update(float deltaTime) 
{   
    rotate(player, block, deltaTime);

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        angle += 10.0f;
    }
    player->drawImageSize(SEMI_TRANSPARENT_BLACK, deltaTime);

    // Check for collision and handle it
    if (collision(player, block)) {
        std::cout << "Colliding " << std::endl;
    } 

    if (collision(block, coli)) {
        // std::cout << "coli " << std::endl;
        coli->setTextureColor(BLACK);
    } 
        
}

// Check collision between two Textures
bool MyScene::collision(Entity* collisionA, Entity* collisionB) {
    
    bool collision = false;

    // Check for collision

    // The -15.0f adjustment on both the x-coordinates && y-coordinates(-5.0f) is specific to the dimensions of the .png image used for these entities.
    // This adjustment is necessary because the image dimensions might not perfectly align with the entity's bounding box,
    // especially if the image has transparent areas or if the bounding box is slightly larger than the visible part of the image.
    // By subtracting 15.0f from the x-coordinates, we ensure that the collision detection logic accounts for this discrepancy.
    return ((collisionA->position.x < (collisionB->position.x + collisionB->size().x - 15.0f) && 
            (collisionA->position.x  + collisionA->size().x - 15.0f) > collisionB->position.x) &&
            (collisionA->position.y < (collisionB->position.y + collisionB->size().y - 5.0f) && 
            (collisionA->position.y + collisionA->size().y - 5.0f) > collisionB->position.y));

    collision = true;

    return collision;

	// return (collisionA->position.x < collisionB->position.x + collisionB->size().x * collisionB->scale.x &&
	// 		collisionA->position.x + collisionA->size().x * collisionA->scale.x > collisionB->position.x &&
	// 		collisionA->position.y < collisionB->position.y + collisionB->size().y * collisionB->scale.y &&
	// 		collisionA->position.y + collisionA->size().y * collisionA->scale.y > collisionB->position.y);


}

void MyScene::rotate(Entity* entityA, Entity* entityB, float deltaTime)
{
    // Define the center of the circle and the radius
    Vector2 center = { entityA->position.x, entityA->position.y }; // Example center point
    float radius = 50.0f; // Example radius

    // Define the speed of the movement around entityA
    float speed = 5.0f; // Example speed
    
    // Update the angle
    angle += speed * deltaTime;

    // Calculate the new position using the updated angle and the radius
    entityB->position.x = center.x + radius * cos(angle);
    entityB->position.y = center.y + radius * sin(angle);
}
// void MyScene::Zoom(float deltaTime)
// {
//     if (GetMouseWheelMove())
//     {
//         playerCam->zoom += ((float)GetMouseWheelMove()*0.05f);
//     }
// }