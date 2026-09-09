#include <stdio.h>
#include <stdlib.h>
int main(void){
  size_t angka = 5;
  int *ptr;
  ptr = malloc(angka);
  if(ptr == NULL){
    printf("malloc gagal\n");
  }
  *ptr = 100;
  printf("angka ptr: %d",*ptr);
  free(ptr);
  return 0;
}
