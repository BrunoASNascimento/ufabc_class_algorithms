#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *esq, *dir, *pai;
} Item;

typedef struct tArvore
{
    Item *raiz;
} Arvore;

Arvore *criaArvoreVazia()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

Item *criaItem(int chave)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = chave;
    novoItem->esq = NULL;
    novoItem->dir = NULL;
    novoItem->pai = NULL;
    return novoItem;
}

void inserirRec(Item **raiz, Item *novoItem, Item *pai)
{
    if (*raiz == NULL)
    {
        novoItem->pai = pai;
        *raiz = novoItem;
    }
    else if (novoItem->chave < (*raiz)->chave)
    {
        inserirRec(&((*raiz)->esq), novoItem, *raiz);
    }
    else if (novoItem->chave > (*raiz)->chave)
    {
        inserirRec(&((*raiz)->dir), novoItem, *raiz);
    }
    // Chaves iguais são ignoradas
}

void inserir(Arvore *arv, int chave)
{
    Item *novoItem = criaItem(chave);
    inserirRec(&(arv->raiz), novoItem, NULL);
}

Item *sucessor(Item *item)
{
    if (item->dir != NULL)
    {
        Item *curr = item->dir;
        while (curr->esq != NULL)
            curr = curr->esq;
        return curr;
    }
    Item *p = item->pai;
    while (p != NULL && item == p->dir)
    {
        item = p;
        p = p->pai;
    }
    return p;
}

Item *minimo(Item *item)
{
    while (item->esq != NULL)
        item = item->esq;
    return item;
}

void transplant(Arvore *arv, Item *u, Item *v)
{
    if (u->pai == NULL)
    {
        arv->raiz = v;
    }
    else if (u == u->pai->esq)
    {
        u->pai->esq = v;
    }
    else
    {
        u->pai->dir = v;
    }
    if (v != NULL)
    {
        v->pai = u->pai;
    }
}

void removerRec(Arvore *arv, Item *z)
{
    if (z == NULL)
        return; // Chave não encontrada

    if (z->esq == NULL)
    {
        transplant(arv, z, z->dir);
    }
    else if (z->dir == NULL)
    {
        transplant(arv, z, z->esq);
    }
    else
    {
        Item *y = minimo(z->dir);
        if (y->pai != z)
        {
            transplant(arv, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplant(arv, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    free(z);
}

Item *busca(Item *raiz, int chave)
{
    if (raiz == NULL || raiz->chave == chave)
        return raiz;
    if (chave < raiz->chave)
        return busca(raiz->esq, chave);
    else
        return busca(raiz->dir, chave);
}

void remover(Arvore *arv, int chave)
{
    Item *itemARemover = busca(arv->raiz, chave);
    removerRec(arv, itemARemover);
}

void imprimirPreOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->chave);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

void liberaItem(Item *item)
{
    if (item != NULL)
    {
        liberaItem(item->esq);
        liberaItem(item->dir);
        free(item);
    }
}

void liberaArvore(Arvore *arv)
{
    liberaItem(arv->raiz);
    free(arv);
}

int main()
{
    int n, m, i, x;
    scanf("%d", &n);
    Arvore *arv = criaArvoreVazia();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arv, x);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &x);
        remover(arv, x);
    }
    imprimirPreOrdem(arv->raiz);
    printf("\n");
    liberaArvore(arv);
    return 0;
}
