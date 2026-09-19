#include <stdio.h>
int main(void){
  FILE *file = fopen("data.bin","rb");

  if(file == NULL){
    printf("gagal dibuka atau dibuat\n");
    return 1;
  }

  int angka;
  fread(&angka,sizeof(int),1,file);

  printf("angkanya: %d\n",angka);

 
  fclose(file);
  return 0;
}
