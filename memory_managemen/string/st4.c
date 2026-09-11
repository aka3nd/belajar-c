#include <stdio.h>
#include <string.h>
int main(void) {
  char name[] = "Aing";
  char *ptr = name;
  printf("name: %s\n", name);

  // mengubah isi char
  *ptr = 'B';
  printf("name: %s\n", name);
  *(ptr+1) = 'o';
  printf("name: %s\n", name);
  //
  //atau seperti ini
  name[2]= 's';
  printf("name: %s\n", name);
  return 0;
}
