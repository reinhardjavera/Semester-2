#include <stdio.h>
#include <stdlib.h>

void calculation(int *choice, int mtx1[][3], int mtx2[][3], int mtx3[][3]){
    int i = 0, j = 0, k = 0;
    fflush(stdin);
    if (*choice == 1){
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                    mtx3[i][j] = 0;
                for (k = 0; k < 3; k++){
                    mtx3[i][j] = mtx3[i][j] + mtx1[i][k] * mtx2[k][j];
                }
            }
        }
        printf("\nHasil: \n\n");
        fflush(stdout);
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                printf("%d ", mtx3[i][j]);
            }
            printf("\n");
        }

    }
    else if (*choice == 2){
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                mtx3[i][j] = mtx1[i][j] + mtx2[i][j];
            }
        }
        printf("\nHasil: \n\n");
        fflush(stdout);
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                printf("%d ", mtx3[i][j]);
            }
            printf("\n");
        }
    }
    else if (*choice == 3){
        printf("\nTranspose Matrix Pertama: \n\n");
        fflush(stdin);
        fflush(stdout);
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                mtx3[i][j] = mtx1[j][i];
            }
        }
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                printf("%d ", mtx3[i][j]);
            }
            printf("\n");
        }
        printf("\n==========================================\n");
        printf("\nTranspose Matrix Kedua: \n\n");
        fflush(stdin);
        fflush(stdout);
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                mtx3[i][j] = mtx2[j][i];
            }
        }
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                printf("%d ", mtx3[i][j]);
            }
            printf("\n");
        }

    }
    else{
        printf("\nError.\n");
    }

}
int main(){
    int matrix1[3][3],matrix2[3][3], totalMatrix[3][3], i, j, choose;
    reInput:
    printf("Input matrix pertama: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nInput matrix kedua: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }
    menu:
    choose = 0;
    printf("\nPilihan : \n1. Perkalian Dua Buah Matrix\n2. Penjumlahan Dua Buah Matrix\n3. Transpose Dua Buah Matrix\n4. Input Ulang Matrix\n5. Exit\nInput : ");
    scanf("%d", &choose);
    fflush(stdin);
    switch(choose){
    case 1:
        printf("\n==========================================\n");
        calculation(&choose, matrix1, matrix2, totalMatrix);
        printf("\n==========================================\n");
        goto menu;
        break;
    case 2:
        printf("\n==========================================\n");
        calculation(&choose, matrix1, matrix2, totalMatrix);
        printf("\n==========================================\n");
        goto menu;
        break;
    case 3:
        printf("\n==========================================\n");
        calculation(&choose, matrix1, matrix2, totalMatrix);
        printf("\n==========================================\n");
        goto menu;
        break;
    case 4:
        printf("\n");
        goto reInput;
        break;
    case 5:
        printf("\n==========================================\n");
        printf("Bye!");
        printf("\n==========================================\n");
        exit(69);
        break;
    default:
        printf("\nInputan tidak valid, silahkan input ulang!\n");
        goto menu;
        break;
    }

    return 0;
}
