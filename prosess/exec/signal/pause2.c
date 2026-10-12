#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>
void Sinyal(int sig){
  printf("nomor signal %d\n",sig);
}

int main(int argc, char *argv[])
{

  signal(SIGUSR1,Sinyal);

  printf("menunggu signal PID: %d\n",getpid());
  pause();
  printf("sinyal sudah dijalankan program selesai \n");
  return 0;
}
