#include <sys/reboot.h>
#include <unistd.h>

int main(void)
{
  
  sync();
  reboot(RB_POWEROFF);
  return 0;
}
