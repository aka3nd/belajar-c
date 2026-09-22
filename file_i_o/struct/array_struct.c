#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int usia;
};

int main(void)
{
    struct Mahasiswa mhs[3];

    mhs[0].usia = 20;
    mhs[1].usia = 21;
    mhs[2].usia = 19;

    strcpy(mhs[0].nama, "Ucup");
    strcpy(mhs[2].nama, "Siti");

    char *buff = "Budi";
    strcpy(mhs[1].nama,buff);


    printf("%d\n", mhs[0].usia);
    printf("%s\n", mhs[0].nama);
    printf("%d\n", mhs[1].usia);
    printf("%s\n", mhs[1].nama);
    printf("%d\n", mhs[2].usia);

    return 0;
}
