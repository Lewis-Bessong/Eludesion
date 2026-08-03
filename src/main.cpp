#include <raylib.h>

int main()
{

    InitWindow(800, 800, "Lewis's first program");
    SetTargetFPS(60);

    // loop
    while (WindowShouldClose() == false)
    {
        // Main Menu Code

        // lambda ?
        auto Menu = []() {

            DrawText("This is Eludesion", 20, 20, 20, BLACK);
        };
        

        //Drawing
        BeginDrawing();
        {
            ClearBackground(LIGHTGRAY);

            Menu();

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;

}