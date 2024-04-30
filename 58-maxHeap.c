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

int filhoDir(int i)
{
    return 2 * i + 2;
}

int filhoEsq(int i)
{
    return 2 * i + 1;
}

int ultimoPai(Heap *h)
{
    return pai(h->quantidade - 1);
}

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

void constroiHeap(Heap *h)
{
    for (int i = ultimoPai(h); i >= 0; i--)
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
    int n, i;
    scanf("%d", &n);
    while (n != 0)
    {
        Heap *h = criaHeapVazio(n);
        for (i = 0; i < n; i++)
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
