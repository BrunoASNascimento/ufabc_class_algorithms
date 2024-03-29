#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *pai, *esq, *dir;
} Item;

typedef struct tArvore
{
    Item *raiz;
    int quantidade;
} Arvore;

Item *criaItem(int x)
{
    Item *item = (Item *)malloc(sizeof(Item));
    item->chave = x;
    item->pai = item->esq = item->dir = NULL;
    return item;
}

Arvore *criaArvoreVazia()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    arv->quantidade = 0;
    return arv;
}

void liberaItem(Item *item)
{
    if (item != NULL)
    {
        liberaItem(item->esq);
        liberaItem(item->dir);
        printf("libera: %d\n", item->chave);
        free(item);
    }
}

void liberaArvore(Arvore *arv)
{
    liberaItem(arv->raiz);
    free(arv);
}

void inserirRec(Item **raiz, Item *item)
{
    if (*raiz == NULL)
    {
        *raiz = item;
    }
    else if (item->chave < (*raiz)->chave)
    {
        inserirRec(&(*raiz)->esq, item);
    }
    else if (item->chave > (*raiz)->chave)
    {
        inserirRec(&(*raiz)->dir, item);
    }
    else
    {

        free(item);
    }
}

void inserir(Arvore *arv, int x)
{
    Item *item = criaItem(x);
    inserirRec(&arv->raiz, item);
    arv->quantidade++;
}

void imprimirRec(Item *item)
{
    if (item != NULL)
    {
        imprimirRec(item->esq);
        printf("%d ", item->chave);
        imprimirRec(item->dir);
    }
}

void imprimir(Arvore *arv)
{
    imprimirRec(arv->raiz);
    printf("\n");
}

int main()
{
    int n, x;
    scanf("%d", &n);
    Arvore *arv = criaArvoreVazia();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arv, x);
    }
    imprimir(arv);
    liberaArvore(arv);
    return 0;
}
