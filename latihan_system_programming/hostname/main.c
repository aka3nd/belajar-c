#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
  char buff[10];
  memset(buff, 0,sizeof(buff));
  gethostname(buff,sizeof(buff));

  printf("hostname: %s\n",buff);
  printf("panjang hostname %zu\n",strlen(buff));
  printf("ukuran buffer: %zu\n",sizeof(buff));

  return 0;
}
