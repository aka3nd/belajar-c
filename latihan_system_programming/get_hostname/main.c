// fungsi sederhana
//
void tambah(int *angka) { *angka = 100; }
#include <stdio.h>
int main(void) {
  int number = 10;

  printf("nilai awal number: %d\n", number);
  tambah(&number);
  printf("nilai awal akhir: %d\n", number);
  return 0;
}
