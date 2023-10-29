#include <stdio.h>
#include <string.h>

struct student {
    char nama[50];
    char jurusan[30];
    float nilai;
};

void showStudentDetail(struct student murid[], int jumlah) {
    char searchNama[50];
    printf("Enter student name to show detail: ");
    scanf(" %[^\n]s", searchNama);

    int i;
    int found = 0;
    for (i = 0; i < jumlah; i++) {
        if (strcmp(murid[i].nama, searchNama) == 0) {
            printf("Student Detail\n");
            printf("------------------------------\n");
            printf("Name    : %s\n", murid[i].nama);
            printf("Jurusan : %s\n", murid[i].jurusan);
            printf("Nilai   : %.2f\n", murid[i].nilai);
            printf("------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Mahasiswa dengan nama'%s' not found.\n", searchNama);
    }
}

int main() {
    struct student murid[100];
    int jumlah = 0;
    int i;

    // baca file txt nya
    FILE *fdata = fopen("database_nilai.txt", "r");
    if (fdata == NULL) {
        printf("Failed to open database_nilai.txt\n");
        return 1;
    }

    while (fscanf(fdata, "%[^😭]😭%[^😭]😭%f\n", murid[jumlah].nama, murid[jumlah].jurusan, &murid[jumlah].nilai) == 3) {
        jumlah++;
    }

    fclose(fdata);

    int pilihan;
    while (1) {
        printf("Welcome To UMN Student Database (%d/100)\n", jumlah);
        printf("1. Tampilkan Semua Mahasiswa\n2. Cari Mahasiswa\n3. Keluar Program\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        printf("\n");

        if (pilihan == 1) {
            printf("                                      List Of Students Information                                    \n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|No.|               Nama               |          Jurusan         |  Nilai  |\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            for (i = 0; i < jumlah; i++) {
                printf("|%-3d| %-33s| %-24s|  %-7.2f|\n", i + 1, murid[i].nama, murid[i].jurusan, murid[i].nilai);
                printf("-----------------------------------------------------------------------------------------------------\n");
            }
            printf("Database Size = %d/100\n", jumlah);
            printf("Press Enter to Continue...");
            getchar();
            getchar();
        } else if (pilihan == 2) {
            showStudentDetail(murid, jumlah);
            printf("Press Enter to Continue");
            getchar();
            getchar();
        } else if (pilihan == 3) {
            printf("Thank You, Have a great day!\n");
            break;
        } else {
            printf("Invalid option.\n");
            printf("Press Enter to Continue");
            getchar();
            getchar();
        }
    }

    return 0;
}
