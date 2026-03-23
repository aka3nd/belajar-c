#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid1 = fork();
  if (pid1 == 0) {
    printf("pid sendiri: %d ,pid parent: %d\n", getpid(), getppid());
  } else {
    printf("pid sendiri: %d ,pid child: %d\n", getpid(), getppid());
  }
  return 0;
}
