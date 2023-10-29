#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Mahasiswa{
    char singer[60];
    char album[60];
    char title[60];
    int year;
    struct Mahasiswa *next, *prev;
}Mahasiswa;

Mahasiswa *node, *head, *prev, *tail;

Mahasiswa *createNode (char singer[60], char album[60], char title[60], int year) {
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    FILE *fdata = fopen("playlist.txt", "a");
    strcpy(newNode->singer, singer);
    strcpy(newNode->album, album);
    strcpy(newNode->title, title);
    newNode->year = year;
    newNode->next = newNode->prev = NULL;
    printf("\nLagu [%s - %s]\nData berhasil ditambahkan!\n", newNode->title, newNode->singer);
    fprintf(fdata, "%s*%s*%s*%d\n", singer, album, title, year);
    fclose(fdata);
    return newNode;
}

Mahasiswa *scanNode (char singer[60], char album[60], char title[60], int year) {
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    strcpy(newNode->singer, singer);
    strcpy(newNode->album, album);
    strcpy(newNode->title, title);
    newNode->year = year;
    return newNode;
}

void reWrite(Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    FILE *f3 = fopen("playlist.txt", "w");
    while (temp != NULL) {
        fprintf(f3, "%s*%s*%s*%d\n", temp->singer, temp->album, temp->title, temp->year);
        temp = temp->next;
    }
    fclose(f3);
}

void printDLL (Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    int i = 1;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("|                                      YOUR PLAYLIST                                          |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("|No.| Singer             | Song Title                 | Album                 | Released Year |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("|%-3d| %-19s| %-27s| %-22s| %-14d|\n", i, temp->singer, temp->title, temp->album, temp->year);
        printf("-----------------------------------------------------------------------------------------------\n");
        temp = temp->next;
        i++;
    }
}

void deleteData(Mahasiswa *tail) {
    Mahasiswa *trash;
    trash = tail;
    tail = tail->prev;
    tail->next = NULL;
    printf("Lagu [%s - %s] berhasil dihapus dari list.\n", trash->title, trash->singer);
    free(trash);
}

int main () {
    int pilihan, choice;
    head = tail = NULL;
    char singer[60], album[60], title[60];
    int year;
    FILE *f1 = fopen("playlist.txt", "r");
    while (!feof(f1)) {
        fscanf(f1, "%[^*]*%[^*]*%[^*]*%d\n", singer, album, title, &year);
        node = scanNode(singer, album, title, year);
        node->next = NULL;
        if (head == NULL) {
            node->prev = NULL;
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    fclose(f1);

    menu:
    printf("--------------------------------------\n");
    printf("| -- WELCOME TO PLAYLIST DATABASE -- |\n");
    printf("--------------------------------------\n");
    printf("1. Tampilkan Data\n2. Tambah Data\n3. Hapus Data\n4. Exit\nChoose: ");
    scanf("%d", &pilihan); fflush(stdin);
    printf("\033[2J\033[1;1H");

    if(pilihan == 1){
        printDLL(head);
        printf("\nPress Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H");
        goto menu;
    }else if(pilihan == 2){
        printf("Input Singer   : "); scanf("%[^\n]", singer); fflush(stdin);
        printf("Album          : "); scanf("%[^\n]", album); fflush(stdin);
        printf("Title          : "); scanf("%[^\n]", title); fflush(stdin);
        printf("Released Year  : "); scanf("%d", &year); fflush(stdin);
        node = createNode(singer, album, title, year);
        node->next = NULL;
        if (head == NULL) {
            node->prev = NULL;
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        printf("\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H");
        goto menu;

    }else if(pilihan == 3){
        deleteData(tail);
        reWrite(head);
        printf("\n");
        printf("Press Any Key To Continue");
        getchar();
        printf("\033[2J\033[1;1H");
        goto menu;
    } else {
        reWrite(head);
        return 0;
    }
}
