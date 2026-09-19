#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int inputAngka;
  int *data;

  printf("masukan angka yang ingin\ndiinputkan: ");
  scanf("%d", &inputAngka);

  data = malloc(inputAngka * sizeof(int));
  if (data == NULL) {
    printf("malloc gagal\n");
    return 1;
  }

  for (int i = 0; i < inputAngka; i++) {
    printf("input data ke %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  printf("data yang dimasukan\n\n");
  for(int i = 0;i<inputAngka;i++){
    printf("data yang diinputkan ke %d = %d\n",i+1, data[i]);
  }
  free(data);

  return 0;
}
