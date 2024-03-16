#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *ant, *prox;
} Item;

typedef struct tLista
{
    Item *primeiro, *ultimo;
    int quantidade;
} Lista;

Lista *criaListaVazia()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->quantidade = 0;
    return lista;
}

Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->ant = NULL;
    novoItem->prox = NULL;
    return novoItem;
}

void liberaLista(Lista *lista)
{
    Item *item = lista->primeiro;
    while (item != NULL)
    {
        Item *temp = item;
        item = item->prox;
        free(temp);
    }
    free(lista);
}

int vazia(Lista *lista)
{
    return lista->primeiro == NULL;
}

void imprimir(Lista *lista)
{
    Item *item = lista->primeiro;
    while (item != NULL)
    {
        printf("%d ", item->chave);
        item = item->prox;
    }
    printf("\n");
}

void imprimirReverso(Lista *lista)
{
    Item *item = lista->ultimo;
    while (item != NULL)
    {
        printf("%d ", item->chave);
        item = item->ant;
    }
    printf("\n");
}

void inserir(Lista *lista, int x)
{
    Item *novoItem = criaItem(x);
    if (vazia(lista))
    {
        lista->primeiro = novoItem;
        lista->ultimo = novoItem;
    }
    else
    {
        novoItem->prox = NULL;
        novoItem->ant = lista->ultimo;
        lista->ultimo->prox = novoItem;
        lista->ultimo = novoItem;
    }
    lista->quantidade++;
}

void remover(Lista *lista, int x)
{
    if (vazia(lista))
        return;
    Item *item = lista->primeiro;
    while (item != NULL && item->chave != x)
    {
        item = item->prox;
    }
    if (item == NULL)
        return;
    if (item->ant != NULL)
        item->ant->prox = item->prox;
    else
        lista->primeiro = item->prox;
    if (item->prox != NULL)
        item->prox->ant = item->ant;
    else
        lista->ultimo = item->ant;
    free(item);
    lista->quantidade--;
}

int main()
{
    Lista *lista = criaListaVazia();
    char op;
    int x;
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &x);
            inserir(lista, x);
            break;
        case 'E':
            scanf("%d", &x);
            remover(lista, x);
            break;
        case 'M':
            imprimir(lista);
            break;
        case 'R':
            imprimirReverso(lista);
            break;
        }
    }
    liberaLista(lista);
    return 0;
}
