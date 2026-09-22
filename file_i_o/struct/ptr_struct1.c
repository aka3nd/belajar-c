// pointer ke struct

#include <stdio.h>
struct Mahasiswa{
  char *nama;
  int usia;
};

int main(void){
  struct Mahasiswa mhs = {"udin",24};
  struct Mahasiswa *ptr = &mhs;

  printf("\n\n============sebelum=======\n\n");
  printf("nama: %s\n",ptr->nama);
  printf("usia: %d\n",ptr->usia);

  printf("\n\n============sesudah=======\n\n");
  ptr->nama="otong";
  ptr->usia=50;
  printf("nama: %s\n",ptr->nama);
  printf("usia: %d\n",ptr->usia);
  return 0;
}
