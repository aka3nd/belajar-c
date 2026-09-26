#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(void){
  struct utsname system;
  printf("alamat sistem: %p\n",&system);
  uname(&system);
  
  char hostname[255];
  gethostname(hostname,sizeof(hostname));

  printf("hostname: %s\n",hostname);
  printf("hostname: %s\n",system.nodename); //sama seperti yang atas
  printf("OS: %s\n",system.sysname);
  printf("release: %s\n",system.release);
  printf("Machine: %s\n",system.machine);
  return 0;
}
