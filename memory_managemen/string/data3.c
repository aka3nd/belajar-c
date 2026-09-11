#include <stdio.h>
void ubah(char *teks){
  *teks = 'D';
}

int main(void){
  char nama[]="dadang";
  printf("nama sebelum diubah: %s\n",nama);
  ubah(nama);
  printf("nama sebelum diubah: %s\n",nama);
  return 0;
}
