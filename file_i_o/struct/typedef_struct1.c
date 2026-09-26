#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    int usia;
} Mahasiswa;

int main(void)
{
    Mahasiswa *mhs;

    mhs = malloc(sizeof(Mahasiswa));

    if (mhs == NULL) {
        return 1;
    }

    strcpy(mhs->nama, "Udin");
    mhs->usia = 25;

    printf("Nama: %s\n", mhs->nama);
    printf("Usia: %d\n", mhs->usia);

    free(mhs);

    return 0;
}
