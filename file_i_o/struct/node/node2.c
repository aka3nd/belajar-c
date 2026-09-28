#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char nama[50];
  int usia;

  struct Node *next;
} Node;

// tambah node diakhir
void tambah_akhir(Node **node, char *nama, int usia) {
  Node *baru = malloc(sizeof(Node));
  if (baru == NULL) {
    printf("gagal membuat malloc\n");
    return;
  }
  strcpy(baru->nama, nama);
  baru->usia = usia;

  baru->next = NULL;
  if (*node == NULL) {
    *node = baru;
    return;
  }

  Node *sekarang = *node;
  while (sekarang->next != NULL) {
    sekarang = sekarang->next;
  }
  sekarang->next = baru;
}

int main(void) {

  Node *head = NULL;

  tambah_akhir(&head, "Udin", 23);
  tambah_akhir(&head, "Jamal", 25);
  tambah_akhir(&head, "Rara", 19);

  Node *sekarang = head;

  while (sekarang != NULL) {
    printf("Nama: %s\n", sekarang->nama);
    printf("Usia: %d\n", sekarang->usia);

    sekarang = sekarang->next;
  }
  return 0;
}
