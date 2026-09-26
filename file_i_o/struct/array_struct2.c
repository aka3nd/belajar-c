#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Mahasiswa {
  char nama[50];
  int usia;
};

int main(void) {
  struct Mahasiswa *murid;
  murid = malloc(3 * sizeof(struct Mahasiswa));

  if(murid == NULL){
    return 1;
  }

  strcpy(murid[0].nama, "udin");
  murid[0].usia = 15;

  strcpy(murid[1].nama, "otong");
  murid[1].usia = 18;

  strcpy(murid[2].nama, "didin");
  murid[2].usia = 20;

  printf("%s %d\n", murid[0].nama, murid[0].usia);
  printf("%s %d\n", murid[1].nama, murid[1].usia);
  printf("%s %d\n", murid[2].nama, murid[2].usia);

  free(murid);

  return 0;
}
