#include <stdio.h>
#include <string.h>
struct Murid {
  char nama[50];
  int usia;
};

int ubah_usia(struct Murid *siswa) {
  siswa->usia = 40; 
  return 0;
}

int main(void) {
  struct Murid siswa;
  // siswa.nama="ucup"; //salah,harus pakai strcpy
  strcpy(siswa.nama, "ucup");
  siswa.usia = 20;

  printf("nama: %s\n", siswa.nama);
  printf("usia: %d\n", siswa.usia);

  if (ubah_usia(&siswa) == -1) {
    printf("gagal mengisi data\n");
    return 1;
  }
  printf("nama: %s\n", siswa.nama);
  printf("usia: %d\n", siswa.usia);

  return 0;
}
