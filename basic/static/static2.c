#include <stdio.h>

static void angka(void){
  angka = 1;
  angka++;
  printf("%d\n",angka);
}

int main(void){
  angka();

  return 0;
}
