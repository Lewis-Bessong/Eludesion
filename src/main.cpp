#include <raylib.h>
#include <iostream> 
#include <string>
#include <Button.hpp>

// test system start ups
int WindowWidth = 800; 
int WindowHeight = 800;

// could be put in header file 

enum class GameState { // enum class keeps things within enum scoped to 'GameState'

    GameMenu,
    GamePlaying,
    GameSettings 
};


int main()
{
    // ======= Window Section ======

    SetConfigFlags(FLAG_VSYNC_HINT); // Can have a fps near users monitor refresh rate
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WindowWidth, WindowHeight, "Eludesion"); // program start 
    SetWindowMinSize(WindowWidth, WindowHeight); // Window cannot be resized less than initial window width and height

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
    Font TitleFont = LoadFont ("alagard.png");
    const char* TitleName = "Eludesion";
    const float TitleFontSize = 160;
    const float TitleSpacing = 0.1;
    const Color TitleColor = MAROON;

    // var for switching states
    GameState CurrentState = GameState::GameMenu; // Variable to contain current states

    int gamepadIdx = 0; // for controller input 

    SetTargetFPS(60);
    
    // ===== Game Loop =====

    while (WindowShouldClose() == false)
    {     

        int CurrentWindowWidth = GetScreenWidth(); // is always getting window width
        int CurrentWindowHeight = GetScreenHeight(); // is always getting window height

        // get title measurements/size
        Vector2 TitleSize = (MeasureTextEx(TitleFont, TitleName, TitleFontSize, TitleSpacing));
        Vector2 TitlePosition = (Vector2) {(CurrentWindowWidth/ 2) - (TitleSize.x / 2), 0};

        // Main Menu Buttons (Rectangles)

        // Play button
        Vector2 PlayRectSize = {}; // Need inner radius and outter radius ?
        Vector2 PlayRectPosition = { (float)CurrentWindowWidth/3, (float)CurrentWindowHeight/-2}; // width is quarter of half, height is inverted from top
        Color PlayRectColor = BEIGE;

        BeginDrawing();
        ClearBackground(WHITE);
        {     
            
            switch (CurrentState) { // start at menu

                case GameState::GameMenu: { // case for menu     
                    
                    /* TO DO FOR MAIN MENU
                    
                    1. Add rectangles/ ovals for game buttons
                    2. Add words (Play, Settings, Locker) ontop of shapes
                    3. Add logic to make it interactive
                                  
                    */



                    DrawTextEx(TitleFont, "Eludesion", TitlePosition, TitleFontSize, TitleSpacing, TitleColor); // Game Menu Title

                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ // used for now to switch to other state
  
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
               
                case GameState::GameSettings: {

                };
            }
           
        }

        EndDrawing();
        
    }
        
    CloseWindow();
    
    return 0;

}