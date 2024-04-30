#include <stdio.h>
#include <stdlib.h>

typedef struct tFilaCircular
{
    int *itens;
    int inicio, fim;
    int tamanho;
} FilaCircular;

FilaCircular *criaFilaCircularVazia(int tamanho)
{
    FilaCircular *fila = (FilaCircular *)malloc(sizeof(FilaCircular));
    fila->itens = (int *)malloc(tamanho * sizeof(int));
    fila->inicio = 0;
    fila->fim = 0; // Inicializa fim no mesmo lugar que inicio
    fila->tamanho = tamanho;
    return fila;
}

void liberaFilaCircular(FilaCircular *fila)
{
    free(fila->itens);
    free(fila);
}

int cheia(FilaCircular *fila)
{
    return ((fila->fim + 1) % fila->tamanho) == fila->inicio;
}

int vazia(FilaCircular *fila)
{
    return fila->inicio == fila->fim;
}

void enfileirar(FilaCircular *fila, int x)
{
    if (!cheia(fila))
    {
        fila->itens[fila->fim] = x;
        fila->fim = (fila->fim + 1) % fila->tamanho; // Atualiza o fim circularmente
    }
}

int desenfileirar(FilaCircular *fila)
{
    if (!vazia(fila))
    {
        int valor = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->tamanho; // Atualiza o inicio circularmente
        return valor;
    }
    return -1;
}

int main()
{
    int N, x;
    char operacao;
    scanf("%d", &N);
    FilaCircular *fila = criaFilaCircularVazia(N);

    while (scanf(" %c %d", &operacao, &x) != EOF)
    {
        if (operacao == 'E')
        {
            enfileirar(fila, x);
        }
        else if (operacao == 'D')
        {
            int desenfileirado = desenfileirar(fila);
            if (desenfileirado != -1)
            {
                printf("%d\n", desenfileirado);
            }
        }
    }

    liberaFilaCircular(fila);
    return 0;
}
