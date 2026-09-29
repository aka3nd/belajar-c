#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  char *argumen[] = {"ls", "-l", "-a", "-h", NULL};

  printf("menjalankan execvp\n");
  execvp("ls",argumen);
  perror("execvp");
  return 1;
}
