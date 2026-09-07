#include <raylib.h>
#include <iostream> 
#include <string>

// why did I do this? 
#define PS_ALIAS_1  "playstation"
#define PS_ALIAS_2  "sony"

// Size of startup
int WindowWidth = 800; 
int WindowHeight = 800;

enum class GameState { // enum class keeps things within enum scoped to 'GameState'

    GameMenu,
    GamePlaying 
};

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
    Vector2 BallPosition = { (float)GetScreenWidth()/2, (float)GetScreenHeight()/2}; // middle of screen
    int BallRadius = 35;
    Color BallColor = BLACK;
    
    GameState CurrentState = GameState::GameMenu;

    int gamepadIdx = 0; // for controller input 

    SetTargetFPS(60);
    
    // ===== Game Loop =====

    while (WindowShouldClose() == false)
    {
        
        BeginDrawing();
        ClearBackground(WHITE);
        SetWindowState(FLAG_WINDOW_MAXIMIZED);
        {     
            
            // will be used for game state switching (All current code will go in gameplaying, then be tested)
            switch (CurrentState) { // start at menu

                case GameState::GameMenu: { // case for menu
                    // new code for menu 

                    DrawText("Click to continue....", WindowWidth/2, WindowHeight/2, 30, BLACK);

                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                        CurrentState = GameState::GamePlaying;       
                    }
                    
                }
            
                case GameState::GamePlaying: {

                    if (CurrentState == GameState::GamePlaying){
                        
                        DrawCircleV(BallPosition, BallRadius, BallColor);
                    }
                    // Wall Collision 

                    if (BallPosition.x >= GetScreenWidth() - BallRadius) BallPosition.x = GetScreenWidth() - BallRadius;  // Checks right wall
                    if (BallPosition.y >= GetScreenHeight() - BallRadius) BallPosition.y = GetScreenHeight() - BallRadius; // Checks bottom wall
                    if (BallPosition.x <= BallRadius) BallPosition.x = BallRadius; // Checks left wall 
                    if (BallPosition.y <= BallRadius) BallPosition.y = BallRadius; // Checks top wall

                    // ====== Movement Logic =======

                    // Keyboard
                    SetExitKey(KEY_ESCAPE); // if pressed exits progsasram

                    if (IsKeyDown(KEY_D)) BallPosition.x += 4.0f;
                    if (IsKeyDown(KEY_A)) BallPosition.x -= 4.0f;
                    if (IsKeyDown(KEY_W)) BallPosition.y -= 4.0f;
                    if (IsKeyDown(KEY_S)) BallPosition.y += 4.0f;

                    // Controller
                    if (IsGamepadAvailable(gamepadIdx)) { // if controller connected

                        DrawText("Controller Connected", GetScreenWidth()/2, 0, 30, BLACK);

                        if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) { // right arrow

                            BallPosition.x += 4.0f;
                        } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) { // left arrow

                            BallPosition.x -= 4.0f;
                        } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_UP)) { // up arrow 

                            BallPosition.y -= 4.0f;
                        } if (IsGamepadButtonDown(gamepadIdx, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) { // down arrow

                            BallPosition.y += 4.0f;
                        } else { // if no controller connected

                            DrawText("No Controller Found", GetScreenWidth()/2, 0, 30, BLACK);
                            
                        }
                    
                    }
                }
                    
            }
           
        }
    }
        EndDrawing();


    CloseWindow();
    return 0;

}