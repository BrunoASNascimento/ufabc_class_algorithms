#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap
{
    int *v;
    int tamanho;
    int quantidade;
} Heap;

Heap *criaHeapVazio(int tam)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->v = (int *)malloc(tam * sizeof(int));
    h->tamanho = tam;
    h->quantidade = 0;
    return h;
}

void liberaHeap(Heap *h)
{
    free(h->v);
    free(h);
}

int pai(int i)
{
    return (i - 1) / 2;
}

int filhoEsq(int i)
{
    return 2 * i + 1;
}

int filhoDir(int i)
{
    return 2 * i + 2;
}

void troca(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void peneirar(Heap *h, int i, int n)
{
    int esq = filhoEsq(i);
    int dir = filhoDir(i);
    int maior = i;
    if (esq < n && h->v[esq] > h->v[maior])
        maior = esq;
    if (dir < n && h->v[dir] > h->v[maior])
        maior = dir;
    if (maior != i)
    {
        troca(h->v, i, maior);
        peneirar(h, maior, n);
    }
}

void constroiHeap(Heap *h)
{
    for (int i = h->quantidade / 2 - 1; i >= 0; i--)
    {
        peneirar(h, i, h->quantidade);
    }
}

void imprime(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void heapSort(Heap *h)
{
    constroiHeap(h);
    imprime(h->v, h->quantidade);
    for (int i = h->quantidade - 1; i >= 0; i--)
    {
        troca(h->v, 0, i);
        peneirar(h, 0, i);
        imprime(h->v, h->quantidade);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Heap *h = criaHeapVazio(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h->v[i]);
    }
    h->quantidade = n;
    heapSort(h);
    liberaHeap(h);
    return 0;
}
