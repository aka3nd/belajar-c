#include <stdio.h>
int main(void){
  FILE *file = fopen("angka.bin","wb");

  if(file == NULL){
    printf("gagal dibuka atau dibuat\n");
    return 1;
  }

  int angka[]={10,20,30};
  fwrite(&angka,sizeof(int),3,file);
 
  fclose(file);
  return 0;
}
