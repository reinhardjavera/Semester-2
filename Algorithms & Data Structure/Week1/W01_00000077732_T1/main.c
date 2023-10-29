#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char *cKata){
    int i;

    for(i=0; cKata[i] !=NULL; i++){
        if(cKata[i]>='a' && cKata[i]<='z'){
            cKata[i] -= 32;
        }
    }
}

void lowercase(char *cKata){
    int i;

    for(i=0; cKata[i] !=NULL; i++){
        if(cKata[i]>='A' && cKata[i]<='Z'){
            cKata[i] += 32;
        }
    }
}

void switching(char *cKata){
    int i;

    for(i=0; cKata[i] !=NULL; i++){
        if(cKata[i]>='a' && cKata[i]<='z'){
            cKata[i] -= 32;
        }
        else if(cKata[i]>='A' && cKata[i]<='Z'){
            cKata[i] +=32;
        }
    }
}

int main(){

    char cKata[100];
    int menu;

    reInput:
    printf("1. Uppercase\n2. Lowercase\n3. Switching\n4. Keluar\nPilihan: ");
    scanf("%d", &menu);

    switch(menu){
    case 1:
        printf("Masukkan Kata yang Diinginkan: ");
        scanf(" %[^\n]", cKata);
        uppercase(&cKata);
        printf("%s");
        break;

    case 2:
        printf("Masukkan Kata yang Diinginkan: ");
        scanf(" %[^\n]", cKata);
        lowercase(&cKata);
        printf("%s");
        break;

    case 3:
        printf("Masukkan Kata yang Diinginkan: ");
        scanf(" %[^\n]", cKata);
        switching(&cKata);
        printf("%s");
        break;

    case 4:
        printf("Bye");
        break;

    default:
        printf("Please input number between 1 and 4!\n");
        goto reInput;
    }

}
