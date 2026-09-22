#include <stdio.h>
int main(void) {
  FILE *file = fopen("nama.txt", "r");
  if (file == NULL) {
    printf("gagal buka file\n");
    return 1;
  }

  char buff[100];
  int angka;
  while (fscanf(file, "%99s %d", buff, &angka) == 2) {
    printf("nama: %s\n", buff);
    printf("umur: %d\n", angka);
  }
  fclose(file);
  return 0;
}
