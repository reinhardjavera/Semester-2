#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[50];
    char major[30];
    char nim[11];

};

struct score{
    float tugas, uts, uas, nilaiAkhir;
    char grade[3];
};

int main()
{
    int dataStudent, menu, i, grade;
    struct student n[100];
    struct score m[100];

    FILE *fdata = fopen ("dataMahasiswa.txt", "w");
    FILE *fnilai = fopen ("nilaiMahasiswa.txt", "w");
    for(dataStudent=0; dataStudent<100; dataStudent++){
    reinput:
    printf("Welcome to simple student database(%d/100)\n", dataStudent);
    printf("1. Show all students \n2. Input new students \n3. Exit \nChoose: ");
    scanf("%d", &menu);

    switch (menu){
    case 1:
        printf("                                          List of Student Information                                           \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("|No.|                       Name                       |               NIM               |       MAJOR      |");
        printf("\n-------------------------------------------------------------------------------------------------------------\n");
        for (i=0;i<dataStudent;i++){
            printf("|%-3d|%-50s|%-35s|%-16s|\n", i + 1, n[i].name, n[i].nim, n[i].major);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf("                       List of Student Score                        \n");
        printf("-------------------------------------------------------------------\n");
        printf("|No.|        Nama        | Tugas | UTS | UAS | Nilai Akhir | Grade |");
        printf("\n-------------------------------------------------------------------\n");
        for (i = 0; i < dataStudent; i++)
        {
            printf("|%-3d|%-19s|%-7.0f|%-5.0f|%-5.0f|%-13.0f|%-7s|\n", i + 1, n[i].name, m[i].tugas, m[i].uts, m[i].uas, m[i].nilaiAkhir, m[i].grade);
        }
        printf("-------------------------------------------------------------------\n\n");
        fflush(stdin);
        goto finish;
        break;
    case 2:
            printf("Insert Student Information\n-------------------\n");
            printf("Name: ");
            fflush(stdin);
            scanf("%[^\n]", n[dataStudent].name);
            fflush(stdin);
            printf("NIM: ");
            scanf("%[^\n]", n[dataStudent].nim);
            fflush(stdin);
            printf("Major: ");
            scanf("%[^\n]", n[dataStudent].major);
            fflush(stdin);
            fprintf(fdata, "%s - %s - %s\n", n[dataStudent].name, n[dataStudent].nim, n[dataStudent].major);
            printf("\n");
            printf("Insert Student Grade:\n------------------\n");
            printf("Nilai Tugas: ");
            scanf("%f", &m[dataStudent].tugas);
            fflush(stdin);
            printf("Nilai UTS: ");
            scanf("%f", &m[dataStudent].uts);
            fflush(stdin);
            printf("NilaiUAS: ");
            scanf("%f", &m[dataStudent].uas);
            fflush(stdin);
            m[dataStudent].nilaiAkhir = m[dataStudent].tugas * 0.3 + m[dataStudent].uts * 0.3 + m[dataStudent].uas * 0.4;
            fflush(stdin);
            if (m[dataStudent].nilaiAkhir >= 95)
            {
                strcpy(m[dataStudent].grade, "A+");
            }
            else if (m[dataStudent].nilaiAkhir >= 85)
            {
                strcpy(m[dataStudent].grade, "A");
            }
            else if (m[dataStudent].nilaiAkhir >= 80)
            {
                strcpy(m[dataStudent].grade, "A-");
            }
            else if (m[dataStudent].nilaiAkhir >= 75)
            {
                strcpy(m[dataStudent].grade, "B+");
            }
            else if (m[dataStudent].nilaiAkhir >= 70)
            {
                strcpy(m[dataStudent].grade, "B");
            }
            else if (m[dataStudent].nilaiAkhir >= 65)
            {
                strcpy(m[dataStudent].grade, "C");
            }
            else if (m[dataStudent].nilaiAkhir >= 60)
            {
                strcpy(m[dataStudent].grade, "C-");
            }
            else if (m[dataStudent].nilaiAkhir >= 55)
            {
                strcpy(m[dataStudent].grade, "D");
            }
            else if (m[dataStudent].nilaiAkhir >= 0)
            {
                strcpy(m[dataStudent].grade, "E");
            }
            fflush(stdin);
            printf("\nNew student added\nPress any key to continue!");
            getchar();
            fprintf(fnilai, "Nama\t\t: %s\nTugas\t\t: %.0f\nUTS\t\t: %.0f\nUAS\t\t: %.0f\nNilai Akhir\t: %.2f\nGrade\t\t: %s\n\n", n[dataStudent].name, m[dataStudent].tugas, m[dataStudent].uts, m[dataStudent].uas, m[dataStudent].nilaiAkhir, m[dataStudent].grade);
            break;

    case 3:
            printf("Thank You & Have a Nice Day");
            goto finish;
            break;
    default:
        printf("Input tidak valid, mohon input ulang!\n\n");
        goto reinput;
        break;
    }

    printf("Data Base is Full\nPress any key to continue");
    getchar();
    goto reinput;
    finish:
    fclose(fdata);
    fclose(fnilai);
    fflush(stdin);
    return 0;
    }
}
