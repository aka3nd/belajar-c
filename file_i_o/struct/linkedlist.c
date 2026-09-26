#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char nama[50];
  int usia;

  struct Node *next;
} Node;

int main(void) {

  Node *pertama;
  Node *kedua;

  pertama = malloc(sizeof(Node));
  kedua = malloc(sizeof(Node));

  if (pertama == NULL || kedua == NULL) {
    free(pertama);
    free(kedua);
    return 1;
  }

  strcpy(pertama->nama, "udin");
  pertama->usia = 20;
  pertama->next = kedua;

  printf("Nama: %s\n", pertama->nama);
  printf("Usia: %d\n", pertama->usia);

  strcpy(kedua->nama, "asep");
  kedua->usia = 24;

  printf("Nama: %s\n", pertama->next->nama);
  printf("Usia: %d\n", pertama->next->usia);
  kedua->next = NULL;

  free(pertama);

  return 0;
}
