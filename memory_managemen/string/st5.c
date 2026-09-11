#include <stdio.h>
int main(void) {
  char nama[] = "Aing";
  char *ptr = nama;
  *ptr = 'B';
  printf("%s\n", nama);

  return 0;
}
