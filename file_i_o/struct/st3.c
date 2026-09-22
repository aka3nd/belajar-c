#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Mahasiswa{
  char *nama;
  int usia;
};

int main(void){
  struct Mahasiswa udin,otong;
  char *nama = "udin";
  
  udin.usia= 24;
  udin.nama = malloc(strlen(nama)+1);
  strcpy(udin.nama,nama);
  printf("nama: %s\n",udin.nama);
  printf("usia: %d\n",udin.usia);

  nama = "ucup";
  otong.nama= malloc(strlen(nama) + 1);
  otong.usia=24;
  strcpy(otong.nama,nama);;
  printf("nama: %s\n",otong.nama);
  printf("usia: %d\n",otong.usia);



  free(udin.nama);
  free(otong.nama);

  return 0;
}
