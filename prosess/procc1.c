#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
pid_t pid1 = fork(); 

if(pid1 == 0){
  printf("ini child\n");
}else{
  printf("ini parent");
}
  return 0;
}
