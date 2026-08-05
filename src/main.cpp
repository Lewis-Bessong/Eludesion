#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 


int main()
{

    InitWindow(WindowWidth, WindowHeight, "Lewis's first program");
    SetTargetFPS(60);

    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {       
            // Circle Creation 

            ClearBackground(WHITE);

            DrawCircle(400, 400, 200, RED);

            

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}