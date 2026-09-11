#include <stdio.h>
int main() {
  char name[] = "aing";
  char *ptr = name;
  printf("%c\n", *ptr);
  printf("%c\n", *(ptr+1));
  return 0;
}
