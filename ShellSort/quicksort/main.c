#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define SIZE 6

/*int getSize(int vet[])
{
    int size = sizeof(vet)/sizeof(vet[0]);
    return size;
}*/

void mediana(int vetor[], int tam)
{
    int primPos, meioPos, ultPos;
    int primeiro, meio, ultimo, medianaPos, auxTroca;

    primPos = 0;
    meioPos = (tam-1)/2;
    ultPos = tam-1;

    primeiro = vetor[primPos];
    meio = vetor[meioPos];
    ultimo = vetor[ultPos];

    if(meio <= ultimo)
        if(primeiro <= meio)
            medianaPos = meioPos;
        else
            if(primeiro <= ultimo)
                medianaPos = primPos;
            else
                medianaPos = ultPos;
    else
        if(meio <= primeiro)
            medianaPos = meioPos;
        else
            if(primeiro <= ultimo)
                medianaPos = ultPos;
            else
                medianaPos = primPos;

    auxTroca = vetor[0];
    vetor[0] = vetor[medianaPos];
    vetor[medianaPos] = auxTroca;
}

void aleatorio(int vetor[], int tam)
{
    int auxTroca;

    srand(time(NULL));
    int randPos = rand() % tam;

    auxTroca = vetor[0];
    vetor[0] = vetor[randPos];
    vetor[randPos] = auxTroca;
}

void printArray(int vet[], int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
}

int main()
{
    int vetTest[] = {3,1,6,5,2,7};

    printArray(vetTest, SIZE);
    printf("\n");

    //med = mediana(vetTest, SIZE);
    mediana(vetTest, SIZE);
    printArray(vetTest, SIZE);

    return 0;
}
