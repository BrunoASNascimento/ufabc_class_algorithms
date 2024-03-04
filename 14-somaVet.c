#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);
    int V[N];

    int sumValor = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
        sumValor += V[i];
    }

    printf("%d\n", sumValor);

    return 0;
}
