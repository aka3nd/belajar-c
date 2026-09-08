#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int *angka;
  angka = malloc(sizeof(int));
  if (angka == NULL) {
    printf("gagal mengalokasikan memory\n");
    return 1;
  }
  *angka = 500;

  printf("nilai angka: %d\n", *angka);
  free(angka);
  return 0;
}
