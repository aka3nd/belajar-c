#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
  system("poweroff");
  perror("system");
  return 1;
}
