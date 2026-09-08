#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *angka;
  angka = malloc(sizeof(int));
  *angka = 100;
  printf("nilai angka: %d\n", *angka);

  free(angka);
  return 0;
}
