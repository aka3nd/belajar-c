#include <stdio.h>

int main(void) {
  int name = 5;
  const int *Cmane = &name;

  printf("angka yang cmane: %d\n", *Cmane);
  return 0;
}
