#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int input_angka;
  int *data;

  printf("berapa data yang ingin diinput: ");
  scanf("%d", &input_angka);
  data = malloc(input_angka * sizeof(int));
  if (data == NULL) {
    printf("maloc gagal dibuat\n");
    return 1;
  }

  for (int i = 0; i < input_angka; i++) {
    printf("masukan data ke %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("=========DATA=========\n\n");
  for (int i = 0; i < input_angka; i++) {
    printf("index data ke %d = %d\n", i, data[i]);
  }

  free(data);
  return 0;
}
