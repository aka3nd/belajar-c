#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char *args[] ={
    "ls",
    "-l",
    NULL
  };

  printf("program sebelum execv()\n");
  execv("/bin/ls",args);
  perror("execv");
  return 1;
}
