#include "raylib.h"
#include <stdio.h>

#include "screen.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const char* appDir = GetApplicationDirectory();
    TraceLog(LOG_INFO, "App directory: %s", appDir);

    //ChangeDirectory(appDir);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    ShowSplashScreen();

    NextGameScreen nextScreen = ShowMainMenu();

    switch(nextScreen)
    {
        case TITLE:
            TraceLog(LOG_INFO, "Next screen: TITLE");
            break;
        case GAMEPLAY:
            TraceLog(LOG_INFO, "Next screen: GAMEPLAY");
            break;
        case EXIT:
            TraceLog(LOG_INFO, "Next screen: EXIT");
            CloseWindow();
            return 0;
            break;
        default:
            TraceLog(LOG_WARNING, "Unknown next screen");
            break;
    }


    char title[100];
    float elapsedTime;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        float deltaTime = GetFrameTime();
        elapsedTime += deltaTime; 
        int fps = GetFPS();
        
        sprintf(title,"Deltatime: %f - FPS: %d", deltaTime, fps);
        SetWindowTitle(title);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}