#include <stdio.h>
int main() {
  // char nama[5] = {'A', 'i', 'n', 'g', '\0'}; //definisi arayy bisa seperti ini
  char name[] = "aing";
  char *ptr = name;
  printf("%s\n", ptr);
  return 0;
}
