#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t berhenti = 0;
void Sinyal(int sig) {
  printf("Handler menerima signal %d\n",sig);
  berhenti = 1;
}

int main(void) {
  struct sigaction sa;
  sa.sa_handler = Sinyal;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  sigaction(SIGINT, &sa, NULL);

  while (berhenti == 0) {
    printf("program berjalan... PID: %d\n", getpid());
    sleep(1);
  }
  printf("Signal diterima: %d\n", (int)berhenti);
  printf("Program selesai\n");
  return 0;
}
