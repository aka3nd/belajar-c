#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *number = calloc(3, sizeof(int));
  if (number == NULL) {
    printf("error\n");
    return 1;
  }

  *number = 100;
  *(number + 1) = 200;
  *(number + 2) = 300;

  printf("%d\n", number[0]);
  printf("%d\n", number[1]);
  printf("%d\n", number[2]);

  free(number);
  return 0;
}
