#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x * size + y) = 0;
        }
    }

    for (int k = 0; k < 8; k++) {
        int x = i + moves[k][0];
        int y = j + moves[k][1];
        if (x >= 0 && x < size && y >= 0 && y < size) {
            *(chessBoard + x * size + y) = 1;
        }
    }

    // Menampilkan array 2D
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d", *(chessBoard + x * size + y));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    int size = 8;
    int *chessBoard = (int *)malloc(size * size * sizeof(int));

    koboImaginaryChess(i, j, size, chessBoard);

    free(chessBoard);
    return 0;
}
