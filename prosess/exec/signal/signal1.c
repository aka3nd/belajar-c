#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t berhenti = 0;

void Sinyal(int a) { berhenti = 1; }

int main(void) {
  signal(SIGINT, Sinyal);

  while (berhenti == 0) {
    printf("program berjalan...\n");
    sleep(1);
  }

  printf("porgram berhenti....\nDengan signal interupt...\n");
  return 0;
}
