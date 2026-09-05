#include <stdio.h>

int main(void){
  int a;
  printf("masukan angka: ");
  scanf("%d",&a);

  while (a <= 10) {
    printf("%d\n",a);
    a += 1;
  }
  return 0;
}
