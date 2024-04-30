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

/**
 * Creates an empty queue.
 * 
 * @return A pointer to the created queue.
 */
Fila *criaFilaVazia()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

/**
 * Creates a new item with the given value.
 * 
 * @param x The value of the item.
 * @return A pointer to the created item.
 */
Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->prox = NULL;
    return novoItem;
}

/**
 * Frees the memory allocated for the queue.
 * 
 * @param fila A pointer to the queue.
 */
void liberaFila(Fila *fila)
{
    Item *atual = fila->inicio;
    while (atual != NULL)
    {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}

/**
 * Checks if the queue is empty.
 * 
 * @param fila A pointer to the queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

/**
 * Prints the elements of the queue.
 * 
 * @param fila A pointer to the queue.
 */
void imprimir(Fila *fila)
{
    Item *atual = fila->inicio;
    while (atual != NULL)
    {
        printf("%d", atual->chave);
        if (atual->prox != NULL)
        {
            printf(" ");
        }
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * Adds an element to the end of the queue.
 * 
 * @param fila A pointer to the queue.
 * @param x The value to be enqueued.
 */
void enfileirar(Fila *fila, int x)
{
    Item *novoItem = criaItem(x);
    if (fila->fim != NULL)
    {
        fila->fim->prox = novoItem;
    }
    else
    {
        fila->inicio = novoItem;
    }
    fila->fim = novoItem;
}

/**
 * Removes and returns the first element of the queue.
 * 
 * @param fila A pointer to the queue.
 * @return The value of the dequeued element, or -1 if the queue is empty.
 */
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

int main()
{
    char op;
    int x;
    Fila *fila = criaFilaVazia();

    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf("%d", &x);
            enfileirar(fila, x);
            break;
        case 'D':
            x = desenfileirar(fila);
            if (x != -1)
            {
                printf("<%d>\n", x);
            }
            break;
        case 'M':
            imprimir(fila);
            break;
        }
    }

    liberaFila(fila);
    return 0;
}
