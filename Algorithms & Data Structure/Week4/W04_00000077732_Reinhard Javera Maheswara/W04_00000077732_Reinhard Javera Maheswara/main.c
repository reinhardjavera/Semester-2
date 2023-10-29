#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nim[11];
    char nama[50];
    char jurusan[30];
    struct Mahasiswa *next;
}Mahasiswa;

Mahasiswa *node, *head, *tail;


Mahasiswa *createNode () {
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    char nim[11], nama[50], jurusan[30];

    printf("NIM: "); scanf("%[^\n]", nim);
    fflush(stdin);
    printf("Nama: "); scanf("%[^\n]", nama);
    fflush(stdin);
    printf("Jurusan: "); scanf("%[^\n]", jurusan);
    fflush(stdin);
    strcpy(newNode->nim, nim);
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;
    return newNode;
}


void deleteFirstData() {
    Mahasiswa *trash;
    trash = head;
    head = head->next;
    free(trash);
}


void deleteAllData() {
    Mahasiswa *temp;
    temp = head;
    int i = 1;

    while (temp != NULL) {
        free(temp);
        temp = temp->next;
        i++;
    }
    head = NULL;
}

void deleteDataByNim() {
    Mahasiswa *trash, *temp;
    char nomorInduk [11];
    trash = head;

    printf("Masukkan NIM: "); scanf("%[^\n]", &nomorInduk); fflush(stdin);

    if (strcmp(trash->nim, nomorInduk) == 0) {
        head = head->next;
        free(trash);
    } else {
        while (strcmp(trash->next->nim, nomorInduk) == 1) {
            trash = trash->next;
        }

        if (trash->next->next != NULL) {
            temp =  trash;
            trash = trash->next;
            temp->next = trash->next;
            free(trash);
        } else {
            tail = trash;
            trash = tail->next;
            tail->next = NULL;
            free(trash);
        }
    }
}


void printLinkedList (Mahasiswa *head) {
    Mahasiswa *temp;
    temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("Data ke %d\n", i);
        printf("NIM     : %s\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}

int main () {
    int choice;
    head = NULL;

    system("cls");
    menu:
    printf("Welcome To Student Data Base\n");
    printf("1. Insert New Student\n2. Print Students Data\n3. Delete All Data\n4. Delete First Data\n5. Delete Data by NIM\n6. Exit\nChoose: ");
    scanf("%d", &choice);
    fflush(stdin);
    system("cls");

    if (choice == 1) {
        if (head == NULL) {
            node = createNode();
            head = node;
            tail = node;
        } else {
            node = createNode();
            tail->next = node;
            tail = node;
            tail->next = NULL;
        }
        printf("Press Any Key To Continue");
        getchar();
        system("cls");
        goto menu;
    } else if (choice == 2) {
        if (head == NULL) {
            printf("=== Data Kosong ===\n");
        } else {
            printLinkedList(head);
        }
        printf("Press Any Key To Continue");
        getchar();
        system("cls");
        goto menu;
    } else if (choice == 3) {
        deleteAllData();
        printf("Semua Data Telah Terhapus\n");
        printf("Press Any Key To Continue");
        getchar();
        system("cls");
        goto menu;
    } else if (choice == 4) {
        deleteFirstData();
        printf("Data Pertama Terhapus\n");
        printf("Press Any Key To Continue");
        getchar();
        system("cls");
        goto menu;
    } else if (choice == 5) {
        deleteDataByNim();
        printf("Data Telah Terhapus\n");
        printf("Press Any Key To Continue");
        getchar();
        system("cls");
        goto menu;
    } else {
        return 0;
    }
}
