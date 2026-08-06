#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 


int main()
{

    InitWindow(WindowWidth, WindowHeight, "Lewis's first program");
    SetTargetFPS(60);

    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen


    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {       
            // Circle Creation 

            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            // Movement Logic 

            // Keyboard
            SetExitKey(KEY_ESCAPE); // if pressed exits program

            if (IsKeyDown(KEY_D)) BallPosition.x += 3.0f;
            if (IsKeyDown(KEY_A)) BallPosition.x -= 3.0f;
            if (IsKeyDown(KEY_W)) BallPosition.y -= 3.0f;
            if (IsKeyDown(KEY_S)) BallPosition.y += 3.0f;

            

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}