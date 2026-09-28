#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
  char nama[50];
  int usia;

  struct Node *next;
} Node;

//tambah node diawal

void tambah_awal(Node **head, char *nama, int usia) {
  Node *baru = malloc(sizeof(Node));

  if (baru == NULL) {
    return;
  }

  strcpy(baru->nama, nama);
  baru->usia = usia;
  baru->next = *head;
  *head = baru;
}

int main(void) {

  Node *head = NULL;
  tambah_awal(&head, "Udin", 22);
  tambah_awal(&head, "Jajang", 27);

  Node *sekarang = head;
  while (sekarang != NULL) {
    printf("nama: %s\n", sekarang->nama);
    printf("usia: %d\n", sekarang->usia);

    sekarang = sekarang->next;
  }

  return 0;
}
