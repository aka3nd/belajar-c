#include <stdio.h>
int main(void) {
  FILE *file = fopen("angka.bin", "rb");

  if (file == NULL) {
    printf("gagal dibuka atau dibuat\n");
    return 1;
  }

  int angka[3];
  fread(angka, sizeof(int), 3, file);

  for (int i = 0; i < 3; i++) {
    printf("angka index ke %d = %d\n", i, angka[i]);
  }

  fclose(file);
  return 0;
}
