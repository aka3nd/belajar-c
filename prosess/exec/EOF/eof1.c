#include <stdio.h>
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

    int angka;

    angka = 10;
    write(fd[1], &angka, sizeof(angka));

    angka = 20;
    write(fd[1], &angka, sizeof(angka));

    angka = 30;
    write(fd[1], &angka, sizeof(angka));

    angka = 40;
    write(fd[1], &angka, sizeof(angka));

    angka = 50;
    write(fd[1], &angka, sizeof(angka));

    close(fd[1]);

  } else {

    close(fd[1]);

    int angka;
    ssize_t n;

    while ((n = read(fd[0], &angka, sizeof(angka))) > 0) {
      printf("Parent menerima: %d\n", angka);
    }

    if (n == -1) {
      perror("read");
    }

    close(fd[0]);

    wait(NULL);
  }

  return 0;
}
