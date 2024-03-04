#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    int totalIfs = 0;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            totalIfs++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            
        }
        for (int k = 0; k < n; k++)
            {
                if (k == 0)
                {

                    printf("%d", arr[k]);
                }
                else
                {
                    printf(" %d", arr[k]);
                }
            }
            printf("\n");
    }

    printf("Total de IFs executados: %d\n", totalIfs);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    return 0;
}



// Incorrect program output
// --- Input ---
// 10
// 54 12 2 90 4 78 55 21 2 48

// --- Program output ---
// 2 12 54 90 4 78 55 21 2 48
// 2 2 54 90 4 78 55 21 12 48
// 2 2 4 90 54 78 55 21 12 48
// 2 2 4 12 54 78 55 21 90 48
// 2 2 4 12 21 78 55 54 90 48
// 2 2 4 12 21 48 55 54 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 78 90
// Total de IFs executados: 45

// --- Expected output (text)---
// 2 12 54 90 4 78 55 21 2 48
// 2 2 54 90 4 78 55 21 12 48
// 2 2 4 90 54 78 55 21 12 48
// 2 2 4 12 54 78 55 21 90 48
// 2 2 4 12 21 78 55 54 90 48
// 2 2 4 12 21 48 55 54 90 78
// 2 2 4 12 21 48 54 55 90 78 // Missing line
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 78 90
// Total de IFs executados: 45



// Incorrect program output
// --- Input ---
// 10
// 90 78 55 54 48 21 12 4 2 2

// --- Program output ---
// 2 78 55 54 48 21 12 4 90 2
// 2 2 55 54 48 21 12 4 90 78
// 2 2 4 54 48 21 12 55 90 78
// 2 2 4 12 48 21 54 55 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 78 90
// Total de IFs executados: 45

// --- Expected output (text)---
// 2 78 55 54 48 21 12 4 90 2
// 2 2 55 54 48 21 12 4 90 78
// 2 2 4 54 48 21 12 55 90 78
// 2 2 4 12 48 21 54 55 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 90 78
// 2 2 4 12 21 48 54 55 78 90
// Total de IFs executados: 45

