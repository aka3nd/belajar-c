#include <stdio.h>

int main(int argc, char *argv[])
{
  int a = 100;
  int* b = &a;

  printf("nilai b: %d\n",*b);
  return 0;
}
