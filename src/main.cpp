#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 


int main()
{

    InitWindow(WindowWidth, WindowHeight, "Lewis's first program");
    SetTargetFPS(60);

    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen

    int gamepadIdx = 0;

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

            // PS4 Controller
            if (IsGamepadAvailable(gamepadIdx)) { // if controller connected

                DrawText("Controller Connected.", WindowWidth/2, 0, 30, BLACK);

                if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) { // right arrow

                    BallPosition.x += 3.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) { // left arrow

                    BallPosition.x -= 3.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_UP)) { // up arrow 

                    BallPosition.y -= 3.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) { // down arrow

                    BallPosition.y += 3.0f;
                }

            } else { // if no controller connected

                DrawText("No Controller Found", WindowWidth/2, 0, 30, BLACK);
            }


        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}