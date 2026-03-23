#include <stdio.h>
#include <sys/wait.h> // wait
#include <unistd.h>   // sleep

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("child memulai\n");
    sleep(2);
    printf("child selesai\n");
  } else {
    printf("parent menunggu\n");
    wait(NULL);
    printf("parent selesai\n");
  }
  return 0;
}
