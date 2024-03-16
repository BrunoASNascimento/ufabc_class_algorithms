#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int q1, int q2)
{
    int *Vaux = (int *)malloc(sizeof(int) * (q1 + q2));
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

    // Copia o restante dos elementos de v[i..q1-1], se houver
    while (i < q1)
    {
        Vaux[k++] = v[i++];
    }

    // Copia o restante dos elementos de v[j..q1+q2-1], se houver
    while (j < q1 + q2)
    {
        Vaux[k++] = v[j++];
    }

    // Copia os elementos de volta para o vetor original
    for (i = 0; i < q1 + q2; i++)
    {
        v[i] = Vaux[i];
    }

    free(Vaux);
}

void imprime(int *v, int q1, int q2)
{
    for (int i = 0; i < q1 + q2; i++)
    {
        printf("%d\n", v[i]);
    }
}

int main()
{
    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);
    int *v = (int *)malloc(sizeof(int) * (q1 + q2));

    for (int i = 0; i < q1; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = q1; i < q1 + q2; i++)
    {
        scanf("%d", &v[i]);
    }

    intercala(v, q1, q2);
    imprime(v, q1, q2);

    free(v);
    return 0;
}
