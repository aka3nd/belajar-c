#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("sebelum execl\n");
  execl("/bin/ls","ls","-l",NULL);
  return 0;;
}
