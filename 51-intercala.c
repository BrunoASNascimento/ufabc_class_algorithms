#include <stdio.h>
#include <stdlib.h>

int *intercala(int *v1, int *v2, int q1, int q2)
{
    int *Vr = malloc((q1 + q2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < q1 && j < q2)
    {
        if (v1[i] < v2[j])
        {
            Vr[k++] = v1[i++];
        }
        else
        {
            Vr[k++] = v2[j++];
        }
    }

    while (i < q1)
    {
        Vr[k++] = v1[i++];
    }

    while (j < q2)
    {
        Vr[k++] = v2[j++];
    }

    return Vr;
}

void imprime(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }
}

int main()
{
    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);

    int *v1 = malloc(q1 * sizeof(int));
    int *v2 = malloc(q2 * sizeof(int));

    for (int i = 0; i < q1; i++)
    {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < q2; i++)
    {
        scanf("%d", &v2[i]);
    }

    int *vr = intercala(v1, v2, q1, q2);
    imprime(vr, q1 + q2);

    free(v1);
    free(v2);
    free(vr);
    return 0;
}
