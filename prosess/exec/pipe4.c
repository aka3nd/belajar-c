#include <stdio.h>
#include <string.h>
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
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    close(fd[0]);
    char pesan1[] = "Nama: udin\n";
    char pesan2[] = "Usia: 23\n";
    char pesan3[] = "Hoby: belajar c\n";

    write(fd[1], pesan1, strlen(pesan1));
    write(fd[1], pesan2, strlen(pesan2));
    write(fd[1], pesan3, strlen(pesan3));

    close(fd[1]);
  } else {
    close(fd[1]);
    char buffer[10];
    ssize_t jumlah;
    while ((jumlah = read(fd[0], buffer, sizeof(buffer) - 1)) > 0) {
      buffer[jumlah] = '\0';
      printf("%s", buffer);
    }

    if (jumlah == -1) {
      perror("read");
    }
    close(fd[0]);
    wait(NULL);
  }
  return 0;
}
