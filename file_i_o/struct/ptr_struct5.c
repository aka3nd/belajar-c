#include <stdio.h>
#include <string.h>
struct Mahasiswa {
  char nama[50];
  int usia;
};
int main(void) {
  struct Mahasiswa murid[3];
  strcpy(murid[0].nama, "udin");
  murid[0].usia = 15;
  strcpy(murid[1].nama, "otong");
  murid[1].usia = 18;
  strcpy(murid[2].nama, "didin");
  murid[2].usia = 20;

  struct Mahasiswa *ptr = murid;
  printf("%s %d\n", ptr->nama, ptr->usia);

  ptr++;

  printf("%s %d\n", ptr->nama, ptr->usia);
  
  ptr++;

  printf("%s %d\n", ptr->nama, ptr->usia);


  struct Mahasiswa *ptr2 = murid;
  printf("%s %d\n", ptr2->nama, ptr2->usia);
  ptr2 = &murid[1];
  printf("%s %d\n", ptr2->nama, ptr2->usia);
  ptr2 = &murid[2];
  printf("%s %d\n", ptr2->nama, ptr2->usia);

  return 0;
}
