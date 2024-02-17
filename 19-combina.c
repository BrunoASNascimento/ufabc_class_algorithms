#include <stdio.h>
#include <stdlib.h>

int *combina(int *v, int *w, int n, int m)
{

    int *z = (int *)malloc((n + m) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        z[i] = v[i];
    }

    for (int i = 0; i < m; i++)
    {
        z[n + i] = w[m - 1 - i];
    }

    return z;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int v[n], w[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &w[i]);
    }

    int *z = combina(v, w, n, m);

    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", z[i]);
    }
    printf("\n");

    free(z);

    return 0;
}
