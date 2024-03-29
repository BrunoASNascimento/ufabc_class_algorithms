#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *esq, *dir;
} Item;

typedef struct tArvore
{
    Item *raiz;
} Arvore;

Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->esq = novoItem->dir = NULL;
    return novoItem;
}

Arvore *criaArvoreVazia()
{
    Arvore *novaArvore = (Arvore *)malloc(sizeof(Arvore));
    novaArvore->raiz = NULL;
    return novaArvore;
}

void inserirRec(Item **raiz, int x)
{
    if (*raiz == NULL)
    {
        *raiz = criaItem(x);
    }
    else if (x < (*raiz)->chave)
    {
        inserirRec(&(*raiz)->esq, x);
    }
    else if (x > (*raiz)->chave)
    {
        inserirRec(&(*raiz)->dir, x);
    }
    // Ignora chaves repetidas
}

void inserir(Arvore *arv, int x)
{
    inserirRec(&arv->raiz, x);
}

void imprimePreOrdem(Item *r)
{
    if (r != NULL)
    {
        printf("%d ", r->chave);
        imprimePreOrdem(r->esq);
        imprimePreOrdem(r->dir);
    }
}

void imprimeInOrdem(Item *r)
{
    if (r != NULL)
    {
        imprimeInOrdem(r->esq);
        printf("%d ", r->chave);
        imprimeInOrdem(r->dir);
    }
}

void imprimePosOrdem(Item *r)
{
    if (r != NULL)
    {
        imprimePosOrdem(r->esq);
        imprimePosOrdem(r->dir);
        printf("%d ", r->chave);
    }
}

void liberaArvore(Item *item)
{
    if (item != NULL)
    {
        liberaArvore(item->esq);
        liberaArvore(item->dir);
        free(item);
    }
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
    printf("Pre-ordem: ");
    imprimePreOrdem(arv->raiz);
    printf("\nIn-ordem: ");
    imprimeInOrdem(arv->raiz);
    printf("\nPos-ordem: ");
    imprimePosOrdem(arv->raiz);
    printf("\n");
    liberaArvore(arv->raiz);
    free(arv);
    return 0;
}
