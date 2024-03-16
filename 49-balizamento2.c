#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int min, seg, cent, inscricao;
} Atleta;

int compara(const void *a, const void *b)
{
    Atleta *atletaA = (Atleta *)a;
    Atleta *atletaB = (Atleta *)b;
    int tempoA = atletaA->min * 6000 + atletaA->seg * 100 + atletaA->cent;
    int tempoB = atletaB->min * 6000 + atletaB->seg * 100 + atletaB->cent;
    if (tempoA != tempoB)
        return tempoA - tempoB;
    return atletaA->inscricao - atletaB->inscricao;
}

void distribuirAtletas(int nRaias, Atleta atletas[], int nAtletas)
{
    int serie = 1, totalSeries = (nAtletas + nRaias - 4) / (nRaias - 1);
    if (totalSeries == 0)
        totalSeries = 1;
    printf("%d %s\n", totalSeries, totalSeries > 1 ? "series" : "serie");

    for (int i = 0; i < nAtletas; i += nRaias)
    {
        int atletasNaSerie = nAtletas - i < nRaias ? nAtletas - i : nRaias;
        if (totalSeries > 1 && atletasNaSerie < 3)
            atletasNaSerie = 3;

        printf("%da. serie:\n", serie++);
        int centro = (nRaias + 1) / 2, passo = 0, lado = 0;

        for (int j = 0; j < atletasNaSerie; j++)
        {
            int raia = centro + passo * (lado ? 1 : -1);
            printf("Raia %d: %s\n", raia, atletas[i + j].nome);
            lado = !lado;
            if (lado == 0)
                passo++;
        }

        i -= nRaias - atletasNaSerie; // Ajuste para a próxima série se atletasNaSerie foi modificado
    }
    printf("\n");
}

int main()
{
    int nRaias, nAtletas;
    scanf("%d %d", &nRaias, &nAtletas);

    Atleta atletas[nAtletas];
    for (int i = 0; i < nAtletas; i++)
    {
        scanf("%s %d %d %d", atletas[i].nome, &atletas[i].min, &atletas[i].seg, &atletas[i].cent);
        atletas[i].inscricao = i;
    }

    qsort(atletas, nAtletas, sizeof(Atleta), compara);

    distribuirAtletas(nRaias, atletas, nAtletas);
    return 0;
}
