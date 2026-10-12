//program 2 pipa

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  if (pipe(fd) == -1) {
    perror("pipe error");
    return 1;
  }

  pid_t pid1 = fork();
  if (pid1 < 0) {
    perror("pid1 error");
    return 1;
  }

  if (pid1 == 0) {
    // menjalankan program ls -la
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    char *argument1[] = {"ls", "-la", NULL};
    execvp("ls", argument1);
    perror("execvp error");
    return 1;
  }

  pid_t pid2 = fork();
  if (pid2 < 0) {
    perror("pid2 error");
    return 1;
  }

  if (pid2 == 0) {
    // close tulis hanya menerima baca
    close(fd[1]);

    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);

    char *argument2[] = {"grep", "txt", NULL};
    execvp("grep", argument2);
    perror("execvp grep error");
    return 1;
  }
  close(fd[0]);
  close(fd[1]);

  waitpid(pid1,NULL,0);
  waitpid(pid2,NULL,0);

  return 0;
}
