#include <stdio.h>
void angka(int a){
  a = 5;
}

int main(){
  int a = 3;
  printf("angka a: %d\n",a);
  angka(a);
  printf("angka a: %d\n",a);
  return 0;
}
