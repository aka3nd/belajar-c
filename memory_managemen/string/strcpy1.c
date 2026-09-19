#include <stdio.h>
#include <string.h>
int main(void){
  char sumber[] = "dadang";
  char tujuan[10];
  printf("sumber: %s\n",sumber);
  strcpy(tujuan,sumber);
  printf("tujuan: %s\n",tujuan);
  return 0;
}
