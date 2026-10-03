#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  if(pid < 0){
    perror("gagal\n");
    return 1;
  }

  if(pid == 0){
    printf("child sedang berjalan ....!!!!\n");
    sleep(5);
    printf("child selesai....!!!!\n");
    return 7;
  }

  printf("parent menunggu child dengan pid: %d\n",pid);
  int status;
  waitpid(pid,&status,0);
  if(WIFEXITED(status)){
   printf("Status exit: %d\n", WEXITSTATUS(status));
  }
  return 0;;
}
