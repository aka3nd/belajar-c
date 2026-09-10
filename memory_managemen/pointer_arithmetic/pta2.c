#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *data = malloc(3 * sizeof(int));
  if(data == NULL){
    printf("malloc gagal\n");
    return 1;
  }
  data[0]= 10;
  data[1]= 30;
  data[2]= 50;

  int *ptr = data;

  printf("data sebelum dimajukan pointernya\n\n");
  printf("data: %d\n",*ptr);

  printf("data sesudah dimajukan pointernya\n\n");
  ptr++;
  printf("data: %d\n",*ptr);
  free(data);
  data = NULL;
  return 0;
}
