#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *prox;
} Item;

typedef struct tFila
{
    Item *inicio, *fim;
} Fila;

Fila *criaFilaVazia()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->prox = NULL;
    return novoItem;
}

void liberaFila(Fila *fila)
{
    Item *item = fila->inicio;
    while (item != NULL)
    {
        Item *temp = item;
        item = item->prox;
        free(temp);
    }
    free(fila);
}

int vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, int x)
{
    Item *novoItem = criaItem(x);
    if (vazia(fila))
    {
        fila->inicio = novoItem;
        fila->fim = novoItem;
    }
    else
    {
        fila->fim->prox = novoItem;
        fila->fim = novoItem;
    }
}

int desenfileirar(Fila *fila)
{
    if (vazia(fila))
    {
        return -1;
    }
    Item *temp = fila->inicio;
    int chave = temp->chave;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    free(temp);
    return chave;
}

void imprimir(Fila *fila)
{
    Item *item = fila->inicio;
    while (item != NULL)
    {
        printf("%d ", item->chave);
        item = item->prox;
    }
    printf("\n");
}

int main()
{
    Fila *fila = criaFilaVazia();
    char op;
    int x;
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf("%d", &x);
            enfileirar(fila, x);
            break;
        case 'D':
            desenfileirar(fila);
            break;
        case 'M':
            imprimir(fila);
            break;
        }
    }
    liberaFila(fila);
    return 0;
}

