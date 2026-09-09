#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  int *angka = calloc(3,sizeof(int));
  if(angka == NULL){
    printf("calloc gagal\n");
    return 1;
  }

  angka[0] = 100;
  angka[1] = 500;
  angka[2] = 1000;

  for(int i=0;i< 3;i++){
    printf("%d\n",angka[i]);
  }

  free(angka);
  return 0;
}
