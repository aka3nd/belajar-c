#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *data;
  data = malloc(sizeof(int));
  *data = 100;
  printf("nilai data adalah: %d", *data);
  free(data);
  return 0;
}
