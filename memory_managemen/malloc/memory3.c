#include <stdio.h>
#include <stdlib.h>
int main(void){
  int *a = malloc(sizeof(*a));
  *a = 100;
  printf("a: %d\t",*a);
  free(a);
  return 0;
}
