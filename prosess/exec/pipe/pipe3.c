#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2];

  if (pipe(fd) == -1) {
    perror("error pipe\n");
    return 1;
  }

  pid_t pid = fork();
  if (pid < 0) {
    perror("pid error\n");
    return 1;
  }

  if (pid == 0) {
    // child menulis
    close(fd[0]); // tutup baca
    char pesan[] = "Nama saya udin\nUsia 23 tahun\n";
    write(fd[1], pesan, strlen(pesan) + 1);
    close(fd[1]);
  } else {
    close(fd[1]);
    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));
    printf("parent menerima: %s\n", buffer);
    close(fd[0]);
    wait(NULL);
  }

  // parent membaca

  return 0;
}
