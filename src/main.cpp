#include <raylib.h>
#include <iostream> 
#include <string>

// Size of startup
const int WindowWidth = 800; 
const int WindowHeight = 800;
 

int main()
{
    // ======= Window Section ======

    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN | FLAG_VSYNC_HINT); // Program can still run when minimized and can have a fps near users monitor refresh rate
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED); // Program can be resizeable and enter in maximized state
    InitWindow(WindowWidth, WindowHeight, "Eludesion"); // program start 
    
    // window Icon
    Image Icon = LoadImage("PhoenixIcon.png");
    ImageFormat(&Icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(Icon);
    UnloadImage(Icon);

    // ======= Shapes/Drawing =======

    // Circle 
    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen

    // rectangle 
    Vector2 RectanglePosition = { (float)WindowWidth/2, (float)WindowHeight/2};
    Vector2 RectangleSize = { (float)200.0f, (float)200.0f};
    
    int gamepadIdx = 0; // for controller input 

    
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {                  
            // ====== Window Dimensions =====
            SetWindowState(FLAG_WINDOW_MAXIMIZED); // Program stays in maximized state (still minimizable) 
           
            // ====== Objects Creation =======

            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            DrawRectangleV(RectanglePosition, RectangleSize, BLACK);

            // ====== Movement Logic =======

            // Keyboard
            SetExitKey(KEY_ESCAPE); // if pressed exits program

            if (IsKeyDown(KEY_D)) BallPosition.x += 3.0f;
            if (IsKeyDown(KEY_A)) BallPosition.x -= 3.0f;
            if (IsKeyDown(KEY_W)) BallPosition.y -= 3.0f;
            if (IsKeyDown(KEY_S)) BallPosition.y += 3.0f;

            // Controller
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