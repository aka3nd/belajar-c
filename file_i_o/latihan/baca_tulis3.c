#include <stdio.h>
int main(void){
  FILE *file = fopen("data.txt","w");
  if(file == NULL){
    printf("error buka file");
    return 1;
  }
  fputc('A',file);
  fputc('B',file);
  fputc('C',file);
  fputc('D',file);
  fputc('E',file);
  fputc('F',file);
  fputc('\n',file);
  fclose(file);
  return 0;
}
