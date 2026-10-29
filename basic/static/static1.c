#include <stdio.h>
void angka(void){
  int angka = 0;
  angka++;
  printf("%d\n",angka);
}

void angka1(void){
  static int angka = 0;
  angka++;
  printf("%d\n",angka);
}

int main(void){
  //variable normal hasilnya tetap satu,karna mereset keawal
  angka();
  angka();
  angka();

  angka1();
  angka1();
  angka1();

  return 0;
}
