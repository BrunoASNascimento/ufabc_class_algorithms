#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *prox;
} Item;

typedef struct tPilha
{
    Item *topo;
    int quantidade;
} Pilha;

Pilha *criaPilhaVazia()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->quantidade = 0;
    return pilha;
}

Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->prox = NULL;
    return novoItem;
}

void liberaPilha(Pilha *pilha)
{
    Item *item = pilha->topo;
    while (item != NULL)
    {
        Item *temp = item;
        item = item->prox;
        free(temp);
    }
    free(pilha);
}

int vazia(Pilha *pilha)
{
    return pilha->topo == NULL;
}

void empilha(Pilha *pilha, int x)
{
    Item *novoItem = criaItem(x);
    novoItem->prox = pilha->topo;
    pilha->topo = novoItem;
    pilha->quantidade++;
}

int desempilha(Pilha *pilha)
{
    if (vazia(pilha))
    {
        return -1;
    }
    Item *topoItem = pilha->topo;
    int chave = topoItem->chave;
    pilha->topo = topoItem->prox;
    free(topoItem);
    pilha->quantidade--;
    return chave;
}

void imprimir(Pilha *pilha)
{
    Item *item = pilha->topo;
    while (item != NULL)
    {
        printf("%d ", item->chave);
        item = item->prox;
    }
    printf("\n");
}

int main()
{
    Pilha *pilha = criaPilhaVazia();
    char op;
    int x;
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf("%d", &x);
            empilha(pilha, x);
            break;
        case 'D':
            desempilha(pilha);
            break;
        case 'M':
            imprimir(pilha);
            break;
        }
    }
    liberaPilha(pilha);
    return 0;
}
