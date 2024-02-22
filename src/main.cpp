#include "myscene.h"

int main(void)
{
    MyScene* myscene = new MyScene(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOWNAME);
    // SetTargetFPS(120);

    SetWindowState(FLAG_VSYNC_HINT);
   
        while (myscene->isActive())
        {
            myscene->run(0);
        }

    // Free dynamically allocated memory
    delete myscene;
}
