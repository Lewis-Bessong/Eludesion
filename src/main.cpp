#include <raylib.h>
#include <iostream> 
#include <string>

// Size of startup
int WindowWidth = GetScreenWidth(); 
int WindowHeight = GetScreenHeight();

enum class GameState { // enum class keeps things within enum scoped to 'GameState'

    GameMenu,
    GamePlaying 
};

int main()
{
    // ======= Window Section ======

    SetConfigFlags(FLAG_VSYNC_HINT); // Can have a fps near users monitor refresh rate
    InitWindow(WindowWidth, WindowHeight, "Eludesion"); // program start 
    Vector2 WindowCenter = { (float)WindowWidth/2, (float)WindowHeight/2};
    
    // window Icon
    Image Icon = LoadImage("PhoenixIcon.png");
    ImageFormat(&Icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(Icon);
    UnloadImage(Icon);

    // Circle 
    Vector2 BallPosition = { (float)WindowWidth/2, (float)WindowHeight/2}; // middle of screen
    int BallRadius = 35;
    Color BallColor = BLACK;
    
    // Game Title Text
    Font font = LoadFont ("alagard.png");
    Vector2 TitlePosition = { (float)GetRenderWidth(), (float)GetRenderHeight()};
    const int TitleFont = 40; 
    const float TitleSpacing = 2.0;
    const Color TitleColor = MAROON;

    GameState CurrentState = GameState::GameMenu; // Variable to contain current states

    int gamepadIdx = 0; // for controller input 

    SetTargetFPS(60);
    
    // ===== Game Loop =====

    while (WindowShouldClose() == false)
    {
        
        BeginDrawing();
        ClearBackground(WHITE);
        {     
            
            // will be used for game state switching (All current code will go in gameplaying, then be tested)
            switch (CurrentState) { // start at menu

                case GameState::GameMenu: { // case for menu 

                    DrawTextEx(font, "Eludesion", WindowCenter, TitleFont, TitleSpacing, TitleColor); // Game Menu Title

                    DrawText("Click to continue....", 400, 400, 50, BLACK);

                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                        CurrentState = GameState::GamePlaying;       
                    }
                    
                }
            
                case GameState::GamePlaying: {

                    // Game State Switch
                    if (IsKeyPressed(KEY_M)) {

                        CurrentState = GameState::GameMenu;
                    }

                    // Circle creation only in this state
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

        EndDrawing();
        
    }
        
    CloseWindow();
    
    return 0;

}