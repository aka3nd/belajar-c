#include <stdio.h>

int angka(int a, int b){
  int result = a*b;
  return result;
}

int main(void){
  int angka1,angka2;

  printf("masukan angka pertama: ");
  scanf("%d",&angka1);
  printf("masukan angka kedua: ");
  scanf("%d",&angka2);

  printf("hasilnya adalah: %d\n",angka(angka1,angka2));

  return 0;
}
