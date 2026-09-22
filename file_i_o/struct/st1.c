// belajar struct
#include <stdio.h>
#include <string.h>
struct Orang {
  char nama[50];
  int usia;
  float tinggi;
};

int main(void) {
  struct Orang orang;
  strcpy(orang.nama, "Budi");
  orang.usia = 25;
  orang.tinggi = 170.5;

  printf("nama: %s\n", orang.nama);
  printf("usia: %d\n", orang.usia);
  printf("tinggi badan: %.1f cm\n", orang.tinggi);

  return 0;
}
