#include <myscene.h>

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    player = new Player();
    block = new Block();

    block->position = Vector3{600, 100};
    player->position = Vector3{width / 2.0f, height / 2.0f};

    addEntity(player);
    addEntity(block);
}   

MyScene::~MyScene() 
{
    removeEntity(player);
    removeEntity(block);
}

void MyScene::update(float deltaTime) 
{   
    // player->draw(0);
    // player->update(deltaTime); //draw player *TEMP
    // block->update(deltaTime); //draw player *TEMP
    // Movement(deltaTime);
}

// bool MyScene::collision(Entity *collisionA, Entity *collisionB) {
//     // Check for horizontal collision
//     bool collisionX = collisionA->position.x < collisionB->position.x + collisionB->width &&
//                        collisionA->position.x + collisionA->width > collisionB->position.x;
//     // Check for vertical collision
//     bool collisionY = collisionA->position.y < collisionB->position.y + collisionB->height &&
//                        collisionA->position.y + collisionA->height > collisionB->position.y;
//     // Return true if there is a collision on both axes
//     return collisionX && collisionY;
// }
//             return (playerA->position.x < playerB->position.x + playerB->sprite()->size.x * playerB->scale.x &&
// 			playerA->position.x + playerA->sprite()->size.x * playerA->scale.x > playerB->position.x &&
// 			playerA->position.y < playerB->position.y + playerB->sprite()->size.y * playerB->scale.y &&
// 			playerA->position.y + playerA->sprite()->size.y * playerA->scale.y > playerB->position.y);
// }

// void MyScene::Zoom(float deltaTime)
// {
//     if (GetMouseWheelMove())
//     {
//         playerCam->zoom += ((float)GetMouseWheelMove()*0.05f);
//     }
// }