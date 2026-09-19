#include <stdio.h>
int main(void) {
  FILE *file = fopen("mahasiswa.txt", "r");
  if (file == NULL) {
    printf("file gagal dibuka/format tidak valid\n");
    return 1;
  }
  char nama[50];
  int usia;

  FILE *hasil = fopen("hasil.txt","w");

  if(hasil == NULL){
    printf("gagal buat file hasil\n");
    fclose(file);
    return 1;
  }

  while(fscanf(file,"%49s %d",nama,&usia) == 2){
    printf("nama: %s | usia: %d\n",nama,usia);
    fprintf(hasil,"nama: %s | usia: %d\n",nama,usia);
  }

  fclose(file);
  fclose(hasil);
  return 0;
}
