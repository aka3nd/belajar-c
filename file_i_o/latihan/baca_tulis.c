#include <stdio.h>
int main(void){
  FILE *file = fopen("data.txt","w");
  if(file == NULL){
    printf("error buka file");
    return 1;
  }
  fprintf(file,"Nama: Budi\n");
  fprintf(file,"Umur: 20\n");
  fprintf(file,"Kota: Bandung\n");
  fclose(file);
  return 0;
}
