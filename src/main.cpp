#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 

struct GameCircle {

    Vector2 center; 
    float radius;
    Color color;

};

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
    
            GameCircle RedCircle = { {400, 400}, 50, RED};

            // Circle Movement


            

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}