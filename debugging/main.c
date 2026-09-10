#include <stdio.h>
int main(int argc, char *argv[]) {
  int angka = 2;
  int *ptr = &angka;
  printf("ptr: %d\n", *ptr);
  return 0;
}
