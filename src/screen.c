#include "screen.h"
#include "raylib.h"

void ShowSplashScreen(void)
{
    float timer = 0.0f;
    float duration = 4.0f;

    while (!WindowShouldClose() && timer < duration)
    {
        // Update
        //----------------------------------------------------------------------------------
        timer += GetFrameTime();

        float alpha = 1.0f;

        if (timer < 1.0f)
            alpha = timer;
        else if (timer > 3.0f)
            alpha = 4.0f - timer;

        unsigned char a = (unsigned char)(alpha * 255);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

            DrawText("MY GAME", 300, 170, 50,
                    Fade(RAYWHITE, alpha));

            DrawText("Powered by raylib", 315, 240, 20,
                    Fade(GRAY, alpha));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}

NextGameScreen ShowMainMenu(void)
{
    const int totalOptions = 3;
    int selectedOption = 0;

    char* options[3] = { "Start Game", "Options", "Exit" };

    NextGameScreen nextScreen = TITLE;

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ENTER))
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_DOWN))
        {
            selectedOption = (selectedOption + 1) % totalOptions;
        } 
            
        else if(IsKeyPressed(KEY_UP))
        {
            selectedOption = (selectedOption - 1 + totalOptions) % totalOptions;
        }

        switch(selectedOption)
        {
            case 0:
                nextScreen = GAMEPLAY;
                break;
            case 1:
                // Handle options
                break;
            case 2:
                nextScreen = EXIT;
                break;
        }
        
            

        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

            DrawText("MAIN MENU", 300, 100, 50, RAYWHITE);

            for(int i = 0; i < totalOptions; i++)
            {
                Color optionColor = (i == selectedOption) ? YELLOW : GRAY;
                DrawText(options[i], 350, 200 + i * 40, 20, optionColor);
            }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return nextScreen;
}