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

void imprimeInOrdem(Item *raiz)
{
    if (raiz != NULL)
    {
        imprimeInOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        imprimeInOrdem(raiz->dir);
    }
}

void imprimirFolhasRec(Item *raiz)
{
    if (raiz != NULL)
    {

        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            printf("%d ", raiz->chave);
        }
        else
        {
            imprimirFolhasRec(raiz->esq);
            imprimirFolhasRec(raiz->dir);
        }
    }
}

void imprimirFolhas(Arvore *arv)
{
    printf("Folhas: ");
    imprimirFolhasRec(arv->raiz);
    printf("\n");
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

    printf("Em ordem: ");
    imprimeInOrdem(arv->raiz);
    printf("\n");
    imprimirFolhas(arv);
    liberaArvore(arv);
    return 0;
}
