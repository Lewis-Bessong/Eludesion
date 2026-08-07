#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 


int main()
{

    InitWindow(WindowWidth, WindowHeight, "Lewis's first program");
    SetTargetFPS(60);

    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen

    // rectangle 
    Vector2 RectanglePosition = { (float)WindowWidth/4, (float)WindowHeight/4};
    Vector2 RectangleSize = { (float)100.0f, (float)100.0f};


    int gamepadIdx = 0;

    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {       
            // ====== Objects Creation =======

            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            DrawRectangleV(RectanglePosition, RectangleSize, MAGENTA);

            // ====== Movement Logic =======

            // Keyboard
            SetExitKey(KEY_ESCAPE); // if pressed exits program

            if (IsKeyDown(KEY_D)) BallPosition.x += 5.0f;
            if (IsKeyDown(KEY_A)) BallPosition.x -= 5.0f;
            if (IsKeyDown(KEY_W)) BallPosition.y -= 5.0f;
            if (IsKeyDown(KEY_S)) BallPosition.y += 5.0f;

            // Controller
            if (IsGamepadAvailable(gamepadIdx)) { // if controller connected

                DrawText("Controller Connected.", WindowWidth/2, 0, 30, BLACK);

                if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) { // right arrow

                    BallPosition.x += 5.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) { // left arrow

                    BallPosition.x -= 5.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_UP)) { // up arrow 

                    BallPosition.y -= 5.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) { // down arrow

                    BallPosition.y += 5.0f;
                }

            } else { // if no controller connected

                DrawText("No Controller Found", WindowWidth/2, 0, 30, BLACK);
            }

            // ======= Collision ========


        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}