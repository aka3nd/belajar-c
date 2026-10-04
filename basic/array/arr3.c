#include <stdio.h>

int main(void) {
  int numbers[] = {1, 2, 3, 4, 5};
  printf("%d\n", numbers[3]); // hasilnya 4 menuju ke indek nomor 4

  //ubah aray;
  numbers[3] = 20;
  printf("%d\n",numbers[3]);
  return 0;
}
