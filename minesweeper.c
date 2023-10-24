#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 8
#define MINE_COUNT 10

int mines[GRID_SIZE][GRID_SIZE];
int revealed[GRID_SIZE][GRID_SIZE];
int game_over = 0;

void initializeGame() {
    memset(mines, 0, sizeof(mines));
    memset(revealed, 0, sizeof(revealed));

    int count = 0;
    while (count < MINE_COUNT) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (mines[x][y] == 0) {
            mines[x][y] = 1;
            count++;
        }
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || revealed[x][y] == 1) {
        return;
    }

    revealed[x][y] = 1;

    if (mines[x][y] == 1) {
        game_over = 1;
    } else {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x + i >= 0 && x + i < GRID_SIZE && y + j >= 0 && y + j < GRID_SIZE && mines[x + i][y + j] == 1) {
                    count++;
                }
            }
        }
        if (count == 0) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    reveal(x + i, y + j);
                }
            }
        }
    }
}

void drawGrid() {
    gfx_FillScreen(255); // Clear screen
    gfx_SetColor(0);
    for (int i = 0; i <= GRID_SIZE; i++) {
        gfx_HorizLine(0, i * 20, GRID_SIZE * 20);
        gfx_VertLine(i * 20, 0, GRID_SIZE * 20);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j] == 1) {
                if (mines[i][j] == 1) {
                    gfx_FillRectangle(i * 20, j * 20, 20, 20);
                } else {
                    int count = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (i + x >= 0 && i + x < GRID_SIZE && j + y >= 0 && j + y < GRID_SIZE && mines[i + x][j + y] == 1) {
                                count++;
                            }
                        }
                    }
                    char str[2];
                    sprintf(str, "%d", count);
                    gfx_PrintStringXY(str, i * 20 + 6, j * 20 + 6);
                }
            }
        }
    }

    gfx_SwapDraw();
}

int main(void) {
    srand(rtc_Time()); // Seed random number generator with current time

    // Initialize graphics
    gfx_Begin();
    gfx_SetDrawBuffer();

    initializeGame();

    while (!os_GetCSC()) {
        int x = os_GetXKey();
        int y = os_GetYKey();
        int key = os_GetCSC();

        if (x != -1 && y != -1) {
            x /= 20;
            y /= 20;
            reveal(x, y);
            drawGrid();

            if (game_over) {
                gfx_PrintStringXY("Game Over", 100, 100);
                gfx_SwapDraw();
                break;
            }
        }
    }

    // Wait for any key before exiting
    while (!os_GetCSC());
    gfx_End();

    return 0;
}