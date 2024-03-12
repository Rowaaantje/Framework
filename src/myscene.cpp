/*
* @todo
* - Use drawTexturePro instead of drawTexture for rendering(player, block).
* - Fix collision detection due to the switch to drawTexturePro.
* - Implemented two new methods for rotating entities around another entity
* - one using drawTexture and the other drawTexturePro.
*   - rotatePosition (drawTexture)
*   - rotateDest(drawTexturePro)
*/

#include <myscene.h>

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    player = new Player();
    sword = new Block();

    camera->offset = Vector2{ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f}; 
    camera->rotation = 0.0f;
    camera->zoom = 0.3f;

    addChild(player);
    addChild(sword);
    for (size_t i = 0; i < 4; i++)
	{
		enemies.push_back(new Enemy(player));
		this->addChild(enemies[i]);
	}

    iskeypressed = false;
}   

MyScene::~MyScene() 
{
    removeChild(player);
    removeChild(sword);
    // delete enemies;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		this->removeChild(enemies[i]);
	}
}

void MyScene::update(float deltaTime) 
{   
    if(!iskeypressed)
    {
        DrawText("Pres SPACE to spawn enemies with rand pos", 190, 200, 20, SEMI_TRANSPARENT_BLACK);
    }
    updateCamera(deltaTime);
    randomEnemyPos(KEY_SPACE, deltaTime);

    //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG
    //DEBUG dest x,y
    rotateDest(player, sword, deltaTime);
    DrawCircle(player->dest.x, player->dest.y, 3.0f, YELLOW);
    DrawCircle(sword->dest.x, sword->dest.y, 1.0f, RED);
    //DEBUG position x,y
    rotatePosition(player, sword, deltaTime);
    DrawCircle(player->position.x, player->position.y, 3.0f, YELLOW);
    DrawCircle(sword->position.x, sword->position.y, 1.0f, RED);
    //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG

    //randomly spawn the enemy at pos when button pres

    //for each enemy in list enemies[i]
    for(size_t i = 0; i < enemies.size(); i++)
    {
        // Check for collision between sword and enemies
        if (collision(sword, enemies[i])) {
            this->enemies[i]->drawImageSize(RED);
        } 

        // Check for collision between player and enemies 
        if (collision(player, enemies[i])) {
            player->drawImageSize(RED);
        } 
    }
}

bool MyScene::collision(Entity* collisionA, Entity* collisionB) 
{   
    // Define a threshold for "almost in range"
    float rangeThreshold = 50.0f; 

    // Calculate the distance between collisionA and collisionB
    float distanceX = collisionA->position.x - collisionB->position.x;
    float distanceY = collisionA->position.y - collisionB->position.y;
    float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

    if(distance <= rangeThreshold)
    {
        // std::cout << " close " << std::endl;
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
        if(collision) 
        {
            //print what we are colliding with
            std::cout << "colliding : " << collisionA << collisionB << std::endl;
        }
        return collision;
    }
    // return (collisionA->position.x < collisionB->position.x + collisionB->size().x * collisionB->scale.x &&
    // 		collisionA->position.x + collisionA->size().x * collisionA->scale.x > collisionB->position.x &&
    // 		collisionA->position.y < collisionB->position.y + collisionB->size().y * collisionB->scale.y &&
    // 		collisionA->position.y + collisionA->size().y * collisionA->scale.y > collisionB->position.y);
}

void MyScene::rotateDest(Entity* pivotEntity, Entity* rotatingEntity, float deltaTime)
{
    // DrawTexture(sword->texture(), rotatingEntity->position.x, rotatingEntity->position.y, WHITE);
    // // Define the center of the circle and the radius
    // // Vector2 center = { pivot->position.x, pivot->position.y }; 
    Vector2 center = {pivotEntity->dest.x, pivotEntity->dest.y};
    float radius = 5.0f; 
    float speed = 5.0f; 
    // Update the angle
    angle += speed * deltaTime;

    // // Calculate the new position using the updated angle and the radius
    rotatingEntity->dest.x = center.x + radius * cos(angle);
    rotatingEntity->dest.y = center.y + radius * sin(angle);

    // std::cout << "Sword Position: (" << rotatingEntity->position.x << ", " << rotatingEntity->position.y << ")" << std::endl;
}

void MyScene::rotatePosition(Entity* pivotEntity, Entity* rotatingEntity, float deltaTime)
{
     // DrawTexture(sword->texture(), rotatingEntity->position.x, rotatingEntity->position.y, WHITE);
    // // Define the center of the circle and the radius
    // // Vector2 center = { pivot->position.x, pivot->position.y }; 
    Vector2 center = {pivotEntity->position.x, pivotEntity->position.y};

    float radius = 5.0f; 
    // Define the speed of the movement around entityA
    float speed = 5.0f; 
    
    // Update the angle
    angle += speed * deltaTime;

    // // Calculate the new position using the updated angle and the radius
    rotatingEntity->position.x = center.x + radius * cos(angle);
    rotatingEntity->position.y = center.y + radius * sin(angle);

    // std::cout << "X " <<rotatingEntity->position.x  << "Y " <<rotatingEntity->position.y << std::endl;
}

void MyScene::randomEnemyPos(int keycode, float deltaTime)
{
    for(size_t i = 0; i < enemies.size(); i++)
    {
        if(IsKeyDown(keycode))
        {
            enemies[i]->randomPosition(deltaTime);
            enemies[i]->setTextureColor(RED); 
            iskeypressed = true;
        }
    }
}

void MyScene::updateCamera(float deltaTime)
{
    // Define the camera's target position based on the player's position
    Vector2 targetPosition = {player->dest.x, player->dest.y};

    // Define the camera's smoothing factor
    float smoothingFactor = 5.0f; // Adjust this value to change the camera's responsiveness
    
    // Interpolate the camera's position towards the target position
    camera->target.x += (targetPosition.x - camera->target.x) * smoothingFactor * deltaTime;
    camera->target.y += (targetPosition.y - camera->target.y) * smoothingFactor * deltaTime;

    //follow drawtexture player
    // camera->target = {(player->position.x + player->size().x /2.0f), (player->position.y + player->size().y /2.0f)};

    if(IsKeyDown(KEY_Q)){
        camera->zoom  += 0.5f;
    } 
    if (IsKeyDown(KEY_E)) 
    {
        camera->zoom  -= 0.5f;
    }

    //clamp the camera to an max zoom
    if(camera->zoom < 3)
    {
        camera->zoom = 3;
    } 
    else if (camera->zoom > 10){
        camera->zoom = 10;
    }
}