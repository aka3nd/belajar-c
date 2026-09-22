#include <stdio.h>
int main(void) {
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("error buka file");
    return 1;
  }

  int baca;
  while ((baca = fgetc(file)) != EOF) {
    printf("%c", baca);
  }
  fclose(file);
  return 0;
}
