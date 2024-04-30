#include <stdio.h>
#include <stdlib.h>

typedef struct tItem
{
    int chave;
    struct tItem *prox;
} Item;

typedef struct tPilha
{
    Item *topo;
    int quantidade;
} Pilha;

/**
 * Creates an empty stack.
 * 
 * @return A pointer to the newly created stack.
 */
Pilha *criaPilhaVazia()
{
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    novaPilha->quantidade = 0;
    return novaPilha;
}

/**
 * Creates a new item with the given value.
 * 
 * @param x The value of the item.
 * @return A pointer to the newly created item.
 */
Item *criaItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = x;
    novoItem->prox = NULL;
    return novoItem;
}

/**
 * Frees the memory allocated for the stack and its items.
 * 
 * @param pilha A pointer to the stack to be freed.
 */
void liberaPilha(Pilha *pilha)
{
    Item *atual = pilha->topo;
    while (atual != NULL)
    {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
}

/**
 * Checks if the stack is empty.
 * 
 * @param pilha A pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int vazia(Pilha *pilha)
{
    return pilha->topo == NULL;
}

/**
 * Prints the elements of the stack.
 * 
 * @param pilha A pointer to the stack.
 */
void imprimir(Pilha *pilha)
{
    Item *atual = pilha->topo;
    if (atual != NULL)
    {
        while (atual != NULL)
        {
            printf("%d", atual->chave);
            atual = atual->prox;
            if (atual != NULL)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}

/**
 * Pushes a new element onto the stack.
 * 
 * @param pilha A pointer to the stack.
 * @param x The value to be pushed onto the stack.
 */
void empilha(Pilha *pilha, int x)
{
    Item *novoItem = criaItem(x);
    novoItem->prox = pilha->topo;
    pilha->topo = novoItem;
    pilha->quantidade++;
}

/**
 * Removes and returns the top element from the stack.
 * 
 * @param pilha A pointer to the stack.
 * @return The value of the top element, or -1 if the stack is empty.
 */
int desempilha(Pilha *pilha)
{
    if (vazia(pilha))
    {
        return -1; // Pilha vazia
    }
    Item *temp = pilha->topo;
    int chave = temp->chave;
    pilha->topo = pilha->topo->prox;
    pilha->quantidade--;
    free(temp);
    return chave;
}

int main()
{
    char op;
    int x;
    Pilha *pilha = criaPilhaVazia();

    while (scanf(" %c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            empilha(pilha, x);
        }
        else if (op == 'D')
        {
            int desempilhado = desempilha(pilha);
            if (desempilhado != -1)
            {
                printf("[%d]\n", desempilhado);
            }
        }
        else if (op == 'M')
        {
            imprimir(pilha);
        }
    }

    liberaPilha(pilha);
    return 0;
}
