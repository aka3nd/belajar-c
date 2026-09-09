#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int input_data;
  printf("berapa data yang ingin anda\nInput?: ");
  scanf("%d", &input_data);

  int *data = malloc(input_data * sizeof(int));
  if (data == NULL) {
    printf("malloc gagal\n");
    return 1;
  }

  for (int i = 0; i < input_data; i++) {
    printf("input data ke : %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < input_data; i++) {
    printf("data ke %d = %d\n", i + 1, data[i]);
  }

  // realokasi.................

  int data_realoc;

  printf("realokasi data: ");
  scanf("%d", &data_realoc);

  int *temp = realloc(data, data_realoc * sizeof(int));
  if (temp == NULL) {
    printf("gagal realokasi\n");
    free(data);
    return 1;
  }

  data = temp;

  for (int i = input_data; i < data_realoc; i++) {
    printf("input data ke : %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("sesudah realloc\n");

  for (int i = 0; i < data_realoc; i++) {
    printf("data ke %d = %d\n", i + 1, data[i]);
  }
  free(data);
  return 0;
}
