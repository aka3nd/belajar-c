#include <stdio.h>
#include <string.h>
struct Mahasiswa {
  char name[50];
  int usia;
};

int main(void) {
  struct Mahasiswa mhs[3];

  strcpy(mhs[0].name, "Udin");
  mhs[0].usia = 20;
  strcpy(mhs[1].name, "Otong");
  mhs[1].usia = 21;
  strcpy(mhs[2].name, "Budi");
  mhs[2].usia = 22;

  for (int i = 0; i < 3; i++) {
    printf("nama: %s\n", mhs[i].name);
    printf("usia: %d\n", mhs[i].usia);
  }

  struct Mahasiswa *ptr = mhs;
  for (int i = 0; i < 3; i++) {
    printf("nama: %s\n", (ptr + i)->name);
    printf("usia: %d\n", (ptr + i)->usia);
  }

  return 0;
}
