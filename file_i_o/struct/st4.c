// array of struct

#include <stdio.h>
struct Mahasiswa {
  char *nama;
  int usia;
};

int main(void) {
  struct Mahasiswa mahasiswa[3];
  mahasiswa[0].nama = "udin";
  mahasiswa[0].usia = 25;

  mahasiswa[1].nama = "otong";
  mahasiswa[1].usia = 29;

  mahasiswa[2].nama = "dodo";
  mahasiswa[2].usia = 33;

  for (int i = 0; i < 3; i++) {
    printf("nama: %s\n", mahasiswa[i].nama);
    printf("usia: %d\n", mahasiswa[i].usia);
  }

  return 0;
}
