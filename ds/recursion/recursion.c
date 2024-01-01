#include <stdio.h>

int factorial(int num) {
  if (num == 0 || num == 1) return 1;

  return num * factorial(num - 1);
}

int fib(int num) {
  if (num == 1) {
    return 0;
  } else if (num == 2) {
    return 1;
  } else {
    return fib(num - 2) + fib(num - 1);
  }
}

int main() {
  int ret = factorial(10);

  printf("10! = %d\n", ret);

  for (int i = 1; i <= 10; i++) {
    printf("%d ", fib(i));
  }

  return 0;
}
