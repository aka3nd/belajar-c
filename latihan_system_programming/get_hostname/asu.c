#include <stdio.h>
#include <sys/utsname.h>

int main(void){
  struct utsname name;
  uname(&name);
  printf("System Operasi: %s\n",name.sysname);
  return 0;
}
