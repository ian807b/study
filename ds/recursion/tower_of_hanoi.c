#include <stdio.h>

// "num" of rings @ "from" move to "to" through "by"
void HanoiTowerMove(int num, char from, char by, char to) {
  if (num == 1) {
    printf("Ring 1 moves from %c to %c \n", from, to);
  } else {
    HanoiTowerMove(num - 1, from, to, by);
    printf("Ring %d moves from %c to %c \n", num, from, to);
    HanoiTowerMove(num - 1, by, from, to);
  }
}

int main() {
  HanoiTowerMove(4, 'A', 'B', 'C');

  return 0;
}