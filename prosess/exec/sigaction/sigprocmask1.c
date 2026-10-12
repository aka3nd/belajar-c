#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT);

  if (sigprocmask(SIG_BLOCK, &set, NULL) == -1) {
    perror("sigprocmask error");
    return 1;
  }
  printf("SIGINT diblokir.\n");
  printf("Tekan Ctrl+C beberapa kali.\n");
  printf("Program berjalan selama 10 detik...\n");

  sleep(10);

  printf("Program selesai.\n");

  return 0;
}
