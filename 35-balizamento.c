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
    int par = 2;                                             // Primeiro par
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

void distribuirAtletas(Atleta atletas[], int numAtletas, int numRaias, int *vectorPositions)
{
    // Ordenando os atletas pelo tempo de balizamento
    qsort(atletas, numAtletas, sizeof(Atleta), comparar);

    // Calculando o número de séries necessárias
    int numSeries = (numAtletas + numRaias - 1) / numRaias; // Arredondando para cima

    // Distribuindo os atletas pelas séries e raias
    printf("%d %s\n", numSeries, numSeries > 1 ? "series" : "serie");
    int controlIndex = numSeries-1;
    for (int i = 0; i < numSeries; i++)
    {
        printf("%da. serie:\n", i + 1);
        int controlMinRaias = 3 - (numAtletas % numRaias);
        if (controlMinRaias < 0)
            controlMinRaias = 0;

        int invertOrder = controlIndex;
        controlIndex--;
        int inicioSerie = (invertOrder * numRaias) - controlMinRaias;
        if (inicioSerie < 0)
            inicioSerie = 0;

        int fimSerie = inicioSerie + numRaias - controlMinRaias;
        if (fimSerie > numAtletas)
            fimSerie = numAtletas;
        
        // int checkProblem = fimSerie - inicioSerie ;
        // if (checkProblem > numRaias)
        // {
        //     inicioSerie=inicioSerie-checkProblem;
        //     if (inicioSerie < 0)
        //     inicioSerie = 0;
        //     fimSerie=fimSerie-checkProblem;
        // }

        // printf("Inicio: %d, Fim: %d\n", inicioSerie, fimSerie);
        // printf("invertOrder: %d\n", invertOrder);

        // Alocação nas raias
        for (int j = inicioSerie; j < fimSerie; j++)
        {
            for (int k = 0; k < numRaias; k++)
            {
                if (vectorPositions[k] == j - inicioSerie + 1)
                {
                    printf("Raia %d: %s\n", k + 1, atletas[j].nome);
                    break;
                }
            }
            // printf("Raia %d: %s\n", j - inicioSerie + 1, atletas[j].nome);
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

    distribuirAtletas(atletas, numAtletas, numRaias, vectorPositions);

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


// --- Input ---
// 10
// 26
// Joana 8 15 0
// Ana 6 36 0
// Ariadne 7 11 25
// Giseli 5 40 45
// Marlene 6 3 0
// MarciaA 6 18 50
// Karla 8 20 0
// Catia 7 10 0
// MarciaB 7 30 0
// MarciaC 8 0 0
// Valquiria 8 15 1
// Jesoni 7 15 0
// DeniseA 7 47 20
// Ligia 8 0 1
// MariaA 11 0 0
// Graciete 8 0 2
// DeniseB 7 47 21
// Desiree 8 1 0
// MariaB 11 0 1
// Margarida 10 5 71
// Bianca 11 46 85
// Mercedes 12 0 0
// Maruse 13 0 0
// Herilene 8 50 0
// MariaC 9 20 0
// Nora 19 0 0

// --- Expected output ---
// 3 series
// 1a. serie:
// Raia 5: MariaA
// Raia 6: MariaB
// Raia 4: Bianca
// Raia 7: Mercedes
// Raia 3: Maruse
// Raia 8: Nora
// 2a. serie:
// Raia 5: MarciaC
// Raia 6: Ligia
// Raia 4: Graciete
// Raia 7: Desiree
// Raia 3: Joana
// Raia 8: Valquiria
// Raia 2: Karla
// Raia 9: Herilene
// Raia 1: MariaC
// Raia 10: Margarida
// 3a. serie:
// Raia 5: Giseli
// Raia 6: Marlene
// Raia 4: MarciaA
// Raia 7: Ana
// Raia 3: Catia
// Raia 8: Ariadne
// Raia 2: Jesoni
// Raia 9: MarciaB
// Raia 1: DeniseA
// Raia 10: DeniseB


// --- Input ---
// 8
// 24
// Eduardo 1 14 24
// Francisco 1 12 45
// Asafe 1 11 44
// Lucas 1 9 11
// Theo 1 6 31
// Fink 1 10 93
// Bezerra 1 12 26
// Enrico 1 13 87
// Otavio 1 38 33
// Felipe 0 0 0
// Davi 1 30 2
// Felippe 1 28 35
// Christian 1 21 0
// Pozati 1 18 32
// Gomes 1 21 27
// Kaua 1 28 57
// Raul 1 17 85
// Gabriel 1 17 22
// Guilherme 1 16 17
// Cavalcante 1 15 7
// Samuel 1 15 99
// Miguel 1 16 44
// Luan 1 17 29
// Marcos 1 18 12

// --- Expected output ---
// 3 series
// 1a. serie:
// Raia 4: Pozati
// Raia 5: Christian
// Raia 3: Gomes
// Raia 6: Felippe
// Raia 2: Kaua
// Raia 7: Davi
// Raia 1: Otavio
// Raia 8: Felipe
// 2a. serie:
// Raia 4: Cavalcante
// Raia 5: Samuel
// Raia 3: Guilherme
// Raia 6: Miguel
// Raia 2: Gabriel
// Raia 7: Luan
// Raia 1: Raul
// Raia 8: Marcos
// 3a. serie:
// Raia 4: Theo
// Raia 5: Lucas
// Raia 3: Fink
// Raia 6: Asafe
// Raia 2: Bezerra
// Raia 7: Francisco
// Raia 1: Enrico
// Raia 8: Eduardo