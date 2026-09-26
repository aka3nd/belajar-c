#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Mahasiswa {
  char nama[50];
  int usia;
};

int main(void) {
  int jumlah;
  printf("jumlah data yang ingin diinput: ");
  scanf("%d",&jumlah);

  struct Mahasiswa *murid;
  murid = malloc(jumlah * sizeof(struct Mahasiswa));

  if (murid == NULL) {
    return 1;
  }
  for (int i = 0; i < jumlah; i++) {
    printf("data murid ke: %d\n", i + 1);
    printf("nama: ");
    scanf("%49s", murid[i].nama);

    printf("Usia: ");
    scanf("%d", &murid[i].usia);
  }

  for (int i = 0; i < jumlah; i++) {
    printf("nama: %s usia: %d\n", murid[i].nama, murid[i].usia);
  }
  free(murid);
  return 0;
}
