#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Orang {
  char *name;
  int usia;
};

int main(void) {
  struct Orang orang, orang2;
  const char *name = "Budi";
  orang.name = malloc(strlen(name) + 1);
  strcpy(orang.name, name);
  orang.usia = 25;

  printf("name: %s\n", orang.name);
  printf("usia: %d\n", orang.usia);

  const char *Andi = "Andi";
  orang2.name = malloc(strlen(Andi) + 1);
  strcpy(orang2.name, Andi);
  orang2.usia = 30;
  printf("name: %s\n", orang2.name);

  printf("usia: %d\n", orang2.usia);
  free(orang.name);
  free(orang2.name);
  return 0;
}
