// latihan realoc data dari malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int input_data, realoc_data;
  int *data;

  printf("data yang ingin anda inputkan: ");
  scanf("%d", &input_data);

  data = malloc(input_data * sizeof(int));

  if (data == NULL) {
    printf("malloc  gagal\n");
    return 1;
  }
  for (int i = 0; i < input_data; i++) {
    printf("masukan data ke %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("\n\n======DATA ANDA ======\n\n");
  for (int i = 0; i < input_data; i++) {
    printf("index data ke %d = %d\n", i, data[i]);
  }

  printf("data yang ingin diubah: ");
  scanf("%d", &realoc_data);

  int *ptr_realoc_data = realloc(data, realoc_data * sizeof(int));
  if (ptr_realoc_data == NULL) {
    printf("realoc gagal\n");
    return 1;
  }
  data = ptr_realoc_data;

  for (int i = input_data; i < realoc_data; i++) {
    printf("masukan data ke %d =", i + 1);
    scanf("%d", &ptr_realoc_data[i]);
  }
  /// data sekarang
  printf("============DATA SEKARANG =======\n\n");
  for (int i = 0; i < realoc_data; i++) {
    printf("index data ke %d = %d\n", i, ptr_realoc_data[i]);
  }
  free(data);
  return 0;
}
