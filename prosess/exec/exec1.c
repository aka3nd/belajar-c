#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid1 = fork();
  if(pid1 == 0){
    execl("/bin/ls","ls", "-la", NULL);
  }else{
    wait(NULL);
    printf("parent selesai\n");
  }
}
