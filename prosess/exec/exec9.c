#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  pid_t pid = fork();
  if(pid == 0){
    char *argument[]={"ls","-l","-a","-h",NULL};
    execvp("ls",argument);
    perror("execvp");
    return 1;
  }

  printf("parent menunggu child selesai...\n");
  wait(NULL);

  return 0;
}
