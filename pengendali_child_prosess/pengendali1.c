#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("pork gagal");
    return 1;
  }

  if (pid == 0) {
    printf("anak sedang bekerja selama 3 detik ....\n");
    sleep(3);
    printf("anak selesai bekerja pamit...\n");
    exit(42);
  } else {
    int status;
    printf("parent menunggu anak (PID: %d) selesai...\n", pid);
    wait(&status);
    if (WIFEXITED(status)) {
      printf("parent: anak pulang dengan status: %d\n", WEXITSTATUS(status));
    }
  }
  return 0;
}
