#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // pipe 2 arah
  int anak_ke_ortu[2];
  int ortu_ke_anak[2];

  // pipe(anak_ke_ortu);
  // pipe(ortu_ke_anak);

  if (pipe(anak_ke_ortu) == -1) {
    perror("pipe anak_ke_ortu gagal");
    return 1;
  }

  if (pipe(ortu_ke_anak) == -1) {
    perror("pipe ortu_ke_anak gagal");
    return 1;
  }

  pid_t pid = fork();

  if (pid < 0) {
    perror("pork gagal");
    return 1;
  }

  if (pid == 0) {
    close(anak_ke_ortu[0]); // close baca anak_ke_ortu
    close(ortu_ke_anak[1]); // close ortu_ke_anak

    int angka1 = 10;
    write(anak_ke_ortu[1], &angka1, sizeof(angka1));

    int angka2 = 20;
    write(anak_ke_ortu[1], &angka2, sizeof(angka2));

    int baca_pesan_ortu;
    read(ortu_ke_anak[0], &baca_pesan_ortu, sizeof(baca_pesan_ortu));
    printf("pesan dari ortu : %d\n", baca_pesan_ortu);

    close(anak_ke_ortu[1]);
    close(ortu_ke_anak[0]);

  } else {
    close(anak_ke_ortu[1]); // close tulis anak_ke_ortu
    close(ortu_ke_anak[0]);

    int baca_anak1;
    int baca_anak2;

    ssize_t n = read(anak_ke_ortu[0], &baca_anak1, sizeof(baca_anak1));
    if (n == -1) {
      perror("error read");
      return 1;
    }
    printf("Ortu menerima: %d\n", baca_anak1);
    printf("read pertama = %zd byte\n", n);
    read(anak_ke_ortu[0], &baca_anak2, sizeof(baca_anak2));
    printf("Ortu menerima: %d\n", baca_anak2);

    int hasil = baca_anak1 + baca_anak2;

    printf("Ortu menjumlahkan: %d\n", hasil);

    write(ortu_ke_anak[1], &hasil, sizeof(hasil));

    close(anak_ke_ortu[0]); // close tulis anak_ke_ortu
    close(ortu_ke_anak[1]);
  }
  return 0;
}
