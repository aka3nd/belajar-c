// program 3 pipa

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd1[2];
  int fd2[2];
  if (pipe(fd1) == -1) {
    perror("pipe error");
    return 1;
  }
  if (pipe(fd2) == -1) {
    perror("pipe error");
    return 1;
  }

  pid_t pid1 = fork();
  if (pid1 < 0) {
    perror("pid1 error");
    return 1;
  }

  if (pid1 == 0) {
    close(fd1[0]);
    dup2(fd1[1], STDOUT_FILENO);
    close(fd1[0]);

    char *buffer1[] = {"ls", "-la", NULL};

    close(fd2[0]);
    close(fd2[1]);

    execvp("ls", buffer1);
  }

  pid_t pid2 = fork();

  if (pid2 < 0) {
    perror("pid 2 error");
    return 1;
  }

  if (pid2 == 0) {
    close(fd1[1]); // close fd1[1] close write
    close(fd2[0]); // close fd2 read

    dup2(fd1[0], STDIN_FILENO);
    close(fd1[0]);

    dup2(fd2[1], STDOUT_FILENO);
    close(fd2[1]);

    char *buffer2[] = {"grep", "txt", NULL};
    execvp("grep", buffer2);
    perror("execvp grep error");
    return 1;
  }

  pid_t pid3 = fork();
  if (pid3 < 0) {
    perror("pid3 error");
    return 1;
  }
  if (pid3 == 0) {
    close(fd1[0]);
    close(fd1[1]);

    close(fd2[1]);
    dup2(fd2[0], STDIN_FILENO);
    close(fd2[0]);

    char *buffer3[] = {"wc", "-l", NULL};
    execvp("wc", buffer3);
    perror("wc error");
    return 1;
  }
  close(fd1[0]);
  close(fd1[1]);

  close(fd2[0]);
  close(fd2[1]);

  waitpid(pid1, NULL, 0);
  waitpid(pid3, NULL, 0);
  waitpid(pid2, NULL, 0);
  return 0;
}
