#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int chave;
    char valor[21];
    struct No *esq, *dir;
} No;

No *criarNo(char *valor)
{
    No *novo = (No *)malloc(sizeof(No));
    int chave = 0;
    for (int i = 0; valor[i] != '\0'; i++)
    {
        chave += (valor[i] * (i + 1)); // Cálculo da chave hash
    }
    novo->chave = chave;
    strcpy(novo->valor, valor);
    novo->esq = novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, No *novo)
{
    if (raiz == NULL)
    {
        return novo;
    }
    if (novo->chave < raiz->chave)
    {
        raiz->esq = inserir(raiz->esq, novo);
    }
    else if (novo->chave > raiz->chave)
    {
        raiz->dir = inserir(raiz->dir, novo);
    }
    // Ignora se a chave já existe
    return raiz;
}

void imprimirPreOrder(No *raiz)
{
    if (raiz != NULL)
    {
        printf("[%d]:%s\n", raiz->chave, raiz->valor);
        imprimirPreOrder(raiz->esq);
        imprimirPreOrder(raiz->dir);
    }
}

void imprimirInOrder(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrder(raiz->esq);
        printf("[%d]:%s\n", raiz->chave, raiz->valor);
        imprimirInOrder(raiz->dir);
    }
}

void imprimirPostOrder(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirPostOrder(raiz->esq);
        imprimirPostOrder(raiz->dir);
        printf("[%d]:%s\n", raiz->chave, raiz->valor);
    }
}

// Adicione aqui as funções 'excluir', 'encontrarMin' e 'liberarArvore',
// seguindo a lógica já estabelecida para a exclusão e liberação de nós.

int main()
{
    char comando[10], valor[21];
    No *raiz = NULL;

    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "insert") == 0)
        {
            scanf("%s", valor);
            raiz = inserir(raiz, criarNo(valor));
        }
        else if (strcmp(comando, "pre-order") == 0)
        {
            imprimirPreOrder(raiz);
        }
        else if (strcmp(comando, "in-order") == 0)
        {
            imprimirInOrder(raiz);
        }
        else if (strcmp(comando, "post-order") == 0)
        {
            imprimirPostOrder(raiz);
        }
        // Implemente a lógica para 'delete' aqui, usando a função 'excluir'.
    }

    // Liberar a memória alocada para a árvore antes de finalizar o programa.
    // liberarArvore(raiz);

    printf("\n");
    return 0;
}
