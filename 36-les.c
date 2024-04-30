#include <stdio.h>
#include <stdlib.h>

// Define a structure for the list
typedef struct tLista
{
    int *itens;     // Dynamic array for storing the items
    int quantidade; // Current number of items in the list
    int tamanho;    // Maximum capacity of the list
} Lista;

// Function to create an empty list with a given size
Lista *criaListaVazia(int tamanho)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));       // Allocate memory for the list structure
    lista->itens = (int *)malloc(tamanho * sizeof(int)); // Allocate memory for the items
    lista->quantidade = 0;                               // Initially, the list has no items
    lista->tamanho = tamanho;                            // Set the capacity of the list
    return lista;                                        // Return the pointer to the newly created list
}

// Function to free the memory allocated for the list
void liberaLista(Lista *lista)
{
    free(lista->itens); // Free the memory allocated for the items
    free(lista);        // Free the memory allocated for the list structure
}

// Function to check if the list is full
int cheia(Lista *lista)
{
    return lista->quantidade == lista->tamanho; // Return true if the list is full
}

// Function to check if the list is empty
int vazia(Lista *lista)
{
    return lista->quantidade == 0; // Return true if the list has no items
}

// Function to insert an item into the list
void inserir(Lista *lista, int x)
{
    if (cheia(lista))
        return; // Do nothing if the list is full

    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->itens[i] == x)
            return; // Do nothing if the item is already in the list
    }

    lista->itens[lista->quantidade] = x; // Add the new item to the end of the list
    lista->quantidade++;                 // Increase the number of items in the list
}

// Function to remove an item from the list
void remover(Lista *lista, int x)
{
    int posicao = -1; // Position of the item to be removed
    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->itens[i] == x)
        {
            posicao = i; // Find the position of the item
            break;
        }
    }

    if (posicao != -1)
    { // If the item was found
        for (int i = posicao; i < lista->quantidade - 1; i++)
        {
            lista->itens[i] = lista->itens[i + 1]; // Shift items to the left
        }
        lista->quantidade--; // Decrease the number of items in the list
    }
}

int main()
{
    int q, x;
    char op;
    scanf("%d", &q);

    Lista *lista = criaListaVazia(q); // Create an empty list with the specified size

    for (int i = 0; i < q; i++)
    {
        scanf(" %c %d", &op, &x); // Read the operation and the item

        if (op == 'I')
        {
            inserir(lista, x); // Insert the item if the operation is 'I'
        }
        else if (op == 'E')
        {
            remover(lista, x); // Remove the item if the operation is 'E'
        }
    }

    // Sort the list
    for (int i = 0; i < lista->quantidade; i++)
    {
        for (int j = i + 1; j < lista->quantidade; j++)
        {
            if (lista->itens[i] > lista->itens[j])
            { // Swap items if they are in the wrong order
                int temp = lista->itens[i];
                lista->itens[i] = lista->itens[j];
                lista->itens[j] = temp;
            }
        }
    }

    if (vazia(lista))
    { // Check if the list is empty
        printf("<vazia>\n");
    }
    else
    {
        for (int i = 0; i < lista->quantidade; i++)
        {
            printf("%d\n", lista->itens[i]); // Print the items in the list
        }
    }

    liberaLista(lista); // Free the memory allocated for the list
    return 0;
}
