#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vetor[1000000];
int swaps;
int recursoes;

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

void swap(int vet[], int pos1, int pos2)
{
    int aux = vet[pos1];
    vet[pos1] = vet[pos2];
    vet[pos2] = aux;
    swaps++;
}

int partLom(int vet[], int esq, int dir)
{
    int ultMenor = esq + 1;
    int chave = vet[esq];

    for(int i = esq + 1; i <= dir; i++)
    {
        if(vet[i] < chave)
        {
            swap(vet, i, ultMenor);
            ultMenor++;
        }
    }
    swap(vet, esq, ultMenor-1); // Coloca particionador na posição final.
    return (ultMenor-1);
}

int partHoare(int vet[], int esq, int dir)
{
    int i = esq;
    int j = dir+1;
    int chave = vet[esq];

    while(1)
    {
        while(vet[++i] <= chave && i != dir); // Acha primeiro elemento da esquerda à direita maior que particionador.
        while(vet[--j] > chave && j != esq); // Acha primeiro elemento da direita à esquerda menor que particionador.
        if(i >= j)
            break;
        swap(vet, i, j);
    }
    swap(vet, esq, j); // Coloca particionador na posição final.
    return j;
}

void qksLomuto(int vet[], int esq, int dir)
{
    int part;
    recursoes++;
    if(esq<dir)
    {
        part = partLom(vet, esq, dir);
        qksLomuto(vet, esq, part-1); // Sub-array menor que particionador.
        qksLomuto(vet, part+1, dir); // Sub-array maior que particionador.
    }
}

void qksHoare(int vet[], int esq, int dir)
{
    int part;
    recursoes++;
    if(esq<dir)
    {
        part = partHoare(vet, esq, dir);
        qksHoare(vet, esq, part-1); // Sub-array menor que particionador.
        qksHoare(vet, part+1, dir); // Sub-array maior que particionador.
    }
}


int main()
{
    int tamanho_vetor, aux_num;
    clock_t start, end;
    double exec_time;

    while (scanf("%d", &tamanho_vetor) != EOF)
    {
        for (int i=0; i<tamanho_vetor; i++)
        {
            scanf("%d", &aux_num);
            vetor[i] = aux_num;
        }

        swaps = 0;
        recursoes = 0;

        start = clock();

        /* !!! Troque funções para diferentes saídas, para enviar resultado para arquivo use "sort ./a.out < entrada-quicksort.txt > stats-mediana-hoare.txt". !!! */
        //mediana(vetor, tamanho_vetor);
        aleatorio(vetor, tamanho_vetor);
        //qksHoare(vetor, 0, tamanho_vetor - 1);
        qksLomuto(vetor, 0, tamanho_vetor - 1);

        end = clock();
        exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("TAMANHO ENTRADA %d", tamanho_vetor);
        printf("\nSWAPS %d", swaps);
        printf("\nRECURSOES %d", recursoes);
        printf("\nTEMPO %f\n", exec_time);

    }
    return 0;
}
