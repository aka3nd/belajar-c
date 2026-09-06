#include <stdio.h>
enum Warna{
  MERAH,
  KUNING,
  HIJAU,
};

int main(void){
  enum Warna warna;

  warna = KUNING;

  printf("warna yang dipilih: %d",warna);
  return 0;
}
