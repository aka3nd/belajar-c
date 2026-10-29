#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  size_t angka = 3;
  int *data = calloc(angka,sizeof(int));
  if (data == NULL) {
    perror("calloc gagal");
    return 1;
  }
  data[0] = 2;
  data[1] = 5;
  data[2] = 9;

  for (int i = 0; i < angka; i++) {
    printf("data anda: %d\n", data[i]);
  }
  return 0;
}
