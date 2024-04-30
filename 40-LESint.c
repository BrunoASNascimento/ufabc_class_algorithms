#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

typedef struct
{
    int itens[MAX];
    int qtd;
} Lista;

/**
 * Initializes the list by setting the quantity of items to zero.
 * 
 * @param lista The list to be initialized.
 */
void criaLista(Lista *lista)
{
    lista->qtd = 0;
}

/**
 * Searches for a value in the list.
 * 
 * @param lista The list to be searched.
 * @param valor The value to be searched for.
 * @return The position of the value if found, -1 otherwise.
 */
int busca(Lista *lista, int valor)
{
    for (int i = 0; i < lista->qtd; i++)
    {
        if (lista->itens[i] == valor)
        {
            return i; // Returns the position if the value is found
        }
    }
    return -1; // Returns -1 if the value is not found
}

/**
 * Inserts a value into the list if it is not already present and the list is not full.
 * 
 * @param lista The list to insert the value into.
 * @param valor The value to be inserted.
 */
void insere(Lista *lista, int valor)
{
    if (lista->qtd >= MAX || busca(lista, valor) != -1)
    {
        return; // Ignores if the list is full or the value already exists
    }

    // Ordered insertion
    int pos;
    for (pos = lista->qtd; pos > 0 && lista->itens[pos - 1] > valor; pos--)
    {
        lista->itens[pos] = lista->itens[pos - 1];
    }
    lista->itens[pos] = valor;
    lista->qtd++;
}

/**
 * Removes a value from the list if it exists.
 * 
 * @param lista The list to remove the value from.
 * @param valor The value to be removed.
 */
void removeValor(Lista *lista, int valor)
{
    int pos = busca(lista, valor);
    if (pos == -1)
    {
        return; // Ignores if the value is not found
    }

    for (int i = pos; i < lista->qtd - 1; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }
    lista->qtd--;
}

/**
 * Prints the values in the list.
 * 
 * @param lista The list to be printed.
 */
void imprimeLista(Lista *lista)
{
    for (int i = 0; i < lista->qtd; i++)
    {
        printf("%d ", lista->itens[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    Lista lista;
    criaLista(&lista);

    char operacao;
    int valor;

    while (scanf(" %c", &operacao) != EOF)
    {
        if (operacao == 'I')
        {
            scanf("%d", &valor);
            insere(&lista, valor);
        }
        else if (operacao == 'R')
        {
            scanf("%d", &valor);
            removeValor(&lista, valor);
        }
        else if (operacao == 'B')
        {
            scanf("%d", &valor);
            printf("%s\n", busca(&lista, valor) != -1 ? "SIM" : "NAO");
        }
        else if (operacao == 'M')
        {
            imprimeLista(&lista);
        }
    }

    return 0;
}
