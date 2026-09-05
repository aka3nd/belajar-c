#include <stdio.h>

int main(void) {
  int a;

  printf("masukan angka: ");
  scanf("%d", &a);

  do {
    printf("angka: %d\n", a);
    a++;

    while (a == 7) {
      int b = 1;
      printf("ini angka: %d", &b);
      b++;

      if (b == 100) {
        break;
      }
    }

  } while (a <= 10);
  return 0;
}
