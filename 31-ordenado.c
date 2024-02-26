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

        int checkSortDesc = 1;
        int checkSortAsc = 1; 
        for (int i = 0; i < N - 1; i++)
        {
            if (vetor[i] < vetor[i + 1])
            {                 
                checkSortDesc = 0; 
                
            } else if (vetor[i] > vetor[i + 1])
            {                 
                checkSortAsc = 0; 
                
            }
        }

        if (checkSortAsc || checkSortDesc)
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
