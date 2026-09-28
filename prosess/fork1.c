#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();

  if(pid == -1){
    perror("gagal pork");
    return 1;
  }

  if (pid == 0) {
    printf("saya: pid saya %d pid parent saya: %d\n",getpid(),getppid());
  } else {
    printf("parent: pid saya %d pid parent saya: %d\n",getpid(),getppid());
  }
  return 0;
}
