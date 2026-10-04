#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("prok gagal\n");
    return 1;
  }

  if (pid == 0) {
    printf("Child menjalankan ls ......\n");
    execl("/bin/ls", "ls", "-l", NULL);

    perror("execl");
    return 1;
  } else {
    wait(NULL);
    printf("Parent: child selesai....\n");
  }
  return 0;
}
