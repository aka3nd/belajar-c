#include <stdio.h>
#include <unistd.h>

int main() {
  const char name[] = "udin sedang makan\n";
  write(1, name, sizeof(name) - 1);

  printf("sizenya: %zu byte\n", sizeof(name));

  return 0;
}
