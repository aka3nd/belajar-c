#include <stdio.h>
int main(void){
  int angka[] = {21,4,55,23,20};
  int *ptr = angka;

  printf("nilai ptr: %d\n",*ptr);
  ptr++;
  printf("nilai ptr: %d\n",*ptr);
  ptr +=3;
  printf("nilai ptr: %d\n",*ptr);
  ptr++;
  printf("nilai ptr: %d\n",*ptr);
  return 0;
}
