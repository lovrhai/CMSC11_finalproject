#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

int main(void) {
    const int screenWidth = 1500;
    const int screenHeight = 900;
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

    InitWindow(screenWidth, screenHeight, "Asan na ako?");
    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! Raylib is working!", 190, 200, 20, DARKGRAY);
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

