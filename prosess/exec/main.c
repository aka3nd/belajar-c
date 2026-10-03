#include <unistd.h>
#include <stdio.h>

int main(void)
{
pid_t pid = fork();

if (pid == 0) {
    printf("Saya child\n");
    printf("PID saya   : %d\n", getpid());
    printf("PID parent : %d\n", getppid());
} else {
    printf("Saya parent\n");
    printf("PID saya   : %d\n", getpid());
    printf("PID child  : %d\n", pid);
}
  return 0;
}
