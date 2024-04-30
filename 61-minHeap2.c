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

int pai(int i) { return (i - 1) / 2; }

int filhoEsq(int i) { return 2 * i + 1; }

int filhoDir(int i) { return 2 * i + 2; }

int vazio(Heap *h) { return h->quantidade == 0; }

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sobeChave(Heap *h, int i)
{
    while (i != 0 && h->v[pai(i)] > h->v[i])
    {
        troca(&h->v[i], &h->v[pai(i)]);
        i = pai(i);
    }
}

void desceChave(Heap *h, int i)
{
    int esq = filhoEsq(i), dir = filhoDir(i), menor = i;
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

void inserir(Heap *h, int x)
{
    if (h->quantidade == h->tamanho)
        return;
    h->v[h->quantidade] = x;
    h->quantidade++;
    sobeChave(h, h->quantidade - 1);
}

int extraiMinimo(Heap *h)
{
    if (vazio(h))
        return -1;
    int min = h->v[0];
    h->v[0] = h->v[h->quantidade - 1];
    h->quantidade--;
    desceChave(h, 0);
    return min;
}

void remover(Heap *h, int x)
{
    for (int i = 0; i < h->quantidade; i++)
    {
        if (h->v[i] == x)
        {
            h->v[i] = h->v[h->quantidade - 1];
            h->quantidade--;
            desceChave(h, i);
            break;
        }
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
                x = extraiMinimo(h);
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
