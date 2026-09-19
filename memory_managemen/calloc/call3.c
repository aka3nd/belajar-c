#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  size_t angka = 3;
  int *data = calloc(angka, sizeof(int));
  if (data == NULL) {
    printf("callc gagal\n");
    return 1;
  }
  for (int i = 0; i < angka; i++) {
    printf("masukan data ke %d = ", i + 1);
    scanf("%d", &data[i]);
  }
  for (int i = 0; i < angka; i++) {
    printf("data anda: %d\n", data[i]);
  }

  free(data);
  return 1;
}
