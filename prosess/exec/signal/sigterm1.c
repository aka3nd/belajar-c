#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void message(int message){
  printf("sigterm dijalankan\n");
}

int main(void)
{

  signal(SIGTERM,message);

  printf("pid saya %d\n",getpid());
  printf("program menunggu\n");

  while (1) {
    pause();
  }
  return 0;
}
