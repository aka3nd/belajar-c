#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *file =fopen("angka.bin","rb");
  if(file == NULL){
    printf("gagal open data\n");
    return 1;
  }

  int data[5];
  fread(data,sizeof(int),5,file);
  for(int i = 0;i < 5;i++){
    printf("angka[%d] = %d\n", i, data[i]);
  }
  fclose(file);
  return 0;
}
