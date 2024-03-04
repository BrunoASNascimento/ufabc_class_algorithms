#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N; 

    while (scanf("%d", &N) != EOF)
    { 
        if (N == 0)
        { 
            printf("S\n");
            continue;
        }

        int *vetor = (int *)malloc(N * sizeof(int)); 
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]); 
        }

        int checkSort = 1; 
        for (int i = 0; i < N - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {                 
                checkSort = 0; 
                break;        
            }
        }

        if (checkSort)
        {
            printf("S\n"); 
        }
        else
        {
            printf("N\n"); 
        }

        free(vetor); 
    }

    return 0;
}
