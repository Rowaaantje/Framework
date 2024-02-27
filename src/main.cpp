#include "core.h"
#include "myscene.h"

int main(void)
{
    Core* core = new Core();

    MyScene* myscene = new MyScene(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOWNAME);
    
    SetWindowState(FLAG_VSYNC_HINT);
   
        while (myscene->isActive())
        {
            core->run(myscene);
        }

    // Free dynamically allocated memory
    delete myscene;
}
