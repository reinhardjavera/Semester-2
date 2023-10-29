#include <stdio.h>
#include <string.h>

struct student {
    char nim[12];
    char nama[50];
    char jurusan[30];
    float tugas;
    float uts;
    float uas;
    float nilai;
    char grade[3];
};

void showStudentDetail(struct student murid[], int jumlah) {
    char searchNIM[12];
    printf("Enter NIM to show student detail: ");
    scanf("%s", searchNIM);

    int i;
    for (i = 1; i <= jumlah; i++) {
        if (strcmp(murid[i].nim, searchNIM) == 0) {
            printf("Student Detail\n");
            printf("------------------------------\n");
            printf("NIM     : %s\n", murid[i].nim);
            printf("Nama    : %s\n", murid[i].nama);
            printf("Jurusan : %s\n", murid[i].jurusan);
            printf("Tugas   : %.2f\n", murid[i].tugas);
            printf("UTS     : %.2f\n", murid[i].uts);
            printf("UAS     : %.2f\n", murid[i].uas);
            printf("Nilai Akhir : %.2f\n", murid[i].nilai);
            printf("Grade   : %s\n", murid[i].grade);
            printf("------------------------------\n");
            return;
        }
    }

    printf("Student with NIM %s not found.\n", searchNIM);
}

int main() {
    struct student murid[100];
    int pilihan, jumlah = 0, i;

    // Read datamurid.txt
    FILE *fdatamurid = fopen("datamurid.txt", "r");
    if (fdatamurid == NULL) {
        printf("Failed to open datamurid.txt\n");
        return 1;
    }

    while (fscanf(fdatamurid, "%[^#]#%[^#]#%[^\n]\n", murid[jumlah + 1].nim, murid[jumlah + 1].nama, murid[jumlah + 1].jurusan) == 3) {
        jumlah++;
    }

    fclose(fdatamurid);

    // Read nilaimurid.txt
    FILE *fnilaimurid = fopen("nilaimurid.txt", "r");
    if (fnilaimurid == NULL) {
        printf("Failed to open nilaimurid.txt\n");
        return 1;
    }

    for (i = 1; i <= jumlah; i++) {
        fscanf(fnilaimurid, "%[^#]#%f#%f#%f#%f#%[^\n]\n", murid[i].nim, &murid[i].tugas, &murid[i].uts, &murid[i].uas, &murid[i].nilai, murid[i].grade);
    }

    fclose(fnilaimurid);

    menu:
    printf("Welcome To Simple Student Database (%d/100)\n", jumlah);
    printf("1. Show All Student\n2. Input New Student\n3. Show Student Detail\n4. Exit\nChoose: ");
    scanf("%d", &pilihan);
    printf("\n");

    if (pilihan == 1) {
        printf("                                      List Of Students Information                                    \n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("|No.|               Name               |     NIM     |  Tugas  |   UTS   |   UAS   |  Nilai Akhir  | Grade |\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        for (i = 1; i <= jumlah; i++) {
            printf("|%-3d| %-33s| %s |  %-7.2f|  %-7.2f|  %-7.2f|     %-10.2f|  %-5s|\n", i, murid[i].nama, murid[i].nim, murid[i].tugas, murid[i].uts, murid[i].uas, murid[i].nilai, murid[i].grade);
            printf("------------------------------------------------------------------------------------------------------------\n");
    }
    printf("Database Size = %d/100\n", jumlah); fflush(stdin);
    printf("Press Any key to Continue...");
    getchar();
    goto menu;

    } else if (pilihan == 2) {
        FILE *fdata = fopen ("datamurid.txt", "w");
    FILE *fnilai = fopen ("nilaimurid.txt", "w");
    printf("Insert Student Information\t\n");
        printf("------------------------------\n"); fflush(stdin);
        printf("NIM     : "); scanf("%[^\n]", murid[jumlah+1].nim); fflush(stdin);
        printf("Nama    : "); scanf("%[^\n]", murid[jumlah+1].nama); fflush(stdin);
        printf("Jurusan : "); scanf("%[^\n]", murid[jumlah+1].jurusan); fflush(stdin);
        printf("\n");
        printf("Insert Student Grade\t\n");
        printf("------------------------------\n"); fflush(stdin);
        printf("Tugas   : "); scanf("%f", &murid[jumlah+1].tugas); fflush(stdin);
        printf("UTS     : "); scanf("%f", &murid[jumlah+1].uts); fflush(stdin);
        printf("UAS     : "); scanf("%f", &murid[jumlah+1].uas); fflush(stdin);
        printf("Inserting Data.....\n");
        printf("New Students Input\n");
        printf("Press Any Key To Continue");
        getchar();
        jumlah++;
        for (i = 1; i <= jumlah; i++) {
            murid[i].nilai = (murid[i].tugas * 0.3) + (murid[i].uts * 0.3) + (murid[i].uas * 0.4);
            if (murid[i].nilai >= 95) {
                strcpy(murid[i].grade, "A+");
            } else if (murid[i].nilai >= 85) {
                strcpy(murid[i].grade, "A");
            } else if (murid[i].nilai >= 80) {
                strcpy(murid[i].grade, "A-");
            } else if (murid[i].nilai >= 75) {
                strcpy(murid[i].grade, "B+");
            } else if (murid[i].nilai >= 70) {
                strcpy(murid[i].grade, "B");
            } else if (murid[i].nilai >= 65) {
                strcpy(murid[i].grade, "C");
            } else if (murid[i].nilai >= 60) {
                strcpy(murid[i].grade, "C-");
            } else if (murid[i].nilai >= 55) {
                strcpy(murid[i].grade, "D");
            } else {
                strcpy(murid[i].grade, "E");
            }
            fprintf(fdata, "NIM     : %s\nNama    : %s\nJurusan : %s\n\n", murid[i].nim, murid[i].nama, murid[i].jurusan);
            fprintf(fnilai, "%s - %s\nTugas: %.2f\nUTS: %.2f\nUAS: %.2f\nNilai Akhir: %.2f\nGrade: %s\n\n", murid[i].nim, murid[i].nama, murid[i].tugas, murid[i].uts, murid[i].uas, murid[i].nilai, murid[i].grade);
        }
        fclose(fnilai);
        fclose(fdata);
        goto menu;

    } else if (pilihan == 3) {
        showStudentDetail(murid, jumlah);
        printf("Press Any Key To Continue");
        getchar();
        getchar();
        goto menu;
    } else if (pilihan == 4) {
        printf("Thank you for using Our Simple Database\n");
        return 0;
    } else {
        printf("Invalid option.\n");
        printf("Press Any Key To Continue");
        getchar();
        getchar();
        goto menu;
    }
}
