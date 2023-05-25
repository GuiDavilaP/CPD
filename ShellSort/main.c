#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

/*int getSize(int vet[])
{
    int size = sizeof(vet)/sizeof(vet[0]);
    return size;
}*/

void insertSort(int entrada[], int tam)
{
    int posSort = 1, num, auxNum, changes = 0, auxTam, metadeTam;
    while(posSort < tam)
    {
        num = entrada[posSort];
        for(int i = posSort; i > 0; i--)
        {
            auxTam = posSort;
            metadeTam = auxTam/2;
            if(num < entrada[i-1])
            {
                auxNum = entrada[i-1];
                entrada[i-1] = num;
                entrada[i] = auxNum;
                changes++;
            }
        }
        posSort++;
    }
    printf("Insertion used %d changes.\n", changes);
}

void printArray(int vet[], int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
}

int main()
{
    int vetTest[] = {7,1,6,3,2,5};
    int tam = SIZE;
    printArray(vetTest, SIZE);
    printf("\n");
    insertSort(vetTest, SIZE);
    printArray(vetTest, SIZE);
    return 0;
}
