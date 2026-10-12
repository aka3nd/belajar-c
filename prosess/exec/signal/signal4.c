#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;
void Notif(int sig) {
  printf("\nsinyal SIGINT %d\n", sig);
  stop = 1;
}

int main(void) {
  signal(SIGINT, Notif);

  while (stop == 0) {
    printf("program berjalan dengan PID: %d\n", getpid());
    pause();
  }
  printf("fungsi stop %d\n",(int)stop);

  return 0;
}
