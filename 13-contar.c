#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);
    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    int X;
    scanf("%d", &X);

    int control = 0;
    for (int i = 0; i < N; i++)
    {
        if (V[i] >= X)
        {
            control++;
        }
    }

    printf("%d\n", control);

    return 0;
}
