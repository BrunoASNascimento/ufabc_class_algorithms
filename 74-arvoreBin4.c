#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem
{
    int chave;
    char palavra[21];
    struct tItem *pai, *esq, *dir;
} Item;

typedef struct tArvore
{
    Item *raiz;
} Arvore;

int calculaChave(char *palavra)
{
    int chave = 0;
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        chave += palavra[i];
    }
    return chave;
}

void inserirComPalavra(Arvore *arv, char *palavra)
{
    int chave = calculaChave(palavra);
}

int main()
{
    char operacao[20];
    char palavra[21];
    Arvore *arv = criaArvoreVazia();

    while (scanf("%s", operacao) != EOF)
    {
        if (strcmp(operacao, "insert") == 0)
        {
            scanf("%s", palavra);
            inserirComPalavra(arv, palavra);
        }
        else if (strcmp(operacao, "delete") == 0)
        {
            scanf("%s", palavra);
        }
        else if (strcmp(operacao, "pre-order") == 0)
        {
            imprimirPreOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(operacao, "in-order") == 0)
        {
            imprimirInOrdem(arv->raiz);
            printf("\n");
        }
        else if (strcmp(operacao, "post-order") == 0)
        {
            imprimirPosOrdem(arv->raiz);
            printf("\n");
        }
    }

    liberaArvore(arv->raiz);
    free(arv);
    return 0;
}
