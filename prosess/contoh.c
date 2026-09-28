#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        sleep(5);
        printf("Child: PPID setelah parent selesai = %d\n", getppid());
    }
    else {
        printf("Parent: PID = %d\n", getpid());
        printf("Parent selesai\n");
    }

    return 0;
}
