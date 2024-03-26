/*
* todo find out how to properly delete an entity
*/

#include <myscene.h>

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    iskeypressed = false;

    camera->offset = Vector2{ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f}; 
    camera->rotation = 0.0f;
    camera->zoom = 0.3f;

    player = new Player();
    sword = new Sword();

    addChild(player);
    addChild(sword);

    for (size_t i = 0; i < 1; i++){
        enemies.push_back(new Enemy(player)); 
        this->addChild(enemies[i]);
    }
}   

MyScene::~MyScene() 
{
    removeChild(player);
    removeChild(sword);
    // delete enemies;
	for(Enemy* enemy : enemies)
	{
		this->removeChild(enemy);
	}
}

void MyScene::update(float deltaTime) 
{   
    if(!iskeypressed)
    {
        DrawText("Pres SPACE to spawn enemies with rand pos", 190, 200, 20, SEMI_TRANSPARENT_BLACK);
    }

    updateCamera(deltaTime);

    spawner(deltaTime);
    
    //randomly spawn the enemy at pos when button pres
    randomEnemyPos(KEY_SPACE, deltaTime);
    rotate(player, sword, deltaTime);

    //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG //DEBUG
    // DrawCircle(player->position.x, player->position.y, 3.0f, YELLOW);
    // DrawCircle(sword->position.x, sword->position.y, 1.0f, RED);
    
    player->setTextureColor(WHITE);

    
    for(Enemy* enemy : enemies)
    {   
        enemy->setTextureColor(WHITE);
        //wierd way to show where the eny died this is supose to represent blood
         DrawCircle(enemy->position.x, enemy->position.y, 1.0f, RED);

        // Check for collision between sword and enemies
        if (collision(sword, enemy, false)) {
            enemy->setTextureColor(RED);
            removeChild(enemy);
        }
        // Check for collision between player and enemies 
        if (collision(player, enemy, true)) {
            player->setTextureColor(RED);
        } 
    }
}

bool MyScene::collision(Entity* collisionA, Entity* collisionB, bool specific) 
{   
    float five  =  5.0f;
    float four  =  4.0f;
    float three =  3.0f;
    float two   =  2.0f;

    // Adjusts the size of the images to match the actual parts they represent.
    // This is important for images with pixels that are not visible (transparent) or if the image's box is a bit bigger than the visible part of the image.
    // By subtracting 4.0f from the x-coordinates, we make sure the collision detection works correctly.
    // we do the same for y-coordinates

    // The division by 4.0f adjustment is for a image(spriteSheets) that has multiple sprites.
    // This is done to make sure that only the part of the image we care about is checked for collisions,
    // especially when we have images that change sprites but we only want to check one sprite at a time.
    // subtracting a value from a image that has transparent pixels, effectively making the collision detection area smaller & visually appealing.
    if (specific) {
        // If 'collision' is true, the method checks for collision considering the entity's size divided by 'four' and adjusted for transparent areas.
        // Check if the left edge of collisionA is to the left of the right edge of collisionB
        return ((collisionA->position.x < (collisionB->position.x + collisionB->size().x - 4.0f) && 
                        // Check if the right edge of collisionA is to the right of the left edge of collisionB
                        ((collisionA->position.x + collisionA->size().x / 4.0f) - 4.0f) > collisionB->position.x) &&
                         // Check if the top edge of collisionA is above the bottom edge of collisionB
                        (collisionA->position.y < (collisionB->position.y + collisionB->size().y - 3.0f) && 
                        // Check if the bottom edge of collisionA is below the top edge of collisionB
                        (collisionA->position.y + collisionA->size().y - 2.0f) > collisionB->position.y));
    } else {
        // If 'collision' is false, the method checks for collision without considering the entity's size divided by 'four'.
        // This is used for entities where the entire sprite should be considered for collision.
        return ((collisionA->position.x < (collisionB->position.x + collisionB->size().x - 4.0f) && 
                (collisionA->position.x + collisionA->size().x - 6.0f) > collisionB->position.x) &&
                (collisionA->position.y < (collisionB->position.y + collisionB->size().y) && 
                (collisionA->position.y + collisionA->size().y ) > collisionB->position.y));
    }
}

void MyScene::rotate(Entity* pivotEntity, Entity* rotatingEntity, float deltaTime)
{
    Vector2 center = {pivotEntity->position.x, pivotEntity->position.y};

    float radius = 15.0f; 
    // Define the speed of the movement around pivotEntity
    float speed = 10.0f; 
    // Update the angle
    angle += speed * deltaTime;
    // // Calculate the new position using the updated angle and the radius
    rotatingEntity->position.x = center.x + radius * cos(angle);
    rotatingEntity->position.y = center.y + radius * sin(angle);
}

void MyScene::randomEnemyPos(int keycode, float deltaTime)
{   
    for(size_t i = 0; i < enemies.size(); i++)
    {
        if(IsKeyDown(keycode))
        {
            enemies[i]->randomPosition(deltaTime);
            enemies[i]->setTextureColor(WHITE); 
            iskeypressed = true;
        }
    }
}

void MyScene::spawner(float deltaTime)
{
    // Check if the left mouse button is pressed
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) * deltaTime * 100) {

        // Get the current mouse position
        Vector2 mousePosition = GetMousePosition();
        // Convert the mouse position from screen coordinates to world coordinates
        Vector2 worldPosition = GetScreenToWorld2D(mousePosition, *camera);

        // Create a new enemy at the mouse position
        Enemy* newEnemy = new Enemy(player);
        // Set the enemy's position to the mouse position with z=0
        newEnemy->position = { worldPosition.x, worldPosition.y, 0.0f }; 
        
        // Add the new enemy to the scene
        addChild(newEnemy);
        newEnemy->setTextureColor(WHITE);
        enemies.push_back(newEnemy); // Make sure to also add the new enemy to your enemies list :)
    }
}

void MyScene::updateCamera(float deltaTime)
{
    // Define the camera's target position based on the player's position
    Vector2 targetPosition = {player->position.x, player->position.y};

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

    // // clamp the camera to an max zoom
    // if(camera->zoom < 3)
    // {
    //     camera->zoom = 3;
    // } 
    // else if (camera->zoom > 10){
    //     camera->zoom = 10;
    // }
}