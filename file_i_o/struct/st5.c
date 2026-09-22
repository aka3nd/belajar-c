#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Mahasiswa {
  char *nama;
  int usia;
};

int main(void) {
  struct Mahasiswa udin, otong;
  udin.usia = 25;

  const char *nama = "udin";
  udin.nama = malloc(strlen(nama) + 1);
  strcpy(udin.nama, nama);

  printf("nama: %s\n", udin.nama);
  printf("usia: %d\n", udin.usia);

  // kedua
  otong.usia = 34;
  const char *nama1 = "otong";
  otong.nama = malloc(strlen(nama1) + 1);
  strcpy(otong.nama, nama1);
  printf("nama: %s\n", otong.nama);
  printf("usia: %d\n", otong.usia);

  free(udin.nama);
  free(otong.nama);

  return 0;
}
