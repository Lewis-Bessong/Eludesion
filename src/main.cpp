#include <raylib.h>
#include <iostream> 

// Screen Info

const int MonitorWidth = GetMonitorWidth(0);
const int MonitorHeight = GetMonitorHeight(0);

const int WindowWidth = GetScreenWidth();
const int WindowHeight = GetScreenHeight();

int main()
{
    // ======= Window Dimensions ======

    InitWindow(MonitorWidth/2, MonitorHeight/2, "Eludesion");
    SetWindowState(FLAG_WINDOW_MAXIMIZED); // Enters in Maximized

    // Circle 
    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen

    // rectangle 
    Vector2 RectanglePosition = { (float)WindowWidth/2, (float)WindowHeight/2};
    Vector2 RectangleSize = { (float)200.0f, (float)200.0f};

    //collision


    int gamepadIdx = 0;

    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {                  
            // ====== Window Dimensions =====

             // Can only Maximize or minimize window 
            SetConfigFlags(FLAG_WINDOW_MINIMIZED);
           


            // ====== Objects Creation =======

            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            DrawRectangleV(RectanglePosition, RectangleSize, BLACK);

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