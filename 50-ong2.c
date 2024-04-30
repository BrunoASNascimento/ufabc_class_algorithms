#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem
{
    char nome[101];
    int rank;
    struct tItem *ant, *prox;
} Item;

typedef struct tLista
{
    Item *primeiro, *ultimo;
} Lista;

Lista *criaListaVazia()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->primeiro = lista->ultimo = NULL;
    return lista;
}

Item *criaItem(char *s)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    strcpy(novoItem->nome, s);
    novoItem->rank = 1;
    novoItem->ant = novoItem->prox = NULL;
    return novoItem;
}

void liberaLista(Lista *lista)
{
    Item *atual = lista->primeiro;
    while (atual != NULL)
    {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

void imprimir(Lista *lista)
{
    Item *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%s [%d]\n", atual->nome, atual->rank);
        atual = atual->prox;
    }
    printf("\n");
}

void troca(Lista *lista, Item *ant, Item *atu)
{
    if (ant->ant)
        ant->ant->prox = atu;
    if (atu->prox)
        atu->prox->ant = ant;
    ant->prox = atu->prox;
    atu->ant = ant->ant;
    ant->ant = atu;
    atu->prox = ant;
    if (lista->primeiro == ant)
        lista->primeiro = atu;
    if (lista->ultimo == atu)
        lista->ultimo = ant;
}

Item *buscaNome(Lista *lista, char *x)
{
    Item *atual = lista->primeiro;
    while (atual != NULL && strcmp(atual->nome, x) != 0)
    {
        atual = atual->prox;
    }
    return atual;
}

void inserir(Lista *lista, char *s)
{
    Item *itemEncontrado = buscaNome(lista, s);
    if (itemEncontrado)
    {
        itemEncontrado->rank++;
        while (itemEncontrado->ant && itemEncontrado->rank > itemEncontrado->ant->rank)
        {
            troca(lista, itemEncontrado->ant, itemEncontrado);
        }
    }
    else
    {
        Item *novoItem = criaItem(s);
        if (lista->ultimo)
        {
            lista->ultimo->prox = novoItem;
            novoItem->ant = lista->ultimo;
            lista->ultimo = novoItem;
        }
        else
        {
            lista->primeiro = lista->ultimo = novoItem;
        }
    }
}

int main()
{
    char s[101];
    Lista *lista = criaListaVazia();
    while (scanf("%s", s) != EOF)
    {
        inserir(lista, s);
    }
    imprimir(lista);
    liberaLista(lista);
    return 0;
}
