#include <stdio.h>
int main(void){
  FILE *file = fopen("data.bin","wb");

  if(file == NULL){
    printf("gagal dibuka atau dibuat\n");
    return 1;
  }

  int angka = 100;
  fwrite(&angka,sizeof(int),1,file);
  
  fclose(file);
  return 0;
}
