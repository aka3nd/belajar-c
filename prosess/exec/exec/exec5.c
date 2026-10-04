#include <stdio.h>
#include <unistd.h>

int main(void){
  printf("program pertama....\n");

  execlp("/bin/ls","ls","-la",NULL);
  //program kedua tidak dijalankan karna process di ganti 
  //ke program ls
  printf("program kedua....\n");
  return 0;
}
