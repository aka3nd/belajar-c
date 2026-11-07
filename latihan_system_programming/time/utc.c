#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  time_t t = time(NULL);
  char time_jakarta[1024];
  char time_makassar[1024];

  tzset(); //set time zone
  struct tm *jakarta = localtime(&t);
  strftime(time_jakarta, sizeof(time_jakarta), "%H:%M:%S\n", jakarta);

  printf("jam jakarta: %s", time_jakarta);

  putenv("TZ=Asia/Makassar"); //mengubah format zona waktu
  tzset();
  struct tm *makassar = localtime(&t);
  strftime(time_makassar,sizeof time_makassar,"%H:%M:%S\n",makassar);
  printf("jam makassar: %s", time_makassar);
  return 0;
}
