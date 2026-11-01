#include <stdio.h>
void say_hello(){
  printf("hello dari callback\n");
}

void callback(void(*fungsi)(void)){
  fungsi();
}

int main(void)
{
  callback(say_hello);
  return 0;
}
