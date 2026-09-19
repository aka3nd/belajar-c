#include <stddef.h>
#include <stdio.h>
#include <string.h>
int main(void){
  char nama[] = "udin";
  printf("ukuran nama: %zu\n",strlen(nama)); //hasilnya 4 byte, padahal 5byte

  size_t panjang = strlen(nama);
  printf("ukuran nama: %zu\n",panjang); //hasilnya 4 byte, padahal 5byte
  return 0;
}
