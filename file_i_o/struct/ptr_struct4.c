#include <stdio.h>
#include <string.h>
struct Mahasiswa {
  char name[50];
  int usia;
};

void Ubah_usia(struct Mahasiswa *murid) {
  //murid->usia = 25; //seperti ini atau seperti dibawah ini 
  (*murid).usia=25;
}

int main(void) {
  struct Mahasiswa murid;

  strcpy(murid.name, "ucup");
  murid.usia = 20;

  printf("nama: %s\n", murid.name);
  printf("usia: %d\n", murid.usia);

  Ubah_usia(&murid);
  printf("nama: %s\n", murid.name);
  printf("usia: %d\n", murid.usia);

  return 0;
}
