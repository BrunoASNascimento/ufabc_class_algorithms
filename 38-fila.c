#include <stdio.h>
#include <stdlib.h>

typedef struct tFila
{
    int *itens;
    int inicio, fim;
    int tamanho;
} Fila;

Fila *criaFilaVazia(int tamanho)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->itens = (int *)malloc(tamanho * sizeof(int));
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = tamanho;
    return fila;
}

void liberaFila(Fila *fila)
{
    free(fila->itens);
    free(fila);
}

int cheia(Fila *fila)
{
    return ((fila->fim + 1) % fila->tamanho) == fila->inicio;
}

int vazia(Fila *fila)
{
    return fila->fim < fila->inicio;
}

void enfileirar(Fila *fila, int x)
{
    if (cheia(fila))
        return;
    fila->fim = (fila->fim + 1) % fila->tamanho;
    fila->itens[fila->fim] = x;
}

int desenfileirar(Fila *fila)
{
    if (vazia(fila))
        return -1;
    int valor = fila->itens[fila->inicio];
    if (fila->inicio == fila->fim)
    {
        fila->inicio = 0;
        fila->fim = -1;
    }
    else
    {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
    return valor;
}

int main()
{
    int n, x;
    char op;
    scanf("%d", &n);

    Fila *fila = criaFilaVazia(n);

    while (scanf(" %c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            enfileirar(fila, x);
        }
        else if (op == 'D')
        {
            int removido = desenfileirar(fila);
            if (removido != -1)
            {
                printf("%d\n", removido);
            }
        }
    }

    liberaFila(fila);
    return 0;
}
