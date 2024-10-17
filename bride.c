#include <stdio.h>

int bridesInNeighbourhood(int* matrix[], int* size, int x, int y) {
    int numberOfNeighbours = 0;

    if (x != 0 && y != 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (matrix[x + i][y + j] == 1)
                    numberOfNeighbours++;
            }
        }
    }

    return numberOfNeighbours;
}

void main() {
    int size[2];

    printf("Please enter the size of the matrix.\n");
    printf("Rows: ");
    scanf("%d", &size[0]);
    printf("Columns: ");
    scanf("%d", &size[1]);

    int matrix[size[0]][size[1]];

    printf("Please enter the matrix elements.\n");
    printf("The format would be assumed as follows:\n");

    int numberOfBrides = 0;

    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            printf("\n>> ");
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1)
                numberOfBrides++;
        }
    }

    struct Bride {
        int x;
        int y;
        int numberOfNeighbours;
    } brides[numberOfBrides];
    int indexForBrides = 0;
    for (int i = 0; i < numberOfBrides; i++) {
        brides[i].x = 0;
        brides[i].y = 0;
        brides[i].numberOfNeighbours = 0;
    }
}