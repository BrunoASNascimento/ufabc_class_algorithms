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

void inserirRec(Item **raiz, int chave)
{
    if (*raiz == NULL)
    {
        *raiz = criaItem(chave);
    }
    else if (chave < (*raiz)->chave)
    {
        inserirRec(&((*raiz)->esq), chave);
    }
    else if (chave > (*raiz)->chave)
    {
        inserirRec(&((*raiz)->dir), chave);
    }
    // Ignora chaves repetidas
}

void inserir(Arvore *arv, int chave)
{
    inserirRec(&(arv->raiz), chave);
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

Item *minimo(Item *raiz)
{
    if (raiz->esq == NULL)
    {
        return raiz;
    }
    else
    {
        return minimo(raiz->esq);
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
    int n, chave;
    scanf("%d", &n);
    Arvore *arv = criaArvoreVazia();

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &chave);
        inserir(arv, chave);
    }

    imprimirInOrdem(arv->raiz);
    printf("\n");

    Item *itemMin = minimo(arv->raiz);
    printf("Menor chave: %d\n", itemMin->chave);

    liberaArvore(arv);
    return 0;
}
