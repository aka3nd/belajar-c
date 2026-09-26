#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
  char nama[50];
  int usia;
  struct Node *next;
} Node;

int main(void) {
  Node *pertama, *kedua, *ketiga;
  pertama = malloc(sizeof(Node));
  kedua = malloc(sizeof(Node));
  ketiga = malloc(sizeof(Node));
  if (pertama == NULL || kedua == NULL || ketiga == NULL) {
    free(pertama);
    free(kedua);
    free(ketiga);
    return 1;
  }

  // pertama
  strcpy(pertama->nama, "Udin");
  pertama->usia = 20;
  pertama->next = kedua;

  // kedua
  strcpy(kedua->nama, "Otong");
  kedua->usia = 25;
  kedua->next = ketiga;

  // ketiga
  strcpy(ketiga->nama, "Dadang");
  ketiga->usia = 30;
  ketiga->next = NULL;

  Node *sekarang = pertama;

  while (sekarang != NULL) {
    printf("nama: %s\n", sekarang->nama);
    printf("nama: %d\n", sekarang->usia);

    sekarang = sekarang->next;
  }

  free(ketiga);
  free(kedua);
  free(pertama);

  return 0;
}
