#include <stdio.h>

int main(void){
  int a = 100;
  int *b = &a;

  printf("sizeof(a) = %zu byte\n",sizeof(a));
  printf("sizeof(b) = %zu byte\n",sizeof(b));
  return 0;
}
