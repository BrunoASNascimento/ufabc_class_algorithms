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
    return novoItem;
}

void inserir(Item **raiz, int chave)
{
    if (*raiz == NULL)
    {
        *raiz = criaItem(chave);
    }
    else if (chave < (*raiz)->chave)
    {
        inserir(&(*raiz)->esq, chave);
    }
    else if (chave > (*raiz)->chave)
    {
        inserir(&(*raiz)->dir, chave);
    }
}

int altura(Item *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int alturaEsquerda = altura(raiz->esq);
        int alturaDireita = altura(raiz->dir);
        if (alturaEsquerda > alturaDireita)
        {
            return alturaEsquerda + 1;
        }
        else
        {
            return alturaDireita + 1;
        }
    }
}

int main()
{
    int n, chave;
    scanf("%d", &n);

    Arvore *arv = criaArvoreVazia();

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &chave);
        inserir(&(arv->raiz), chave);
    }

    printf("%d\n", altura(arv->raiz));

    return 0;
}
