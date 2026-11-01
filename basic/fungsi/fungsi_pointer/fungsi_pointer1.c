#include <stdio.h>
void say_hello(void) { printf("saya fungsion pinter\n"); }

int main(void) {
  //langsung eksekusi
  say_hello(); // fungsi langsung dijalankan;
  void (*anjay)(void);
  //tidak dieksekusi
  anjay = say_hello; //fungsi tidak langsung dijalankan
  anjay();
  return 0;
}
