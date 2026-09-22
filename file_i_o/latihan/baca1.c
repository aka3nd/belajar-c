#include <stdio.h>
int main(void) {
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("error buka file");
    return 1;
  }

  char baca;
  baca = fgetc(file);
  printf("%c",baca);

  baca = fgetc(file); //maju satu caracter pembacaannya;
  printf("%c",baca);

  while((baca = fgetc(file)) != EOF){
    printf("%c",baca);
  }
  fclose(file);
  return 0;
}
