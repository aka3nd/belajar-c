#include <stdio.h>
#include <unistd.h>

int main(void){
  printf("program pertama....\n");
  execlp("pwd","pwd",NULL);
  printf("program kedua....\n");

  perror("execlp");
  return 1;
}
