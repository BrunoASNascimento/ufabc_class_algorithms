#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int particiona(int *v, int n, int p)
{

    int temp = v[p];
    v[p] = v[n - 1];
    v[n - 1] = temp;

    int pivô = v[n - 1];
    int i = -1;
    for (int j = 0; j < n - 1; j++)
    {
        if (v[j] <= pivô)
        {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    temp = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = temp;

    return i + 1;
}

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    int *v = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int nova_posicao_pivo = particiona(v, n, p);

    printf("%d\n", nova_posicao_pivo);

    imprimir(v, n);

    free(v);
    return 0;
}
