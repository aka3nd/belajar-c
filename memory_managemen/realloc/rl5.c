#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int input_data;
  int *data;

  printf("masukan data yang ingin diinput: ");
  scanf("%d", &input_data);

  data = malloc(input_data * sizeof(int));
  if (data == NULL) {
    return 1;
  }
  for (int i = 0; i < input_data; i++) {
    printf("inputkan data %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("\nData anda....\n");
  for (int i = 0; i < input_data; i++) {
    printf("data index ke %d = %d\n", i, data[i]);
  }

  printf("\nrealok data\n");

  int input_data_realoc;
  int *ptr_realok;

  printf("masukan data yang ingin diinput: ");
  scanf("%d", &input_data_realoc);
  ptr_realok = realloc(data, input_data_realoc * sizeof(input_data_realoc));

  if (ptr_realok == NULL) {
    printf("realok gagal\n");
    free(data);
    return 1;
  }

  data = ptr_realok;

  for (int i = input_data; i < input_data_realoc; i++) {
    printf("masukan data: %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("\nData anda....\n");
  for (int i = 0; i < input_data_realoc; i++) {
    printf("data index ke %d = %d\n", i, data[i]);
  }
  free(data);
  return 0;
}
