#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap
{
    int *v; // Array to store the heap elements
    int tamanho; // Maximum size of the heap
    int quantidade; // Current number of elements in the heap
} Heap;

/**
 * Creates an empty heap with the given maximum size.
 * 
 * @param tam The maximum size of the heap
 * @return A pointer to the created heap
 */
Heap *criaHeapVazio(int tam)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->v = (int *)malloc(tam * sizeof(int));
    h->tamanho = tam;
    h->quantidade = 0;
    return h;
}

/**
 * Frees the memory allocated for the heap.
 * 
 * @param h A pointer to the heap to be freed
 */
void liberaHeap(Heap *h)
{
    free(h->v);
    free(h);
}

/**
 * Returns the index of the parent of the element at index i.
 * 
 * @param i The index of the element
 * @return The index of the parent element
 */
int pai(int i)
{
    return (i - 1) / 2;
}

/**
 * Returns the index of the right child of the element at index i.
 * 
 * @param i The index of the element
 * @return The index of the right child element
 */
int filhoDir(int i)
{
    return 2 * i + 2;
}

/**
 * Returns the index of the left child of the element at index i.
 * 
 * @param i The index of the element
 * @return The index of the left child element
 */
int filhoEsq(int i)
{
    return 2 * i + 1;
}

/**
 * Returns the index of the last parent element in the heap.
 * 
 * @param h A pointer to the heap
 * @return The index of the last parent element
 */
int ultimoPai(Heap *h)
{
    return pai(h->quantidade - 1);
}

/**
 * Moves the element at index i down the heap until it reaches its correct position.
 * 
 * @param h A pointer to the heap
 * @param i The index of the element to be moved down
 */
void desceChave(Heap *h, int i)
{
    int maior = i;
    int esq = filhoEsq(i);
    int dir = filhoDir(i);

    if (esq < h->quantidade && h->v[esq] > h->v[maior])
    {
        maior = esq;
    }
    if (dir < h->quantidade && h->v[dir] > h->v[maior])
    {
        maior = dir;
    }

    if (maior != i)
    {
        int temp = h->v[i];
        h->v[i] = h->v[maior];
        h->v[maior] = temp;
        desceChave(h, maior);
    }
}

/**
 * Builds a heap from the given array of elements.
 * 
 * @param h A pointer to the heap
 */
void constroiHeap(Heap *h)
{
    for (int i = ultimoPai(h); i >= 0; i--)
    {
        desceChave(h, i);
    }
}

/**
 * Prints the elements of the array.
 * 
 * @param v The array of elements
 * @param n The number of elements to be printed
 */
void imprime(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/**
 * Checks if the heap is empty.
 * 
 * @param h A pointer to the heap
 * @return 1 if the heap is empty, 0 otherwise
 */
int vazio(Heap *h)
{
    return h->quantidade == 0;
}

/**
 * Checks if the heap is full.
 * 
 * @param h A pointer to the heap
 * @return 1 if the heap is full, 0 otherwise
 */
int cheio(Heap *h)
{
    return h->quantidade == h->tamanho;
}

/**
 * Moves the element at index i up the heap until it reaches its correct position.
 * 
 * @param h A pointer to the heap
 * @param i The index of the element to be moved up
 */
void sobeChave(Heap *h, int i)
{
    while (i != 0 && h->v[pai(i)] < h->v[i])
    {
        int temp = h->v[i];
        h->v[i] = h->v[pai(i)];
        h->v[pai(i)] = temp;
        i = pai(i);
    }
}

/**
 * Inserts a new element into the heap.
 * 
 * @param h A pointer to the heap
 * @param x The element to be inserted
 */
void inserir(Heap *h, int x)
{
    if (!cheio(h))
    {
        h->v[h->quantidade++] = x;
        sobeChave(h, h->quantidade - 1);
    }
}

/**
 * Removes the maximum element from the heap.
 * 
 * @param h A pointer to the heap
 * @return The maximum element, or -1 if the heap is empty
 */
int extraiMaximo(Heap *h)
{
    if (!vazio(h))
    {
        int maximo = h->v[0];
        h->v[0] = h->v[h->quantidade - 1];
        h->quantidade--;
        desceChave(h, 0);
        return maximo;
    }
    return -1; // Heap vazio
}

/**
 * Removes the first occurrence of the element x from the heap.
 * 
 * @param h A pointer to the heap
 * @param x The element to be removed
 */
void remover(Heap *h, int x)
{
    int i;
    for (i = 0; i < h->quantidade; i++)
    {
        if (h->v[i] == x)
        {
            h->v[i] = h->v[h->quantidade - 1];
            h->quantidade--;
            sobeChave(h, i);
            desceChave(h, i);
            break;
        }
    }
}

int main()
{
    int tam;
    scanf("%d", &tam);
    Heap *h = criaHeapVazio(tam);
    char op;
    int x;
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &x);
            inserir(h, x);
            break;
        case 'R':
            scanf("%d", &x);
            remover(h, x);
            break;
        case 'E':
            if (!vazio(h))
            {
                x = extraiMaximo(h);
                printf("[%d]\n", x);
            }
            break;
        case 'P':
            if (!vazio(h))
            {
                imprime(h->v, h->quantidade);
            }
            break;
        }
    }
    liberaHeap(h);
    return 0;
}
