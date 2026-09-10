#include <stdlib.h>

int main(void) {
  int *data = malloc(2 * sizeof(int));

  data[0] = 10;
  data[1] = 20;

  data++; // maju
  data--; // mundur kembali

  free(data); // sekarang valid
  return 0;
}
