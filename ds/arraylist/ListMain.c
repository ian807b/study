// Code from '윤성우의 열혈 자료 구조'

#include <stdio.h>

#include "ArrayList.h"

int main(void) {
  List list;
  int data;
  ListInit(&list);

  for (int i = 0; i < 9; i++) {
    LInsert(&list, i + 1);
  }

  printf("Number of data: %d \n", LCount(&list));

  if (LFirst(&list, &data)) {
    printf("%d ", data);

    while (LNext(&list, &data)) printf("%d ", data);
  }
  printf("\n\n");

  if (LFirst(&list, &data)) {
    if (data == 22) LRemove(&list);

    while (LNext(&list, &data)) {
      if (data == 22) LRemove(&list);
    }
  }

  printf("Number of data: %d \n", LCount(&list));

  if (LFirst(&list, &data)) {
    printf("%d ", data);

    while (LNext(&list, &data)) printf("%d ", data);
  }
  printf("\n\n");

  return 0;
}