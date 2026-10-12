#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void Sinyal(int sig) { printf("nomor signal: %d\n", sig); }

int main(void) {
  pid_t pid = fork();

  if (pid < 0) {
    perror("pid gagal");
    return 1;
  }

  if (pid == 0) {
    signal(SIGUSR1, Sinyal);
    printf("Child: pid saya %d\n", getpid());
    printf("Child: menunggu sinyal ...\n");
    pause();
    printf("Child: Sinyal diterima\n");
  } else {
    printf("parent: pid child %d\n", pid);
    sleep(2);
    printf("parent menunggu SIGUSR1\n");
    kill(pid, SIGUSR1);
    waitpid(pid, NULL, 0);

    printf("Parent: child sudah selesai\n");
  }
  return 0;
}
