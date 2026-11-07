#include <stdio.h>
#define  CETAK(x) printf(#x"\n"); 

int main(void){
  CETAK("hello");
  CETAK("world");
  return 0;
}
