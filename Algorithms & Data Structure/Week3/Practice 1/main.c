#include <stdio.h>
#include <stdlib.h>


struct order{
    char food[30];
    int quantity;
    int price;
};

struct bill{
    char food[30];
    int quantity;
    int price;
    int total;

};

int main()
{
    struct order s[4];
    int i=0, j;

    FILE *fin = fopen("order.txt","r");
    while(!feof(fin))
    {
        fscanf(fin,"%[^#]#%[^#]#&d\n",s[i].food,&s[i].quantity,&s[i].price);
        fflush(stdin);
        i++;
    }
    fclose(fin);

    for (j = 0;j<i;j++)
    {
        printf("%s#%d#%d\n",s[j].food,&s[j].quantity,s[j].price);
    }

    struct bill s[5];
    int i=0;
    FILE *fout = fopen("bill.txt","w");
    for (i -=1;i >= 0;i--)
    {
        fprintf(fout,"%d * %d = %d\n\n",s[i].food,&s[i].quantity,s[i].price,s[i].total);
    }
    fclose(fout);

    return 0;
}
