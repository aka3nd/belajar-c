#include <stdio.h>
void cetak(char *teks) {
  printf("%s\n", teks);
  printf("%c\n", *teks);
  printf("%c\n", *teks + 1);// ambil karaketr pertama digeser satu ,u jadi v
  printf("%c\n", *(teks + 2)); // pointer pertama digeser dua,nperbedaanya sitanda ()
  printf("%c\n", *(teks + 3));
}

int main(void) {
  char nama[] = "udin";
  cetak(nama);
  return 0;
}
