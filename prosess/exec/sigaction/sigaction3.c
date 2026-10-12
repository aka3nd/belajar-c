#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t berhenti = 0;

void HANDLER_INT(int sig) {
  (void)sig;
  printf("handler sigint dimulai\n");
  sleep(5);
  printf("handler sigint selesai\n");
  berhenti = 1;
}

void HANDLER_TERM(int sig) {
  (void)sig;
  printf("handler sigterm dijalankan\n");
  berhenti = 1;
}

int main(void) {
  struct sigaction sa_int;
  struct sigaction sa_term;

  sa_int.sa_handler = HANDLER_INT; // buat handler
  sigemptyset(&sa_int.sa_mask);
  sigaddset(&sa_int.sa_mask, SIGTERM);
  sa_int.sa_flags = 0;
  sigaction(SIGINT, &sa_int, NULL);

  // signal term
  sa_term.sa_handler = HANDLER_TERM;
  sigemptyset(&sa_term.sa_mask);
  sa_term.sa_flags = 0;
  sigaction(SIGTERM, &sa_term, NULL);

  while (berhenti == 0) {
    printf("Program berjalan... PID: %d\n", getpid());
    sleep(1);
  }

  printf("Program selesai\n");

  return 0;
}
