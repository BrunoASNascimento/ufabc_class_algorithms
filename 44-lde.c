#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *prox;
} Item;

typedef struct tLista
{
    Item *inicio;
    int quantidade;
} Lista;

Lista *criaListaVazia()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->prox = NULL;
    return novoItem;
}

void liberaLista(Lista *lista)
{
    Item *item = lista->inicio;
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
    return lista->inicio == NULL;
}

void imprimir(Lista *lista)
{
    Item *item = lista->inicio;
    while (item != NULL)
    {
        printf("%d ", item->chave);
        item = item->prox;
    }
    printf("\n");
}

int buscar(Lista *lista, int x)
{
    Item *item = lista->inicio;
    while (item != NULL)
    {
        if (item->chave == x)
            return 1;
        item = item->prox;
    }
    return 0;
}

void inserir(Lista *lista, int x)
{
    if (!buscar(lista, x))
    {
        Item *novoItem = criaItem(x);
        if (vazia(lista))
        {
            lista->inicio = novoItem;
        }
        else
        {
            Item *anterior = NULL;
            Item *atual = lista->inicio;
            while (atual != NULL && atual->chave < x)
            {
                anterior = atual;
                atual = atual->prox;
            }
            if (anterior == NULL)
            {
                novoItem->prox = lista->inicio;
                lista->inicio = novoItem;
            }
            else
            {
                novoItem->prox = anterior->prox;
                anterior->prox = novoItem;
            }
        }
        lista->quantidade++;
    }
}

void remover(Lista *lista, int x)
{
    Item *anterior = NULL;
    Item *atual = lista->inicio;
    while (atual != NULL && atual->chave != x)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL)
    {
        if (anterior == NULL)
        {
            lista->inicio = atual->prox;
        }
        else
        {
            anterior->prox = atual->prox;
        }
        free(atual);
        lista->quantidade--;
    }
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
        case 'R':
            scanf("%d", &x);
            remover(lista, x);
            break;
        case 'B':
            scanf("%d", &x);
            printf("%s\n", buscar(lista, x) ? "SIM" : "NAO");
            break;
        case 'L':
            imprimir(lista);
            break;
        }
    }
    liberaLista(lista);
    return 0;
}
