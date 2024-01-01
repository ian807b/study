#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target) {
  int mid;

  if (first > last) {
    return -1;
  }

  mid = (first + last) / 2;
  if (ar[mid] == target) {
    return mid;
  } else if (target < ar[mid]) {
    return BSearchRecur(ar, first, mid - 1, target);
  } else {
    return BSearchRecur(ar, mid + 1, last, target);
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11};
  int idx1, idx2;

  idx1 = BSearchRecur(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 9);
  if (idx1 == -1) {
    printf("Target = 9 not found \n");
  } else {
    printf("Target = 9 at index %d \n", idx1);
  }
  idx2 = BSearchRecur(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 4);
  if (idx2 == -1) {
    printf("Target = 4 not found \n");
  } else {
    printf("Target = 4 at index %d \n", idx1);
  }

  return 0;
}