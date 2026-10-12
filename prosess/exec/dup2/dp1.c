#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  if (pipe(fd) == -1) {
    perror("pipe error");
    return 1;
  }
  // fork
  pid_t pid = fork();
  if (pid < 0) {
    perror("pid error");
    return 1;
  }

  if (pid == 0) {
    close(fd[0]); // close baca,karna kita akan menulis
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    char *argument[] = {"ls", "-la", NULL};
    execvp("ls", argument);

  } else {
    close(fd[1]);
    printf("menunggu child selesai\n");
    char buffer[1024];
    ssize_t jumlah;
    while ((jumlah = read(fd[0], buffer, sizeof(buffer))) > 0) {
      write(STDOUT_FILENO, buffer, jumlah);
    }
    close(fd[0]);
    wait(NULL);
  }
  return 0;
}
