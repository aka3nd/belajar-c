#include <stdio.h>
#include <string.h>

typedef struct{
  char name[50];
  int age;
}Mahasiswa;


int main(int argc, char *argv[])
{
  Mahasiswa udin;
  strcpy(udin.name,"udin");
  udin.age = 28;
  printf("namaku: %s\n",udin.name);
  printf("umurku : %d",udin.age);

  return 0;
}
