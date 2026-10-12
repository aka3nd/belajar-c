#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void Sinyal(int sig)
{
    (void)sig;
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = Sinyal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa, NULL);

    char buffer[100];

    printf("Ketik sesuatu: ");
    fflush(stdout);

    ssize_t hasil = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

    if (hasil == -1) {
        perror("read");
        return 1;
    }

    buffer[hasil] = '\0';

    printf("Input: %s\n", buffer);

    return 0;
}
