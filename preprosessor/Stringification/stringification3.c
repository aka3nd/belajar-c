#include <stdio.h>

#define NAMA(x) printf(#x"\n");
#define BUAT_VAR(a,b) a ## b

int main(void){
  NAMA("ahmad");

  int angka1 = 500;
  printf("%d\n",BUAT_VAR(angka,1));
  return 0;
}
