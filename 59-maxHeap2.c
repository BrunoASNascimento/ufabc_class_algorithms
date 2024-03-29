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

int filhoEsq(int i) { return (2 * i) + 1; }

int filhoDir(int i) { return (2 * i) + 2; }

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void desceChave(Heap *h, int i)
{
    int esq = filhoEsq(i), dir = filhoDir(i), maior = i;
    if (esq < h->quantidade && h->v[esq] > h->v[maior])
        maior = esq;
    if (dir < h->quantidade && h->v[dir] > h->v[maior])
        maior = dir;
    if (maior != i)
    {
        troca(&h->v[i], &h->v[maior]);
        desceChave(h, maior);
    }
}

void sobeChave(Heap *h, int i)
{
    while (i != 0 && h->v[pai(i)] < h->v[i])
    {
        troca(&h->v[i], &h->v[pai(i)]);
        i = pai(i);
    }
}

void inserir(Heap *h, int x)
{
    if (h->quantidade < h->tamanho)
    {
        h->v[h->quantidade] = x;
        h->quantidade++;
        sobeChave(h, h->quantidade - 1);
    }
}

int extraiMaximo(Heap *h)
{
    if (h->quantidade > 0)
    {
        int maximo = h->v[0];
        h->v[0] = h->v[h->quantidade - 1];
        h->quantidade--;
        desceChave(h, 0);
        return maximo;
    }
    return -1;
}

void imprime(Heap *h)
{
    for (int i = 0; i < h->quantidade; i++)
    {
        printf("%d ", h->v[i]);
    }
    printf("\n");
}

int main()
{
    int tam, x;
    char op;
    scanf("%d", &tam);
    Heap *h = criaHeapVazio(tam);

    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &x);
            inserir(h, x);
            break;
        case 'E':
            printf("[%d]\n", extraiMaximo(h));
            break;
        case 'P':
            imprime(h);
            break;
        }
    }

    liberaHeap(h);
    return 0;
}


// --- Input ---
// 10
// I 50
// P
// I 30
// P
// I 70
// P
// I 90
// P
// I 10
// P
// I 20
// P
// I 40
// P
// I 80
// P
// I 60
// P
// I 50
// P
// E
// P
// R 50
// P
// E
// P
// E
// P
// R 50
// P
// E
// P
// E
// P
// E
// P
// E
// P
// E
// P
// I 111
// P
// I 222
// P
// I 5
// P

// --- Expected output (text)---
// 50
// 50 30
// 70 30 50
// 90 70 50 30
// 90 70 50 30 10
// 90 70 50 30 10 20
// 90 70 50 30 10 20 40
// 90 80 50 70 10 20 40 30
// 90 80 50 70 10 20 40 30 60
// 90 80 50 70 50 20 40 30 60 10
// [90]
// 80 70 50 60 50 20 40 30 10
// 80 70 40 60 50 20 10 30
// [80]
// 70 60 40 30 50 20 10
// [70]
// 60 50 40 30 10 20
// 60 30 40 20 10
// [60]
// 40 30 10 20
// [40]
// 30 20 10
// [30]
// 20 10
// [20]
// 10
// [10]
// 111
// 222 111
// 222 111 5