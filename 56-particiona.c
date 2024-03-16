#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o conteúdo do vetor
void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função de particionamento Lomuto
int particiona(int *v, int n, int p)
{
    // Troca o pivô com o último elemento
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

    // Coloca o pivô na sua posição final
    temp = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = temp;

    // Retorna a nova posição do pivô
    return i + 1;
}

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    int *v = (int *)malloc(sizeof(int) * n);

    // Leitura dos elementos do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    // Realiza o particionamento e obtém a nova posição do pivô
    int nova_posicao_pivo = particiona(v, n, p);

    // Imprime a nova posição do pivô
    printf("%d\n", nova_posicao_pivo);
    // Imprime o vetor rearranjado
    imprimir(v, n);

    free(v);
    return 0;
}
