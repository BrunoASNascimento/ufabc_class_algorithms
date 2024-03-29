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
} Arvore;

Arvore *criaArvoreVazia()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

Item *criaItem(int x)
{
    Item *novo = (Item *)malloc(sizeof(Item));
    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

void inserirRec(Item **raiz, Item *novo, Item *pai)
{
    if (*raiz == NULL)
    {
        novo->pai = pai;
        *raiz = novo;
    }
    else if (novo->chave < (*raiz)->chave)
    {
        inserirRec(&((*raiz)->esq), novo, *raiz);
    }
    else if (novo->chave > (*raiz)->chave)
    {
        inserirRec(&((*raiz)->dir), novo, *raiz);
    }
}

void inserir(Arvore *arv, int x)
{
    Item *novo = criaItem(x);
    inserirRec(&(arv->raiz), novo, NULL);
}

Item *busca(Item *raiz, int x)
{
    if (raiz == NULL || raiz->chave == x)
        return raiz;
    if (x < raiz->chave)
        return busca(raiz->esq, x);
    else
        return busca(raiz->dir, x);
}

Item *antecessor(Item *i)
{
    if (i->esq != NULL)
    {
        Item *curr = i->esq;
        while (curr->dir != NULL)
        {
            curr = curr->dir;
        }
        return curr;
    }
    Item *p = i->pai;
    while (p != NULL && i == p->esq)
    {
        i = p;
        p = p->pai;
    }
    return p;
}

void imprimirInOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirInOrdem(raiz->dir);
    }
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
    imprimirInOrdem(arv->raiz);
    printf("\n");

    while (scanf("%d", &x) != EOF)
    {
        Item *it = busca(arv->raiz, x);
        if (it != NULL)
        {
            Item *ant = antecessor(it);
            if (ant != NULL)
            {
                printf("Antecessor de %d: %d\n", x, ant->chave);
            }
            else
            {
                printf("Nao ha antecessor para a chave pesquisada.\n");
            }
        }
        else
        {
            printf("Chave nao encontrada.\n");
        }
    }

    liberaArvore(arv);
    return 0;
}
