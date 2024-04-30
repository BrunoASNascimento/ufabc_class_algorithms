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
 * @param chave The key of the new item.
 * @return A pointer to the created item.
 */
Item *novoItem(int chave)
{
    Item *novo = (Item *)malloc(sizeof(Item));
    novo->chave = chave;
    novo->esq = novo->dir = NULL;
    return novo;
}

/**
 * Recursively inserts a new item with the given key into the tree.
 * 
 * @param raiz The root of the current subtree.
 * @param chave The key of the item to be inserted.
 * @return The updated root of the subtree.
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
 * @param arv The tree to insert the item into.
 * @param chave The key of the item to be inserted.
 */
void inserir(Arvore *arv, int chave)
{
    arv->raiz = inserirRec(arv->raiz, chave);
}

/**
 * Prints the items in the tree in ascending order.
 * 
 * @param raiz The root of the current subtree.
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
 * Prints the leaf items in the tree.
 * 
 * @param raiz The root of the current subtree.
 */
void imprimirFolhas(Item *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            printf("%d ", raiz->chave);
        }
        imprimirFolhas(raiz->esq);
        imprimirFolhas(raiz->dir);
    }
}

/**
 * Frees the memory allocated for the items in the tree in post-order traversal.
 * 
 * @param raiz The root of the current subtree.
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
    int n, i, x;
    scanf("%d", &n);
    Arvore *arv = criaArvoreVazia();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arv, x);
    }
    imprimirEmOrdem(arv->raiz);
    printf("\nFolhas: ");
    imprimirFolhas(arv->raiz);
    printf("\n");
    liberaPosOrdem(arv->raiz);
    free(arv);
    return 0;
}
