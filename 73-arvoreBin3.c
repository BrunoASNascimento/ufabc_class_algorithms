#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem
{
    char chave;
    struct tItem *pai, *esq, *dir;
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

Item *criaItem(char chave)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = chave;
    novoItem->esq = novoItem->dir = novoItem->pai = NULL;
    return novoItem;
}

Item *insereItem(Item *raiz, char chave, Item *pai)
{
    if (raiz == NULL)
    {
        raiz = criaItem(chave);
        raiz->pai = pai;
    }
    else if (chave <= raiz->chave)
    {
        raiz->dir = insereItem(raiz->dir, chave, raiz);
    }
    else
    {
        raiz->esq = insereItem(raiz->esq, chave, raiz);
    }
    return raiz;
}

void inserir(Arvore *arv, char chave)
{
    arv->raiz = insereItem(arv->raiz, chave, NULL);
}

void imprimirPreOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->chave);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

void imprimirInOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrdem(raiz->esq);
        printf("%c ", raiz->chave);
        imprimirInOrdem(raiz->dir);
    }
}

void imprimirPosOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirPosOrdem(raiz->esq);
        imprimirPosOrdem(raiz->dir);
        printf("%c ", raiz->chave);
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
    char comando[20];
    char valor;
    Arvore *arv = criaArvoreVazia();
    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "insert") == 0)
        {
            scanf(" %c", &valor);
            inserir(arv, valor);
        }
        else if (strcmp(comando, "delete") == 0)
        {
            scanf(" %c", &valor);
            // A função de remoção não está implementada neste exemplo
        }
        else if (strcmp(comando, "pre-order") == 0)
        {
            imprimirPreOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(comando, "in-order") == 0)
        {
            imprimirInOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(comando, "post-order") == 0)
        {
            imprimirPosOrdem(arv->raiz);
            printf("\n");
        }
    }
    liberaArvore(arv->raiz);
    free(arv);
    return 0;
}
