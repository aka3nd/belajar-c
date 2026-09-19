#include <stdio.h>
int main(void) {
  FILE *file = fopen("mahasiswa.txt", "r");
  if (file == NULL) {
    printf("file gagal dibuka/format tidak valid\n");
    return 1;
  }
  char nama[50];
  int umur;

  while (fscanf(file, "%49s %d", nama, &umur) == 2) {
    printf("Nama: %s | Umur: %d\n", nama, umur);
  }
  fclose(file);
  return 0;
}
