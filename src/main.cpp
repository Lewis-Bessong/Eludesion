#include <raylib.h>
#include <iostream> 

const int WindowWidth = 800;
const int WindowHeight = 800;

int main()
{
    // ======= Window Dimensions ======

    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN); // Program still runs when minimized
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Program can be resizeable
    SetConfigFlags(FLAG_WINDOW_MAXIMIZED); // Program enters in maximized state 
    InitWindow(WindowWidth, WindowHeight, "Eludesion"); // program start 
    

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
            SetWindowState(FLAG_WINDOW_MAXIMIZED); // Program constantly stays at Mixaized state (still minimizeable) 
           


            // ====== Objects Creation =======

            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            DrawRectangleV(RectanglePosition, RectangleSize, BLACK);

            // ====== Movement Logic =======

            // Keyboard
            SetExitKey(KEY_ESCAPE); // if pressed exits program

            if (IsKeyDown(KEY_D)) BallPosition.x += 2.0f;
            if (IsKeyDown(KEY_A)) BallPosition.x -= 2.0f;
            if (IsKeyDown(KEY_W)) BallPosition.y -= 2.0f;
            if (IsKeyDown(KEY_S)) BallPosition.y += 2.0f;

            // Controller
            if (IsGamepadAvailable(gamepadIdx)) { // if controller connected

                DrawText("Controller Connected.", WindowWidth/2, 0, 30, BLACK);

                if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) { // right arrow

                    BallPosition.x += 2.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) { // left arrow

                    BallPosition.x -= 2.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_UP)) { // up arrow 

                    BallPosition.y -= 2.0f;
                } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) { // down arrow

                    BallPosition.y += 2.0f;
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