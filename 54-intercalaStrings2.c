#include <stdio.h>
#include <stdlib.h>

void intercala(char *v, int q1, int q2)
{
    char *Vaux = malloc(sizeof(char) * (q1 + q2));
    int i = 0, j = q1, k = 0;

    while (i < q1 && j < q1 + q2)
    {
        if (v[i] < v[j])
        {
            Vaux[k++] = v[i++];
        }
        else
        {
            Vaux[k++] = v[j++];
        }
    }

    // Copia o restante dos caracteres da primeira substring, se houver
    while (i < q1)
    {
        Vaux[k++] = v[i++];
    }

    // Copia o restante dos caracteres da segunda substring, se houver
    while (j < q1 + q2)
    {
        Vaux[k++] = v[j++];
    }

    // Copia o vetor auxiliar de volta para o vetor original
    for (i = 0; i < q1 + q2; i++)
    {
        v[i] = Vaux[i];
    }

    free(Vaux);
}

int main()
{
    int q1, q2;
    scanf("%d %d", &q1, &q2);
    char *v = malloc(sizeof(char) * (q1 + q2 + 1)); // +1 para o caractere nulo '\0'

    // Leitura dos caracteres
    scanf("%s", v);

    intercala(v, q1, q2);

    printf("%s\n", v);

    free(v);
    return 0;
}
