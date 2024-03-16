#include <stdio.h>
#include <stdlib.h>

char *intercala(char *v1, char *v2, int q1, int q2)
{
    char *Sr = (char *)malloc(sizeof(char) * (q1 + q2 + 1)); // +1 para o caractere nulo '\0'
    int i = 0, j = 0, k = 0;

    while (i < q1 && j < q2)
    {
        if (v1[i] < v2[j])
        {
            Sr[k++] = v1[i++];
        }
        else
        {
            Sr[k++] = v2[j++];
        }
    }

    // Copia o restante dos caracteres de v1, se houver
    while (i < q1)
    {
        Sr[k++] = v1[i++];
    }

    // Copia o restante dos caracteres de v2, se houver
    while (j < q2)
    {
        Sr[k++] = v2[j++];
    }

    Sr[k] = '\0'; // Adiciona o caractere nulo no final da string resultante
    return Sr;
}

int main()
{
    int N1, N2;
    scanf("%d", &N1);
    char *S1 = malloc(sizeof(char) * (N1 + 1)); // +1 para o caractere nulo '\0'
    for (int i = 0; i < N1; i++)
    {
        scanf(" %c", &S1[i]);
    }
    S1[N1] = '\0'; // Adiciona o caractere nulo no final da string

    scanf("%d", &N2);
    char *S2 = malloc(sizeof(char) * (N2 + 1)); // +1 para o caractere nulo '\0'
    for (int i = 0; i < N2; i++)
    {
        scanf(" %c", &S2[i]);
    }
    S2[N2] = '\0'; // Adiciona o caractere nulo no final da string

    char *Sr = intercala(S1, S2, N1, N2);
    printf("%s\n", Sr);

    // Liberação da memória alocada
    free(S1);
    free(S2);
    free(Sr);

    return 0;
}
