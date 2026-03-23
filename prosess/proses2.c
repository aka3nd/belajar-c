#include <unistd.h>
#include <stdio.h>

int main(){
  pid_t pid1 = fork();
  if(pid1 == 0){
    printf("ini child\n");
  }else{
    printf("ini parent\n");
  }
  return 0;
}
