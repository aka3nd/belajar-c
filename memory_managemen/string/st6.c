#include <stdio.h>
int main(void){
  char teks[]= "aing";
  char *ini_ptr = teks;

  printf("%s\n",teks);
  *ini_ptr = 'B';
  printf("%s\n",teks);
  teks[0] = 'C';
  printf("%s\n",teks);
  *ini_ptr = 'G';
  printf("%s\n",teks);
  *(ini_ptr+1) = 'o';
  printf("%s\n",teks);
  return 0;
}
