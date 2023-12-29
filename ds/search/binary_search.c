#include <stdio.h>

int binary_search(int ar[], int len, int target) {
  int first = 0;
  int last = len - 1;
  int mid;

  while (first <= last) {
    mid = (first + last) / 2;
    if (ar[mid] == target) {
      return mid;
    } else {
      if (target < ar[mid]) {
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }
  }

  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int idx;

  idx = binary_search(arr, sizeof(arr) / sizeof(int), 7);
  if (idx == -1) {
    printf("Not found\n");
  } else {
    printf("Element found at %d\n", idx);
  }

  idx = binary_search(arr, sizeof(arr) / sizeof(int), 8);
  if (idx == -1) {
    printf("Not found\n");
  } else {
    printf("Element found at %d\n", idx);
  }

  return 0;
}