#include <stdio.h>

struct Bride {
  int x;
  int y;
  int numberOfNeighbours;
  int distanceFromBoy;
};

// calculate number of neighbors for a given bride
int helperFunction(int skipValueForI, int skipValueForJ, int* size,
  int matrix[size[0]][size[1]], int x, int y) {
  int numberOfNeighbours = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      else if (i == skipValueForI || j == skipValueForJ)
        continue;
      else if (matrix[x + i][y + j] == 1)
        numberOfNeighbours++;
    }
  }
  return numberOfNeighbours;
}

int bridesInNeighbourhood(int* size, int matrix[size[0]][size[1]], int x,
  int y) {
  int rows = size[0], cols = size[1];
  int numberOfNeighbours = 0;
  if (x != 0 && y != 0 && x != (rows - 1) && y != (cols - 1)) {
    numberOfNeighbours = helperFunction(10, 10, size, matrix, x, y);
  }
  else if (x == 0 && y == (cols - 1)) {
    numberOfNeighbours = helperFunction(-1, 1, size, matrix, x, y);
  }
  else if (x == (rows - 1) && y == 0) {
    numberOfNeighbours = helperFunction(1, -1, size, matrix, x, y);
  }
  else if (x == (rows - 1) && y == (cols - 1)) {
    numberOfNeighbours = helperFunction(1, 1, size, matrix, x, y);
  }
  else if (x == (rows - 1)) {
    numberOfNeighbours = helperFunction(1, 10, size, matrix, x, y);
  }
  else if (x == 0) {
    numberOfNeighbours = helperFunction(-1, 10, size, matrix, x, y);
  }
  else if (y == 0) {
    numberOfNeighbours = helperFunction(10, -1, size, matrix, x, y);
  }
  else if (y == (cols - 1)) {
    numberOfNeighbours = helperFunction(10, 1, size, matrix, x, y);
  }
  return numberOfNeighbours;
}

void main() {
  int size[2];

  printf("Please enter the size of the matrix.\n");
  // printf("Rows: ");
  // scanf("%d", &size[0]);
  // printf("Columns: ");
  // scanf("%d", &size[1]);
  scanf("%d %d", &size[0], &size[1]);

  int matrix[size[0]][size[1]];

  printf("Please enter the matrix elements.\n");
  int numberOfBrides = 0;

  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      scanf("%d", &matrix[i][j]);
      if (matrix[i][j] == 1)
        numberOfBrides++;
    }
  }

  struct Bride brides[numberOfBrides];

  int index = 0;
  int maxNeighbours = 0;
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      if (matrix[i][j] == 1) {
        brides[index].x = i;
        brides[index].y = j;
        brides[index].numberOfNeighbours =
          bridesInNeighbourhood(size, matrix, i, j);
        if (brides[index].numberOfNeighbours > maxNeighbours)
          maxNeighbours = brides[index].numberOfNeighbours;
        index++;
      }
    }
  }
  index = 0;

  struct Bride favourableBride;
  favourableBride.distanceFromBoy = 0;
  int numberOfBridesWithMaxQualities = 0;
  for (int i = 0; i < numberOfBrides; i++) {
    if (brides[i].numberOfNeighbours == maxNeighbours) {
      numberOfBridesWithMaxQualities++;
      favourableBride = brides[i];
    }
  }

  // if there is only one girl with most qualities she is the bride
  // hence display her details and end program
  if (numberOfBridesWithMaxQualities == 1) {
    printf("%d:%d:%d\n", favourableBride.x + 1, favourableBride.y + 1,
      favourableBride.numberOfNeighbours);
    return;
  }

  index = 0;
  struct Bride bridesWithMaxQualities[numberOfBridesWithMaxQualities];
  int minDistanceFromBoy = size[0] + size[1];
  for (int i = 0; i < numberOfBrides; i++) {
    if (brides[i].numberOfNeighbours == maxNeighbours) {
      bridesWithMaxQualities[index] = brides[i];
      bridesWithMaxQualities[index].distanceFromBoy = brides[i].x + brides[i].y;
      if (bridesWithMaxQualities[index].distanceFromBoy < minDistanceFromBoy) {
        minDistanceFromBoy = bridesWithMaxQualities[index].distanceFromBoy;
      }
      index++;
    }
  }

  int numberOfFavourableBrides = 0;
  for (int i = 0; i < numberOfBridesWithMaxQualities; i++) {
    if (bridesWithMaxQualities[i].distanceFromBoy == minDistanceFromBoy) {
      numberOfFavourableBrides++;
      favourableBride = bridesWithMaxQualities[i];
    }
  }

  if (numberOfFavourableBrides > 1) {
    printf("Polygamy not allowed!\n");
    return;
  }

  // for (int i = 0; i < numberOfBridesWithMaxQualities; i++) {
  //   if (bridesWithMaxQualities[i].distanceFromBoy == minDistanceFromBoy) {
  //     favourableBride = bridesWithMaxQualities[i];
  //   }
  // }


  printf("%d:%d:%d\n", favourableBride.x + 1, favourableBride.y + 1,
    favourableBride.numberOfNeighbours);
  return;
}