#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2];

  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }

  pid_t pid = fork();
  if (pid < 0) {
    perror("pid gagal\n");
    return 1;
  }

  if (pid == 0) {
    // Child
    close(fd[1]);
    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));

    printf("Child menerima: %s\n", buffer);
    close(fd[0]);

    return 0;
  }

  // parent
  close(fd[0]);
  char pesan[100];

  strcpy(pesan, "hallo Child\n");
  write(fd[1], pesan, sizeof(pesan));
  close(fd[1]);
  waitpid(pid, NULL, 0);

  return 0;
}
