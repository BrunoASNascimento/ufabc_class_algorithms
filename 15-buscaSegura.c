#include <stdio.h>

int main()
{
    int N;
    int valueToSearch;

    scanf("%d", &N);
    int values[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &values[i]);
    }

    while (scanf("%d", &valueToSearch) != EOF)
    {
        int found = 0;

        for (int i = 0; i < N; i++)
        {
            if (values[i] == valueToSearch)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("SIM\n");
        }
        else
        {
            printf("CHAVE NAO ENCONTRADA\n");
        }
    }

    return 0;
}
