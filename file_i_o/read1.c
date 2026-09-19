#include <stdio.h>
int main(int argc, char *argv[]) {
  FILE *file = fopen("nama_murid.txt", "r"); // r=baca file
  if (file == NULL) {
    printf("gagal buka file\n");
    return 1;
  }

  int baca_teks;

  // cara pertama
  while ((baca_teks = fgetc(file)) != EOF) {
    putchar(baca_teks); // putscar = menampilkan teks kelayar terminal
  }

  rewind(file);

  // cara kedua
  char panjang_byte[100];

  while (fgets(panjang_byte, sizeof(panjang_byte), file) != NULL) {
    printf("%s", panjang_byte);
  }
  fclose(file);
  return 0;
}
