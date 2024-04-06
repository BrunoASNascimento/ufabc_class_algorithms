#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *ant, *prox;
} Item;

typedef struct tLista
{
    Item *primeiro, *ultimo;
    int quantidade;
} Lista;

/**
 * Cria uma lista vazia.
 * 
 * @return Um ponteiro para a lista vazia.
 */
Lista *criaListaVazia()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->primeiro = lista->ultimo = NULL;
    lista->quantidade = 0;
    return lista;
}

/**
 * Cria um novo item com a chave especificada.
 * 
 * @param x A chave do novo item.
 * @return Um ponteiro para o novo item.
 */
Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->ant = novoItem->prox = NULL;
    return novoItem;
}

/**
 * Libera a memória alocada para a lista.
 * 
 * @param lista Um ponteiro para a lista.
 */
void liberaLista(Lista *lista)
{
    Item *atual = lista->primeiro;
    while (atual != NULL)
    {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

/**
 * Verifica se a lista está vazia.
 * 
 * @param lista Um ponteiro para a lista.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
int vazia(Lista *lista)
{
    return lista->primeiro == NULL;
}

/**
 * Imprime os elementos da lista.
 * 
 * @param lista Um ponteiro para a lista.
 */
void imprimir(Lista *lista)
{
    Item *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * Imprime os elementos da lista em ordem reversa.
 * 
 * @param lista Um ponteiro para a lista.
 */
void imprimirReverso(Lista *lista)
{
    Item *atual = lista->ultimo;
    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->ant;
    }
    printf("\n");
}

/**
 * Insere um novo elemento na lista.
 * 
 * @param lista Um ponteiro para a lista.
 * @param x A chave do novo elemento a ser inserido.
 */
void inserir(Lista *lista, int x)
{
    Item *novoItem = criaItem(x);

    // Lista vazia
    if (vazia(lista))
    {
        lista->primeiro = lista->ultimo = novoItem;
    }
    else
    {
        // Inserção ordenada
        Item *atual = lista->primeiro;
        while (atual != NULL && atual->chave < x)
        {
            atual = atual->prox;
        }
        if (atual == lista->primeiro)
        {
            // Inserção no início
            novoItem->prox = lista->primeiro;
            lista->primeiro->ant = novoItem;
            lista->primeiro = novoItem;
        }
        else if (atual == NULL)
        {
            // Inserção no fim
            novoItem->ant = lista->ultimo;
            lista->ultimo->prox = novoItem;
            lista->ultimo = novoItem;
        }
        else
        {
            // Inserção no meio
            novoItem->prox = atual;
            novoItem->ant = atual->ant;
            atual->ant->prox = novoItem;
            atual->ant = novoItem;
        }
    }
    lista->quantidade++;
}

/**
 * Remove um elemento da lista.
 * 
 * @param lista Um ponteiro para a lista.
 * @param x A chave do elemento a ser removido.
 */
void remover(Lista *lista, int x)
{
    Item *atual = lista->primeiro;
    while (atual != NULL && atual->chave != x)
    {
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        return; // Não encontrado
    }

    if (atual == lista->primeiro)
    {
        lista->primeiro = atual->prox;
        if (lista->primeiro != NULL)
        {
            lista->primeiro->ant = NULL;
        }
    }
    else
    {
        atual->ant->prox = atual->prox;
    }
    if (atual == lista->ultimo)
    {
        lista->ultimo = atual->ant;
        if (lista->ultimo != NULL)
        {
            lista->ultimo->prox = NULL;
        }
    }
    else
    {
        atual->prox->ant = atual->ant;
    }

    free(atual);
    lista->quantidade--;
}

int main()
{
    char op;
    int x;
    Lista *lista = criaListaVazia();

    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &x);
            inserir(lista, x);
            break;
        case 'E':
            scanf("%d", &x);
            remover(lista, x);
            break;
        case 'M':
            imprimir(lista);
            break;
        case 'R':
            imprimirReverso(lista);
            break;
        }
    }

    liberaLista(lista);
    return 0;
}
