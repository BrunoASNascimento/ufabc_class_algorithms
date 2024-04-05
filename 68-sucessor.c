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

Item *busca(Item *raiz, int x)
{
    if (raiz == NULL || raiz->chave == x)
        return raiz;
    if (x < raiz->chave)
        return busca(raiz->esq, x);
    else
        return busca(raiz->dir, x);
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

Item *sucessor(Item *i)
{
    if (i->dir != NULL)
    {   
        // printf("i->dir->chave: %d\n", i->dir->chave);
        Item *curr = i->dir;
        while (curr->esq != NULL)
        {
            curr = curr->esq;
        }
        return curr;
    }
    Item *p = i->pai;
    // printf("p->chave: %d\n", p->chave);
    while (p != NULL && i == p->dir )
    {
        // printf("p->chave while: %d\n", p->chave);
        i = p;
        p = p->pai;
    }
    // return p;
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

    while (scanf("%d", &x) != EOF)
    {
        Item *it = busca(arv->raiz, x);
        if (it != NULL)
        {
            Item *suc = sucessor(it);
            if (suc != NULL)
            {
                printf("Sucessor de %d: %d\n", x, suc->chave);
            }
            else
            {
                printf("Nao ha sucessor para a chave pesquisada.\n");
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


// --- Input ---
// 7
// 3 2 5 1 4 6 7
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8

// --- Program output ---
// Nao ha sucessor para a chave pesquisada.
// Sucessor de 2: 5
// Sucessor de 3: 4
// Sucessor de 4: 6
// Sucessor de 5: 6
// Sucessor de 6: 7
// Nao ha sucessor para a chave pesquisada.
// Chave nao encontrada.
// libera: 1
// libera: 2
// libera: 4
// libera: 7
// libera: 6
// libera: 5
// libera: 3

// --- Expected output (text)---
// Nao ha sucessor para a chave pesquisada.
// Nao ha sucessor para a chave pesquisada.
// Sucessor de 3: 4
// Nao ha sucessor para a chave pesquisada.
// Sucessor de 5: 6
// Sucessor de 6: 7
// Nao ha sucessor para a chave pesquisada.
// Chave nao encontrada.
// libera: 1
// libera: 2
// libera: 4
// libera: 7
// libera: 6
// libera: 5
// libera: 3