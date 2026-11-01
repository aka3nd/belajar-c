#include <stdio.h>
#include <string.h>
void ubah(int **ptr){
  *ptr = NULL;
}
int main(void){
  int angka = 5;
  int *b = &angka;
  ubah(&b);

  printf("%p\n",&angka);
  printf("%p\n",b);
  printf("%p\n",(void *)b);
  
  return 0;
}
