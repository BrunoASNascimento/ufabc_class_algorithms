#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item *esq, *dir;
} Item;

typedef struct Arvore
{
    Item *raiz;
} Arvore;

/**
 * Creates an empty tree.
 * 
 * @return A pointer to the created tree.
 */
Arvore *criaArvoreVazia()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

/**
 * Creates a new item with the given key.
 * 
 * @param chave The key of the item.
 * @return A pointer to the created item.
 */
Item *novoItem(int chave)
{
    Item *item = (Item *)malloc(sizeof(Item));
    item->chave = chave;
    item->esq = item->dir = NULL;
    return item;
}

/**
 * Recursively inserts a new item with the given key into the tree.
 * 
 * @param raiz The root of the tree.
 * @param chave The key of the item to be inserted.
 * @return The updated root of the tree.
 */
Item *inserirRec(Item *raiz, int chave)
{
    if (raiz == NULL)
    {
        return novoItem(chave);
    }
    if (chave < raiz->chave)
    {
        raiz->esq = inserirRec(raiz->esq, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = inserirRec(raiz->dir, chave);
    }
    return raiz;
}

/**
 * Inserts a new item with the given key into the tree.
 * 
 * @param arv The tree.
 * @param chave The key of the item to be inserted.
 */
void inserir(Arvore *arv, int chave)
{
    arv->raiz = inserirRec(arv->raiz, chave);
}

/**
 * Recursively searches for an item with the given key in the tree.
 * 
 * @param raiz The root of the tree.
 * @param chave The key to search for.
 * @return A pointer to the item if found, or NULL otherwise.
 */
Item *buscaPosicao(Item *raiz, int chave)
{
    if (raiz == NULL || raiz->chave == chave)
    {
        return raiz;
    }
    if (chave < raiz->chave)
    {
        return buscaPosicao(raiz->esq, chave);
    }
    return buscaPosicao(raiz->dir, chave);
}

/**
 * Finds the maximum value in the subtree rooted at the given item.
 * 
 * @param item The root of the subtree.
 * @return A pointer to the item with the maximum value.
 */
Item *maxValor(Item *item)
{
    Item *atual = item;
    while (atual && atual->dir != NULL)
    {
        atual = atual->dir;
    }
    return atual;
}

/**
 * Finds the predecessor of the given item.
 * 
 * @param item The item.
 * @return A pointer to the predecessor item, or NULL if it doesn't exist.
 */
Item *antecessor(Item *item)
{
    if (item == NULL || item->esq == NULL)
    {
        return NULL;
    }
    return maxValor(item->esq);
}

/**
 * Prints the items in the tree in ascending order.
 * 
 * @param raiz The root of the tree.
 */
void imprimirEmOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->dir);
    }
}

/**
 * Frees the memory allocated for the items in the tree in post-order traversal.
 * 
 * @param raiz The root of the tree.
 */
void liberaPosOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        liberaPosOrdem(raiz->esq);
        liberaPosOrdem(raiz->dir);
        printf("libera: %d\n", raiz->chave);
        free(raiz);
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
    imprimirEmOrdem(arv->raiz);
    printf("\n");
    while (scanf("%d", &x) != EOF)
    {
        Item *it = buscaPosicao(arv->raiz, x);
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
    liberaPosOrdem(arv->raiz);
    free(arv);
    return 0;
}
