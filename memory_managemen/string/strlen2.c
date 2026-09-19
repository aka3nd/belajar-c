#include <stdio.h>
#include <string.h>
int main(void){
  char nama[] = "otong";
  char *ptr = nama;

  printf("panjang nama: %zu\n",strlen(ptr));
  return 0;
}
