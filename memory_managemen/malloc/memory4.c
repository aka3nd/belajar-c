#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *data;
  int angka = 5;
  data = malloc(sizeof(int));
  *data = 500;
  printf("nilai data: %d\n",*data);
  printf("nilai data: %d\n",angka);
  free(data);
  return 0;
}
