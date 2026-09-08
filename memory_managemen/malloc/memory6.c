#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int jumlah;
  int *data;
  printf("jumlah data: ");
  scanf("%d", &jumlah);

  data = malloc(jumlah * sizeof(int));
  if (data == NULL) {
    printf("malloc gagal..\n");
    return 1;
  }

  for (int i = 0; i < jumlah; i++) {
    printf("data ke: %d = ", i + 1);
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < jumlah; i++) {
    printf("%d\n", data[i]);
  }
  free(data);
  return 0;
}
