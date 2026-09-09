#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *data = calloc(2, sizeof(int));
  if (data == NULL) {
    printf("calloc gagal\n");
    return 1;
  }

  data[0] = 100;
  data[1] = 200;

  printf("sebelum realloc\n");
  for (int i = 0; i < 2; i++) {
    printf("data ke: %d = %d\n", i, data[i]);
  }

  printf("sesudah realoc\n");
  data = realloc(data, 4 * sizeof(int));

  if (data == NULL) {
    printf("realoc gagal\n");
    return 1;
  }
  data[2] = 300;
  data[3] = 400;
  for (int i = 0; i < 4; i++) {
    printf("data ke: %d = %d\n", i, data[i]);
  }

  free(data);
  return 0;
}
