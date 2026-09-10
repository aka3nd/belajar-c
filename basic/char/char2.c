
#include <stdio.h>
int main(void){
  char *name ="jokowi";
  char *ptr = name;
  printf("ptr %c\n",*ptr);
  ptr++;
  printf("ptr %c\n",*ptr);
  return 0;
}
