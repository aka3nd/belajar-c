#include <stdio.h>
#include <stdlib.h>
int main(void){
  int *data;
  data = malloc(2* sizeof(int));
  if(data == NULL){
    return 1;
  }
  data[0] = 10;
  data[1] = 20;

  printf("data: %d\n",*data);

  data++;
  printf("data: %d\n",*data);

  free(data);
  return 0;
}
