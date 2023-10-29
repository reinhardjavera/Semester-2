#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char nama[30];
    char jurusan[20];
    float ipk;
};

void clickAnything(){
    printf("\nClick anything to continue\n\n");
    getch();
}

void inputStudent(struct student s[20], int *number){
    printf("Name  : ");
    scanf("%s", s[*number].nama);
    fflush(stdin);
    printf("Major : ");
    scanf("%s", s[*number].jurusan);
    fflush(stdin);
    printf("GPA   : ");
    scanf("%f", &s[*number].ipk);
    *number = *number + 1;
    fflush(stdin);
}

void printAll(struct student murid[20], int *number){
    printf("-------\n");
    printf("|%s |\t\t\t%s\t\t\t|\t\t%s\t\t|\t%s\t|\n", "No.", "Name", "Major", "GPA");
    printf("----------\n");
    for (int i = 0; i < *number; i++)
    {
        printf("|%-4d|%-42s|%-31s|%15.2f|\n", i + 1, murid[i].nama, murid[i].jurusan, murid[i].ipk);
    }
    printf("------------\n");
}
int main()
{
    int num = 0, choice;
    struct student murid[20];
    menu :
        choice = 0;
        fflush(stdin);
        printf("Welcome to simple student database (%d/20)\n1. Show all students\n2. Input new student\n3. Exit\nChoose: ", num);
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printAll(murid, &num);
            clickAnything();
            goto menu;
            break;
        case 2:
            if (num < 20)
            {
                inputStudent(murid, &num);
            }else
            {
                printf("\nDatabase is full(max 20)\n");
                clickAnything();
            }
            goto menu;
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\n\nInput not valid, please reinput!.\n\n");
            goto menu;
            break;
        }
    return 0;
}
