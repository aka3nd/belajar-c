#include <stdio.h>

int result(int a,int b);

int main() {
  int a, b, hasil;
  printf("masukan angka pertama: ");
  scanf("%d", &a);
  printf("masukan angka kedua: ");
  scanf("%d", &b);

  hasil = result(a, b);
  printf("hasilnya adalah: %d\n", hasil);
  return 0;
}
int result(int a, int b) { return a * b; }
