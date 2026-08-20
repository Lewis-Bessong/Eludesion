#include <raylib.h>
#include <iostream> 
#include <string>

// Size of startup
int WindowWidth = 800; 
int WindowHeight = 800;

int main()
{
    // ======= Window Section ======

    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN | FLAG_VSYNC_HINT); // Program can still run when minimized and can have a fps near users monitor refresh rate
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Program can be resizeable
    InitWindow(WindowWidth, WindowHeight, "Eludesion"); // program start 
    
    // window Icon
    Image Icon = LoadImage("PhoenixIcon.png");
    ImageFormat(&Icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(Icon);
    UnloadImage(Icon);

    // ======= Shapes/Drawing =======


    // Circle 
    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen

    Vector2 Center = {WindowWidth/2 + WindowHeight/2};
    
    int gamepadIdx = 0; // for controller input 

    
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {                  
            // ====== Window Dimensions ===== 
            SetWindowState(FLAG_WINDOW_MAXIMIZED);
            
           
            // ====== Objects Creation =======
            ClearBackground(WHITE);
    
            DrawCircleV(BallPosition, 50, RED);

            // ====== Movement Logic =======

            // Keyboard
            SetExitKey(KEY_ESCAPE); // if pressed exits progsasram

            if (IsKeyDown(KEY_D)) BallPosition.x += 3.0f;
            if (IsKeyDown(KEY_A)) BallPosition.x -= 3.0f;
            if (IsKeyDown(KEY_W)) BallPosition.y -= 3.0f;
            if (IsKeyDown(KEY_S)) BallPosition.y += 3.0f;

            // Controller
            if (IsGamepadAvailable(gamepadIdx)) { // if controller connected

                DrawText("Controller Connected", WindowWidth/2, 0, 30, BLACK);

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

            // ======= Collision Section ======

            if (CheckCollisionCircleLine(Center, Center/2, ) = true) {


            };
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}