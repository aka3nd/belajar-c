#include <stdio.h>

#define CETAK(x) printf(#x"\n");

int main(void){
  CETAK(freebsd);
  CETAK(linux);
  return 0;
}
