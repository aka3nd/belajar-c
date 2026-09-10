#include <stdio.h>
int main(void) {
  const int angka[] = {1, 3, 4, 5, 7};
  const int *ptr = angka;

  printf("%d\n", *ptr);
  ptr++;
  printf("%d\n", *ptr);

  // meundurkan posisi pointer
  ptr--;
  printf("%d\n", *ptr);

  return 0;
}
