#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX

struct date
{
    int tanggal, bulan, tahun;
};

typedef struct mahasiswa
{
    char nami[30];
    char npm[20];
    char asal[15];
    char semester[5];
    struct date lahir;
} mhs;

mhs maha[MAX] = {};

int main()
{

    char muter = 'y';
    int pilih, siswa, data, ubah, hapus, a, b, i, j;

menu:

    system("cls");

    printf("--------- PROGRAM MANAJEMEN MAHASISWA UPN  ---------\n\n");

    printf("Menu: \n");
    printf("[1] Input data mahasiswa\n");
    printf("[2] Menampilkan data mahasiswa\n");
    printf("[3] Edit data mahasiswa\n");
    printf("[4] hapus data mahasiswa\n");
    printf("[5] Sorting data mahasiswa\n");
    printf("[6] Keluar\n");

    printf("\nMasukkan pilihan anda: ");
    scanf("%d", &pilih);

    if (pilih == 1)
    {

        system("cls");

        printf("\n--------- INPUT DATA MAHASISWA ---------\n\n");
        printf("\nMasukkan jumlah mahasiswa: ");
        scanf("%d", &siswa);

        for (a = 0; a <= siswa - 1; a++)
        {

            system("cls");
            fflush(stdin);

            printf("\nMahasiswa %d ", a + 1);
            printf("\nMasukkan NPM: ");
            gets(maha[a].npm);
            printf("\nMasukkan nama: ");
            gets(maha[a].nami);
            printf("\nMasukkan asal kota: ");
            gets(maha[a].asal);
            printf("\nMasukkan semester: ");
            gets(maha[a].semester);
            printf("\nMasukkan tanggal lahir (DD/MM/YYYY) (Pisahkan dengan koma): ");
            scanf("%d, %d, %d", &maha[a].lahir.tanggal, &maha[a].lahir.bulan, &maha[a].lahir.tahun);

            sleep(1);
        }
        goto menu;
    }
    else if (pilih == 2)
    {
        system("cls");

        data = 0;

        printf("\n--------- DATA MAHASISWA ---------\n");

        for (a = 0; a <= siswa - 1; a++)
        {

            data = data + 1;

            printf("\n\nMahasiswa %d ", data);

            printf("\nNPM : %s", maha[a].npm);
            printf("\nNama : %s", maha[a].nami);
            printf("\nAsal : %s", maha[a].asal);
            printf("\nSemester : %s", maha[a].semester);
            printf("\nTanggal lahir : %d - %d - %d", maha[a].lahir.tanggal, maha[a].lahir.bulan, maha[a].lahir.tahun);
        }
        printf("\n\n\nTekan enter untuk menuju ke menu !!");
        getch();

        goto menu;
    }
    else if (pilih == 3)
    {

        while (muter == 'y')
        {
            system("cls");

            printf("\n--------- EDIT DATA MAHASISWA ---------\n\n");

            printf("\nMasukkan nomor data mahasiswa yang ingin di edit: ");
            scanf("%d", &ubah);

            fflush(stdin);
            printf("\nMasukkan NPM: ");
            gets(maha[ubah - 1].npm);
            printf("\nMasukkan nama: ");
            gets(maha[ubah - 1].nami);
            printf("\nMasukkan asal kota: ");
            gets(maha[ubah - 1].asal);
            printf("\nMasukkan semester: ");
            gets(maha[ubah - 1].semester);
            printf("\nMasukkan tanggal lahir (DD/MM/YYYY) (Pisahkan dengan koma): ");
            scanf("%d, %d, %d", &maha[ubah - 1].lahir.tanggal, &maha[ubah - 1].lahir.bulan, &maha[ubah - 1].lahir.tahun);

            printf("\n\nApakah mau edit data lagi (y/t)? :");
            scanf(" %c", &muter);

            b++;
        }
        goto menu;
    }
    else if (pilih == 4)
    {
        delete :

            system("cls");

        printf("\n--------- HAPUS DATA MAHASISWA ---------\n\n");
        printf("\nMasukkan nomor data mahasiswa yang ingin dihapus: ");
        scanf("%d", &hapus);

        if (hapus >= siswa + 1)
        {

            printf("\nTerdapat kesalahan");
            sleep(2);
            goto delete;
        }
        else
        {
            printf("\n----- SUKSES -----\n");
            printf("\nData ke-%d berhasil dihapus\n", hapus);
            sleep(2);
            goto menu;

            for (a = hapus - 1; a <= siswa - 1; a++)
            {

                strcpy(maha[a].nami, maha[a + 1].nami);
                strcpy(maha[a].npm, maha[a + 1].npm);
                strcpy(maha[a].asal, maha[a + 1].asal);
                strcpy(maha[a].semester, maha[a + 1].semester);
                strcpy(maha[a].lahir.tanggal, maha[a + 1].lahir.tanggal);
                strcpy(maha[a].lahir.bulan, maha[a + 1].lahir.bulan);
                strcpy(maha[a].lahir.tahun, maha[a + 1].lahir.tahun);
            }
            goto menu;
        }
    }
    else if (pilih == 5)
    {
        system("cls");
        int sort;

        printf("Opsi sorting: ");
        printf("\n1. NPM (ascending)");
        printf("\n2. NPM (descending)");
        printf("\n3. Nama (ascending)");
        printf("\n4. Nama (descending)");

        printf("\nSilahakan masukkan pilihan: ");
        scanf("%d", &sort);

        if (sort == 1)
        {
            system("cls");

            for (i = 0; i < siswa - 1; i++)
            {
                for (j = 1; j < siswa; j++)
                {
                    if (strcmp(maha[j - 1].npm, maha[j].npm) > 0)
                    {
                        bubble(j);
                    }
                }
            }
            for (a = 0; a < siswa; a++)
            {
                printf("\nNPM = %s", maha[a].npm);
                printf("\nNama = %s", maha[a].nami);
                printf("\nAsal = %s", maha[a].asal);
                printf("\nSemester = %s", maha[a].semester);
                printf("\nTanggal lahir = %d - %d -%d\n", maha[a].lahir.tanggal, maha[a].lahir.bulan, maha[a].lahir.tahun);
            }
        }
        else if (sort == 2)
        {
            system("cls");

            for (i = 0; i < siswa - 1; i++)
            {
                for (j = 1; j < siswa; j++)
                {
                    if (strcmp(maha[j - 1].npm, maha[j].npm) < 0)
                    {
                        bubble(j);
                    }
                }
            }
            for (a = 0; a < siswa; a++)
            {
                printf("\nNPM = %s", maha[a].npm);
                printf("\nNama = %s", maha[a].nami);
                printf("\nAsal = %s", maha[a].asal);
                printf("\nSemester = %s", maha[a].semester);
                printf("\nTanggal lahir = %d - %d -%d\n", maha[a].lahir.tanggal, maha[a].lahir.bulan, maha[a].lahir.tahun);
            }
        }
        else if (sort == 3)
        {
            system("cls");

            for (i = 0; i < siswa - 1; i++)
            {
                for (j = 1; j < siswa; j++)
                {
                    if (strcmp(maha[j - 1].nami, maha[j].nami) > 0)
                    {
                        bubble(j);
                    }
                }
            }
            for (a = 0; a < siswa; a++)
            {
                printf("\nNama = %s", maha[a].nami);
                printf("\nNPM = %s", maha[a].npm);
                printf("\nAsal = %s", maha[a].asal);
                printf("\nSemester = %s", maha[a].semester);
                printf("\nTanggal lahir = %d - %d -%d\n", maha[a].lahir.tanggal, maha[a].lahir.bulan, maha[a].lahir.tahun);
            }
        }
        else if (sort == 4)
        {
            system("cls");

            for (i = 0; i < siswa - 1; i++)
            {
                for (j = 1; j < siswa; j++)
                {
                    if (strcmp(maha[j - 1].nami, maha[j].nami) < 0)
                    {
                        bubble(j);
                    }
                }
            }
            for (a = 0; a < siswa; a++)
            {
                printf("\nNama = %s", maha[a].nami);
                printf("\nNPM = %s", maha[a].npm);
                printf("\nAsal = %s", maha[a].asal);
                printf("\nSemester = %s", maha[a].semester);
                printf("\nTanggal lahir = %d - %d -%d\n", maha[a].lahir.tanggal, maha[a].lahir.bulan, maha[a].lahir.tahun);
            }
        }

        printf("\nTekan enter untuk menuju ke menu !!");
        getch();
        goto menu;
    }

    else if (pilih == 6)
    {
        system("cls");

        printf("\n--------- TERIMA KASIH ---------\n\n");
        sleep(1);

        return 0;
    }
    else
    {

        system("cls");

        printf("\n--- Mohon maaf terdapat kesalahan input !! ---");
        sleep(2);

        goto menu;
    }
}

void bubble(int j)
{
    char temp[100];

    strcpy(temp, maha[j - 1].npm);
    strcpy(maha[j - 1].npm, maha[j].npm);
    strcpy(maha[j].npm, temp);

    strcpy(temp, maha[j - 1].nami);
    strcpy(maha[j - 1].nami, maha[j].nami);
    strcpy(maha[j].nami, temp);
}