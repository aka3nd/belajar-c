#include <stdio.h>
void angka(void) {
  int nilai = 5;
  printf("angka : %d\n", nilai);
}

int main(void) {
  void (*number)(void);
  number = angka;
  number();
  return 0;
}
