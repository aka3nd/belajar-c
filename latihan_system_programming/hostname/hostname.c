#include <stdio.h>
#include <sys/utsname.h>

int main(void){
  struct utsname info;
  uname(&info);

  printf("hostname: %s\n",info.sysname);
  printf("arsitect: %s\n",info.machine);
  return 0;
}
