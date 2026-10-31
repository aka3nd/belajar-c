#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
  int random = rand() % 10 + 1;

  while (1) {

    int angka;
    printf("masukan angka tebakanmu: ");
    scanf("%d", &angka);

    if (angka == random) {
      printf("selamat tebakanmu benar!!!!!!!\n");
      break;
    } else if (angka > random) {
      printf("angka tebakanmu lebih besar\n");
    } else if (angka < random) {
      printf("angka tebakanmu lebih kecil\n");
    } else if (angka <= 0) {
      printf("angka kamu tidak boleh satu atau lebih kecil\n");
    } else {
      printf("angka yang dimasukan salah!!!!");
    }

    printf("angka tebakanmu %d\n", angka);
    printf("angka random %d\n", random);

    int percobaan = 0;
    percobaan++;
    printf("percobaanmu ke %d\n", percobaan);
  }
  return 0;
}
