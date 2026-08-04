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
            ToggleFullscreen();

            ClearBackground(BLACK);
            GenImageColor(400, 400, WHITE); // half of screen is black 

            DrawText("This Is Eludesion", 0, 0, 30, WHITE);
            
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}