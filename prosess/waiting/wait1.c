#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid2 = fork();

  if (pid2 == 0) {
    printf("ini child\n");
    wait(NULL);
  } else {
    printf("ini parent\n");
  }
  return 0;
}
