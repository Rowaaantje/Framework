#include "raylib.h"
#include "myscene.h"


constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 800;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Suusy title");
    SetTargetFPS(120);

    MyScene* myscene = new MyScene();

    // Texture2D texture = LoadTexture("assets/test.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GREEN);
            myscene->update(0);
            DrawFPS(300,  300);

        // const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        // const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        // DrawTexture(texture, texture_x, texture_y, WHITE);

        // const char* text = "OMG! IT WORKS!";
        // const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 1, 1);
        // DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    // Free dynamically allocated memory
    delete myscene;

    return 0;
}
