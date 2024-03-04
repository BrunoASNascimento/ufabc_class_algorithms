#include <stdio.h>

void bubbleSort(int *v, int n)
{
    int i, j, aux;
    int totalSwaps = 0, totalIfsExecuted = 0, totalIfsSatisfied = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            totalIfsExecuted++;
            if (v[j] > v[j + 1])
            {

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                totalSwaps++;
                totalIfsSatisfied++;

                for (int k = 0; k < n; k++)
                {
                    printf("%d", v[k]);
                    if (k < n - 1)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }

    printf("Total de IFs executados: %d\n", totalIfsExecuted);
    printf("Total de IFs satisfeitos: %d\n", totalIfsSatisfied);
}

int main()
{
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    bubbleSort(v, n);

    return 0;
}
