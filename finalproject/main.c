#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

#define BOARD_TOP_TILES 4

#define FILE_NAME "leaderboard.txt"

void center_text(const char*, int, int, Color);

int main(void) {

    //set default window size
    InitWindow(1920, 1080, "Asan na ako?");
    SetTargetFPS(60);

    //font for data inside leaderboard (still unused)
    Font customFont = LoadFontEx("C:/Windows/Fonts/segoeui.ttf", 32, 0, 250);

    int box_width = 1300, box_height = 100, gap = 12;
    int startX = GetScreenWidth()/2, startY = 275;

    bool menu_pressed = false;

    while (!WindowShouldClose()) {
        //mouse
        Vector2 mouse = GetMousePosition();
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            //top texts
            center_text("LEADERBOARD", startY - 220, 100, BLACK);
            DrawText("Rank", startX - 600, startY - 60, 40, BLACK);
            DrawText("Name", startX - 200, startY - 60, 40, BLACK);
            DrawText("Level", startX + 220, startY - 60, 40, BLACK);
            DrawText("Score", startX + 450, startY - 60, 40, BLACK);

            //boxes
            for (int i = 0; i < 5; i++){
                Rectangle box = {(GetScreenWidth() - box_width)/2, startY + i * (box_height + gap), box_width, box_height};
                DrawRectangleRounded(box, 0.5f, 16, LIGHTGRAY);
            }

            //menu button
            Rectangle menu_button = {(GetScreenWidth() - 500)/2, startY + 5.25 * (box_height + gap), 500, box_height};
            DrawRectangleRounded(menu_button, 0.5f, 8, LIGHTGRAY);
            center_text("MENU", startY + 5.5 * (box_height + gap), 50, BLACK);

            //hovering and clicking menu button
            Color fill = Fade(BLUE, 0.0F);
            bool hovered = CheckCollisionPointRec(mouse, menu_button);
            if (hovered){
                fill = Fade(BLUE, 0.2F);
                SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    menu_pressed = true;
                }
            }

            //printing fill
            DrawRectangleRounded(menu_button, 0.5f, 16, fill);
            if (menu_pressed){
                DrawText("Check: MenuIsPressed", 500, 900, 20, BLACK);
            }

            DrawFPS(10, 10);


        EndDrawing();
    }
    UnloadFont (customFont);
    CloseWindow();
    return 0;
}

void center_text(const char *text, int y, int font_size, Color color){
    int text_size = MeasureText(text, font_size);
    DrawText(text, (GetScreenWidth() - text_size)/2, y, font_size, color);
}
