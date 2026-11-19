#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

#define NAME_LEN 20
#define TILE_SIZE 20
#define BOARD_TOP_TILES 4
#define HORIZONTAL_BOARD_SIZE 4
#define VERTICAL_BOARD_SIZE 6
#define FILE_NAME "leaderboard.txt"

#define CELL_WIDTH 300
#define CELL_HEIGHT 75

float max_scores = INFINITY;
const char *top_tiles [BOARD_TOP_TILES] = {"Rank", "Name", "Score", "Time"};

const char *board [VERTICAL_BOARD_SIZE][HORIZONTAL_BOARD_SIZE];

int main(void) {
    const int screenWidth = 1500;
    const int screenHeight = 900;

    //SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

    //add title
    InitWindow(screenWidth, screenHeight, "Asan na ako?");

    //fps at the top
    SetTargetFPS(60);

    //board[VERTICAL_BOARD_SIZE][HORIZONTAL_BOARD_SIZE];

    int startX = 165;
    int startY = 250;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);

            for(int y = 0; y < VERTICAL_BOARD_SIZE; y++){
                for (int x = 0; x < HORIZONTAL_BOARD_SIZE; x++){
                    Rectangle rect = {
                        startX + (x * CELL_WIDTH),
                        startY + (y * CELL_HEIGHT),
                        CELL_WIDTH,
                        CELL_HEIGHT
                    };

                    DrawRectangleLinesEx(rect, 2, PINK);

                    DrawTextEx(
                        GetFontDefault(),
                        board[y][x],
                        (Vector2){
                            rect.x + 125, rect.y + 25
                        },
                        30, 1, BLACK
                    );
                }
            }
            DrawText("===LEADERBOARD===", startX + 290, startY - 150, 60, BLACK);
            DrawFPS(10, 10);


        EndDrawing();
    }


    CloseWindow();
    return 0;
}


const char *board[VERTICAL_BOARD_SIZE][HORIZONTAL_BOARD_SIZE] = {
        {"Rank", "Name", "Score", "Time"},
        {"1", "Juan", "1500", "01:20"},
        {"2", "Maria", "1200", "01:45"},
        {"3", "Pedro", "950", "02:10"},
        {"4", "Ana", "800", "02:30"},
        {"5", "Luis", "600", "03:00"},
};

