#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1 = fork();

  if (pid1 == 0) {
    execl("/bin/ls", "ls", "-la", NULL);
  } else {
    wait(NULL);
    printf("program selesai\n");
  }
  return 0;
}
