#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char valor;
    struct No *esq, *dir;
} No;

No *inserir(No *raiz, char valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    else if (valor < raiz->valor)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else
    { // Inclui valores iguais na subárvore direita
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

No *encontrarMin(No *raiz)
{
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

No *excluir(No *raiz, char valor)
{
    if (raiz == NULL)
        return raiz; // Caso base
    if (valor < raiz->valor)
    { // Valor está na subárvore esquerda
        raiz->esq = excluir(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    { // Valor está na subárvore direita
        raiz->dir = excluir(raiz->dir, valor);
    }
    else
    {
        // Nó com apenas um filho ou sem filhos
        if (raiz->esq == NULL)
        {
            No *temp = raiz->dir;
            if (raiz != NULL)
            {
                free(raiz);
            }
            
            return temp;
        }
        else if (raiz->dir == NULL)
        {
            No *temp = raiz->esq;
            if (raiz != NULL)
            {
                free(raiz);
            }
            return temp;
        }

        // Nó com dois filhos: Pegue o sucessor in-order (menor na subárvore direita)
        No *temp = encontrarMin(raiz->dir);

        // Copia o valor do sucessor in-order para este nó
        raiz->valor = temp->valor;

        // Deleta o sucessor in-order
        raiz->dir = excluir(raiz->dir, temp->valor);
    }
    return raiz;
}

void imprimirPreOrder(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->valor);
        imprimirPreOrder(raiz->esq);
        imprimirPreOrder(raiz->dir);
    }
}

void imprimirInOrder(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrder(raiz->esq);
        printf("%c ", raiz->valor);
        imprimirInOrder(raiz->dir);
    }
}

void imprimirPostOrder(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirPostOrder(raiz->esq);
        imprimirPostOrder(raiz->dir);
        printf("%c ", raiz->valor);
    }
}

void liberarArvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{
    char comando[10];
    char valor;
    No *raiz = NULL;

    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "insert") == 0)
        {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if (strcmp(comando, "delete") == 0)
        {
            scanf(" %c", &valor);

            raiz = excluir(raiz, valor);
        }
        else if (strcmp(comando, "pre-order") == 0)
        {
            imprimirPreOrder(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "in-order") == 0)
        {
            imprimirInOrder(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "post-order") == 0)
        {
            imprimirPostOrder(raiz);
            printf("\n");
        }
    }

    liberarArvore(raiz);
    printf("\n"); // Salta uma linha antes de finalizar o programa
    return 0;
}
