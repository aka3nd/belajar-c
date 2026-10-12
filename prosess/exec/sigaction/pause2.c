#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

volatile sig_atomic_t diterima = 1;
void handler(int sig){
  diterima = 0;
}
int main(void)
{
  struct sigaction sa={0};
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags=0;
  sigaction(SIGINT,&sa,NULL);

  while(!diterima){
    pause();
  }

  printf("pause selesai\n");
  return 0;
}
