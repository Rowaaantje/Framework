#include "config.h"
#include "raylib.h"
#include "myscene.h"

int main(void)
{

    // InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOWNAME);


    MyScene* myscene = new MyScene(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOWNAME);
    SetTargetFPS(120);
    while (!WindowShouldClose())     // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        
        //----------------------------------------------------------------------------------

        // Draw
       //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GREEN);
            myscene->update(0);

            // myscene->player->draw(0);
            // DrawFPS(300,  300);
        
        EndDrawing();
    }

    CloseWindow();

    // Free dynamically allocated memory
    delete myscene;
}
