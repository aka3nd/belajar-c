#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Mahasiswa{
  char nama[50];
  int usia;
};

int main(void){
  struct Mahasiswa *mhs = malloc(sizeof(struct Mahasiswa));

  if(mhs == NULL){
    return 1;
  }
  //strcpy(mhs->nama,"dadang"); //cara pertama
  mhs->usia = 50;

  char *buff = "otong"; //cara kedua

  strcpy(mhs->nama,buff);

  printf("nama: %s\n",mhs->nama);
  printf("usia: %d\n",(*mhs).usia);

  free(mhs);

  return 0;
}
