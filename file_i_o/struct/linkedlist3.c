#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
  char nama[50];
  int usia;
  struct Node *next;
} Node;

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

  tambah_awal(&head, "Udin", 20);
  tambah_awal(&head, "Otong", 30);
  tambah_awal(&head, "Dadang", 40);
  const Node *sekarang = head;

  while (sekarang != NULL) {
    printf("Nama: %s, Usia: %d\n", sekarang->nama, sekarang->usia);

    sekarang = sekarang->next;
  }

  return 0;
}
