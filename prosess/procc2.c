#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  pid_t pid = fork();

  if (pid == -1) {
    perror("process error\n");
    return 1;
  }

  if (pid == 0) {
    printf("child: sedang bekerja....\n");
    sleep(2);
    printf("Child selesai....!\n");
    exit(1);
  } else {
    int status;
    printf("Parent menunggu child ...\n");
    wait(&status);
    printf("Parent: child sudah selesai\n");

    if (WIFEXITED(status)) {
      printf("Child keluar secara normal\n");
      printf("Status exit: %d\n", WEXITSTATUS(status));
    }
  }

  return 0;
}
