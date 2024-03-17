#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int min, seg, cent; // Representa o tempo como minutos, segundos, centésimos
} Atleta;

// Função para criar um vetor de posições de raia
int *createVectorPositionByPosition(int numRaias)
{
    int *vectorPositions = (int *)malloc(numRaias * sizeof(int));
    int impar = numRaias % 2 == 0 ? numRaias - 1 : numRaias; // Último ímpar
    int par = 2;                        // Primeiro par
    int indice = 0;

    // Preenchendo ímpares
    for (int i = impar; i > 0; i -= 2)
    {
        vectorPositions[indice++] = i;
    }

    // Preenchendo pares
    for (int i = par; indice < numRaias; i += 2)
    {
        vectorPositions[indice++] = i;
    }
    return vectorPositions;
}

int comparar(const void *a, const void *b)
{
    Atleta *atletaA = (Atleta *)a;
    Atleta *atletaB = (Atleta *)b;

    // Priorizando atletas com tempo definido
    if (atletaA->min == 0 && atletaA->seg == 0 && atletaA->cent == 0 && (atletaB->min > 0 || atletaB->seg > 0 || atletaB->cent > 0))
    {
        return 1; // Atleta A vem depois de B
    }
    else if (atletaB->min == 0 && atletaB->seg == 0 && atletaB->cent == 0 && (atletaA->min > 0 || atletaA->seg > 0 || atletaA->cent > 0))
    {
        return -1; // Atleta A vem antes de B
    }
    else
    {
        // Comparação por tempo total em centésimos
        int tempoTotalA = atletaA->min * 6000 + atletaA->seg * 100 + atletaA->cent;
        int tempoTotalB = atletaB->min * 6000 + atletaB->seg * 100 + atletaB->cent;
        return tempoTotalA - tempoTotalB;
    }
}

void distribuirAtletas(Atleta atletas[], int numAtletas, int numRaias)
{
    // Ordenando os atletas pelo tempo de balizamento
    qsort(atletas, numAtletas, sizeof(Atleta), comparar);

    // Calculando o número de séries necessárias
    int numSeries = (numAtletas + numRaias - 1) / numRaias; // Arredondando para cima

    // Distribuindo os atletas pelas séries e raias
    printf("%d %s\n", numSeries, numSeries > 1 ? "series" : "serie");
    for (int i = 0; i < numSeries; i++)
    {
        printf("%da. serie:\n", i + 1);
        int inicioSerie = i * numRaias;
        int fimSerie = inicioSerie + numRaias;
        if (fimSerie > numAtletas)
            fimSerie = numAtletas;

        // Alocação nas raias
        for (int j = inicioSerie; j < fimSerie; j++)
        {
            printf("Raia %d: %s\n", j - inicioSerie + 1, atletas[j].nome);
        }
    }
}

int main()
{
    int numRaias, numAtletas;
    scanf("%d %d", &numRaias, &numAtletas);

    Atleta *atletas = (Atleta *)malloc(numAtletas * sizeof(Atleta));

    for (int i = 0; i < numAtletas; i++)
    {
        scanf("%s %d %d %d", atletas[i].nome, &atletas[i].min, &atletas[i].seg, &atletas[i].cent);
    }

    // chmae e print a função createVectorPositionByPosition
    int *vectorPositions = createVectorPositionByPosition(numRaias);
    for (int i = 0; i < numRaias; i++)
    {
        printf("Vetor: %d\n", vectorPositions[i]);
    }

    distribuirAtletas(atletas, numAtletas, numRaias);

    free(atletas);
    return 0;
}



// --- Input ---
// 8
// 10
// Floriana 0 52 8
// Leticia 0 55 10
// Cris 0 55 43
// Julia 0 58 32
// Helena 1 0 39
// Vitoria 1 0 41
// Maria 1 5 14
// Isabela 1 15 22
// Lucia 2 0 0
// Ana 0 0 0

// --- Expected output (text)---
// 2 series
// 1a. serie:
// Raia 4: Isabela
// Raia 5: Lucia
// Raia 3: Ana
// 2a. serie:
// Raia 4: Floriana
// Raia 5: Leticia
// Raia 3: Cris
// Raia 6: Julia
// Raia 2: Helena
// Raia 7: Vitoria
// Raia 1: Maria