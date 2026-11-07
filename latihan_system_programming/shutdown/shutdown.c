#include <stdio.h>
#include <stdlib.h>
#include <sys/reboot.h>
#include <unistd.h>

int main(void) {

  sync();

  printf("sistem dimatikan...!!!!!!!\n");
  if (reboot(RB_POWEROFF) == -1) {
    perror("poweroff gagal dijalankan");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
