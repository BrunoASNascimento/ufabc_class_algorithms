#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Arvore *novaArvore = (Arvore *)malloc(sizeof(Arvore));
    novaArvore->raiz = NULL;
    return novaArvore;
}

Item *criaItem(int chave)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = chave;
    novoItem->esq = novoItem->dir = NULL;
    return novoItem;
}

Item *insereItem(Item *raiz, int chave, int *inserido)
{
    if (raiz == NULL)
    {
        raiz = criaItem(chave);
        *inserido = 1;
    }
    else if (chave < raiz->chave)
    {
        raiz->esq = insereItem(raiz->esq, chave, inserido);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = insereItem(raiz->dir, chave, inserido);
    }
    return raiz;
}

void inserir(Arvore *arv, int chave)
{
    int inserido = 0;
    arv->raiz = insereItem(arv->raiz, chave, &inserido);
}

Item *encontrarMinimo(Item *raiz)
{
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

Item *removerItem(Item *raiz, int chave, int *removido)
{
    if (raiz == NULL)
        return raiz;

    if (chave < raiz->chave)
    {
        raiz->esq = removerItem(raiz->esq, chave, removido);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = removerItem(raiz->dir, chave, removido);
    }
    else
    {
        if (raiz->esq == NULL)
        {
            Item *temp = raiz->dir;
            free(raiz);
            *removido = 1;
            return temp;
        }
        else if (raiz->dir == NULL)
        {
            Item *temp = raiz->esq;
            free(raiz);
            *removido = 1;
            return temp;
        }

        Item *temp = encontrarMinimo(raiz->dir);
        raiz->chave = temp->chave;
        raiz->dir = removerItem(raiz->dir, temp->chave, removido);
    }
    return raiz;
}

int remover(Arvore *arv, int chave)
{
    int removido = 0;
    arv->raiz = removerItem(arv->raiz, chave, &removido);
    return removido;
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

void imprimirInOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirInOrdem(raiz->dir);
    }
}

void imprimirPosOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirPosOrdem(raiz->esq);
        imprimirPosOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void liberaArvore(Item *raiz)
{
    if (raiz != NULL)
    {
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{
    char op[20];
    int x;
    Arvore *arv = criaArvoreVazia();
    while (scanf("%s", op) != EOF)
    {
        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            inserir(arv, x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            scanf("%d", &x);
            if (remover(arv, x))
            {
                printf("%d\n", x);
            }
        }
        else if (strcmp(op, "pre-order") == 0)
        {
            imprimirPreOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(op, "in-order") == 0)
        {
            imprimirInOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(op, "post-order") == 0)
        {
            imprimirPosOrdem(arv->raiz);
            printf("\n");
        }
    }
    liberaArvore(arv->raiz);
    free(arv);
    return 0;
}
