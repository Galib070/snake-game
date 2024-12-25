#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int i, j, field[WIDTH][HEIGHT];
int x, y, gy, head, tail, gameover;
int fx, fy, flag, var;

void setup() {
    gameover = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    gy = y;
    head = 5;
    tail = 1;
    for (i = 0; i < head; i++) {
        gy++;
        field[x][gy - head] = i + 1;
    }
    fx = rand() % 18 + 1;
    fy = rand() % 18 + 1;
    field[fx][fy] = -1;
}

void print() {
    for (i = 0; i < WIDTH; i++) {
        if (i == 0) {
            printf("\n");
        }
        for (j = 0; j < HEIGHT; j++) {
            if (field[i][j] == 0) {
                printf(" ");
            }
            if (field[i][j] > 0 && field[i][j] != head) {
                printf("o");
            }
            if (field[i][j] == head) {
                printf("O");
            }
            if (field[i][j] == -1) {
                printf("F");
            }
            if (j == WIDTH - 1) {
                printf("\n");
            }
        }
    }
}

void resetScreenPosition() {
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void movement() {
    var = _getch();
    switch (var) {
    case 'w':
        flag = 1;
        break;
    case 'a':
        flag = 2;
        break;
    case 's':
        flag = 3;
        break;
    case 'd':
        flag = 4;
        break;
    }
}

void gameLogic() {
    switch (flag) {
    case 1:
        y--;
        if (y == -1)
            y = HEIGHT - 1;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameover = 1;
        }
        if (field[x][y] == -1) {
            tail -= 2;
            fx = rand() % 18 + 1;
            fy = rand() % 18 + 1;
            field[fx][fy] = -1;
        }
        head++;
        field[x][y] = head;
        break;
    case 2:
        x--;
        if (x == -1)
            x = WIDTH - 1;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameover = 1;
        }
        if (field[x][y] == -1) {
            tail -= 2;
            fx = rand() % 18 + 1;
            fy = rand() % 18 + 1;
            field[fx][fy] = -1;
        }
        head++;
        field[x][y] = head;
        break;
    case 3:
        y++;
        if (y == HEIGHT)
            y = 0;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameover = 1;
        }
        if (field[x][y] == -1) {
            tail -= 2;
            fx = rand() % 18 + 1;
            fy = rand() % 18 + 1;
            field[fx][fy] = -1;
        }
        head++;
        field[x][y] = head;
        break;
    case 4:
        x++;
        if (x == WIDTH)
            x = 0;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameover = 1;
        }
        if (field[x][y] == -1) {
            tail -= 2;
            fx = rand() % 18 + 1;
            fy = rand() % 18 + 1;
            field[fx][fy] = -1;
        }
        head++;
        field[x][y] = head;
        break;
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (field[i][j] == tail) {
                field[i][j] = 0;
            }
        }
    }
    tail++;
}

int main() {
    setup();
    while (!gameover) {
        resetScreenPosition();
        print();
        movement();
        gameLogic();
        Sleep(100);
    }
    printf("Game Over!\n");
    return 0;
}
