#include <stdio.h>
int main(void) {
  int angka = 10;
  int *ptr = &angka;
  int **ptr2 = &ptr;

  printf("angka : %d\n", angka);
  printf("ptr : %d\n", *ptr);
  printf("ptr2 : %d\n", **ptr2);

  // diubah
  **ptr2 = 50;
  printf("angka : %d\n", angka);
  printf("ptr : %d\n", *ptr);
  printf("ptr2 : %d\n", **ptr2);

  return 0;
}
