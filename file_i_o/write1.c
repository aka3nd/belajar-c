#include <stdio.h>
int main(void) {
  // belajar tulis file
  FILE *file = fopen("nama_murid.txt", "w"); // w = write/tulis
  if (file == NULL) {
    printf("gagal open\n");
    return 1;
  }
  fputc('u', file);
  fputc('d', file);
  fputc('i', file);
  fputc('n', file);
  fputc('\n', file); // fputc = input char

  int usia = 25;
  fprintf(file, "dadang %d\n", usia); // fprintf = string + type data

  fputs("jomok\n",file);
  fclose(file);
  return 0;
}
