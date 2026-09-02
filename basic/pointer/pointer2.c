#include <stdio.h>

int main(void) {
  int a = 100;
  int* p = &a;
  printf("alamat a: %p\n", &a);
  printf("isi p : %p\n", p);
  printf("nilai *p : %d\n", *p);
  return 0;
}
