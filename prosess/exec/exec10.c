#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("pork gagal\n");
    return 1;
  }

  if (pid == 0) {
    char *argumet[] = {"ls", "-la", NULL};
    execvp("ls", argumet);
    perror("execvp");
    return 1;
  }
  printf("Parent\n");
  printf("PID  : %d\n", getpid());
  printf("Child PID : %d\n", pid);
  //wait(NULL);
  waitpid(pid,NULL,0);

  printf("Child sudah selesai\n");
  return 0;
}
