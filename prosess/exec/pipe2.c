#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2]; // mendefinisikan int fd array
  if (pipe(fd) == -1) {
    perror("pipe gagal\n");
    return 1;
  }

  // fork proses
  pid_t pid = fork();
  if (pid < 0) {
    perror("pid");
    return 1;
  }

  if (pid == 0) {
    // menulis data
    close(fd[0]);
    char pesan[] = "hallo mama\n";
    write(fd[1], pesan, sizeof(pesan));
    close(fd[1]);
  } else {
    // membaca data
    close(fd[1]);
    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));
    printf("pesan dari Child: %s\n",buffer);
    close(fd[0]);
    wait(NULL);
  }

  return 0;
}
