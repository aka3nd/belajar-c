#include <stdio.h>
int main(void) {
  FILE *file = fopen("angka.bin", "wb");
  if (file == NULL) {
    printf("gagal open berkas\n");
    return 1;
  }

  int angka[5] = {1, 2, 3, 4, 5};
  fwrite(angka,sizeof(int),5,file);

  fclose(file);
  return 0;
}
