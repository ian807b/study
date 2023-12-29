#include <stdio.h>

int linear_search(int ar[], int len, int target) {
  for (int i = 0; i < len; i++) {
    if (ar[i] == target) {
      return i;
    }
  }

  return -1;
}

int main() {
  int arr[] = {3, 5, 2, 4, 9};
  int idx;

  idx = linear_search(arr, sizeof(arr) / sizeof(int), 4);
  if (idx == -1) {
    printf("Not found\n");
  } else {
    printf("Element found at idx: %d\n", idx);
  }
  return 0;
}