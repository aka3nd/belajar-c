#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int angka = 2;
  int *data;
  data = malloc(angka * sizeof(int));
  if (data == NULL) {
    printf("malloc gagal\n");
    return 1;
  }
  data[0] = 100;
  data[1] = 200;

  printf("data sebelum realoc\n");
  for (int i = 0; i < 2; i++) {
    printf("data ke: %d = %d\n", i, data[i]);
  }

  // data = realloc(data, 4 * sizeof(int)); //ini sudah benar lebih baik pakai
  // pointer sementaraa
  int *temp = realloc(data, 4 * sizeof(int));
  if (temp == NULL) {
    printf("realoc gagal\n");
    free(data);
    return 1;
  }

  data = temp; //disamakan dengan variabel temp

  data[2] = 300;
  data[3] = 500;
  printf("data sesudah realoc\n");
  for (int i = 0; i < 4; i++) {
    printf("data ke: %d = %d\n", i, data[i]);
  }
  free(data);
  return 0;
}
