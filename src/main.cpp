#include <raylib.h>
#include <iostream> 

const int WindowHeight = 800;
const int WindowWidth = 800; 

struct GameCircle { // class for circle (draw circle vector 2)

    Vector2 center; 
    float radius;
    Color color;

    int Width = 400;
    int Height = 400;

};

int main()
{

    InitWindow(WindowWidth, WindowHeight, "Lewis's first program");
    SetTargetFPS(60);

    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu
        BeginDrawing();
        {       
            // Circle Creation 

            ClearBackground(WHITE);
    
            GameCircle RedCircle = { {RedCircle.Width, RedCircle.Height}, 50, RED};

            // Movement Logic 

            // Keyboard

            if (IsKeyPressed(KEY_W)) {

                RedCircle.Width += 3;
            } if (IsKeyPressed(KEY_S)) {

                RedCircle.Height += 3;
            }
            

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}