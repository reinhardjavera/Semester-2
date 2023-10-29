#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *bil, int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= 1; j--)
        {
            if (bil[j] < bil[j - 1])
            {
                swap(&bil[j], &bil[j - 1]);
            }
        }
    }
}

void insertionSort(int *bil, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        // Menetapkan elemen di indeks ke-i sebagai nilai minimum
        temp = bil[i];

        // Cek nilai minimum terhadap elemen selanjutnya
        for (j = i - 1; j >= 0 && bil[j] > temp; j--)
        {
            bil[j + 1] = bil[j];
        }

        bil[j + 1] = temp;
    }
}

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

void insertNode(int val, LinkedList **head)
{
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        LinkedList *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void radixSort(int *data, int n)
{
    int i, j, maks;
    LinkedList *bucket[10];
    for (i = 0; i < 10; i++)
    {
        bucket[i] = NULL;
    }

    maks = data[0];
    for (i = 1; i < n; i++)
    {
        if (maks < data[i])
        {
            maks = data[i];
        }
    }

    int totalIterasi = 0;
    while (maks > 0)
    {
        maks /= 10;
        totalIterasi++;
    }

    int pembagi = 1;

    for (i = 0; i < totalIterasi; i++)
    {
        for (j = 0; j < n; j++)
        {
            int digit = (data[j] / pembagi) % 10;
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        int idx = 0;
        for (j = 0; j < 10; j++)
        {
            LinkedList *temp = bucket[j];
            while (temp != NULL)
            {
                data[idx] = temp->value;
                idx++;
                temp = temp->next;
            }
        }

        for (j = 0; j < 10; j++)
        {
            LinkedList *trash, *temp = bucket[j];
            while (temp != NULL)
            {
                trash = temp;
                temp = temp->next;
                free(trash);
            }
            bucket[j] = NULL;
        }
    }
}

void selectionSort(int *bil, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int temp = i;

        for (j = i + 1; j < n; j++)
        {
            if (bil[j] < bil[temp])
            {
                temp = j;
            }
        }

        if (temp != i)
        {
            swap(&bil[temp], &bil[i]);
        }
    }
}

int main()
{
int i, n, *bil;
printf("Banyak bilangan: ");
scanf("%d", &n);
bil = malloc(sizeof(int) * n);

for (i = 0; i < n; i++)
{
    printf("Input bilangan ke-%d: ", i + 1);
    scanf("%d", &bil[i]);
}

int pilihan;
printf("\nMenu Pilihan Sorting:\n");
printf("1. Bubble Sort\n");
printf("2. Insertion Sort\n");
printf("3. Radix Sort\n");
printf("4. Selection Sort\n");
printf("Pilih jenis sorting (1-4): ");
scanf("%d", &pilihan);

switch (pilihan)
{
    case 1:
        bubbleSort(bil, n);
        printf("Hasil Bubble Sort:\n");
        break;
    case 2:
        insertionSort(bil, n);
        printf("Hasil Insertion Sort:\n");
        break;
    case 3:
        radixSort(bil, n);
        printf("Hasil Radix Sort:\n");
        break;
    case 4:
        selectionSort(bil, n);
        printf("Hasil Selection Sort:\n");
        break;
    default:
        printf("Pilihan tidak valid.\n");
        free(bil);
        return 0;
}

for (i = 0; i < n; i++)
{
    printf("%d ", bil[i]);
}

free(bil);

return 0;
}

