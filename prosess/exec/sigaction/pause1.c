#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig) { printf("\nSignal diterima: %d\n", sig); }

int main(void) {
  struct sigaction sa = {0};
  sa.sa_handler = handler; // buat handler ke fungsi
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  //sigaction(SIGINT, &sa, NULL);

  printf("get pid: %ld\n", (long)getpid());
  printf("Program menunggu signal...\n");
  pause();
  printf("pause selesai\n");

  return 0;
}
