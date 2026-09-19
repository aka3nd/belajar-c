#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *file = fopen("nama_murid.txt","a");
  if (file == NULL) {
    printf("gagal buka file\n");
    return 1;
  
  }

  fprintf(file,"jamal\n");
  fclose(file);
  return 0;
}
