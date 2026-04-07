#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1 = fork();

  if (pid1 == 0) {
    printf("pid child berjalan\n");
  } else {
    printf("pid parent sedang jalan\n");
    wait(NULL);
  }
  return 0;
}
