#include <myscene.h>

// #include <rshapes.c> //rember

MyScene::MyScene(uint16_t width, uint16_t height, const char* windowName) 
    : Scene(width, height, windowName)
{   
    iskeypressed = false;
    player = new Player();
    block = new Block();
    sword = new Block();

	for (size_t i = 0; i < 4; i++)
	{
		enemies.push_back(new Enemy(player));
		this->addChild(enemies[i]);
	}

    // block->position = Vector3{600, 100};
    // player->position = Vector3{width / 2.0f, height / 2.0f};
    addChild(player);
    addChild(block);
    addChild(sword);
}   

MyScene::~MyScene() 
{
    removeChild(player);
    removeChild(block);
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
    
    //randomly spawn the enemy at pos when button pres
    randomEnemyPos(KEY_SPACE, deltaTime);
    //rotate sword around player
    rotateAround(player, sword, deltaTime);
    //draw the real Image Size
    this->sword->drawImageSize(SEMI_TRANSPARENT_BLACK);

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
    
    if (collision(player, block)) {
        // std::cout << "coli " << std::endl;
        player->drawImageSize(RED);
    } 
}

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
    if(collision) //if collision = true 
    {
        //print what we are colliding with
        std::cout << "colliding : " << collisionA << collisionB << std::endl;
    }

    return collision;

	// return (collisionA->position.x < collisionB->position.x + collisionB->size().x * collisionB->scale.x &&
	// 		collisionA->position.x + collisionA->size().x * collisionA->scale.x > collisionB->position.x &&
	// 		collisionA->position.y < collisionB->position.y + collisionB->size().y * collisionB->scale.y &&
	// 		collisionA->position.y + collisionA->size().y * collisionA->scale.y > collisionB->position.y);


}

void MyScene::rotateAround(Entity* pivot, Entity* rotating, float deltaTime)
{
    // Define the center of the circle and the radius
    Vector2 center = { pivot->position.x, pivot->position.y }; // Example center point
    float radius = 50.0f; // Example radius

    // Define the speed of the movement around entityA
    float speed = 5.0f; // Example speed
    
    // Update the angle
    angle += speed * deltaTime;

    // Calculate the new position using the updated angle and the radius
    rotating->position.x = center.x + radius * cos(angle);
    rotating->position.y = center.y + radius * sin(angle);
}

void MyScene::randomEnemyPos(int keycode, float deltaTime)
{
    for(size_t i = 0; i < enemies.size(); i++)
    {
        if(IsKeyDown(keycode))
        {
            enemies[i]->randomPosition(deltaTime);
            iskeypressed = true;
        }
    }
}