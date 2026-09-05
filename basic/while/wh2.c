#include <stdio.h>

int main(void) {
  char file;
  printf("masukan caracter: ");
  scanf("%c", &file);

  while (file == 'c') {
    printf("ini carakter c ");
    break;
  }

  return 0;
}
