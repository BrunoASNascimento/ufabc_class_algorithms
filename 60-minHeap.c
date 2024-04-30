#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap
{
    int *v;
    int tamanho;    // tamanho do vetor alocado
    int quantidade; // qtde elementos inseridos
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

int pai(int i) { return (i - 1) / 2; }

int filhoEsq(int i) { return 2 * i + 1; }

int filhoDir(int i) { return 2 * i + 2; }

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void desceChave(Heap *h, int i)
{
    int esq = filhoEsq(i), dir = filhoDir(i);
    int menor = i;
    if (esq < h->quantidade && h->v[esq] < h->v[menor])
        menor = esq;
    if (dir < h->quantidade && h->v[dir] < h->v[menor])
        menor = dir;
    if (menor != i)
    {
        troca(&h->v[i], &h->v[menor]);
        desceChave(h, menor);
    }
}

void constroiHeap(Heap *h)
{
    int i;
    for (i = h->quantidade / 2 - 1; i >= 0; i--)
    {
        desceChave(h, i);
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

int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        Heap *h = criaHeapVazio(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &h->v[i]);
        }
        h->quantidade = n;
        constroiHeap(h);
        imprime(h->v, h->quantidade);
        liberaHeap(h);
        scanf("%d", &n);
    }
    return 0;
}
