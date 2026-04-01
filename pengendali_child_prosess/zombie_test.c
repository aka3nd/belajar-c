#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent: Tidak melakukan wait(), langsung tidur lama
        printf("Parent (PID: %d) tidur 30 detik. Cek 'ps aux' sekarang!\n", getpid());
        sleep(30);
        printf("Parent bangun dan selesai.\n");
    } else if (pid == 0) {
        // Child: Langsung mati
        printf("Child (PID: %d) berhenti sekarang.\n", getpid());
        exit(0);
    }

    return 0;
}
