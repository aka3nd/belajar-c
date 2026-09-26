#include <stdio.h>
struct Mahasiswa {
  char name[50];
  int usia;
};

void isi_data(struct Mahasiswa *mhs) { mhs->usia = 50; }

int main(void) {
  struct Mahasiswa mhs = {"udin", 20};
  printf("name: %s\n", mhs.name);
  printf("usia: %d\n", mhs.usia);

  isi_data(&mhs);
  printf("name: %s\n", mhs.name);
  printf("usia: %d\n", mhs.usia);
}
