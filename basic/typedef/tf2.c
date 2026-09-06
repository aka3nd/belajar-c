#include <stdio.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
} Data;

int main(void) {
  Data data1;
  strcpy(data1.name, "joko santoso");
  data1.age = 40;

  printf("namaku: %s umurku: %d\n", data1.name, data1.age);
  return 0;
}
