#include <stdio.h>
int main(void){
  FILE *file = fopen("data.txt","w");
  if(file == NULL){
    printf("error buka file");
    return 1;
  }
  fputs("Nama: Budi\n",file); //input string fputs,
  fputs("Umur: 20\n",file);
  fputs("Kota: Bandung\n",file);
  fclose(file);
  return 0;
}
