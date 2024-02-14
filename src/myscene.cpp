#include "myscene.h"

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    player = new Player();
    block = new Block();

    block->position = Vector2{600, 100};
    player->position = Vector2{100, 100};

    addEntity(player);
    addEntity(block);
}   

MyScene::~MyScene() 
{
    delete player;
    delete block;
}

void MyScene::update(float deltaTime) 
{   
    // player->draw(0);
    player->update(deltaTime);
    block->update(deltaTime);
    Movement(deltaTime);

    //playerCam
    // Zoom(deltaTime);

    if (collision(player, block))
	{   
       std::cout <<"syssy"<<std::endl;
	}
}

void MyScene::Movement(float deltaTime)
{
#ifndef Player

    if (IsKeyDown(KEY_S)) player->position.y += 3.0f;
    else if (IsKeyDown(KEY_W)) player->position.y -= 3.0f;
    if (IsKeyDown(KEY_D)) player->position.x += 3.0f;
    else if (IsKeyDown(KEY_A)) player->position.x -= 3.0f;

    if (IsKeyDown(KEY_Q)) 
    {
        player->scale.x -= 1;
        std::cout << "scale x " << player->scale.x <<  std::endl;
    }
    else if (IsKeyDown(KEY_E)) 
    {
        player->scale.y -= 1;
        std::cout << "scale y " << player->scale.y <<  std::endl;
    }
    else
    {
        player->scale.y =  100 ;
        player->scale.x =  100 ;
    }
#endif /* Movement */

// #ifndef Block

//      if (IsKeyDown(KEY_DOWN)) block->position.y += 3.0f;
//     else if (IsKeyDown(KEY_UP)) block->position.y -= 3.0f;
//     if (IsKeyDown(KEY_RIGHT)) block->position.x += 3.0f;
//     else if (IsKeyDown(KEY_LEFT)) block->position.x -= 3.0f;
// #endif /* Movement */
}

bool MyScene::collision(Entity *collisionA, Entity *collisionB) {
    // Check for horizontal collision
    bool collisionX = collisionA->position.x < collisionB->position.x + collisionB->width &&
                       collisionA->position.x + collisionA->width > collisionB->position.x;
    // Check for vertical collision
    bool collisionY = collisionA->position.y < collisionB->position.y + collisionB->height &&
                       collisionA->position.y + collisionA->height > collisionB->position.y;
    // Return true if there is a collision on both axes
    return collisionX && collisionY;
}
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