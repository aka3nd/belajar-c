#include <stdio.h>
#include <string.h>
struct Mahasiswa{
  char name[50];
  int umur;
  float nilai;
};


int main(int argc, char *argv[])
{
  struct Mahasiswa udin;
  strcpy(udin.name,"jokowi dodo");
  udin.umur = 28;
  udin.nilai = 5.2;

  printf("nama: %s\n",udin.name);
  printf("umur: %d\n",udin.umur);
  printf("nilai: %.2f\n",udin.nilai);
  return 0;
}
