#include <stdio.h>
#include <stdlib.h>
int main(void) {
  FILE *file = fopen("buah_buahan.txt", "r");
  if (file == NULL) {
    printf("error buka file");
    return 1;
  }

  char baca[100];
  while (fgets(baca, sizeof(baca), file) != NULL) {
    printf("%s", baca);
  }
  fclose(file);

  return 0;
}
