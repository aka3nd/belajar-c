#include <stdio.h>
#include <string.h>
int main(void) {
  FILE *file = fopen("nama_umur.txt", "r");
  if (file == NULL) {
    return 1;
  }
  char baris[100];
  char buff[50];
  int usia;
  while (fgets(baris, sizeof(baris), file) != NULL) {
    if (sscanf(baris, "%49s %d", buff, &usia) == 2) {
      printf("nama: %s\n", buff);
      printf("usia: %d\n", usia);
    } else {
      printf("format data salah %s", baris);
    }
  }
  fclose(file);
  return 0;
}
