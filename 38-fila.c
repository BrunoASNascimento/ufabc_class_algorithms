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
    fila->fim = 0;
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
    return fila->inicio == fila->fim;
}

void enfileirar(Fila *fila, int x)
{
    if (!cheia(fila))
    {
        fila->itens[fila->fim] = x;
        fila->fim = (fila->fim + 1) % fila->tamanho;
    }
}

int desenfileirar(Fila *fila)
{
    if (!vazia(fila))
    {
        int valor = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
        if (fila->inicio == fila->fim)
        { 
            fila->inicio = fila->fim = 0;
        }
        return valor;
    }
    return -1;
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
            int desenfileirado = desenfileirar(fila);
            if (desenfileirado != -1)
            {
                printf("%d\n", desenfileirado);
            }
        }
    }

    liberaFila(fila);
    return 0;
}
