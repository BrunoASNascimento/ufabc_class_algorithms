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
    fila->fim = -1;
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
    return (fila->fim + 1) % fila->tamanho == fila->inicio;
}

int vazia(FilaCircular *fila)
{
    return fila->inicio == (fila->fim + 1) % fila->tamanho;
}

void enfileirar(FilaCircular *fila, int x)
{
    if (!cheia(fila))
    {
        fila->fim = (fila->fim + 1) % fila->tamanho;
        fila->itens[fila->fim] = x;
    }
}

int desenfileirar(FilaCircular *fila)
{
    if (!vazia(fila))
    {
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
    return -1;
}

int main()
{
    int n, x;
    char op;
    scanf("%d", &n);

    FilaCircular *fila = criaFilaCircularVazia(n);

    while (scanf(" %c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            enfileirar(fila, x);
        }
        else if (op == 'D')
        {
            int valor = desenfileirar(fila);
            if (valor != -1)
            {
                printf("%d\n", valor);
            }
        }
    }

    liberaFilaCircular(fila);
    return 0;
}
